#!/usr/bin/env python3

import socket
import os
import sys
from time import sleep

message = "Hello, c program!"

port = 2501

s = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

s.sendto(message.encode(),('127.0.0.1',port))
print("Python message sent: " + message)

data, addr = s.recvfrom(1024)
print("Python received message: " + str(data) + " from " + str(addr))
