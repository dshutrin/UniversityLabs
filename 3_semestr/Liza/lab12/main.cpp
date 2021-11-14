#include <iostream>
#include <string>
#include <vector>
using namespace std;


template <class T>
class Set{
private:
	void sort(){
		for (int i = 0; i < this->count; i++){
			for (int k = i+1; k < this->count; k++){
				if (this->body[i] > this->body[k]){
					T a1 = this->body[i];
					this->body[i] = this->body[k];
					this->body[k] = a1;
				}
			}
		}
	}
public:
	vector<T> body;
	int count = 0;

	void add(T val){
		bool flag = false;
		for (T &a: this->body)
			if (a == val)
				flag = true;
		if (flag == false){
			this->body.push_back(val);
			this->count++;
			this->sort();
		}
	}	

	void show(){
		for (T &a: this->body)
			cout << a << endl;
	}

	T operator[](int index){
		return this->body[index];
	}
};


int main(){
	Set<string> my_set;

	my_set.add("Dmitry");
	my_set.add("Elizaveta");
	my_set.add("Arseny");
	my_set.add("Ekaterina");
	my_set.add("Tatyana");
	my_set.add("Evgeny");
	my_set.add("Alex");
	my_set.add("Nikita");
	my_set.add("Alex");

	my_set.show();
}