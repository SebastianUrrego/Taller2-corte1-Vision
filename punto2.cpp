#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    cv::Mat src = cv::imread("../Data/tutor.png");
    if (src.empty()) {
        std::cerr << "No se pudo cargar la imagen" << std::endl;
        return -1;
    }

    // Paso 1: Convertir a escala de grises
    cv::Mat gray;
    cv::cvtColor(src, gray, cv::COLOR_BGR2GRAY);

    // Paso 2: Umbralización para obtener el texto blanco limpio
    cv::Mat thresh;
    cv::threshold(gray, thresh, 200, 255, cv::THRESH_BINARY);

    // Paso 3: Erosión para adelgazar el texto blanco
    int kernelSize = 3; // Ajustar según el adelgazamiento deseado
    cv::Mat kernel = cv::getStructuringElement(
        cv::MORPH_ELLIPSE,
        cv::Size(kernelSize, kernelSize)
    );
    cv::Mat dst;
    cv::erode(thresh, dst, kernel, cv::Point(-1,-1), 1); // 2 iteraciones

    cv::imshow("Entrada", src);
    cv::imshow("Salida - Texto adelgazado", dst);
    cv::imwrite("../Data/salida2.png", dst);

    cv::waitKey(0);
    return 0;
}
