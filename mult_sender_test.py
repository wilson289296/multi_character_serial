#serial prep
import serial
import time
port = "/dev/ttyACM0"
ser = serial.Serial(port,9600)
ser.flushInput()
from evdev import InputDevice, categorize, ecodes
xpad = InputDevice('/dev/input/event0')
#button & analog codes
abtn = 304
bbtn = 305
xbtn = 307
ybtn = 308
dvert = 17 #up = -1, down = 1
dhori = 16 #left = -1, right = 1
xboxbtn = 316
lstart = 314
rstart = 315
lbump = 310
rbump = 311
ljoypush = 317
rjoypush = 318

#joysticks need more testing
#leftjoyvert = 04
#leftjoyhori = 03
#rightjoyvert = 01
#rightjoyhori = 00

#min = 0, max = 1024
ltrig = 02
rtrig = 05

time.sleep(3) #give arduino time to prep

#transmitted strings must be terminated with \0
for event in xpad.read_loop():
    if event.type == ecodes.EV_KEY:
	if event.code == bbtn:
	    if event.value == 1:
		print("B down")
		ser.write("Bd\0")
	    else:
		print("B up")
		ser.write("Bu\0")
	if event.code == abtn:
	    if event.value == 1:
		print("A down")
		ser.write("Ad\0")
	    else:
		print("A up")
		ser.write("Au\0") 
	if event.code == xbtn:
	    if event.value == 1:
		print("X down")
		ser.write("Xd\0")
	    else:
		print("X up")
		ser.write("Xu\0") 
	if event.code == ybtn:
	    if event.value == 1:
		print("Y down")
		ser.write("Yd\0")
	    else:
		print("Y up")
		ser.write("Yu\0")
