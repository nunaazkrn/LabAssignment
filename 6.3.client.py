import socket
import signal
import sys

ClientSocket = socket.socket()
host = '192.168.53.3'
port = 8898

print('waiting for a connection from client')
try:
    ClientSocket.connect((host, port))
except socket.error as e:
    print(str(e))

Response = ClientSocket.recv(1024)
print(Response.decode("utf-8"))
while True:
    Input = input('Enter the operation and number that you want to execute: ')
    
    if Input == 'exit':
        break
    else:
        ClientSocket.send(str.encode(Input))
        Response = ClientSocket.recv(1024)
        print(Response.decode("utf-8"))

ClientSocket.close()
