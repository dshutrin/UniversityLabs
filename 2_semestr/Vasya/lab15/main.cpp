#include <iostream>
#include <vector>
using namespace std;

class Line_mas{
public:

	Line_mas(){
		Line_mas::count = 0;
	}

	void append(string line){
		Line_mas::body.push_back(line);
		Line_mas::count++;
	}

	void show(){
		for (int i = 0; i < Line_mas::count; i++)
			cout << Line_mas::body[i] << endl;
	}

	int len(){
		return Line_mas::count;
	}

	bool in(string val){
		bool ans = 0;
		for (int i = 0; i < Line_mas::count; i++){
			if (Line_mas::body[i] == val){
				ans = 1;
				break;
			}
		}
		return ans;
	}

	string operator [] (int index){
		string ans = "NULL";
		if (Line_mas::count > 0){
			if ((index >= 0) && (index <= Line_mas::count-1))// контроль выхода за пределы массива
				ans = Line_mas::body[index];
		}
		return ans;
	}

	Line_mas operator & (Line_mas a) {// слияние с исключением повторений
		Line_mas n_mas;
		for (int i = 0; i < Line_mas::count; i++){
			if (n_mas.in(Line_mas::body[i]) == 0)
				n_mas.append(Line_mas::body[i]);
		}
		for (int i = 0; i < a.len(); i++){
			if (n_mas.in(a[i]) == 0)
				n_mas.append(a[i]);
		}
		return n_mas;
	}

	Line_mas operator + (Line_mas a) {// простое слияние
		Line_mas n_mas;
		for (int i = 0; i < Line_mas::count; i++){
			n_mas.append(Line_mas::body[i]);
		}
		for (int i = 0; i < a.len(); i++){
			n_mas.append(a[i]);
		}
		return n_mas;
	}

private:
	int count;
	vector<string> body = new vector<string>;
};

int main(){
	Line_mas lines1;
	Line_mas lines2;

	lines1.append("Hello world");

	lines2.append("Hello world");
	lines2.append("Hello friends"); 

	Line_mas nn;
	nn = lines1 + lines2;

	Line_mas nn2;
	nn2 = lines1 & lines2;

	nn.show();
	cout << endl;
	nn2.show();
}