import socket
import sys
import os
import signal

# Create a TCP/IP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)



def handler(signum, frame):
    sock.close()

# Bind the socket to the port
server_address = ('localhost', 30003)
print('starting up on %s port %s' % server_address)

try:
    sock.bind(server_address)
except (socket.errror, exc):
    print('failed to bind socket: %S' & exc)
    handler(0, 0)
    exit()

# Listen for incoming connections
sock.listen(1)

while 1:
    try:
        while 1:
            newSocket, address = sock.accept()
            # loop serving the new client
            while 1:
                receivedData = newSocket.recv(1024)
                if not receivedData:
                    break
                # Echo back the same data you just received
                print(str(address) + " : " + str(receivedData))
                newSocket.send(b'\x08\x01(\x01')

            newSocket.close()
    finally:
        handler(0, 0)
