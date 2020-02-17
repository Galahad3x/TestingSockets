#!/usr/bin/env python3

import socket
import os
import sys
from time import sleep

port = 2500

s = socket.socket(socket.AF_INET,socket.SOCK_STREAM);

s.bind(('',port))
print("Parent: Socket binded to port " + str(port))

s.listen(3)

sleep(1)
while True:
    c, addr = s.accept()
    print("Parent: Got connection from" + str(addr))

    while True:
        message = c.recv(1024).decode()
        if message != "":
            print(message)
        else:
            print("Parent: Closing connection from" + str(addr))
            c.close()
            break

    #cont = input("Continue receiving connections?: {y/n}")
    #if cont == "n":
    #    break

s.close()
exit(0)
