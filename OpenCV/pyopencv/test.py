import cv2 as cv
import numpy as np

filename = "OpenCV\cvtest\images\gate.jpg"
image = cv.imread(filename)

# Convertir a escala de grises
grayImage = cv.cvtColor(image, cv.COLOR_BGR2GRAY)

# Crear archivo
cv.imwrite("gate_gris.jpg", grayImage)

# Mostrar
cv.imshow("Image", image)
cv.imshow("Grayscale Image", grayImage)
cv.waitKey(0)
