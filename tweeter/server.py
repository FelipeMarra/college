from concurrent.futures import process
from socket import *
from struct import *
import sys
import threading
import re

#Metaclass used to make the TagStore a Singleton
class SingletonMeta(type):
    _instances = {}

    def __call__(cls, *args, **kwargs):
        """
        Possible changes to the value of the `__init__` argument do not affect
        the returned instance.
        """
        if cls not in cls._instances:
            instance = super().__call__(*args, **kwargs)
            cls._instances[cls] = instance
        return cls._instances[cls]

# class Client:
#     def __init__(self, addr) -> None:
#         self.addr = addr

#A tag is have a name and the users that are subscribed to it
#It handles the subscriptions sending
class Tag:
    def __init__(self, name: str, sub_clients: list) -> None:
        self.name = name
        self. sub_clients = sub_clients

#A class that stores an controlls whos in the tags
class TagStore(metaclass=SingletonMeta):
    def __init__(self) -> None:
        self.tagsMap = {}

    def tags_names(self):
        return self.tagsMap.keys()

    def add_user_to_tag(self, client_socket: socket, tag_name: str):
        if client_socket in self.tagsMap[tag_name].sub_clients:
            return f"Already Subscribed to Tag {tag_name}"
        self.tagsMap[tag_name].sub_clients.append(client_socket)
        return f"Subscribed to Tag {tag_name}"

    def add_tag(self, tag_name: str, client_socket: socket):
        #If the tag already exists, add client
        if tag_name in self.tagsMap:
            return self.add_user_to_tag(client_socket, tag_name)
        #otherwise create the tag with the client inside
        else:
            new_tag = Tag(name=tag_name, sub_clients=[client_socket])
            self.tagsMap[tag_name] = new_tag
            return f"Created and Subscribed to Tag {tag_name}"

    def remove_user_from_tag(self, tag_name: str, client_socket: socket):
        if not tag_name in self.tagsMap:
            return f"Tag {tag_name} don't exist"
        
        if not (client_socket in self.tagsMap[tag_name].sub_clients):
            return f"Not subscribed to {tag_name}"
        
        self.tagsMap[tag_name].sub_clients.remove(client_socket)
        
        #if nobody is listening to the tag we can remove it
        if len(self.tagsMap[tag_name].sub_clients) == 0:
            self.tagsMap.pop(tag_name)

        return f"Unsubscribed from {tag_name}"

    def send_to_subs(self, tags: list, message: str):
        subs = set()
        for tag_name in tags:
            if not tag_name in self.tagsMap:
                return f"Tag {tag_name} don't exist"

            subs.update(self.tagsMap[tag_name].sub_clients)
        
        for sub in subs:
            sub.send(message.encode())
        
        return f"Message sent!"

all_subs = []

#Create Server and return server socket
def create_server():
    file, server_port = sys.argv
    try:
        server_socket = socket(AF_INET, SOCK_STREAM)
        server_socket.bind(("", int(server_port)))
        server_socket.listen(1)
        print(f"Server ready at port {server_port}, {gethostbyname(gethostname())}")
        print()
        server_socket.getsockname()
        return server_socket;
    except:
        raise Exception("Can't create server")

def kill_server():
    for sub in all_subs:
        try:
            sub.send("##die".encode())
        except:
            print("Error sending ##die")
        try:
            sub.close()
        except:
            print("trying to close")

    serverSocket.close()
    exit()

def process_message(message, client_socket):
    tagStore = TagStore()

    if message == "##kill":
        kill_server()
    
    if message[0] == "+":
        tag_name = message[1:]
        res = tagStore.add_tag(tag_name, client_socket)
        return res 

    if message[0] == "-":
        tag_name = message[1:]
        res = tagStore.remove_user_from_tag(tag_name, client_socket)
        return res

    #get all tags
    tags = [t[1:] for t in re.findall("#\w+", message)]
    res = tagStore.send_to_subs(tags, message)
    return res

def new_connection(clientSocket, addr):
    tagStore = TagStore()
    
    while True:
        received = clientSocket.recv(4)

        if not received:
            print(f"Closing connection with {addr}")
            clientSocket.close()
            quit()

        sentenceSize = unpack("!I", received)[0]
        
        client_message = clientSocket.recv(sentenceSize).decode()

        print(f"Received from {addr}: {client_message}")

        result = process_message(client_message, clientSocket)
        
        clientSocket.send(result.encode())

        print(f"All tags for now: {(*tagStore.tagsMap,)}")

def handle_connections(serverSocket):
    while True:
        try:
            clientSocket, addr = serverSocket.accept()
        except:
            print("Error accepting")
            quit()

        all_subs.append(clientSocket)

        new_trhead = threading.Thread(target=new_connection, args=(clientSocket, addr))
        new_trhead.start()

if __name__ == "__main__":
    serverSocket = create_server()
    handle_connections(serverSocket)