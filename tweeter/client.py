from pickle import FALSE
from socket import *
from struct import *
import threading
import string
import sys

file, server_ip, server_port = sys.argv

MESSAGE_MAX_SIZE = 500

#Connects with the server and returns the socket
def connect_with_server():
    try:
        clientSocket = socket(AF_INET, SOCK_STREAM, 0)
        clientSocket.settimeout(5)
        clientSocket.connect((server_ip, int(server_port)))
        clientSocket.settimeout(None)
        return clientSocket
    except:
        raise Exception("Can't connect to server")

def message_is_valid(message):
    if any(c not in string.printable for c in message):
        print("Invalid message: Message contains not ASCII letters")
        return False
    if not(any(c in ("#") for c in message)) and message[0] != "-" and message[0] != "+":
        print("Invalid message: Message is not tag-related. Stop saying bullshit!")
        return False
    return True

#Sends a message to the server
def send_message(clientSocket:socket):
    while True:
        message = input("Message: ")
        if(message):
            if(message_is_valid(message)):
                try:
                    #send sentence size
                    #TODO verify size, 1 letter == 1 byte?
                    clientSocket.send(pack("!I", len(message)))
                    #send sentence
                    clientSocket.send(message.encode())
                except:
                    print("Error sending message")
                    clientSocket.close()
                    quit()
        else:
            #if theres no message
            clientSocket.close()
            quit()

def receive_message(clientSocket):
    while True:
        try:
            server_res = clientSocket.recv(int(server_port)).decode()
        except:
            print("Error receiving message")
            clientSocket.close()
            quit()

        #print(server_res)
        if server_res == "##die":
            print("Server was killed, press enter to exit")
            clientSocket.close()
            quit()
        else:
            print("Server Response: ", server_res)

def listen_user_input(clientSocket):
    #send message in a new thread
    new_thread = threading.Thread(target=send_message, args=(clientSocket, ))
    new_thread.start()

def listem_server(clientSocket):
    new_thread = threading.Thread(target=receive_message, args=(clientSocket,))
    new_thread.start()


if __name__ == "__main__":
    clientSocket = connect_with_server()

    listem_server(clientSocket)
    listen_user_input(clientSocket)