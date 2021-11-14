#include <iostream>
#include <vector>

using namespace std;

int main(){
    int x, y;
    system("chcp 65001");
    cout << "Введите размер матрицы по гризонтали: ";
    cin >> x;
    cout << "Введите размер матрицы по вертикали: ";
    cin >> y;

    double **matr = new double*[y];
    for (int i = 0; i < y; i++){
        matr[i] = new double[x];
    }

    cout << "Изначальная матрица:\n";
    for (int i = 0; i < y; i++){
        for (int k = 0; k < x; k++){
            matr[i][k] = (rand() % 40) + 10;
            cout << matr[i][k] << " ";
        }
       cout << endl;
    }

    cout << endl;

    int count = 0;
    for (int i = 1; i < y; i++){
        double j = matr[i][count]/matr[0][count];
        cout << j << " ";
        for (int k = i; k < y; k++){
            for (int u = 0; u < x; u++){
                matr[k][u] -= matr[0][u] * j;//нижний треугольник должен зануляться, но так как есть погрешность(double черезчур точный тип), они не зануляются
            }
        }
        count++;
    }

    cout << "\n\nИзменённая матрица:\n";
    for (int i = 0; i < y; i++){
        for (int k = 0; k < x; k++){
            cout << matr[i][k] << "\t";
            if (matr[i][k] == 0)
                cout << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < y; i++){
       delete matr[i];
    }
    delete matr;

}