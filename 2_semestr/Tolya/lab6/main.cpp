#include <iostream>
#include <math.h>

bool check(int x, int y, int xa, int xb, int xc, int ya, int yb, int yc) { // проверка вхождения точки в треугольник
    bool access = false;
    double flag1 = (xa - x) * (yb - ya) - (xb - xa) * (ya - y);
    double flag2 = (xb - x) * (yc - yb) - (xc - xb) * (yb - y);
    double flag3 = (xc - x) * (ya - yc) - (xa - xc) * (yc - y);
    if (((flag1 < 0) && (flag2 < 0) && (flag3 < 0)) || ((flag1 > 0) && (flag2 > 0) && (flag3 > 0))) {
        access = true;
    }
    return access;
}

int main() {
    using namespace std;

    int len1, len2;
    cout << "Enter points count in mas1: ";
    cin >> len1;
    cout << "Enter points count in mas2: ";
    cin >> len2;



    int** points1 = new int* [3];
    for (int i = 0; i < 3; i++) {
        points1[i] = new int[2];
        points1[i][0] = 0;
        points1[i][1] = 0;
    }
    int** points2 = new int* [3];
    for (int i = 0; i < 3; i++) {
        points2[i] = new int[2];
        points2[i][0] = 0;
        points2[i][1] = 0;
    }



    cout << "\nEnter points1:\n";
    for (int i = 0; i < len1; i++) {
        cout << "Point " << i + 1 << endl;
        cout << "Enter point: ";
        cin >> points1[i][0];
        cin >> points1[i][1];
    }

    cout << "\n\n\nEnter points2:\n";
    for (int i = 0; i < len2; i++) {
        cout << "Point " << i + 1 << endl;
        cout << "Enter point: ";
        cin >> points2[i][0];
        cin >> points2[i][1];
    }

    int** ans = new int* [3];
    for (int i = 0; i < 3; i++) {
        ans[i] = new int[2];
        ans[i][0] = 0;
        ans[i][1] = 0;
    }
    double pr = 0;

    for (int i = 0; i < len1; i++) { // ищем треугольник с наибольшей площадью
        for (int j = 0; j < len1; j++) {
            for (int k = 0; k < len1; k++) {
                if ((i != j) & (j != k) & (k != i)) {

                    int x1 = points1[i][0], y1 = points1[i][1];
                    int x2 = points1[j][0], y2 = points1[j][1];
                    int x3 = points1[k][0], y3 = points1[k][1];
                    cout << ((std::abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1))) / 2) << endl;
                    if (((std::abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1))) / 2) > pr) {
                        pr = ((std::abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1))) / 2);
                    }
                }
            }
        }
    }

    for (int i = 0; i < len1; i++) { // ищем наименьший подходящий треугольник
        for (int j = 0; j < len1; j++) {
            for (int k = 0; k < len1; k++) {

                if ((i != j) & (j != k) & (k != i)) {
                    int x1 = points1[i][0], y1 = points1[i][1];
                    int x2 = points1[j][0], y2 = points1[j][1];
                    int x3 = points1[k][0], y3 = points1[k][1];
                    if (((std::abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1))) / 2) <= pr) {
                        bool flag = true;
                        for (int h = 0; h < len2; h++) {
                            int x = points2[h][0], y = points2[h][1];
                            if (check(x, y, x1, x2, x3, y1, y2, y3) == false) {
                                flag = false;
                                break;
                            }
                        }
                        if (flag == true) { // если все точки входят в треугольник
                            ans[0][0] = x1; ans[0][1] = y1;
                            ans[1][0] = x2; ans[1][1] = y2;
                            ans[2][0] = x3; ans[2][1] = y3;
                        }
                        pr = ((std::abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1))) / 2);
                    }
                }
            }
        }
    }

    cout << "Answer: " << endl;
    for (int i = 0; i < 3; i++) {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }

    for (int i = 0; i < len1; i++)
        delete[] points1[i];
    delete[] points1;
    for (int i = 0; i < len2; i++)
        delete[] points2[i];
    delete[] points2;
    for (int i = 0; i < 3; i++)
        delete[] ans[i];
    delete[] ans;
}