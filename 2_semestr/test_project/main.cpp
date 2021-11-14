#include <iostream>
using namespace std;

class Program {
private:
	string name;
public:
	
	void set_name(string new_name) {
		this->name = new_name;
	}

	void start() {
		cout << this->name;
	}
};



int main() {
	Program object;

	object.set_name("Dmitry");
	object.start();
}