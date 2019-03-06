#serial prep
import serial
import time
port = "/dev/ttyACM1"
ser = serial.Serial(port,9600)
ser.flushInput()

#transmitted strings must be terminated with \0
time.sleep(3)
ser.write("B\0")
time.sleep(3)
ser.write("A\0")
time.sleep(3)
ser.write("X\0")
time.sleep(3)
ser.write("Y\0")
