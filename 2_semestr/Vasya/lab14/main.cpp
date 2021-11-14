#include <iostream>
#include <list>
using namespace std;

struct STR{
	string word = "Hello";
	list<int> numbers;
};

int main(){
	list<STR> my_list;

	int count;
	cout << "Enter ptrs count: ";
	cin >> count;

	for (int i = 0; i < count; i++){
		STR tptr;
		int len = 11;
		cout << "Enter ptr word: ";
		cin >> tptr.word;
		while (len > 10 || len < 0){
			cout << "Enter, how many pages have this ptr(1-10): ";
			cin >> len;
		}
		for (int k = 0; k < len; k++){
			int in;
			cout << "Enter " << i+1 << "`s number for this ptr: ";
			cin >> in;
			tptr.numbers.push_back(in);
		}
		my_list.push_back(tptr);
	}

	int mode = 0;

	while (mode != 2){
		cout << "Choice action:\n1 - find numbers from word\n2 - exit\n>>> " << endl;

		cin >> mode;

		if (mode == 1){
			string find;
			cout << "Enter sought word: ";
			cin >> find;
			cout << "Pages: ";
			int flag = 0;
			for (STR &a: my_list)
				if (a.word == find){
					flag = 1;
					for (int &b: a.numbers)
						cout << b << " ";
				}
			if (flag == 0)
				cout << "not found!";
			cout << endl;
			mode = 0;
		}
	}
}