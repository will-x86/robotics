from machine import Pin
import time
import random

red_led = Pin(15, Pin.OUT)
orange_led = Pin(22, Pin.OUT)
green_led = Pin(21, Pin.OUT)
buzzer = Pin(3, Pin.OUT)
button = Pin(2, Pin.IN, Pin.PULL_UP)

def all_off():
    red_led.off()
    orange_led.off()
    green_led.off()

def beep(duration=0.5):
    buzzer.on()
    time.sleep(duration)
    buzzer.off()

def check_button_violation(state):
    if button.value() == 0 and state != "green":
        print(f"Brother do you want to die - It's {state.upper()}")
        beep(0.5)
        time.sleep(0.3)

def wait_and_check(duration, state):
    steps = int(duration * 10)
    for i in range(steps):
        check_button_violation(state)
        time.sleep(0.1)

def traffic_light_cycle():
    all_off()
    red_led.on()
    red_time = random.uniform(3, 7)
    print(f"RED - {red_time:.1f}s")
    wait_and_check(red_time, "red")
    
    all_off()
    green_led.on()
    green_time = random.uniform(4, 8)
    print(f"GREEN - {green_time:.1f}s")
    
    steps = int(green_time * 10)
    for i in range(steps):
        if button.value() == 0:
            print("Button pressed on GREEN")
            time.sleep(0.3)
        time.sleep(0.1)
    
    all_off()
    orange_led.on()
    orange_time = random.uniform(2, 4)
    print(f"ORANGE - {orange_time:.1f}s")
    wait_and_check(orange_time, "orange")

print("Traffic light system started")
print("Press the button when you would cross the road")

try:
    while True:
        traffic_light_cycle()
except KeyboardInterrupt:
    print("Stopping")
    all_off()
    buzzer.off()