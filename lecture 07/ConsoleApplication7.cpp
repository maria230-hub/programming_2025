//первый вариант
//пункт первый
#include <iostream>
#include <cstdlib>
using namespace std;

// Функция для поиска столбцов с нулевыми элементами
int* findZeroColumns(int** matrix, int rows, int cols, int& zeroCount) {
    int* zeroColumns = 0;
    zeroCount = 0;

    int* hasZero = (int*)calloc(cols, sizeof(int));
    if (!hasZero) return 0;

    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows; ++i) {
            if (matrix[i][j] == 0) {
                hasZero[j] = 1;
                break;
            }
        }
    }

    for (int j = 0; j < cols; ++j) {
        if (hasZero[j]) {
            zeroCount++;
        }
    }

    if (zeroCount > 0) {
        zeroColumns = (int*)malloc(zeroCount * sizeof(int));
        if (zeroColumns) {
            int index = 0;
            for (int j = 0; j < cols; ++j) {
                if (hasZero[j]) {
                    zeroColumns[index++] = j;
                }
            }
        }
    }

    free(hasZero);
    return zeroColumns;
}

int** removeColumns(int** matrix, int rows, int cols, int* columnsToRemove, int removeCount, int& newCols) {
    if (removeCount == 0) {
        newCols = cols;
        return 0;
    }

    newCols = cols - removeCount;
    int** newMatrix = (int**)malloc(rows * sizeof(int*));
    if (!newMatrix) return 0;

    for (int i = 0; i < rows; ++i) {
        newMatrix[i] = (int*)malloc(newCols * sizeof(int));
        if (!newMatrix[i]) {
            for (int p = 0; p < i; ++p) {
                free(newMatrix[p]);
            }
            free(newMatrix);
            return 0;
        }

        int newJ = 0;
        for (int j = 0; j < cols; ++j) {
            bool shouldRemove = false;
            for (int p = 0; p < removeCount; ++p) {
                if (j == columnsToRemove[p]) {
                    shouldRemove = true;
                    break;
                }
            }

            if (!shouldRemove) {
                newMatrix[i][newJ++] = matrix[i][j];
            }
        }
    }

    return newMatrix;
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void freeMatrix(int** matrix, int rows) {
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

    int rows = 2;
    int cols = 2;

    int** matrix = (int**)malloc(rows * sizeof(int*));
    if (!matrix) {
        cout << "Ошибка выделения памяти" << endl;
        return 1;
    }

    for (int i = 0; i < rows; ++i) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        if (!matrix[i]) {
            cout << "Ошибка выделения памяти" << endl;
            for (int j = 0; j < i; ++j) {
                free(matrix[j]);
            }
            free(matrix);
            return 1;
        }
    }
    cout << "Введите числа для матрицы 2x2:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "matrix[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    printMatrix(matrix, 2, 2);

    int A, B, C, D;

    do {
        cout << "Введите A (строки добавить снизу, >= 0): ";
        cin >> A;
        if (A < 0) cout << "Ошибка! A не может быть отрицательным." << endl;
    } while (A < 0);

    do {
        cout << "Введите B (столбцы добавить справа, >= 0): ";
        cin >> B;
        if (B < 0) cout << "Ошибка! B не может быть отрицательным." << endl;
    } while (B < 0);

    cout << "Введите коэффициент C: ";
    cin >> C;
    cout << "Введите коэффициент D: ";
    cin >> D;

    if (B > 0) {
        int newCols = cols + B;
        for (int i = 0; i < rows; ++i) {
            int* newRow = (int*)realloc(matrix[i], newCols * sizeof(int));
            if (!newRow) {
                cout << "Ошибка выделения памяти для столбцов" << endl;
                freeMatrix(matrix, rows);
                return 1;
            }
            matrix[i] = newRow;
            for (int j = cols; j < newCols; ++j) {
                matrix[i][j] = i * C + j * D;
            }
        }
        cols = newCols;
        printMatrix(matrix, rows, cols);
    }

    if (A > 0) {
        int newRows = rows + A;
        int** newMatrix = (int**)realloc(matrix, newRows * sizeof(int*));
        if (!newMatrix) {
            cout << "Ошибка выделения памяти для строк" << endl;
            freeMatrix(matrix, rows);
            return 1;
        }
        matrix = newMatrix;

        for (int i = rows; i < newRows; ++i) {
            matrix[i] = (int*)malloc(cols * sizeof(int));
            if (!matrix[i]) {
                cout << "Ошибка выделения памяти для новых строк" << endl;
                for (int j = rows; j < i; ++j) {
                    free(matrix[j]);
                }
                matrix = (int**)realloc(matrix, rows * sizeof(int*));
                freeMatrix(matrix, rows);
                return 1;
            }

            for (int j = 0; j < cols; ++j) {
                matrix[i][j] = i * C + j * D;
            }
        }
        rows = newRows;
        printMatrix(matrix, rows, cols);
    }

    int zeroCount = 0;
    int* zeroColumns = findZeroColumns(matrix, rows, cols, zeroCount);

    int** finalMatrix = 0;
    int finalCols = 0;

    if (zeroCount > 0 && zeroColumns) {
        cout << "Найдены нули в столбцах: ";
        for (int i = 0; i < zeroCount; ++i) {
            cout << zeroColumns[i] << " ";
        }
        cout << endl;

        finalMatrix = removeColumns(matrix, rows, cols, zeroColumns, zeroCount, finalCols);

        if (finalMatrix && finalCols > 0) {
            printMatrix(finalMatrix, rows, finalCols);
        }

        free(zeroColumns);
    }
    else {
        cout << "Столбцов с нулевыми элементами не найдено" << endl;
        finalMatrix = matrix;
        finalCols = cols;
    }

    if (finalMatrix != matrix) {
        freeMatrix(matrix, rows);
    }
    if (finalMatrix && finalMatrix != matrix) {
        freeMatrix(finalMatrix, rows);
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