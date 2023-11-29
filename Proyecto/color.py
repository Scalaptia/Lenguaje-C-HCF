# librerias
import numpy as np 
import imutils
import cv2 

cap=cv2.VideoCapture(0)
cap.set(3,640)
cap.set(4,480)

# Contadores de objetos
count_amarillo = 0
count_rojo = 0
count_verde = 0
count_azul = 0

while True:
    ret,frame= cap.read()
    hsv=cv2.cvtColor(frame,cv2.COLOR_BGR2HSV)
    
    # -- amarillo --
    amrillo_oscuro=np.array([25,70,120])
    amrillo_claro=np.array([30,255,255])

    # -- rojo --
    rojo_osc= np.array([0,50,120])
    rojo_claro= np.array([10,255,255])

     # -- verde --
    verde_osc= np.array([40,70,80])
    verde_claro= np.array([70,255,255])

     # -- azul --
    azul_osc= np.array([90,60,0])
    azul_claro= np.array([121,255,255])

    # filtrar colores
    cara1= cv2.inRange(hsv,amrillo_oscuro,amrillo_claro)
    cara2= cv2.inRange(hsv,rojo_osc,rojo_claro)
    cara3= cv2.inRange(hsv,verde_osc,verde_claro)
    cara4= cv2.inRange(hsv,azul_osc,azul_claro)

    # definir contorno de objeto

    contorno1= cv2.findContours(cara1,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)
    contorno1= imutils.grab_contours(contorno1)

    contorno2= cv2.findContours(cara2,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)
    contorno2= imutils.grab_contours(contorno2)

    contorno3= cv2.findContours(cara3,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)
    contorno3= imutils.grab_contours(contorno3)

    contorno4= cv2.findContours(cara4,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)
    contorno4= imutils.grab_contours(contorno4)

    # area de objetos
    for c in contorno1:
        area1= cv2.contourArea(c)
        count_amarillo = len([c for c in contorno1 if cv2.contourArea(c) > 5000])
        if area1>5000:
            cv2.drawContours(frame,[c],-1,(30,255,255),3)
            m= cv2.moments(c)
            cx=int(m['m10']/m['m00'])
            cy=int(m['m01']/m['m00'])
            cv2.circle(frame,(cx,cy),7,(255,255,255),-1)
            cv2.putText(frame,'Amarillo',(cx-20,cy-20),cv2.FONT_ITALIC,2,(255,255,255),2)
    
    for c in contorno2:
        area2= cv2.contourArea(c)
        count_rojo = len([c for c in contorno2 if cv2.contourArea(c) > 5000])
        if area2>5000:
            cv2.drawContours(frame,[c],-1,(0,0,255),3)
            m= cv2.moments(c)
            cx=int(m['m10']/m['m00'])
            cy=int(m['m01']/m['m00'])
            cv2.circle(frame,(cx,cy),7,(255,255,255),-1)
            cv2.putText(frame,'Rojo',(cx-20,cy-20),cv2.FONT_ITALIC,2,(255,255,255),2)   

    for c in contorno3:
        area3= cv2.contourArea(c)
        count_verde = len([c for c in contorno3 if cv2.contourArea(c) > 5000])
        if area3>5000:
            cv2.drawContours(frame,[c],-1,(0,255,0),3)
            m= cv2.moments(c)
            cx=int(m['m10']/m['m00'])
            cy=int(m['m01']/m['m00'])
            cv2.circle(frame,(cx,cy),7,(255,255,255),-1)
            cv2.putText(frame,'Verde',(cx-20,cy-20),cv2.FONT_ITALIC,2,(255,255,255),2) 

    for c in contorno4:
        area4= cv2.contourArea(c)
        count_azul = len([c for c in contorno4 if cv2.contourArea(c) > 5000])
        if area4>5000:
            cv2.drawContours(frame,[c],-1,(255,0,0),3)
            m= cv2.moments(c)
            cx=int(m['m10']/m['m00'])
            cy=int(m['m01']/m['m00'])
            cv2.circle(frame,(cx,cy),7,(255,255,255),-1)
            cv2.putText(frame,'Azul',(cx-20,cy-20),cv2.FONT_ITALIC,2,(255,255,255),2)  

    # Mostrar el recuento en la ventana
    cv2.putText(frame, f'Amarillo: {count_amarillo}', (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 255, 255), 2)
    cv2.putText(frame, f'Rojo: {count_rojo}', (10, 70), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 255, 255), 2)
    cv2.putText(frame, f'Verde: {count_verde}', (10, 110), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 255, 255), 2)
    cv2.putText(frame, f'Azul: {count_azul}', (10, 150), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 255, 255), 2)

    cv2.imshow('VIDEO',frame)
    k = cv2.waitKey(1)
    if k == 27:
        break
cap.release()
cv2.destroyAllWindows()