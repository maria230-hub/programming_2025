#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cstdlib>
#include <ctime>
using Vector = std::vector<int>;
using namespace std;

//вариант 1
//пункт 1

// просмотр массива
void viewMassive(const Vector& arr) {
    cout << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i];
        if (i < arr.size() - 1) {
            cout << " ";
        }
    }
    cout << "]" << endl;
}

// ввод чисел в массив
void inputMassive(Vector& arr) {
    arr.clear();
    int count;
    cout << "Введите количество элементов массива: ";
    cin >> count;

    if (count <= 0) {
        cout << "Ошибка" << endl;
        return;
    }

    cout << "Введите " << count << " элементов: " << endl;
    for (int i = 0; i < count; ++i) {
        int digit;
        cout << "Элемент " << (i + 1) << ": ";
        cin >> digit;
        arr.push_back(digit);
    }
    cout << "Массив успешно заполнен: ";
    viewMassive(arr);
}

// добавление элемента в начало
void addtotheBegginig(Vector& arr, int digit) {
    arr.insert(arr.begin(), digit);
}

// добавлние значения в конец
void addtotheEnd(Vector& arr, int digit) {
    arr.push_back(digit);
}

// очистка массива
void purifedArray(Vector& arr) {
    arr.clear();
}

// поиск эл-та в массиве
vector<size_t> findValue(const Vector& arr, int digit) {
    vector<size_t> x;
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == digit) {
            x.push_back(i);
        }
    }
    return x;
}

// вывод результата поиска эл-та
void printReselt(const vector<size_t> x) {
    if (x.empty()) {
        cout << "[]" << endl;
    }
    else {
        cout << "[";
        for (size_t i = 0; i < x.size(); ++i) {
            cout << x[i];
            if (i < x.size() - 1) {
                cout << ",";
            }
        }
        cout << "]" << endl;
    }
}

// работа с четными и нечетными значениями
void PrimeDigits(Vector& arr) {
    cout << "Исходный массив: ";
    viewMassive(arr);

    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] % 2 == 0) {
            arr[i] += 2;
        }
        else {
            arr[i] = -arr[i];
        }
    }

    cout << "Полученный массив: ";
    viewMassive(arr);
}

void firstpoint() {
    Vector array;
    int choice;

    // начальный ввод массива
    cout << "Ввод чисел в массив" << endl;
    inputMassive(array);

    do {
        cout << " Введите 0 для выхода из программы" << endl;
        cout << " Введите 1 для просмотра массива" << endl;
        cout << " Введите 2 для ввода нового массива" << endl;
        cout << " Введите 3 для добавления числа в начало массива" << endl;
        cout << " Введите 4 для добавления числа в конец массива" << endl;
        cout << " Введите 5 для очистки массива" << endl;
        cout << " Введите 6 для поиска элемента массива" << endl;
        cout << " Введите 7 для работы с четными и нечетными числами" << endl;
        cout << " Введите цифру: ";
        cin >> choice;

        switch (choice) {
        case 0:
            cout << "Программа завершена" << endl;
            break;

        case 1:
            if (array.empty()) {
                cout << "В массиве ничего нет" << endl;
            }
            else {
                cout << "Текущий массив: ";
                viewMassive(array);
            }
            break;

        case 2:
            inputMassive(array);
            break;

        case 3:
            if (array.empty()) {
                cout << "В массиве ничего нет" << endl;
            }
            else {
                int digit;
                cout << "Введите число (добавление в начало): ";
                cin >> digit;
                cout << "Исходный массив: ";
                viewMassive(array);
                addtotheBegginig(array, digit);
                cout << "Преобразованный массив: ";
                viewMassive(array);
            }
            break;

        case 4:
            if (array.empty()) {
                cout << "В массиве ничего нет" << endl;
            }
            else {
                int digit;
                cout << "Введите число (добавление в конец): ";
                cin >> digit;
                cout << "Исходный массив: ";
                viewMassive(array);
                addtotheEnd(array, digit);
                cout << "Преобразованный массив: ";
                viewMassive(array);
            }
            break;

        case 5:
            if (array.empty()) {
                cout << "В массиве ничего нет" << endl;
            }
            else {
                cout << "Массив до очистки: ";
                viewMassive(array);
                purifedArray(array);
                cout << "Массив успешно очищен" << endl;
            }
            break;

        case 6:
            if (array.empty()) {
                cout << "В массиве ничего нет" << endl;
            }
            else {
                cout << "Исходный массив: ";
                viewMassive(array);
                int digit;
                cout << "Введите число для поиска в массиве: ";
                cin >> digit;
                vector<size_t> x = findValue(array, digit);
                cout << "Индексы найденного элемента " << digit << ": ";
                printReselt(x);
            }
            break;

        case 7:
            if (array.empty()) {
                cout << "В массиве ничего нет" << endl;
            }
            else {
                PrimeDigits(array);
            }
            break;

        default:
            cout << "Неверно, введите цифру от 0 до 7" << endl;
        }
    } while (choice != 0);
}
// пункт 2
using Array_10 = std::array<int, 10>;

void viewArray(const Array_10& arr) {
    cout << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i];
        if (i < arr.size() - 1) {
            cout << " ";
        }
    }
    cout << "]" << endl;
}

bool compareDescending(int a, int b) {
    return a > b;
}

