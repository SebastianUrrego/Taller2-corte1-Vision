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

    // Paso 2: Umbralización para obtener solo el texto blanco limpio
    // Elimina sombras y grises intermedios -> deja solo lo muy brillante
    cv::Mat thresh;
    cv::threshold(gray, thresh, 200, 255, cv::THRESH_BINARY);

    // Paso 3: Dilatación para engrosar el texto blanco
    int kernelSize = 3; // Ajustar según el grosor deseado (3, 5, 7...)
    cv::Mat kernel = cv::getStructuringElement(
        cv::MORPH_ELLIPSE,
        cv::Size(kernelSize, kernelSize)
    );
    cv::Mat dst;
    cv::dilate(thresh, dst, kernel, cv::Point(-1,-1), 3); // 2 iteraciones

    // Mostrar
    cv::imshow("Entrada", src);
    cv::imshow("Salida - Texto engrosado", dst);
    cv::imwrite("../Data/salida1.png", dst);

    cv::waitKey(0);
    return 0;
}
