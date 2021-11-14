#include <iostream>
#include <math.h>
#include <iomanip>

double F(int x, double dX, double a, double b, double c) {
    double ans;
    if (((x - a) < 0) && (c != 0)) {
        ans = (double)(a - (x / (10 + b)));
    }
    else {
        if (((x - a) > 0) && (c == 0)) {
            ans = (double)((x - a) / (x - c));
        }
        else {
            ans = (double)((3 * x) + (2 / c));
        }
    }
    return ans;
}


void part1() {
    using namespace std;
    double a, b, c, x, y;
    int Xn, Xk;
    double d;
    cout << "Enter a: "; cin >> a;
    cout << "Enter b: "; cin >> b;
    cout << "Enter c: "; cin >> c;
    cout << "Enter d: "; cin >> d;
    cout << "Enter Xn: "; cin >> Xn;
    cout << "Enter Xk: "; cin >> Xk;
    int Ac = (a / 1), Bc = (b / 1), Cc = (c / 1);
    system("cls");
    cout << setw(10) << "x |" << setw(10) << "y" << endl;
    for (double i = Xn; i < Xk; i += d) {
        if (((Ac || Bc) && (Cc)) != 0) {
            cout << setw(10) << (double)i << " | " << F(i, d, a, b, c) << endl;
        }
        else {
            cout << setw(10) << (double)i << " | " << (int)F(i, d, a, b, c) << endl;
        }
    }
    system("pause");
}



void part2() {
    using namespace std;
    double xn, xk, dx, ans = 0;
    cout << "Enter xn: ";
    cin >> xn;
    cout << "Enter xk: ";
    cin >> xk;
    cout << "Enter dx: ";
    cin >> dx;
    for (double i = xn; i <= xk; i += dx) {
        cout << i << endl;
        if ((i < 1) & (i > -1)) {
            ans = ans + (pow(i, 2 * i + 1) / (2 * i + 1));
            cout << "added: " << (pow(i, 2 * i + 1) / (2 * i + 1)) << endl;
        }
    }
    ans *= 2;
    cout << "ans: " << ans << endl;
    system("pause");
}



int main() {
    system("chcp 65001");
    using namespace std;
    part1();
    part2();
    return 0;
}