#include <iostream>
#include <cmath>
#include <math.h>

int main(){
    using namespace std;

    double x, y, r, z2;
    bool ans = false;
    while (true){
        cout << "Enter radius: ";
        cin >> r;
        cout << "Enter x: ";
        cin >> x;
        cout << "Enter y: ";
        cin >> y;
        if (((x > 0) && (y > 0)) || ((x < 0)&&(y < 0))){
            if ((x*x + y*y) <= r*r){
                ans = true;
            }
        } 

        if ((x < 0) && (y > 0)){
            double xa = 0, ya = r;
            double xb = 0, yb = 0;
            double xc = -r, yc = 0;

            double flag1 = (xa - x)*(yb - ya)-(xb - xa)*(ya - y);
            double flag2 = (xb - x)*(yc - yb)-(xc - xb)*(yb - y);
            double flag3 = (xc - x)*(ya - yc)-(xa - xc)*(yc - y);

            if (((flag1 < 0)&&(flag2 < 0)&&(flag3 < 0))||((flag1 > 0)&&(flag2 > 0)&&(flag3 > 0))){
                ans = true;
            }

        }

        if (ans == true){
            cout << "Point in polygon!" << endl;
        }else{
            cout << "Point not in polygon!" << endl;
        }

        system("pause");
        system("cls");
    }
    return 0;
}