#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Solution{
public:
	virtual void answers() = 0;//вывод ответов
	virtual void compute() = 0;//вычисление корней
};

class Square: public Solution{
private:
	double a, b, c, x1, x2;
	int have_ans;//сколько корней (0, 1 или 2)
public:

	Square(double a, double b, double c){
		Square::a = a;
		Square::b = b;
		Square::c = c;
		Square::have_ans = 0;
	}

	void compute(){
		double D = Square::b*Square::b - (4*Square::a*Square::c);
		if (D < 0){
			void();
		}else{
			if (D == 0){
				Square::have_ans = 1;
				Square::x1 = (-Square::b)/(2*Square::a);
			}else{
				if (D > 0){
					Square::have_ans = 2;
					Square::x1 = (-Square::b-sqrt(D))/(2*Square::a);
					Square::x1 = (-Square::b+sqrt(D))/(2*Square::a);
				}
			}
		}
	}

	void answers(){
		if (Square::have_ans == 0){
			cout << "Haven`t answers!\n";
		}else{
			if (Square::have_ans == 1){
				cout << "x = " << Square::x1 << endl;
			}else{
				if (Square::have_ans == 2){
					cout << "x1 = " << Square::x1 << "\nx2 = " << Square::x2 << endl;
				}
			}
		}
		
	}
};

class Linear: public Solution{
private:
	double a, b, x;
public:
	Linear(double a, double b){
		Linear::a = a;
		Linear::b = b;
	}

	void compute(){
		Linear::x = -Linear::b / Linear::a;//x = -b/a
	}

	void answers(){
		cout << "x = " << Linear::x << endl;
	}
};

template <class T>
class Series{
private:
	int len;
	vector<T> body;
public:

	void add(T obj){//добавлени уравнения в массив
		Series::body.push_back(obj);
		Series::len = 1;
	}

	T* operator [](int index){//возвращает указатель на уравнене по индексу
		T* ans = &Series::body[0];
		if (Series::len > index){
			ans = &Series::body[index];
		}
		return ans;
	}

};


int main(){
	Square ur1(-4, 1, 5.21);//-4x^2 + x + 5.21 = 0
	ur1.compute();
	ur1.answers();

	Linear ur2(2, 4);//2x + 4 = 0
	ur2.compute();
	ur2.answers();

	cout << endl << endl;

	Series<Square> mas;
	mas.add(ur1);
	mas[0]->compute();
	mas[0]->answers();

	Series<Linear> mas2;
	mas2.add(ur2);
	mas2[0]->compute();
	mas2[0]->answers();
}