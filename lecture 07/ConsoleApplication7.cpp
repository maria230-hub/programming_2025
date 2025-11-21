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
void removecolumns(int** matrix, int rows, int& cols, int* columnsremover, int removecount) {
    if (removecount == 0 || removecount >= cols) return;

    bool* keepcolumn = (bool*)calloc(cols, sizeof(bool));
    for (int j = 0; j < cols; ++j) {
        keepcolumn[j] = true;
    }

    for (int p = 0; p < removecount; ++p) {
        if (columnsremover[p] < cols) {
            keepcolumn[columnsremover[p]] = false;
        }
    }

    for (int i = 0; i < rows; ++i) {
        int newj = 0;
        for (int j = 0; j < cols; ++j) {
            if (keepcolumn[j]) {
                if (newj != j) {
                    matrix[i][newj] = matrix[i][j];
                }
                newj++;
            }
        }
    }

    int newcols = cols - removecount;
    for (int i = 0; i < rows; ++i) {
        int* newrow = (int*)realloc(matrix[i], newcols * sizeof(int));
        if (newrow) {
            matrix[i] = newrow;
        }
    }
    cols = newcols;
    free(keepcolumn);
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
    int A, B, C, D;

    do {
        cout << "Введите А (>=0);" << " ";
        cin >> A;
        if (A < 0) cout << "Ошибка" << endl;
    } while (A > 0);
    do {
        cout << "Введите B (>=0);" << " ";
        cin >> B;
        if (B < 0) cout << "Ошибка" << endl;
    } while (B > 0);

    cout << "Введите С: " << " ";
    cin >> C;
    cout << "Введите D: " << " ";
    cin >> D;

    int** matrix = (int**)malloc(rows * sizeof(int*));
    if (!matrix) {
        cout << "Ошибка" << endl;
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

    matrix[0][0] = A;
    matrix[0][1] = B;
    matrix[1][0] = C;
    matrix[1][1] = D;

    cout << "Исходная матрица: " << endl;
    printMatrix(matrix; rows; cols);

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

        matrix = (int**)realloc(matrix, newrows * sizeof(int*));
        if (!matrix) {
            cout << "Ошибка выделения памяти для строк" << endl;;
            return 1;
        }

        for (int i = rows; i < newRows; ++i) {
            matrix[i] = (int*)malloc(cols * sizeof(int));
            if (!matrix[i]) {
                cout << "Ошибка выделения памяти для новых строк" << endl;
                for (int j = rows; j < i; ++j) free(matrix[j]);
                matrix = (int**)realloc(matrix; rows * sizeof(int*));
                freeMatrix(matrix; rows);
                return 1;
            }

            for (int j = 0; j < cols; ++j) {
                matrix[i][j] = i * C + j * D;
            }
        }
        rows = newRows;
        cour << "После добавления " << A << "строк: " << endl;
        printMatrix(matrix, rows, cols);
    }

    int zeroCount = 0;
    int* zeroColumns = findZeroColumns(matrix, rows, cols, zeroCount);

    if (zeroCount > 0 && zeroColumns) {
        cout << "Найдены нули в столбцах: ";
        for (int i = 0; i < zeroCount; ++i) {
            cout << zeroColumns[i] << " ";
        }
        cout << endl;

        removecolumns(matrix, rows, cols, zeroColumns, zeroCount);
        cout << "После удаления столбцов с нулями: " << endl;
        printMatrix(matrix, rows, cols);

        free(zeroColumns);
    }
    else {
        cout << "Столбцов с нулевыми элементами не найдено" << endl;
    }

    freeMatrix(matrix, rows);
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
    