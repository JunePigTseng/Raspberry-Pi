import RPi.GPIO as GPIO
import time

# 使用BCM模式，即GPIO编号模式
GPIO.setmode(GPIO.BCM)

# 设置GPIO引脚编号，例如GPIO 17
LED_PIN = 13
GPIO.setup(LED_PIN, GPIO.OUT)

try:
    while True:
        # 开启LED
        GPIO.output(LED_PIN, GPIO.HIGH)
        print("LED is ON")
        time.sleep(1)

        # 关闭LED
        GPIO.output(LED_PIN, GPIO.LOW)
        print("LED is OFF")
        time.sleep(1)

except KeyboardInterrupt:
    # 捕获Ctrl+C终止程序
    print("Program terminated")

finally:
    # 清理GPIO设置
    GPIO.cleanup()