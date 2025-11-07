#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	const int PMax = 4;
	int x[PMax];
	int mini[PMax];
	cout << "Введите элементы массива = " << " ";
	for (int g = 0; g < PMax; ++g) {
		cin >> x[g];
		int temp = abs(x[g]);
		mini[g] = 9;
		if (temp == 0) {
			mini[g] = 0;
		}
		else {
			while (temp > 0) {
				int num = temp % 10;
				if (num < mini[g]) {
					mini[g] = num;
				}
				temp /= 10;
			}
		}
	}
	bool checkx = false;
	bool checkx = false;
	if (mini[0] == mini[PMax - 1]) {
		checkx = true;
	}
	if (checkx) {
		for (int i = 0; i < PMax - 1; ++i) {
			for (int j = 0; j < PMax - i - 1; ++j) {
				if (x[j] > x[j + 1]) {
					swap(x[j], x[j + 1]);
				}
			}
		}
		cout << "массив = " << " ";
	}
	else {
		cout << "Массив осталося неизменным: " << " ";
	}
	for (int g = 0; g < PMax; ++g) {
		cout << x[g] << " ";
	}
	cout << endl;
    const int NMax = 3;
    const int MMax= 4;
    int matrix[NMax][MMax];

    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < NMax; ++i) {
        cout << "Строка " << i << " = ";
        for (int j = 0; j < MMax; ++j) {
            cin >> matrix[i][j];
        }
    }
    int minD = INT_MAX;
    int t = 0;

    cout << "Суммы строк:" << endl;
    for (int i = 0; i < NMax; ++i) {
        int Sum = 0;
        for (int j = 0; j < MMax; ++j) {
            Sum += matrix[i][j];
        }

		int df;
		if (Sum == INT_MIN) {
			df = INT_MAX;
		}
		else {
			df = abs(Sum);
		}
        cout << "Строка " << i + 1<< ": сумма = " << Sum << endl;

        if (df < minD) {
            minD = df;
            t = i; 
        }
    }

    cout << "Строка " << t + 1 << " имеет сумму, значение которой наиболее приближенное к нулю" << endl;
    for (int j = 0; j < MMax; j++) {
        matrix[t][j] = 0;
    }
    cout << "Новая матрица:" << endl;
    for (int i = 0; i < NMax; ++i) {
        for (int j = 0; j < MMax; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}