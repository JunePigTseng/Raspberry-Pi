import RPi.GPIO as GPIO
import time

# 使用BCM模式，即GPIO编号模式
GPIO.setmode(GPIO.BCM)

# 设置GPIO引脚编号，例如GPIO 17
LED_PIN = 12
GPIO.setup(LED_PIN, GPIO.OUT)
PWM = GPIO.PWM(LED_PIN, 50)
PWM.start(50)

try:
    while True:
        print("Do")
        PWM.ChangeFrequency(523)
        time.sleep(1)

        print("Re")
        PWM.ChangeFrequency(587)
        time.sleep(1)

        print("Mi")
        PWM.ChangeFrequency(659)
        time.sleep(1)

except KeyboardInterrupt:
    # 捕获Ctrl+C终止程序
    print("Program terminated")

finally:
    # 清理GPIO设置
    GPIO.cleanup()