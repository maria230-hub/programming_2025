#include <iostream>
#include <cstdlib>
using namespace std;

int* findzero(int** matrix, int rows, int cols, int& zerocount) {
    int* zerocolumns = 0;
    zerocount = 0;

    int* zero = (int*)calloc(cols, sizeof(int));
    if (!zero) return 0;

    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows; ++i) {
            if (matrix[i][j] == 0) {
                zero[j] = 1;
                break;
            }
        }
    }

    for (int j = 0; j < cols; ++j) {
        if (zero[j] == 1) {
            zerocount++;
        }
    }

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

void printmatrix(int** matrix, int rows, int cols) {
    cout << "Матрица " << rows << "x" << cols << ":" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void freematrix(int** matrix, int rows) {
    if (matrix) {
        for (int i = 0; i < rows; ++i) {
            free(matrix[i]);
        }
        free(matrix);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    int rows = 2;
    int cols = 2;
    int A, B, C, D;

    cout << "Введите параметры A, B, C, D:" << endl;

    do {
        cout << "A (строки добавить снизу, >= 0): ";
        cin >> A;
        if (A < 0) cout << "Ошибка! A не может быть отрицательным." << endl;
    } while (A < 0);

    do {
        cout << "B (столбцов добавить справа, >= 0): ";
        cin >> B;
        if (B < 0) cout << "Ошибка! B не может быть отрицательным." << endl;
    } while (B < 0);

    cout << "C (коэффициент для строк): ";
    cin >> C;
    cout << "D (коэффициент для столбцов): ";
    cin >> D;

    int** matrix = (int**)malloc(rows * sizeof(int*));
    if (!matrix) {
        cout << "Ошибка выделения памяти" << endl;
        return 1;
    }

    for (int i = 0; i < rows; ++i) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        if (!matrix[i]) {
            cout << "Ошибка выделения памяти" << endl;
            for (int j = 0; j < i; ++j) free(matrix[j]);
            free(matrix);
            return 1;
        }
    }

    matrix[0][0] = A;
    matrix[0][1] = B;
    matrix[1][0] = C;
    matrix[1][1] = D;

    cout << "\nИсходная матрица 2x2:" << endl;
    printmatrix(matrix, rows, cols);
    if (B > 0) {
        int newcols = cols + B;
        for (int i = 0; i < rows; ++i) {
            int* newrow = (int*)realloc(matrix[i], newcols * sizeof(int));
            if (!newrow) {
                cout << "Ошибка выделения памяти для столбцов" << endl;
                freematrix(matrix, rows);
                return 1;
            }
            matrix[i] = newrow;

            for (int j = cols; j < newcols; ++j) {
                matrix[i][j] = i * C + j * D;
            }
        }
        cols = newcols;
        cout << "После добавления " << B << " столбцов:" << endl;
        printmatrix(matrix, rows, cols);
    }

    if (A > 0) {
        int newrows = rows + A;

        matrix = (int**)realloc(matrix, newrows * sizeof(int*));
        if (!matrix) {
            cout << "Ошибка выделения памяти для строк" << endl;
            return 1;
        }

        for (int i = rows; i < newrows; ++i) {
            matrix[i] = (int*)malloc(cols * sizeof(int));
            if (!matrix[i]) {
                cout << "Ошибка выделения памяти для новых строк" << endl;
                for (int j = rows; j < i; ++j) free(matrix[j]);
                matrix = (int**)realloc(matrix, rows * sizeof(int*));
                freematrix(matrix, rows);
                return 1;
            }

            for (int j = 0; j < cols; ++j) {
                matrix[i][j] = i * C + j * D;
            }
        }
        rows = newrows;
        cout << "После добавления " << A << " строк:" << endl;
        printmatrix(matrix, rows, cols);
    }

    int zerocount = 0;
    int* zerocolumns = findzero(matrix, rows, cols, zerocount);

    if (zerocount > 0 && zerocolumns) {
        cout << "Найдены нули в столбцах: ";
        for (int i = 0; i < zerocount; ++i) {
            cout << zerocolumns[i] << " ";
        }
        cout << endl;

        removecolumns(matrix, rows, cols, zerocolumns, zerocount);

        cout << "После удаления столбцов с нулями:" << endl;
        printmatrix(matrix, rows, cols);

        free(zerocolumns);
    }
    else {
        cout << "Столбцов с нулевыми элементами не найдено" << endl;
    }

    // Освобождение памяти
    freematrix(matrix, rows);

    // Пункт второй - работа с указателями
    double a, b;
    cout << "\nВведите a = ";
    cin >> a;
    cout << "Введите b = ";
    cin >> b;
    cout << "a = " << a << "; " << "b = " << b << endl;

    double* da = new double(a);
    double* db = new double(b);

    // Увеличение a в 3 раза
    *da *= 3;
    cout << "Новое a = " << *da << "; " << "b = " << *db << endl;

    // Замена значений
    double temp = *da;
    *da = *db;
    *db = temp;
    cout << "Заменённое a = " << *da << "; " << "b = " << *db << endl;

    delete da;
    delete db;

    return 0;
}