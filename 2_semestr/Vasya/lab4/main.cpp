#include <iostream>
using namespace std;

int main(){
	cout << "Enter elements count: ";
	int count;
	cin >> count;
	int *mas = new int[count];
	int index, var;

	for (int i = 0; i < count; i++){
		mas[i] = rand()%50 - 25;
		if (i == 0){
			var = abs(mas[i]);
			index = 0;
		}
		else
			if (abs(mas[i]) < var){
				index = i;
				var = abs(mas[i]);
			}
	}

	for (int i = 0; i < count; i++)
		cout << mas[i] << " ";

	cout << endl << "Min: " << var << endl;

	int sum = 0, flag = 0;
	for (int i = 0; i < count; i++){
		if (flag == 0){
			if (mas[i] < 0)
				flag = 1;
		}else{
			sum += abs(mas[i]);
		}
	}

	cout << "Sum: " << sum << endl;

	int min, max, s = 0;
	cout << "Enter min for del: "; cin >> min;
	cout << "Enter max for del: "; cin >> max;

	int c = 0;

	for (int i = 0; i < count; i++){
		if ((min <= abs(mas[i])) and (abs(mas[i]) <= max)){
			c++;
		}
	}

	for (int i = 0; i < count; i++){
		for (int j = i; j < count; j++){
			if ((min <= abs(mas[i])) and (abs(mas[i]) <= max)){
				for (int k = i; k < count; k++){
					int h = mas[i];
					mas[i] = mas[k];
					mas[k] = h;
				}
			}
		}
	}

	for (int i = 0; i < c; i++){
		mas[count-i-1] = 0;
	}

	cout << endl << c << endl;
	for (int i = 0; i < count; i++){
		cout << mas[i] << " ";
	}
	delete mas;
}