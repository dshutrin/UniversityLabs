#include <iostream>
#include <cmath>
using namespace std;


struct point{
	int id;
	int x;
	int y;
};


bool belongs(double r, int x, int y, int x0, int y0){
	return sqrt((x0 - x) + (y0 - y)) == r;
}




int main(){
	int len;
	cin >> len;
	point mas1[len];

	for (int i = 0; i < len; i++){
		mas1[i].id = i;
		cin >> mas1[i].x;
		cin >> mas1[i].y;
	}

	

}