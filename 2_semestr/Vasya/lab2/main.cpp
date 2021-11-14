#include <iostream>
#include <cmath>
using namespace std;

int main(){
	
	int r = 1;
	int x, y, flag = 0;
	cout << "Enter x,y coords: ";
	cin >> x;
	cin >> y;

	if ((x >= 0)&&(y >= 0)){
		if (sqrt(x*x + y*y) <= 1){
			flag = 1;
		}
	}

	else if ((x < 0)&&(y < 0)){
		double f=(x+r)*(-1)/y;
		if(f>=0)
			flag=1;
	}

	cout << flag << endl;

}