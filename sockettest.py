#!/usr/bin/python3.7

import socket
import os
from time import sleep

port = 2000

s = socket.socket(socket.AF_INET,socket.SOCK_STREAM);

pid = os.fork()

if pid != 0:
    s.bind(('',port))
    print("Parent: Socket binded to port " + str(port))

    s.listen(3)

    sleep(2)
    c, addr = s.accept()
    print("Parent: Got connection from" + str(addr))

    message = "Thank you for connection\n"
    c.send(message.encode())
    print("Parent sent: Thank you for your connection")

    #received = s.recv(1024)
    #print("Parent received " + str(received))

    c.close()
    s.close()
    exit(0)

s.connect(('127.0.0.1',port))

print("Child received" + str(s.recv(1024)))

#s.send("I am your child\n")
#print("Child sent: I am your child")

s.close()
