#include <iostream>
using namespace std;

template <typename T>
T max_el(T *mas, int len){
	T max = mas[0];
	for (int i = 0; i < len; i++)
		if (*(mas + i) > max)
			max = *(mas + i);
	return max;
}

template <typename T>
T sum(T *mas, int len){
	T ans;
	int index;
	for (int i = 0; i < len; i++)
		if (*(mas + i) > 0)
			index = i;

	for (int i = 0; i < index; i++)
		ans += *(mas + i);
	return ans;
}

template <typename T>
void compact(T *mas, int len){
	T a = 0, b = 50;
	int h = 0;
	for (int i = 0; i < len; i++){
		if ((abs(mas[i]) >= a) and (abs(mas[i]) <= b)){
			for (int k = i+1; k < len; k++){
				mas[k-1] = mas[k];
			}
			mas[len-1] = 0;
		}
	}
}

int main(){
	int mas[10];

	for (int i = 0; i < 10; i++){
		mas[i] = rand()%100;
		cout << mas[i] << " ";
	}

	cout << endl;

	compact(&mas[0], 10);

	for (int i = 0; i < 10; i++){
		cout << mas[i] << " ";
	}

}