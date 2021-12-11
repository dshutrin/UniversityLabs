#include <iostream>
#include <string>
#include <list>
#include <conio.h>
using namespace std;

template <class T>
class Stack{
public:
	list<T> body;
	int max_size, size = 0;

	Stack(int val=10){
		this->max_size = val;
	}

	void add(T val){
		if (this->size < this->max_size){
			this->body.push_back(val);
			this->size++;
		}else{
			cout << "Stack is full" << endl;
		}
	}

	T get(){
		if (this->size > 0){
			T ans = this->body.back();
			this->body.pop_back();
			this->size--;
			return ans;
		}else{
			return T();
		}
	}
};

int main(){
	system("chcp 65001");
	system("cls");

	Stack<int> st;		int a;
	Stack<double> st1;	double b;
	Stack<string> st2;	string s;

	int menu = 0;
	while (menu != 4){
		cout << "Выберите, с каким типом даннных вы хотите работать:\n1) int\n2) double\n3) string\n4) Exit" << endl;
		cin >> menu;
		cin.get();

		if (menu == 1){
			bool good = true;
			cout << "Введите число (int): ";
			while (!(cin >> a)){
				cout << "error\n";
        		cin.clear();      
        		fflush(stdin);  
			}
			
			st.add(a);
		}

		if (menu == 2){
			bool good = true;
			cout << "Введите число (double): ";
			while (!(cin >> b)){
				cout << "error\n";
        		cin.clear();      
        		fflush(stdin);  
			}
			st1.add(b);
		}

		if (menu == 3){
			getline(cin, s);
			while (cin.fail()){
				cin.clear();
				getline(cin, s);
			};
			st2.add(s);
		}
		system("cls");
	}

	cout << "INT: ";
	while(st.size > 0){
		cout << st.get() << " ";
	}
	cout << endl << "DOUBLE: ";

	while (st1.size > 0){
		cout << st1.get() << " ";
	}
	cout << endl << "STRING: ";

	while (st2.size > 0){
		cout << st2.get() << " ";
	}
	cout << endl;
}
