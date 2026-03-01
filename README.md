# Taller Electiva - Visión por Computador
Ejercicios de procesamiento de imágenes en C++ usando OpenCV, desarrollados en Qt Creator.

---

## 🛠️ Requisitos
- Qt Creator
- OpenCV 4.x
- C++17

---

## 📁 Estructura
```
├── ejercicio1.cpp   # Dilatación morfológica
├── ejercicio2.cpp   # Erosión morfológica
├── ejercicio3.cpp   # Relleno de huecos (FloodFill + Bitwise)
├── ejercicio4.cpp   # Eliminación de ruido (FindContours)
├── ejercicio5.cpp   # Separación de canales RGB
├── ejercicio6.cpp   # Eliminación de ruido (MedianBlur)
├── ejercicio7.cpp   # Resaltar color en HSV
└── TallerVision.pro # Proyecto Qt Creator
```

---

## 📌 Descripción de ejercicios

### Ejercicio 1 - Dilatación
Engrosa el texto blanco sobre fondo negro.  
**Operación:** `threshold` + `dilate`

### Ejercicio 2 - Erosión
Adelgaza el texto blanco sobre fondo negro.  
**Operación:** `threshold` + `erode`

### Ejercicio 3 - Relleno de huecos
Rellena los huecos negros dentro del pájaro blanco.  
**Operación:** `bitwise_not` + `floodFill` + `bitwise_or`

### Ejercicio 4 - Eliminar ruido externo
Elimina fragmentos blancos pequeños fuera del pájaro.  
**Operación:** `findContours` + `drawContours(FILLED)` con el contorno de mayor área

### Ejercicio 5 - Separación de canales
Genera 3 imágenes independientes, una por cada canal R, G y B.  
**Operación:** `split` + `merge`

### Ejercicio 6 - Eliminar ruido sal y pimienta
Suaviza la imagen Lena eliminando el ruido sin perder nitidez.  
**Operación:** `medianBlur`

### Ejercicio 7 - Resaltar color en HSV
Resalta un color específico dejando el resto en escala de grises.  
**Operación:** `cvtColor(BGR→HSV)` + `inRange` + `bitwise_or`  
**Ecuación:**
```
h1 = (h - r/2 + 180) mod 180
h2 = (h + r/2 + 180) mod 180
```
