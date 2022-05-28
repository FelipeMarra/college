from concurrent.futures import process
from socket import *
from struct import *
import threading
import sys
import re

MESSAGE_MAX_SIZE = 500

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

#A tag have a name and the users that are subscribed to it
class Tag:
    def __init__(self, name: str, sub_clients: list):
        self.name = name
        self. sub_clients = sub_clients

#A class that stores and controlls whos in the tags
class TagStore(metaclass=SingletonMeta):
    def __init__(self):
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
            return f"+{tag_name}"

    def remove_user_from_tag(self, tag_name: str, client_socket: socket):
        if not tag_name in self.tagsMap:
            return f"Tag {tag_name} don't exist"
        
        if not (client_socket in self.tagsMap[tag_name].sub_clients):
            return f"Not subscribed to {tag_name}"
        
        self.tagsMap[tag_name].sub_clients.remove(client_socket)
        
        #if nobody is listening to the tag we can remove it
        if len(self.tagsMap[tag_name].sub_clients) == 0:
            self.tagsMap.pop(tag_name)

        return f"-{tag_name}"

    def send_to_subs(self, tags: list, message: str):
        subs = set()
        for tag_name in tags:
            if not tag_name in self.tagsMap:
                return f"Tag {tag_name} don't exist"

            subs.update(self.tagsMap[tag_name].sub_clients)
        
        for sub in subs:
            try:
                sub.send(message.encode())
            except:
                print(f"Error sending to {sub}")

        return f"Message sent!"

class Server:
    def __init__(self):
        self.all_subs = []
        self.serverSocket = None

    #Create Server and return server socket
    def start(self):
        file, server_port = sys.argv
        try:
            server_socket = socket(AF_INET, SOCK_STREAM)
            server_socket.bind(("", int(server_port)))
            server_socket.listen(1)
            print(f"Server ready at port {server_port}, {gethostbyname(gethostname())}")
            print()

            self.serverSocket = server_socket;

            self.handle_connections()
        except:
            raise Exception("Can't create server")

    def handle_connections(self):
        while True:
            try:
                clientSocket, addr = self.serverSocket.accept()
            except:
                print("Error accepting")
                quit()

            self.all_subs.append(clientSocket)
            
            new_thread = threading.Thread(target=self.listen_client, args=(clientSocket, addr))
            new_thread.start()

    def listen_client(self, client_socket, addr):
        tagStore = TagStore()

        mounting_message = ""

        while True:
            received = client_socket.recv(4)

            if not received:
                print(f"Closing connection with {addr}: Client Disconnected")
                client_socket.close()
                quit()

            received_message_size = unpack("!I", received)[0]

            if received_message_size > MESSAGE_MAX_SIZE:
                print(f"Closing connection with {addr}: Message Overflow")
                client_socket.close()
                quit()


            received_message = client_socket.recv(received_message_size).decode()

            by_n_messages = received_message.split("\\n")

            for split_message in by_n_messages:
                #cheack if to kill
                if self.process_kill(received_message):
                    quit()


                #check if it is to process + and -
                add_sub_res = self.process_add_subtract(split_message, client_socket)

                if add_sub_res:
                    client_socket.send(add_sub_res.encode())
                    print(f"All tags for now: {(*tagStore.tagsMap,)}")
                    #ignore possible mouting message
                    mounting_message = ""
                    continue
                

                mounting_message = f"{mounting_message} {split_message}"

                #if theres no \n, continue to receive the rest of the message
                if not split_message:
                    #otherwise it is suposed to be a finalized # message
                    print(f"Finalized Message from {addr}: {mounting_message}")
                    result = self.process_hashtag(mounting_message)

                    client_socket.send(result.encode())

                    mounting_message = ""
                else:
                    print(f"Mounting Message from {addr}: {mounting_message}")

    def process_kill(self, message):
        if message == "##kill":
            self.suicide()

        return ""

    def process_add_subtract(self, message, client_socket):
        tagStore = TagStore()

        if not message:
            return ""

        if message[0] == "+":
            tag_name = message[1:]
            res = tagStore.add_tag(tag_name, client_socket)
            return res 

        if message[0] == "-":
            tag_name = message[1:]
            res = tagStore.remove_user_from_tag(tag_name, client_socket)
            return res
        
        return ""


    def process_hashtag(self, message):
        tagStore = TagStore()

        #get all tags
        tags = [t[1:] for t in re.findall("#\w+", message)]
        res = tagStore.send_to_subs(tags, message)
        return res

    def suicide(self):
        for sub in self.all_subs:

            sub.send("##die".encode())

            try:
                sub.close()
            except:
                print("Error trying to close")

        self.serverSocket.close()
        exit()


if __name__ == "__main__":
    server = Server()
    server.start()