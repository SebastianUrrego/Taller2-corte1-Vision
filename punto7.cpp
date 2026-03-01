#include <opencv2/opencv.hpp>
#include <iostream>

// h_center: hue central en escala OpenCV (0-179)
// r: rango en escala OpenCV
cv::Mat resaltarColor(const cv::Mat& src, double h_center, double r) {
    // Convertir BGR -> HSV
    cv::Mat hsv;
    cv::cvtColor(src, hsv, cv::COLOR_BGR2HSV);

    // Aplicar ecuación del enunciado en escala OpenCV (0-179)
    // h1 = (h - r/2 + 180) mod 180
    // h2 = (h + r/2 + 180) mod 180
    double h1 = fmod((h_center - r / 2.0 + 180.0), 180.0);
    double h2 = fmod((h_center + r / 2.0 + 180.0), 180.0);

    // Crear máscara según rango de hue
    cv::Mat mask;
    if (h1 <= h2) {
        // Rango normal, no cruza el 0
        cv::inRange(hsv, cv::Scalar(h1, 50, 50), cv::Scalar(h2, 255, 255), mask);
    } else {
        // Rango que cruza el 0 (ej: rojos)
        cv::Mat mask1, mask2;
        cv::inRange(hsv, cv::Scalar(h1, 50, 50), cv::Scalar(179, 255, 255), mask1);
        cv::inRange(hsv, cv::Scalar(0,  50, 50), cv::Scalar(h2, 255, 255),  mask2);
        cv::bitwise_or(mask1, mask2, mask);
    }

    // Convertir original a gris en 3 canales
    cv::Mat gray, gray3;
    cv::cvtColor(src, gray, cv::COLOR_BGR2GRAY);
    cv::cvtColor(gray, gray3, cv::COLOR_GRAY2BGR);

    // Combinar: color donde hay máscara, gris donde no
    cv::Mat resultado = gray3.clone();
    src.copyTo(resultado, mask);

    return resultado;
}

int main() {
    cv::Mat src = cv::imread("../Data/mes.jpg");
    if (src.empty()) {
        std::cerr << "No se pudo cargar la imagen" << std::endl;
        return -1;
    }

    double r = 20.0; // rango de hue en escala OpenCV (0-179)

    // Valores de hue en escala OpenCV (0-179):
    // Rojo   ~  0 (o 170-179)
    // Verde  ~ 60
    // Azul   ~ 110

    // Imagen 1: Resaltar verde (césped): hue ~60 en OpenCV
    cv::Mat salidaVerde = resaltarColor(src, 60.0, 40.0);

    // Imagen 2: Resaltar azul del uniforme: hue ~110 en OpenCV
    cv::Mat salidaAzul = resaltarColor(src, 110.0, 20.0);

    // Imagen 3: Resaltar rojo del uniforme: hue ~0 (o 170) en OpenCV
    cv::Mat salidaRojo = resaltarColor(src, 170.0, 20.0);

    // Mostrar
    cv::imshow("Entrada", src);
    cv::imshow("1 - Resaltar Verde (cesped)", salidaVerde);
    cv::imshow("2 - Resaltar Azul (uniforme)", salidaAzul);
    cv::imshow("3 - Resaltar Rojo (uniforme)", salidaRojo);

    // Guardar
    cv::imwrite("salida7_verde.png", salidaVerde);
    cv::imwrite("salida7_azul.png", salidaAzul);
    cv::imwrite("salida7_rojo.png", salidaRojo);

    cv::waitKey(0);
    return 0;
}
