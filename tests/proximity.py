import json
from serial import Serial
from time import sleep

# General definition
serial_port = "COM5"

try:
    s = Serial(serial_port)
except:
    print("Was not possible to open com serial: {}".format(serial_port))
    exit(-1)

while(True):
    res = s.readline().replace(" ", "")
    response = json.loads(res)
    print(response["state"])
