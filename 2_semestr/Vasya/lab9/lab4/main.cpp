#include <iostream>
using namespace std;

int summa(int *mas, int count){//поиск суммы модулей после первого отрицательного 
	int flag = 0;
	int summ = 0;
	for (int i = 0; i < count; i++){
		if (flag == 0){
			if (mas[i] < 0)
				flag = 1;
		}else{
			summ += abs(mas[i]);
		}
	}
	return summ;
}

int minimum(int *mas, int count){// поиск минимального по модулю элемента
	int minn = 0;
	for (int i = 0; i < count; i++){
		*(mas + i) = rand()%50 - 25;
		if (i == 0){
			minn = abs(*(mas + i));
		}
		else
			if (abs(*(mas + i)) < minn){
				minn = abs(*(mas + i));
			}
	}
	return minn;
}

void sort(int *mas, int count, int min, int max){// сортировка массива (перемещение нулевых элементов вправо)
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
}

int main(){
	cout << "Enter elements count: ";
	int count;
	cin >> count;

	int mas[count];
	int min, max = 0, sum;

	min = minimum(&mas[0], count);
	cout << endl << "Min: " << min << endl;
	sum = summa(&mas[0], count);
	cout << "Sum: " << sum << endl;

	for (int i = 0; i < count; i++)// вывод массива
		cout << mas[i] << " ";

	// сортировка и зануление
	cout << endl << "Enter min for del: "; cin >> min;// ввод границ удаления
	cout << "Enter max for del: "; cin >> max;// 
	sort(&mas[0], count, min, max);
	// -=====================-

	for (int i = 0; i < count; i++)// вывод массива
		cout << mas[i] << " ";
	
}