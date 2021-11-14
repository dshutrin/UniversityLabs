#include <iostream>
#include <cmath>
using namespace std;

int main(){
	double z1, z2;
	int a = 3;
	z1 = (1-2*pow(sin(a),2))/(1+sin(2*a));
	z2 = (1-tan(a))/(1+tan(a));
	cout << z1 << " " << z2;
}