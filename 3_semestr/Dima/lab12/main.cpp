#include <iostream>
#include <sstream>
#include <string>
#include <list>
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
	Stack<int> st;
	
	st.add(1);
	st.add(3);
	st.add(2);

	while (st.size > 0)
		cout << st.get() << endl;

}