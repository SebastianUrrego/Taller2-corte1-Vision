#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    cv::Mat src = cv::imread("../Data/imagenBGR.png");
    if (src.empty()) {
        std::cerr << "No se pudo cargar la imagen" << std::endl;
        return -1;
    }

    // Separar los canales BGR de OpenCV
    // OpenCV usa BGR (Blue, Green, Red), no RGB
    std::vector<cv::Mat> canales;
    cv::split(src, canales);

    // canales[0] = Blue (B)
    // canales[1] = Green (G)
    // canales[2] = Red (R)

    // Crear imágenes a color para cada canal
    // Canal R: solo tiene el componente rojo activado
    cv::Mat imgR = cv::Mat::zeros(src.size(), src.type());
    cv::Mat imgG = cv::Mat::zeros(src.size(), src.type());
    cv::Mat imgB = cv::Mat::zeros(src.size(), src.type());

    // Para el canal R: mezclar solo el canal rojo (índice 2 en BGR)
    std::vector<cv::Mat> canalesR = {
        cv::Mat::zeros(src.size(), CV_8UC1),  // B = 0
        cv::Mat::zeros(src.size(), CV_8UC1),  // G = 0
        canales[2]                             // R = canal rojo
    };
    cv::merge(canalesR, imgR);

    // Para el canal G: solo el canal verde (índice 1)
    std::vector<cv::Mat> canalesG = {
        cv::Mat::zeros(src.size(), CV_8UC1),  // B = 0
        canales[1],                            // G = canal verde
        cv::Mat::zeros(src.size(), CV_8UC1)   // R = 0
    };
    cv::merge(canalesG, imgG);

    // Para el canal B: solo el canal azul (índice 0)
    std::vector<cv::Mat> canalesB = {
        canales[0],                            // B = canal azul
        cv::Mat::zeros(src.size(), CV_8UC1),  // G = 0
        cv::Mat::zeros(src.size(), CV_8UC1)   // R = 0
    };
    cv::merge(canalesB, imgB);

    // Mostrar resultados
    cv::imshow("Entrada", src);
    cv::imshow("Canal R (Rojo)", imgR);
    cv::imshow("Canal G (Verde)", imgG);
    cv::imshow("Canal B (Azul)", imgB);

    // Guardar imágenes
    cv::imwrite("salida5_R.png", imgR);
    cv::imwrite("salida5_G.png", imgG);
    cv::imwrite("salida5_B.png", imgB);

    cv::waitKey(0);
    return 0;
}

