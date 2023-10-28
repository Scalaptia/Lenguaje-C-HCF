#include <stdio.h>
#include <opencv2/opencv.hpp>

int main(int, char **)
{
    // Leer
    auto filename = "C:\\Users\\ferna\\OneDrive\\Documentos\\GitHub\\Lenguaje-C-HCF\\cvtest\\images\\gate.jpg";
    auto image = cv::imread(filename);

    // Convertir a escala de grises
    cv::Mat grayImage;
    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);

    // Crear archivo
    cv::imwrite("gate_gris.jpg", grayImage);

    // Mostrar
    cv::imshow("Image", image);
    cv::imshow("Grayscale Image", grayImage);
    cv::waitKey(0);

    return 0;
}
