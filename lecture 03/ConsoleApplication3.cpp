#include <iostream>
#include <bitset>

int main()
{
	setlocale(LC_ALL, "Russian");
	short a;
	int i;
	std::cout << "Введите число a:" << std::endl;
	std::cin >> a;
	std::cout << "Введите номер бита i:" << std::endl;
	std::cin >> i;
	if (i == 1) {
		int x, y;
		std::cout << "Введите несколько целых чисел" << std::endl;
		std::cin >> x >> y;
		if (x > y) {
			std::cout << "максимальное число = " << x << std::endl;
		} else {
			std::cout << "максимальное число = " << y << std::endl;
		}
		std::bitset <8> x1 = a;
		std::cout << "число a до установления бита i в 0 = " << std::endl;
		std::cout << x1.to_string() << std::endl;
		std::cout << "число a после установления бита i в 0 = " <<std::endl;
		std::cout << (a & ~(1 << i)) << std::endl;
	}
	else {
		std::cout << "инвертированное число a = " << ~a << std::endl;
	}
	int NumberOfMonth;
	std::cout << "Введите номер месяца = " << std::endl;
	std::cin >> NumberOfMonth;
	switch (NumberOfMonth) {
	case 1: std::cout << "Январь"; break;
	case 2: std::cout << "Февраль"; break;
	case 3: std::cout << "Март"; break;
	case 4: std::cout << "Апрель"; break;
	case 5: std::cout << "Май"; break;
	case 6: std::cout << "Июнь"; break;
	case 7: std::cout << "Июль"; break;
	case 8: std::cout << "Август"; break;
	case 9: std::cout << "Сентябрь"; break;
	case 10: std::cout << "Октябрь"; break;
	case 11: std::cout << "Ноябрь"; break;
	case 12: std::cout << "Декабрь"; break;
	default: std::cout << "такого месяца не существует :(";
	}
	return 0;
}
