#include <iostream>
#include <math.h>
#include <List>
using namespace std;

class Number{
	public:

		double value = 0;
		int intPart = 0;
		double fract = 0.0;

		Number (double val = 0.0){
			Number::value = (int)val;
			Number::intPart = (int)val;
		}

		virtual int get_whole() = 0; // получить целую часть
		virtual double get_fraction() = 0; // получить дробную часть
		virtual double get_value() = 0; // получть значение полностью

};

class Integer: public Number{
	public:

		Integer(int var = 0){
			Integer::value = var;
			Integer::intPart = var;
		}

		int get_whole(){
			return Integer::value;
		}

		int get_value(){
			return (int)Integer::value;
		}

		double get_fraction(){
			return 0.0;
		}

		Integer operator = (int var1){
			Integer ans(var1);
			return ans;
		}
};

Integer operator + (Integer var1, Integer var2){
	Integer ans(var1.value + var2.value);
	return ans;
}

Integer operator - (Integer var1, Integer var2){
	Integer ans(var1.value - var2.value);
	return ans;
}

Integer operator * (Integer var1, Integer var2){
	Integer ans(var1.value * var2.value);
	return ans;
}

Integer operator / (Integer var1, Integer var2){
	Integer ans(int(var1.value / var2.value));
	return ans;
}

class Real: public Number{
public:

	Real(double var = 0.0){
		double fractPart, intPart;
		fractPart = modf(var, &intPart);
		Real::value = var;
		Real::intPart = intPart;
		Real::fract = fractPart;
	}

	int get_whole(){
		return Real::intPart;
	}

	double get_fraction(){
		return Real::fract;
	}

	double get_value(){
		return Real::value;
	}

	Real operator = (double var1){
		Real ans(var1);
		return ans;
	}

};

Real operator + (Real var1, Real var2){
	Real ans(var1.value + var2.value);
	return ans;
}

Real operator - (Real var1, Real var2){
	Real ans(var1.value - var2.value);
	return ans;
}

Real operator * (Real var1, Real var2){
	Real ans(var1.value * var2.value);
	return ans;
}

Real operator / (Real var1, Real var2){
	Real ans(var1.value / var2.value);
	return ans;
}

template <class T>
class Series{
private:
	int len = 0;
	T *body;

public:

	Series(int len = 0){
		Series::len = len;
		Series::body = new T[len];
		for (int i = 0; i < len; i++){
			T z(0);
			Series::body[i].value = z.value;
			Series::body[i].fract = z.fract;
			Series::body[i].intPart = z.intPart;
		}
	}

	void set(int index, T var){// установить значение index`ого элемента на значение элемента var
		Series::body[index].value = var.value;
		Series::body[index].fract = var.fract;
		Series::body[index].intPart = var.intPart;
	}

	void show(){
		for (int i = 0; i < Series::len; i++){
			cout << Series::body[i].value << " ";
		}
	}

	void set_all(){
		for (int i = 0; i < Series::len; i++){
			cout << i+1 << ") ";
			double val;
			cin >> val;
			T j(val);
			Series::set(i, j);
		}
	}

	T operator [] (int index){
		return body[index];
	}

};

int main(){

// Integer
	Integer a = 1;
	Integer b = 1234;

	Integer c = a + b;
	cout << "Integer:" << endl << c.value << endl;

	c = a - b;
	cout << c.value << endl;
	c = a * b;
	cout << c.value << endl;
	c = b / a;
	cout << c.value << endl;
	cout << a.get_whole() << "." << a.get_fraction() << endl << endl << "Real:" << endl;

//Real
	Real x = 3.5, y = 1.5, z;
	cout << x.value << " = " << x.intPart << " + " << x.fract << endl;

	z = x - y;
	cout << z.value << endl;

	z = x + y;
	cout << z.value << endl;

	z = x * y;
	cout << z.value << endl;

	z = x / y;
	cout << z.value << endl;

//Series
	cout << endl << "Series:" << endl;
	Series<Integer> mas(3);//Создаем массив длиной 10, изначально он забивается нулями
	mas.show();//вывод массива на экран
	
	cout << endl << mas[0].get_value() << endl;// выводим значение mas[2]

	mas.set_all();//заполнить массив вручную
	mas.show();

	mas.set(2, Integer(4));//присваиваем 3му элементу списка mas значение 4 (mas[2] = 4)
	cout << endl;
	mas.show();
}