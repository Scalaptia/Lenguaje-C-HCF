import cv2
import numpy as np

from util import get_limits


blue = [255, 0, 0] # BGR
yellow = [0, 255, 255] # BGR
cap = cv2.VideoCapture(0)
while True:
    ret, frame = cap.read()

    hsvImage = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    lowerLimitBlue, upperLimitBlue = get_limits(color=blue)
    lowerLimitYellow, upperLimitYellow = get_limits(color=yellow)

    maskBlue = cv2.inRange(hsvImage, lowerLimitBlue, upperLimitBlue)
    maskYellow = cv2.inRange(hsvImage, lowerLimitYellow, upperLimitYellow)

    contoursBlue, _ = cv2.findContours(maskBlue, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    contoursYellow, _ = cv2.findContours(maskYellow, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    # Create a black image of the same size as the frame
    black_screen = np.zeros_like(frame)

    bounding_box_count_blue = 0  # Initialize bounding box count for blue objects
    bounding_box_count_yellow = 0  # Initialize bounding box count for yellow objects

    for contour in contoursBlue:
        bbox = cv2.boundingRect(contour)
        x, y, w, h = bbox

        # Filter out slightly smaller contours
        if 25 < w < 500 and 25 < h < 500:
            frame = cv2.rectangle(frame, (x, y), (x+w, y+h), (255, 0, 0), 5)  # Change line color to blue
            # Draw the rectangles on the black screen
            black_screen = cv2.rectangle(black_screen, (x, y), (x+w, y+h), (255, 0, 0), 5)  # Change line color to blue

            bounding_box_count_blue += 1  # Increment bounding box count for blue objects

    for contour in contoursYellow:
        bbox = cv2.boundingRect(contour)
        x, y, w, h = bbox

        # Filter out slightly smaller contours
        if 25 < w < 500 and 25 < h < 500:
            frame = cv2.rectangle(frame, (x, y), (x+w, y+h), (0, 255, 255), 5)  # Change line color to yellow
            # Draw the rectangles on the black screen
            black_screen = cv2.rectangle(black_screen, (x, y), (x+w, y+h), (0, 255, 255), 5)  # Change line color to yellow

            bounding_box_count_yellow += 1  # Increment bounding box count for yellow objects

    # Display bounding box count for blue objects on the frame
    cv2.putText(black_screen, f"Objetos Azules: {bounding_box_count_blue}", (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 255, 255), 2)

    # Display bounding box count for yellow objects on the frame
    cv2.putText(black_screen, f"Objetos Amarillos: {bounding_box_count_yellow}", (10, 70), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 255, 255), 2)

    cv2.imshow('frame', frame)
    cv2.imshow('bounding lines', black_screen)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()

cv2.destroyAllWindows()