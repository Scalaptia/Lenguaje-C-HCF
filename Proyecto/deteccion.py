import cv2
import numpy as np

from util import get_limits


blue = [255, 0, 0] # BGR
cap = cv2.VideoCapture(0)
while True:
    ret, frame = cap.read()

    hsvImage = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    lowerLimit, upperLimit = get_limits(color=blue)

    mask = cv2.inRange(hsvImage, lowerLimit, upperLimit)

    contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    # Create a black image of the same size as the frame
    black_screen = np.zeros_like(frame)

    for contour in contours:
        bbox = cv2.boundingRect(contour)
        x, y, w, h = bbox

        # Filter out slightly smaller contours
        if 25 < w < 500 and 25 < h < 500:
            frame = cv2.rectangle(frame, (x, y), (x+w, y+h), (255, 0, 0), 5)  # Change line color to blue
            # Draw the rectangles on the black screen
            black_screen = cv2.rectangle(black_screen, (x, y), (x+w, y+h), (255, 0, 0), 5)  # Change line color to blue

    cv2.imshow('frame', frame)
    cv2.imshow('bounding lines', black_screen)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()

cv2.destroyAllWindows()