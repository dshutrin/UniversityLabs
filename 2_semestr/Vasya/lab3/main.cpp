#include <iostream>
#include <cmath>
using namespace std;

double F(double x, double a, double b, double c, double d){
	double ans;
	if ((x < 1)&&(c != 0)){
		ans = a*x*x + (b / c);
	}else{
		if ((x > 1.5)&&(c == 0)){
			ans = (x - a)/pow((x - c), 2);
		}
		else{
			ans = (x*x) / (c*c);
		}
	}
	return ans;
}

void part2(){
    using namespace std;
    double xn, xk, dx, ans = 0;
    cout << "Enter xn: ";
    cin >> xn;
    cout << "Enter xk: ";
    cin >> xk;
    cout << "Enter dx: ";
    cin >> dx;
    for (double i = xn; i <= xk; i += dx){
        if ((i > 1) or (i < -1)){
            ans = ans + 1/((2*i + 1)*pow(i, 2*i+1));
        }
    }
    cout << "ans: " << ans << endl;
}

int main(){
	double a, b, c, d, xn, xk, dx;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	cin >> xn;
	cin >> xk;
	cin >> dx;

	for (int i = xn; i <= xk; i += dx){
		cout << "F(" << i << ") =\t" << F(i, a, b, c, d) << endl;
	}

	cout << endl;
	part2();

}