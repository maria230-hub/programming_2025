#include <iostream>
#include <cmath>

int main() {
    setlocale(LC_ALL, "Russian");
    int spaceofint = sizeof(int) * 8;
    int sizeoffloat = sizeof(float) * 8;
    std::cout << "int, ��������" << spaceofint << "���(�), ���. �������� = " << INT_MIN << ", ����. �������� = " << INT_MAX << std::endl;
    std::cout << "float, ��������" << sizeoffloat << "���(�), ����. �������� = " << std::numeric_limits<float>::max() << ", ���. �������� = " << std::numeric_limits<float>::min() << std::endl;
    unsigned int a, b; // ��� ��� ������ ����-�� ������������ �����&������������� ����� => ��� ������ unsigned int
    std::cout << "����� ����� b" << std::endl;
    std::cin >> b;
    std::cout << "����� ����� a" << std::endl;
    std::cin >> a;
    float c = sqrt(a * a + b * b); //��.������ ����� ���� ������� ������ :( => ��� ������ float
    int f = c + a + b;
    std::cout << "�������� � = " << c << std::endl;
    std::cout << "�������� ��������� = " << f << std::endl;
}