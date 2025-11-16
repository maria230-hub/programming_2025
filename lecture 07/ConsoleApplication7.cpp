//первый вариант
//пункт первый
#include <iostream>
#include <cstdlib> //для calloc & malloc & realloc
using namespace std;

int* findzero(int** matrix, int rows, int cols, int& zerocount) {
    int* zerocolumns = 0;
    zerocount = 0;

    // calloc для выделения и обнуления памяти
    int* zero = (int*)calloc(cols, sizeof(int));
    if (!zero) return 0;

    // Проверяка столбцов на наличие нулей
    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows; ++i) {
            if (matrix[i][j] == 0) {
                zero[j] = 1;
                break;
            }
        }
    }

    // Счет столбцов с нулями
    for (int j = 0; j < cols; ++j) {
        if (zero[j] == 1) {
            zerocount++;
        }
    }

    // Массив с индексами столбцов, содержащих нули
    if (zerocount > 0) {
        zerocolumns = (int*)malloc(zerocount * sizeof(int));
        if (zerocolumns) {
            int index = 0;
            for (int j = 0; j < cols; ++j) {
                if (zero[j] == 1) {
                    zerocolumns[index++] = j;
                }
            }
        }
    }

    free(zero);
    return zerocolumns;
}

int** removecolumns(int** matrix, int rows, int cols, int* columnsremover, int removecount, int& newcols) {
    if (removecount == 0) {
        newcols = cols;
        return matrix;
    }
    newcols = cols - removecount;
    int** newmatrix = (int**)malloc(rows * sizeof(int*));
    if (!newmatrix) return 0;

    for (int i = 0; i < rows; ++i) {
        newmatrix[i] = (int*)malloc(newcols * sizeof(int));
        if (!newmatrix[i]) {
            for (int p = 0; p < i; ++p) {
                free(newmatrix[p]);
            }
            free(newmatrix);
            return 0;
        }
        int newj = 0;
        for (int j = 0; j < cols; ++j) {
            bool shouldremove = false;
            for (int p = 0; p < removecount; ++p) {
                if (j == columnsremover[p]) {
                    shouldremove = true;
                    break;
                }
            }
            if (!shouldremove) {
                if (newj < newcols) {  // Защита от выхода за границы
                    newmatrix[i][newj++] = matrix[i][j];
                }
            }
        }
    }
    return newmatrix;
}

// Новая функция с использованием realloc для добавления строк
int** addRowsWithRealloc(int** matrix, int& currentRows, int newTotalRows, int cols, int C, int D) {
    if (newTotalRows <= currentRows) return matrix;

    // realloc для изменения размера массива указателей
    int** newMatrix = (int**)realloc(matrix, newTotalRows * sizeof(int*));
    if (!newMatrix) return 0;

    // Выделение память для новых строк
    for (int i = currentRows; i < newTotalRows; ++i) {
        newMatrix[i] = (int*)calloc(cols, sizeof(int));  // calloc для новых строк
        if (!newMatrix[i]) {
            // В случае ошибки освобождаем память
            for (int j = currentRows; j < i; ++j) {
                free(newMatrix[j]);
            }
            // Возвращение исходный размер
            newMatrix = (int**)realloc(newMatrix, currentRows * sizeof(int*));
            return newMatrix;
        }
        // Заполнение новой строки по формуле:
        for (int j = 0; j < cols; ++j) {
            newMatrix[i][j] = i * C + j * D;
        }
    }

    currentRows = newTotalRows;
    return newMatrix;
}

