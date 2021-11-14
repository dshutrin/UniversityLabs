#include <iostream>
using namespace std;

struct MARSH{
	int number;
	string start;
	string end;
};

int main(){
	system("chcp 65001");
	system("cls");
	MARSH *routes = new MARSH[5];
	for (int  i = 0; i < 5; i++){
		routes[i].number = i+1;
		cout << "Маршрут №" << i+1 << ":" << endl;
		cout << "\tВведите название пункта начала маршрута: ";
		getline(cin, routes[i].start);
		cout << "\tВведите название конечной точки маршрута: ";
		getline(cin, routes[i].end);
		routes[i].end;
	}

	int count = 0;
	string find;
	cout << "Какой пункт хотите найти?: ";
	getline(cin, find);

	for (int i = 0; i < 5; i++){
		if ((routes[i].start == find)or(routes[i].end == find)){
			cout << "Маршрут №" << routes[i].number << endl;
			cout << "\tНачальная точка: " << routes[i].start << endl;
			cout << "\tПункт назначения: " << routes[i].end << endl;
			count++;
		}
	}

	if (count == 0){
		cout << "Подходящих мамршрутов не найдено!";
	}

	delete routes;
}