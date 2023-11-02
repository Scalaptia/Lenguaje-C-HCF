import cv2
import numpy as np

# Initialize the camera capture
cap = cv2.VideoCapture(
    0
)  # Use the default camera (change the index if you have multiple cameras)

# Create a window for displaying the resized image
cv2.namedWindow("Resized Camera Input", cv2.WND_PROP_FULLSCREEN)
cv2.setWindowProperty(
    "Resized Camera Input", cv2.WND_PROP_FULLSCREEN, cv2.WINDOW_FULLSCREEN
)

while True:
    ret, frame = cap.read()  # Capture a frame from the camera

    # Check if the frame was captured successfully
    if not ret:
        break

    # Resize the frame to 16x16 pixels while maintaining the aspect ratio
    frame = cv2.resize(frame, (16, 16))

    # Create a larger frame that fills the screen
    screen_width = 1920  # Change this to your screen's width
    screen_height = 1080  # Change this to your screen's height
    larger_frame = np.zeros((screen_height, screen_width, 3), dtype=np.uint8)

    # Calculate the position to center the 16x16 frame within the larger frame
    x_offset = (screen_width - 16) // 2
    y_offset = (screen_height - 16) // 2

    # Copy the 16x16 frame into the larger frame at the calculated position
    larger_frame[y_offset : y_offset + 16, x_offset : x_offset + 16] = frame

    # Display the larger frame
    cv2.imshow("Resized Camera Input", larger_frame)

    # Break the loop if the 'q' key is pressed
    if cv2.waitKey(1) & 0xFF == ord("q"):
        break

# Release the camera and close the display window
cap.release()
cv2.destroyAllWindows()
