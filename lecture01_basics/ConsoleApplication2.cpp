#include <iostream>
#include <cmath>

int main() {
    setlocale(LC_ALL, "Russian");
    int spaceofint = sizeof(int) * 8;
    int sizeoffloat = sizeof(float) * 8;
    std::cout << "int, занимает" << spaceofint << "бит(а), мин. значение = " << std::numeric_limits<int>::min() << ", макс. значение = " << std::numeric_limits<int>::max() << std::endl;
    std::cout << "float, занимает" << sizeoffloat << "бит(а), макс. значение = " << std::numeric_limits<float>::max() << ", мин. значение = " << std::numeric_limits<float>::min() << std::endl;
    unsigned int a, b; // так как катеты прям-го треугольника целые&положительные числа => тип данных unsigned int
    std::cout << "введи число b" << std::endl;
    std::cin >> b;
    std::cout << "введи число a" << std::endl;
    std::cin >> a;
    float c = sqrt(a * a + b * b); //кв.корень может быть нецелым числом :( => тип данных float
    int f = c + a + b;
    std::cout << "значение с = " << c << std::endl;
    std::cout << "значение периметра = " << f << std::endl;
}