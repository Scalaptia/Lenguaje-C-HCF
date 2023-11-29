import cv2
import numpy as np
import time
from twilio.rest import Client
import os
from dotenv import load_dotenv

load_dotenv()
TWILIO_SID = os.getenv('TWILIO_SID')
TWILIO_AUTH_TOKEN = os.getenv('TWILIO_AUTH_TOKEN')
TWILIO_PHONE_NUMBER = os.getenv('TWILIO_PHONE_NUMBER')
YOUR_PHONE_NUMBER = os.getenv('YOUR_PHONE_NUMBER')

LOW_STOCK_THRESHOLD_BLUE = 1
LOW_STOCK_THRESHOLD_YELLOW = 1

TIME_BETWEEN_RUNS = 60 # Time in seconds

client = Client(TWILIO_SID, TWILIO_AUTH_TOKEN)

def send_sms(message):
    message = client.messages.create(
        body=message,
        from_=TWILIO_PHONE_NUMBER,
        to=YOUR_PHONE_NUMBER
    )

def get_limits(color):
    c = np.uint8([[color]])  # BGR values
    hsvC = cv2.cvtColor(c, cv2.COLOR_BGR2HSV)

    hue = hsvC[0][0][0]  # Get the hue value

    # Handle red hue wrap-around
    if hue >= 165:  # Upper limit for divided red hue
        lowerLimit = np.array([hue - 10, 100, 100], dtype=np.uint8)
        upperLimit = np.array([180, 255, 255], dtype=np.uint8)
    elif hue <= 15:  # Lower limit for divided red hue
        lowerLimit = np.array([0, 100, 100], dtype=np.uint8)
        upperLimit = np.array([hue + 10, 255, 255], dtype=np.uint8)
    else:
        lowerLimit = np.array([hue - 10, 100, 100], dtype=np.uint8)
        upperLimit = np.array([hue + 10, 255, 255], dtype=np.uint8)

    return lowerLimit, upperLimit

blue = [255, 0, 0] # BGR
yellow = [0, 255, 255] # BGR
cap = cv2.VideoCapture(0)

last_run_time = time.time()
while True:
    current_time = time.time()
    ret, frame = cap.read()

    hsvImage = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    lowerLimitBlue, upperLimitBlue = get_limits(color=blue)
    lowerLimitYellow, upperLimitYellow = get_limits(color=yellow)

    maskBlue = cv2.inRange(hsvImage, lowerLimitBlue, upperLimitBlue)
    maskYellow = cv2.inRange(hsvImage, lowerLimitYellow, upperLimitYellow)

    contoursBlue, _ = cv2.findContours(maskBlue, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    contoursYellow, _ = cv2.findContours(maskYellow, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    ### Draw bounding boxes ###
    black_screen = np.zeros_like(frame)

    bounding_box_count_blue = 0
    bounding_box_count_yellow = 0

    for contour in contoursBlue:
        bbox = cv2.boundingRect(contour)
        x, y, w, h = bbox

        # Filter out slightly smaller contours
        if 25 < w < 500 and 25 < h < 500:
            frame = cv2.rectangle(frame, (x, y), (x+w, y+h), (255, 0, 0), 5)  # Linea azul
            black_screen = cv2.rectangle(black_screen, (x, y), (x+w, y+h), (255, 0, 0), 5)  # Linea azul 
            bounding_box_count_blue += 1

    for contour in contoursYellow:
        bbox = cv2.boundingRect(contour)
        x, y, w, h = bbox

        # Filtrar objetos pequeños
        if 25 < w < 500 and 25 < h < 500:
            frame = cv2.rectangle(frame, (x, y), (x+w, y+h), (0, 255, 255), 5) # Linea amarilla
            black_screen = cv2.rectangle(black_screen, (x, y), (x+w, y+h), (0, 255, 255), 5)  # Linea amarilla
            bounding_box_count_yellow += 1

    # Contador de objetos
    cv2.putText(black_screen, f"Objetos Azules: {bounding_box_count_blue}", (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 255, 255), 2)
    cv2.putText(black_screen, f"Objetos Amarillos: {bounding_box_count_yellow}", (10, 70), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 255, 255), 2)

    if current_time - last_run_time >= TIME_BETWEEN_RUNS:
        last_run_time = current_time

        if bounding_box_count_blue < LOW_STOCK_THRESHOLD_BLUE:
            message = "Low stock for blue objects!"
            send_sms(message)

        if bounding_box_count_yellow < LOW_STOCK_THRESHOLD_YELLOW:
            message = "Low stock for yellow objects!"
            send_sms(message)

    cv2.imshow('video', frame)
    cv2.imshow('objetos', black_screen)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()

cv2.destroyAllWindows()