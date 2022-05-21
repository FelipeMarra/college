from pickle import FALSE
from socket import *
from struct import *
import threading
import string
import sys
from time import sleep

file, server_ip, server_port = sys.argv

MESSAGE_MAX_SIZE = 500

#Connects with the server and returns the socket
def connect_with_server():
    try:
        clientSocket = socket(AF_INET, SOCK_STREAM, 0)
        clientSocket.settimeout(15)
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
def send_message(message:str, clientSocket:socket):
    if(message_is_valid(message)):
        try:
            #send sentence size
            #TODO verify size, 1 letter == 1 byte?
            clientSocket.send(pack("!I", len(message)))
            #send sentence
            clientSocket.send(message.encode())
        except:
            raise Exception("Error sending message")

def receive_message(clientSocket):
    while True:
        try:
            #receive answer
            server_res = clientSocket.recv(int(server_port))
            print("Server Response: ", server_res.decode())
            print()
        except:
            raise Exception("Error receiving message")

def listen_user_input(clientSocket):
    #While theres a user input
    message = "init"
    while message:
        message = input("Message: ")
        
        #send message in a new thread
        new_thread = threading.Thread(target=send_message, args=(message, clientSocket))
        new_thread.start()
    
    clientSocket.close()

def listem_server(clientSocket):
    new_thread = threading.Thread(target=receive_message, args=(clientSocket,))
    new_thread.start()


if __name__ == "__main__":
    clientSocket = connect_with_server()

    listem_server(clientSocket)
    listen_user_input(clientSocket)