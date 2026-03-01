#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    cv::Mat src = cv::imread("../Data/ave2.png", cv::IMREAD_GRAYSCALE);
    if (src.empty()) {
        std::cerr << "No se pudo cargar la imagen" << std::endl;
        return -1;
    }

    // Paso 1: Umbralización para obtener binario limpio
    cv::Mat thresh;
    cv::threshold(src, thresh, 127, 255, cv::THRESH_BINARY);

    // Paso 2: Encontrar todos los contornos externos
    std::vector<std::vector<cv::Point>> contornos;
    cv::findContours(thresh, contornos, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    // Paso 3: Encontrar el contorno MÁS GRANDE (el pájaro), ignorar fragmentos pequeños
    int idxMayor = 0;
    double areaMax = 0;
    for (int i = 0; i < (int)contornos.size(); i++) {
        double area = cv::contourArea(contornos[i]);
        if (area > areaMax) {
            areaMax = area;
            idxMayor = i;
        }
    }

    // Paso 4: Dibujar SOLO el contorno más grande relleno de blanco
    cv::Mat dst = cv::Mat::zeros(src.size(), CV_8UC1);
    cv::drawContours(dst, contornos, idxMayor, cv::Scalar(255), cv::FILLED);

    cv::imshow("Entrada", src);
    cv::imshow("Salida - Relleno completo", dst);
    cv::imwrite("salida3.png", dst);

    cv::waitKey(0);
    return 0;
}
