#include <iostream>
#include <Windows.h>
#include <time.h>
#include <iomanip>

using namespace std;

void Create(int(&mas)[9][5], const int row, const int column) {
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            mas[i][j] = 5 + rand() % 61;
}

void Print(int(&mas)[9][5], const int row, const int column) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (mas[i][j] >= 10)
                cout << mas[i][j] << "  ";
            else
                cout << mas[i][j] << "   ";
        }
        cout << endl;
    }
    cout << endl;
}

void Amount(int(&mas)[9][5], const int row, const int column) {
    int amount = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (mas[i][j] % 2 == 1 && mas[i][j] % 13 != 0) {
                amount += 1;
            }
        }
    }
    cout << amount;
}

void Sum(int(&mas)[9][5], const int row, const int column) {
    int sum = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (mas[i][j] % 2 == 1 && mas[i][j] % 13 != 0) {
                sum += mas[i][j];
            }
        }
    }
    cout << sum;
}

void PrintZero(int(&mas)[9][5], const int row, const int column) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (mas[i][j] % 2 == 1 && mas[i][j] % 13 != 0) {
                cout << 0 << "   ";
            }
            else
                if (mas[i][j] >= 10)
                    cout << mas[i][j] << "  ";
                else
                    cout << mas[i][j] << "   ";
        }
        cout << endl;
    }
    cout << endl;
}

void Sort(int(&mas)[9][5], const int row, const int column) {
    int sort1 = 1;
    int sort2 = 1;
    int j = 0, n1 = 0, n2 = 0;

    for (int m = 0; m < row - 1; m++) {
        n1 = m;
        n1 += 1;
        for (n1; n1 < row; n1++) {
            if (mas[m][j] == mas[n1][j]) {
                sort1 = 0;
            }
        }
    }

    if (sort1 == 1) { 
        j = 0;
        for (int i = 0; i < row - 1; i++) {
            int maxnum = mas[i][j];
            int indexmaxnum = i;
            for (int k = i; k < row; k++) {
                if (mas[k][j] > maxnum) {
                    maxnum = mas[k][j];
                    indexmaxnum = k;
                }
            }
            mas[indexmaxnum][j] = mas[i][j];
            mas[i][j] = maxnum;
        }
    }
    else if (sort1 == 0) {
        j = 1;
        // Перевіряємо, чи сортувати 2 рядок
        for (int m = 0; m < row - 1; m++) {
            n2 = m;
            n2 += 1;
            for (n2; n2 < row; n2++) {
                if (mas[m][j] == mas[n2][j]) {
                    sort2 = 0;
                }
            }
        }
        if (sort2 == 1) { // Сортуємо другий
            j = 1;

            for (int i = 0; i < row - 1; i++) {
                int maxnum = mas[i][j];
                int indexmaxnum = i;
                for (int k = i; k < row; k++) {
                    if (mas[k][j] > maxnum) {
                        maxnum = mas[k][j];
                        indexmaxnum = k;
                    }
                }
                mas[indexmaxnum][j] = mas[i][j];
                mas[i][j] = maxnum;
            }
        }
        else if (sort2 == 0) { // Сортуємо четвертий
            j = 3;

            for (int i = 0; i < row - 1; i++) {
                int maxnum = mas[i][j];
                int indexmaxnum = i;
                for (int k = i; k < row; k++) {
                    if (mas[k][j] > maxnum) {
                        maxnum = mas[k][j];
                        indexmaxnum = k;
                    }
                }
                mas[indexmaxnum][j] = mas[i][j];
                mas[i][j] = maxnum;
            }
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int row = 9;
    const int column = 5;

    int a[row][column];

    cout << "Матриця: " << endl << endl;
    Create(a, row, column);
    Print(a, row, column);

    cout << "Потрібні елементи матриці замінено нулями: " << endl << endl;
    PrintZero(a, row, column);
    cout << "Кількість елементів, задовільняючих критерій: "; Amount(a, row, column); cout << endl;
    cout << "Сума елементів, задовільняючих критерій: "; Sum(a, row, column); cout << endl << endl;

    cout << "Відсортована матриця: " << endl << endl;
    Sort(a, row, column);
    Print(a, row, column);

    cin.get();
    return 0;
}