#include <iostream>
#include <cmath>
using namespace std;

int sumofdigits(int a, int b) {
    cout << "исп. функция суммы 2-х чисел: " << endl;
    return a + 2 * b + 3;
}

int sumofdigits(int a, int b, int c) {
    cout << "исп. функция суммы 3-х чисел: " << endl;
    int firstsum = a + b;
    int secondsum = a + c;
    int thirdsum = b + c;

    int maxofsum = firstsum;
    if (secondsum > maxofsum) {
        maxofsum = secondsum;
    }
    if (thirdsum > maxofsum) {
        maxofsum = thirdsum;
    }
    return maxofsum;
}


void digitinput1() {
    cout << "исп. функция пункта 1 " << endl;
    int x, y, z;
    cout << "Введите числа: ";
    cin >> x >> y >> z;
    int result;
    if (x == 0) {
        result = sumofdigits(y, z);
    }
    else if (y == 0) {
        result = sumofdigits(x, z);
    }
    else if (z == 0) {
        result = sumofdigits(x, y);
    }
    else {
        result = sumofdigits(x, y, z);
    }
    cout << "Результат: " << result << endl;
}

void findTriangle(int a, int b) {
    cout << "исп. функция вычисления гипотенузы и периметра " << endl;

    if (a <= 0 || b <= 0) {
        cout << "Катеты должны быть положительными" << endl;
        return;
    }
    double c = sqrt(a * a + b * b);
    cout << "гипотенуза = " << c << endl;
    cout << "периметр = " << a + b + c << endl;
}

void digitinput2(int p, int k) {
    cout << "исп. функция пункта 2: " << endl;
    findTriangle(p, k);
}

int main() {
    setlocale(LC_ALL, "Russian");
    int choice;

    do {
        cout << "Выбор пункта (1 или 2) = ";
        cin >> choice;

        switch (choice) {
        case 1:
            digitinput1();
            break;
        case 2: {
            int p, k;
            cout << "Введите катет p = ";
            cin >> p;
            cout << "Введите катет k = ";
            cin >> k;
            digitinput2(p, k);
            break;
        }
        default:
            cout << "Выберите 1 или 2" << endl;
            break;
        }

        cout << "Продолжить? (1-да, 0-нет) ";
        cin >> choice;

    } while (choice != 0);

    cout << "Конец программы " << endl;
    return 0;
}