#include <iostream>
#include <cmath>
using namespace std;

class Program {
private:
	bool map[100][100];
	double distance, game = true;
	int tx, ty, x, y, i = 0;

	double dist(int x1, int y1, int x2, int y2) {//расстояние до необходимых координат
		return sqrt(abs(x2 - x1) * abs(x2 - x1) + abs(y2 - y1) * abs(y2 - y1));
	}

	void clear_mas() {//очищаем карту
		for (int j = 0; j < 100; j++) {
			for (int k = 0; k < 100; k++) {
				Program::map[j][k] = 0;
			}
		}
	}

	void set_points() {//создание точки, которую ищем
		Program::tx = rand() % 100; Program::ty = rand() % 100;
		Program::map[Program::tx][Program::ty] = 1;
	}

	void init() {//создание карты
		clear_mas();
		set_points();
	}

	void input() {//ввод координат с клавиатуры с защитой от дурака
		cout << "Enter your x(int): ";
		while (!(cin >> Program::x)) {
			cout << "FAIL INPUT\n";
			cin.clear();
			cin.sync();
			cout << "Enter your x(int): ";
		}
		cin.clear();
		cin.sync();
		cout << "Enter your y(int): ";
		while (!(cin >> Program::y)) {
			cout << "FAIL INPUT\n";
			cin.clear();
			cin.sync();
			cout << "Enter your y(int): ";
		}
		cin.clear();
		cin.sync();
	}

public:
	void run() {

		Program::init();
		Program::input();

		distance = Program::dist(Program::x, Program::y,
			Program::tx, Program::ty);

		if (not((Program::x == Program::tx) and (Program::y == Program::ty))) {
			cout << "\n-===MISS===-\n\n";
			Program::i++;
			while ((not((Program::x == Program::tx) and (Program::y == Program::ty))) and (Program::game == 1)) {
				if (Program::i == 10) {
					Program::game = false;
				}
				if (Program::game == 1) {
					Program::input();
					if (not((Program::x == Program::tx) and (Program::y == Program::ty))) {
						if (Program::dist(Program::x, Program::y, Program::tx, Program::ty) < distance) {
							cout << "nearer!\n";//если новые координаты ближе предыдущих
						}
						else {
							if (Program::dist(Program::x, Program::y, Program::tx, Program::ty) > distance) {
								cout << "further!\n";//если новые координаты дальше предыдущих
							}
						}
						cout << "\n-===MISS===-\n\n";
					}
					distance = Program::dist(Program::x, Program::y, Program::tx, Program::ty);
					Program::i++;
				}
			}
		}
		if (((Program::x == Program::tx) and (Program::y == Program::ty)) or (Program::game == true))
			cout << "!!!YOU WIN!!!";
		else
			cout << "!!!YOU LOSE!!!";
		cout << "\nCoordinates: ";
		cout << Program::tx << " " << Program::ty;
	}
};

int main() {
	Program val;
	val.run();
}