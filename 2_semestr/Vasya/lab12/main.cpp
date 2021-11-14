#include <iostream>
using namespace std;

template <typename T>
void create(T *mas, int len){// задаем значения элементов массива
	for (int i = 0; i < len; i++){
		*(mas + i) = rand()%1000-500;// рандомное задание значения
	}
}

template <typename T>
T max(T *mas, int len){
	T max = *(mas);
	for (int i = 0; i < len; i++){
		if (*(mas + i) > max){
			max = *(mas + i);
		}
	}
	return max;
}

template <typename T>
T sum(T *mas, int len){// сумма элементов между 1м и 2м положительным числом
	T ans = 0;
	int first = -1, second = -1, flag = 0;
	for (int i = 0; i < len; i++){
		if (*(mas + i) > 0){
			if (first == -1){
				first = i;
			}else{
				if (second == -1){
					second = i;
				}
			}
		}else{
			if ((first != -1) & (second == -1)){
				ans += *(mas + i);
			}
		}
	}
	return ans;
}

template <typename T, typename T2>
void sort(T *mas, T2 mas_el, int len){// сортировка
	for (int j = 0; j < len; j++){
		for (int i = 0; i < len-1; i++){
			if (*(mas + i) == 0){
				T2 f;
				f = mas[i];
				mas[i] = mas[i+1];
				mas[i+1] = f;
			}
		}
	}
}

int main(){
	int len;
	cout << "Enter mas len: ";
	cin >> len;//ввод длины массива
	int mas[len];

	create(&mas[0], len);

	cout << "Mas: ";
	for (int i = 0; i < len; i++)
		cout << mas[i] << " ";

	cout << endl << "Max: " << max(&mas[0], len) << endl;
	cout << "Sum: " << sum(&mas[0], len) << endl;
	
	sort(&mas[0], mas[0], len);
	cout << "Sort: ";
	for (int i = 0; i < len; i++)
		cout << mas[i] << " ";
}