#include <iostream>
#include <cmath>
/*
очень
большой
комментарий
:3
*/
int main() {
    setlocale(LC_ALL, "Russian");
    int spaceofint = sizeof(unsigned int) * 8; //размер в битах
    int sizeoffloat = sizeof(float) * 8;
    std::cout << "int, занимает" << spaceofint << "бит(а), мин. значение = " << std::numeric_limits<unsigned int>::lowest() << ", макс. значение = " << std::numeric_limits<unsigned int>::max() << std::endl;
    std::cout << "float, занимает" << sizeoffloat << "бит(а), макс. значение = " << std::numeric_limits<float>::max() << ", мин. значение = " << std::numeric_limits<float>::lowest() << std::endl;
    unsigned int a, b; // так как катеты прям-го треугольника целые&положительные числа => тип данных unsigned int
    std::cout << "введи число b" << std::endl;
    std::cin >> b;
    std::cout << "введи число a" << std::endl;
    std::cin >> a;
    float c = sqrt(a * a + b * b); //кв.корень может быть нецелым числом :( => тип данных float
    float f = c + a + b;
    std::cout << "значение с = " << c << std::endl;
    std::cout << "значение периметра = " << f << std::endl;
}