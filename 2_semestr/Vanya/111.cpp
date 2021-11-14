#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;

int main()
{
    double a;
    double B, z1, z2;
    cin >> a >> B;
    z1 = (pow((cos(a) - cos(B)), 2)-(pow((sin(a)-sin(B)),2)));
    z2 = -4*(pow((sin((a-B)/2)),2))*cos(a+B);
    cout << z1 << endl << z2 << endl;
    system("pause");
    return 0;
}