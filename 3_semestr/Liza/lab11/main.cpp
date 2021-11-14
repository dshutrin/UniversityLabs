#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
	Triangle Tetragon Move Compare
*/

class Point{
public:
	int x;
	int y;

	void move(int a, int b){
		this->x += a;
		this->y += b;
	}
};

class Factory{
public:
	Factory(){
		void();
	}

	~Factory(){
		void();
	}
};

class Triangle: public Factory{
public:
	Point mas[3];

	Triangle(int x1, int y1, int x2, int y2, int x3, int y3){
		this->mas[0].x = x1;
		this->mas[0].y = y1;

		this->mas[1].x = x2;
		this->mas[1].y = y2;

		this->mas[2].x = x3;
		this->mas[2].y = y3;
	}

	void move(int x, int y){
		for (int i = 0; i < 3; i++)
			this->mas[i].move(x, y);
	}

	void show(){
		for (int i = 0; i < 3; i++){
			cout << this->mas[i].x << " " << this->mas[i].y << endl;
		}
		cout << endl;
	}

	double get_sqare(){
		return abs((this->mas[1].x - this->mas[0].x) * (this->mas[2].y - this->mas[0].y) - (this->mas[2].x - this->mas[0].x) * (this->mas[1].y - this->mas[0].y))/2;
	}

};

class Tetragon: public Factory{
public:
	Point mas[4];

	Tetragon(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
		this->mas[0].x = x1;
		this->mas[0].y = y1;

		this->mas[1].x = x2;
		this->mas[1].y = y2;

		this->mas[2].x = x3;
		this->mas[2].y = y3;

		this->mas[3].x = x4;
		this->mas[3].y = y4;
	}

	void move(int x, int y){
		for (int i = 0; i < 4; i++)
			this->mas[i].move(x, y);
	}

	void show(){
		for (int i = 0; i < 4; i++){
			cout << this->mas[i].x << " " << this->mas[i].y << endl;
		}
		cout << endl;
	}

	double get_sqare(){
		double a = this->mas[0].x * this->mas[1].y; 
		double b = this->mas[1].x * this->mas[2].y;
		double c = this->mas[2].x * this->mas[3].y; 
		double d = this->mas[3].x * this->mas[0].y;

		double a1 = this->mas[1].x * this->mas[0].y;
		double b1 = this->mas[2].x * this->mas[1].y;
		double c1 = this->mas[3].x * this->mas[2].y;
		double d1 = this->mas[0].x * this->mas[3].y;
		
		return abs(a+b+c+d-a1-b1-c1-d1)/2;
	}

};


template <class T>
T compare(T *a, T *b){
	if ((a->get_sqare()) > (b->get_sqare())){
		cout << "1 element is bigger!" << endl;
		return *a;
	}else{
		cout << "2 element is bigger!" << endl;
		return *b;
	}
}


int get_mode(){
	int mode;
	cout << "Choice mode: " << endl;
	cout << "1) add Triangle" << endl;
	cout << "2) add Tetragon" << endl;
	cout << "3) delete Triangle" << endl;
	cout << "4) delete Tetragon" << endl;
	cout << "5) compare Triangles" << endl;
	cout << "6) compare Tetragons" << endl;
	cout << "7) move Triangle" << endl;
	cout << "8) move Tetragon" << endl;
	cout << "9) exit\n>>> ";
	cin >> mode;
	cin.get();
	return mode;
};


int get_int(){
	int val;
	cin >> val;
	cin.get();
	return val;
}


int main(){

	int mode = 0;
	mode = get_mode();

	vector<Triangle> tregs;
	vector<Tetragon> tetrs;

	int count_tr = 0;
	int count_te = 0;


	while (mode != 9){

		if (mode == 1){
			if (count_tr < 2){
				Triangle val(0,0, 0,0, 0,0);
				cout << "Enter Triangle positions(3 x,y): ";
				for (int i = 0; i < 3; i++){
					val.mas[i].x = get_int();
					val.mas[i].y = get_int();
				}

				tregs.push_back(val);
				count_tr++;
	
				cout << "Compleate!\n";
				system("pause");
			}else{
				cout << "You have 2 var of Triangle!\n";
				system("pause");
			}
		}
		if (mode == 2){
			if (count_te < 2){
				Tetragon val(0,0, 0,0, 0,0, 0,0);
				cout << "Enter Tetragon positions(4 x,y): ";
				
				for (int i = 0; i < 4; i++){
					val.mas[i].x = get_int();
					val.mas[i].y = get_int();
				}

				tetrs.push_back(val);
				count_te++;
	
				cout << "Compleate!\n";
			}else{
				cout << "You have 2 var of Tetragon!\n";
			}
			system("pause");
		}
		if (mode == 3){
			cout << "Enter number for delete: ";
			int num = get_int();
			num--;
			if ((num > 0) and (num <= count_tr)){
				tregs.erase(tregs.begin()+num);
				count_tr--;
				cout << "Compleate!\n";
			}else{
				cout << "Index error!\n";
			}
			system("pause");
		}
		if (mode == 4){
			cout << "Enter number for delete: ";
			int num = get_int();
			num--;
			if ((num > 0) and (num <= count_te)){
				tetrs.erase(tetrs.begin()+num);
				count_tr--;
				cout << "Compleate!\n";
			}else{
				cout << "Index error!\n";
			}
			system("pause");
		}
		if (mode == 5){
			if (count_tr == 2){
				Triangle var = compare(&tregs[0], &tregs[1]);
				var.show();
			}else{
				cout << "You haven`t 2 Triangles!\n";
			}
			system("pause");
		}
		if (mode == 6){
			if (count_tr == 2){
				Tetragon var = compare(&tetrs[0], &tetrs[1]);
				var.show();
			}else{
				cout << "You haven`t 2 Tetragons!\n";
			}
			system("pause");	
		}
		if (mode == 7){
			cout << "Enter number for move: ";
			int num = get_int() - 1;
			if ((num > 0) and (num <= count_tr)){
				int x, y;
				cout << "Enter x, y to move: ";
				x = get_int();
				y = get_int();
				tregs[num].move(x, y);
				cout << "Compleate!";
			}else{
				cout << "Index error!\n";
			}
			system("pause");			
		}
		if (mode == 8){
			cout << "Enter number for move: ";
			int num = get_int() - 1;
			if ((num > 0) and (num <= count_te)){
				int x, y;
				cout << "Enter x, y to move: ";
				x = get_int();
				y = get_int();
				tetrs[num].move(x, y);
				cout << "Compleate!";
			}else{
				cout << "Index error!\n";
			}
			system("pause");			
		}

		system("cls");
		mode = get_mode();
	}

}