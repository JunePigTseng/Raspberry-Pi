import RPi.GPIO as GPIO
import time

# 禁用GPIO的警告信息
GPIO.setwarnings(False)

# 设置GPIO为BCM编号模式
GPIO.setmode(GPIO.BCM)

# 定义LED和按钮引脚
LED_PIN = 13
btn1_pin = 14
btn2_pin = 15

# 设置LED引脚为输出模式，按钮引脚为输入模式
GPIO.setup(LED_PIN, GPIO.OUT)
GPIO.setup(btn1_pin, GPIO.IN)
GPIO.setup(btn2_pin, GPIO.IN)

try:
    while True:
        v1 = 1 - GPIO.input(btn1_pin)  # 检测按钮1状态
        v2 = 1 - GPIO.input(btn2_pin)  # 检测按钮2状态

        if v1 ^ v2:
            GPIO.output(LED_PIN, GPIO.HIGH)
        else:
            GPIO.output(LED_PIN, GPIO.LOW)

        time.sleep(0.1)

except KeyboardInterrupt:
    # 捕获Ctrl+C终止程序
    print("Program terminated")

finally:
    # 清理GPIO设置
    GPIO.cleanup()