//передача по значению
Array_10 sortByValue(Array_10 arr, bool sortarray) {
    cout << "работа с копией массива" << endl;
    if (sortarray) {
        sort(arr.begin(), arr.end());
        cout << "сортировка по возрастанию" << endl;
    }
    else {
        sort(arr.begin(), arr.end(), compareDescending);
        cout << "сортировка по убыванию" << endl;
    }
    return arr;
}

//передача по ссылке
void sortByReference(Array_10& arr, bool sortarray) {
    cout << "работа с исходным массивом" << endl;
    if (sortarray) {
        sort(arr.begin(), arr.end());
        cout << "сортировка по возрастанию" << endl;
    }
    else {
        sort(arr.begin(), arr.end(), compareDescending);
        cout << "сортировка по убыванию" << endl;
    }
}

//передача по указателю
void sortByPointer(Array_10* arr, bool sortarray) {
    if (arr != nullptr) {
        cout << "работа с исходным массивом через указатель" << endl;
        if (sortarray) {
            sort(arr->begin(), arr->end());
            cout << "сортировка по возрастанию" << endl;
        }
        else {
            sort(arr->begin(), arr->end(), compareDescending);
            cout << "сортировка по убыванию" << endl;
        }
    }
}

void secondpoint() {
    Array_10 arr;
    srand(time(0));
    for (int i = 0; i < 10; ++i) {
        arr[i] = rand() % 21 - 10;
    }
    cout << "Исходный массив: ";
    viewArray(arr);

    // 1. Передача по значению
    cout << "\n1. ПЕРЕДАЧА ПО ЗНАЧЕНИЮ:" << endl;

    cout << "   а) Сортировка по возрастанию:" << endl;
    cout << "   Массив до сортировки: ";
    viewArray(arr);
    Array_10 sortedAsc = sortByValue(arr, true);
    cout << "   Массив после сортировки (оригинал не изменился): ";
    viewArray(arr);
    cout << "   Результат функции (новая копия): ";
    viewArray(sortedAsc);

    cout << "   б) Сортировка по убыванию:" << endl;
    cout << "   Массив до сортировки: ";
    viewArray(arr);
    Array_10 sortedDesc = sortByValue(arr, false);
    cout << "   Массив после сортировки (оригинал не изменился): ";
    viewArray(arr);
    cout << "   Результат функции (новая копия): ";
    viewArray(sortedDesc);

    // 2. Передача по ссылке
    cout << "\n2. ПЕРЕДАЧА ПО ССЫЛКЕ:" << endl;

    // Восстанавливаем исходный массив
    for (int i = 0; i < 10; ++i) {
        arr[i] = rand() % 21 - 10;
    }
    cout << "   Восстановленный исходный массив: ";
    viewArray(arr);

    cout << "   а) Сортировка по возрастанию:" << endl;
    cout << "   Массив до сортировки: ";
    viewArray(arr);
    sortByReference(arr, true);
    cout << "   Массив после сортировки (оригинал изменился): ";
    viewArray(arr);

    cout << "   б) Сортировка по убыванию:" << endl;
    cout << "   Массив до сортировки: ";
    viewArray(arr);
    sortByReference(arr, false);
    cout << "   Массив после сортировки (оригинал изменился): ";
    viewArray(arr);

    // 3. Передача по указателю
    cout << "\n3. ПЕРЕДАЧА ПО УКАЗАТЕЛЮ:" << endl;

    // Восстанавливаем исходный массив
    for (int i = 0; i < 10; ++i) {
        arr[i] = rand() % 21 - 10;
    }
    cout << "   Восстановленный исходный массив: ";
    viewArray(arr);

    cout << "   а) Сортировка по возрастанию:" << endl;
    cout << "   Массив до сортировки: ";
    viewArray(arr);
    sortByPointer(&arr, true);
    cout << "   Массив после сортировки (оригинал изменился): ";
    viewArray(arr);

    cout << "   б) Сортировка по убыванию:" << endl;
    cout << "   Массив до сортировки: ";
    viewArray(arr);
    sortByPointer(&arr, false);
    cout << "   Массив после сортировки (оригинал изменился): ";
    viewArray(arr);

    cout << "  ПЕРЕДАЧА МАССИВА В ФУНКЦИЮ ПО ЗНАЧЕНИЮ: " << endl;
    cout << "  Создается полная копия массива, все изменения применяются к копии." << endl;
    cout << "  Оригинальный массив остается неизменным. Память расходуется на копию." << endl;
    cout << "  Подходит когда нужно сохранить исходные данные неизменными." << endl;

    cout << "  ПЕРЕДАЧА МАССИВА В ФУНКЦИЮ ПО ССЫЛКЕ: " << endl;
    cout << "  Функция работает непосредственно с оригинальным массивом." << endl;
    cout << "  Все изменения сохраняются. Эффективно по памяти и производительности." << endl;
    cout << "  Используется когда нужно изменить оригинальный массив." << endl;

    cout << " ПЕРЕДАЧА МАССИВА В ФУНКЦИЮ ПО УКАЗАТЕЛЮ: " << endl;
    cout << " Функция получает адрес массива и работает с оригиналом через указатель." << endl;
    cout << " Все изменения сохраняются. Требует проверки на nullptr." << endl;
    cout << " Часто используется в C-стиле, позволяет изменять оригинальный массив." << endl;
}
int main() {
    setlocale(LC_ALL, "Russian");
    firstpoint();
    secondpoint();
    return 0;
}