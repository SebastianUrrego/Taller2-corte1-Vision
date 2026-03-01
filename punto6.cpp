#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    cv::Mat src = cv::imread("../Data/lenanoise.png");
    if (src.empty()) {
        std::cerr << "No se pudo cargar la imagen" << std::endl;
        return -1;
    }

    cv::Mat dst;

    // Filtro de Mediana: ideal para ruido sal y pimienta (puntos blancos/negros dispersos)
    // Reemplaza cada pixel por la MEDIANA de sus vecinos -> elimina outliers sin borrosar
    // El valor debe ser impar (3, 5, 7...), aumentar si queda ruido residual
    cv::medianBlur(src, dst, 5);

    cv::imshow("Entrada con ruido", src);
    cv::imshow("Salida - Filtro Gaussiano", dst);
    cv::imwrite("salida6.png", dst);

    cv::waitKey(0);
    return 0;
}


