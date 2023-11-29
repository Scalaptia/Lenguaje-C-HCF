import numpy as np 
import imutils
import cv2 

cap = cv2.VideoCapture(0)
cap.set(3, 640)
cap.set(4, 480)

# Rangos de colores
colores = {
    'amarillo': ([25, 70, 120], [30, 255, 255]),
    'rojo': ([0, 50, 120], [10, 255, 255]),
    'verde': ([40, 70, 80], [70, 255, 255]),
    'azul': ([90, 60, 0], [121, 255, 255])
}

while True:
    ret, frame = cap.read()
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    # Contadores de objetos
    contadores = {
        'amarillo': 0,
        'rojo': 0,
        'verde': 0,
        'azul': 0
    }

    for color, (lower, upper) in colores.items():
        mask = cv2.inRange(hsv, np.array(lower), np.array(upper))
        contornos = cv2.findContours(mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
        contornos = imutils.grab_contours(contornos)

        for c in contornos:
            area = cv2.contourArea(c)
            if area > 5000:
                cv2.drawContours(frame, [c], -1, colores[color][0], 3)
                m = cv2.moments(c)
                cx = int(m['m10'] / m['m00'])
                cy = int(m['m01'] / m['m00'])
                cv2.circle(frame, (cx, cy), 7, (255, 255, 255), -1)

                contadores[color] += 1

                # Crear ventana para mostrar solo las caras del color detectado
                mask_color = cv2.bitwise_and(frame, frame, mask=mask)
                cv2.imshow(f'{color.capitalize()} Faces', mask_color)

    # Mostrar el recuento en la ventana
    y = 30
    for color, count in contadores.items():
        cv2.putText(frame, f'{color.capitalize()}: {count}', (10, y), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 255, 255), 2)
        y += 40

    cv2.imshow('VIDEO', frame)
    k = cv2.waitKey(1)
    if k == 27:
        break

cap.release()
cv2.destroyAllWindows()# Crear ventanas para mostrar solo las caras de cada color detectado
for color in colores.keys():
    cv2.namedWindow(f'{color.capitalize()} Faces', cv2.WINDOW_NORMAL)
    cv2.resizeWindow(f'{color.capitalize()} Faces', 640, 480)
