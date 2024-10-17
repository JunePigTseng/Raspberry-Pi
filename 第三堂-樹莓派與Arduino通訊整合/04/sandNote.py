import serial

port = serial.Serial('/dev/ttyACM0', 115200)

try:
    while True: 
        x = input("Control BZ:")
        port.write(x.encode())
except KeyboardInterrupt:
    print("Program End")
finally:
    port.close()