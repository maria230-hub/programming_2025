#include <iostream>
#include <cmath>

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	std::cout << "введите n = " << " ";
	std::cin >> n;
	int sum = 0;
	int maxi = INT_MIN;
	int max = 0;
	int k = 0;
	bool rightindex = false;
	std::cout << "введите числа = " << " ";
	for (int i = 1; i <= n; ++i) {
		int number;
		std::cin >> number;
		if (number % 2 != 0) {
			continue;
		}
		sum += number;
		k += 1;
		if (!rightindex) {
			maxi = number;
			max = i;
			rightindex = true;
		} else if (number > maxi) {
			maxi = number;
			max = i;
		}
	}
	if (rightindex) {
		std::cout << max << " (номер последовательности)" << ":" << " ";
		std::cout << maxi << " (наибольшее число последовательности)" << std::endl;;
		std::cout << "сумма = " << sum << ";" << " ";
		std::cout << "наибольшее значение числа = " << maxi << std::endl;
	}
	else {
		std::cout << "такой последовательности не существует" << std::endl;
	}
	int d;
	std::cout << "введите число d, меньшее 1000 = " << " ";
	std::cin >> d;

	if (abs(d) >= 1000) {
		std::cout << "не соответствует условию задачи" << std::endl;
	}
	int d1 = abs(d);
	int mini = INT_MAX;

	while (d1 > 0) {
		int number = d1 % 10;
		d1 /= 10;
		if (number != 7 && number != 0) {
			if (number < mini) {
				mini = number;
			}
		}
	}
	if (mini == INT_MAX) {
		std::cout << "нет цифр, отличных от 0 и 7" << std::endl;
	}
	else {
		std::cout << "наименьшая цифра числа " << d << " = " << mini << std::endl;
	}
	return 0;
}