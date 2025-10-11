#include <iostream>
#include <bitset>

/*Для пункта 1 число А (short) вводиться с клавиатуры, номер бита i тоже.
Проверить правильность ввода i и определить по заданию. Все числа выводить в виде “5 = 00000101”.
(будем рассматривать только первые 8 бит).
Для первого сравнения в пункте 1, вытащить значение i бита в отдельную переменную.*/

int main()
{
	setlocale(LC_ALL, "Russian");
	short a;
	int i;
	std::cout << "Введите число a:" << std::endl;
	std::cin >> a;
	std::cout << "Введите номер бита i:" << std::endl;
	std::cin >> i;
	int bitsize = (1 & (a >> i));
	if (i > (sizeof(int) * 8 - 1)) {
		std::cout << "такого бита не существует" << std::endl;
	}
	else {
		std::cout << "значение бита i = " << bitsize << std::endl;
	}
	if (bitsize == 1) {
		int x, y;
		std::cout << "Введите несколько целых чисел" << std::endl;
		std::cin >> x >> y;
		if (x > y) {
			std::cout << "максимальное число = " << x << std::endl;
		}
		else {
			std::cout << "максимальное число = " << y << std::endl;
		}
		std::bitset <8> x1 = a;
		std::bitset <8> x2 = (a & ~(1 << i));
		std::cout << "число a до установления бита i в 0 = " << std::endl;
		std::cout << x1.to_string() << std::endl;
		std::cout << "число a после установления бита i в 0 = " << std::endl;
		std::cout << x2.to_string() << std::endl;
	}
	else {
		std::bitset <8> x3 = a;
		std::bitset <8> x4 = (~a);
		std::cout << "число a = " << x3.to_string() << std::endl;
		std::cout << "инвертированное число a = " << x4.to_string() << std::endl;
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