void freematrix(int** matrix, int rows) {
    if (matrix) {
        for (int i = 0; i < rows; ++i) {
            if (matrix[i]) {
                free(matrix[i]);
            }
        }
        free(matrix);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    // Создание начальной квадратной матрицы с использованием calloc
    int** arr = (int**)calloc(2, sizeof(int*));
    if (!arr) {
        cout << "Ошибка выделения памяти" << endl; return 1;
    }

    for (int i = 0; i < 2; ++i) {
        arr[i] = (int*)calloc(2, sizeof(int));  // calloc инициализирует нулями
        if (!arr[i]) {
            cout << "Ошибка выделения памяти" << endl;
            for (int j = 0; j < i; ++j) {
                free(arr[j]);
            }
            free(arr);
            return 1;
        }
    }

    cout << "Введите числа для квадратной матрицы 2x2:" << endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << "элемент [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }

    cout << "\nИсходная матрица:" << endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    int A, B, C, D;

    // Ввод A
    do {
        cout << "\nВведите A (сколько строк добавить снизу, >= 0): ";
        cin >> A;
        if (A < 0) {
            cout << "Ошибка! A не может быть отрицательным." << endl;
        }
    } while (A < 0);

    // Ввод B  
    do {
        cout << "Введите B (сколько столбцов добавить справа, >= 0): ";
        cin >> B;
        if (B < 0) {
            cout << "Ошибка! B не может быть отрицательным." << endl;
        }
    } while (B < 0);

    cout << "Введите коэффициент C: ";
    cin >> C;
    cout << "Введите коэффициент D: ";
    cin >> D;

    int currentRows = 2;
    int currentCols = 2 + B;  // Сначала добавляются столбцы

    // Расширенную матрица с новыми столбцами
    int** extendedMatrix = (int**)calloc(currentRows, sizeof(int*));
    if (!extendedMatrix) {
        cout << "Ошибка выделения памяти" << endl;
        freematrix(arr, 2);
        return 1;
    }

    for (int i = 0; i < currentRows; ++i) {
        extendedMatrix[i] = (int*)calloc(currentCols, sizeof(int));
        if (!extendedMatrix[i]) {
            cout << "Ошибка выделения памяти" << endl;
            for (int j = 0; j < i; ++j) {
                free(extendedMatrix[j]);
            }
            free(extendedMatrix);
            freematrix(arr, 2);
            return 1;
        }

        // Копирование исходных данных
        for (int j = 0; j < 2; ++j) {
            extendedMatrix[i][j] = arr[i][j];
        }

        // Заполнение новых столбцов
        for (int j = 2; j < currentCols; ++j) {
            extendedMatrix[i][j] = i * C + j * D;
        }
    }

    // realloc для добавления строк
    int newTotalRows = 2 + A;
    int** finalMatrix = addRowsWithRealloc(extendedMatrix, currentRows, newTotalRows, currentCols, C, D);

    if (!finalMatrix) {
        cout << "Ошибка при добавлении строк" << endl;
        freematrix(arr, 2);
        return 1;
    }

    cout << "\nРасширенная матрица (" << newTotalRows << "x" << currentCols << "):" << endl;
    for (int i = 0; i < newTotalRows; ++i) {
        for (int j = 0; j < currentCols; ++j) {
            cout << finalMatrix[i][j] << "\t";
        }
        cout << endl;
    }

    // Поиск столбцов с нулями
    int zerocount = 0;
    int* zerocolumns = findzero(finalMatrix, newTotalRows, currentCols, zerocount);

    if (zerocount > 0 && zerocolumns) {
        cout << "\nНайдены нули в столбцах: ";
        for (int i = 0; i < zerocount; ++i) {
            cout << zerocolumns[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "\nСтолбцов с нулевыми элементами не найдено" << endl;
    }

    // Удаление столбцов с нулями
    int finalCols = 0;
    int** resultMatrix = removecolumns(finalMatrix, newTotalRows, currentCols, zerocolumns, zerocount, finalCols);

    if (finalCols > 0 && resultMatrix) {
        cout << "\nФинальная матрица после удаления столбцов с нулями (" << newTotalRows << "x" << finalCols << "):" << endl; for (int i = 0; i < newTotalRows; ++i) {
            for (int j = 0; j < finalCols; ++j) {
                cout << resultMatrix[i][j] << "\t";
            }
            cout << endl;
        }
    }
    else {
        cout << "\nПосле удаления столбцов матрица пуста" << endl;
    }

    // Освобождение памяти
    freematrix(arr, 2);
    if (finalMatrix != resultMatrix) {
        freematrix(finalMatrix, newTotalRows);
    }
    if (resultMatrix && resultMatrix != finalMatrix) {
        freematrix(resultMatrix, newTotalRows);
    }
    if (zerocolumns) {
        free(zerocolumns);
    }

    //пункт второй
    double a, b;
    cout << "Введите a = " << endl;
    cin >> a;
    cout << "Введите b = " << endl;
    cin >> b;
    cout << "a = " << a << "; " << "b = " << b << endl;

    double* da = new double(a);
    double* db = new double(b);
    //увеличение a в 3 раза
    *da *= 3;
    cout << "Новое a = " << *da << "; " << "b = " << *db << endl;
    //замена 
    double temp = *da;
    *da = *db;
    *db = temp;
    cout << "Заменённое a = " << *da << "; " << "b = " << *db << endl;
    delete da;
    delete db;

    return 0;
}