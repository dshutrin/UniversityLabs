#include <iostream>
#include <string>
using namespace std;

/*
	SymbString		OctString	 operator -(T&, T&)
*/


class Factory {
public:
	Factory(){void();}
	~Factory(){void();}

	virtual void show() {};
	virtual void set_value() {};
};


class SymbString : public Factory {
public:
	string val;

	SymbString(string value="") {
		this->val = value;
	}

	~SymbString() {
		void();
	}

	string get_val() {
		return this->val;
	}

	void set_value(string val) {
		this->val = val;
	}

	void show() {
		cout << this->val;
	}
};

SymbString operator -(SymbString &one, SymbString &other) {
	
	// реализовать вырезание подстроки из строки
	string answer = "";

	string a = one.val;
	string b = other.val;

	int len1 = 0;
	int len2 = 0;
	bool flag = false;

	for (char &counter: a)
		len1++;
	for (char &counter: b)
		len2++;

	if (len2 <= len1){
		
		for (int i = 0; i < len1-len2+1; i++){
			if (a[i] == b[0]){
				flag = true;
				for (int k = 0; k < len2; k++){
					if (a[i+k] != b[k]){
						flag = false;
					}
				}
			}
			if (flag == true){
				a = a.erase(i, len2);
				return SymbString(a);
			}
		}

	}
	return SymbString(a);
}

class OctString : public Factory {
public:
	int val;

	OctString(int value=00) {
		this->val = value;
	}

	~OctString() {
		void();
	}

	int get_val() {
		return this->val;
	}

	void set_value(int val) {
		this->val = val;
	}

	void show() {
		cout << this->val;
	}

};

OctString operator -(OctString& one, OctString& other) {
	return OctString(one.val - other.val);
}

std::ostream& operator<< (std::ostream& out, const SymbString& obj){
	out << obj.val;
	return out;
}

std::ostream& operator<< (std::ostream& out, const OctString& obj) {
	out << obj.val;
	return out;
}

int main() {

	int count_s = 0;
	int count_o = 0;

	SymbString *s_1 = new SymbString;
	SymbString *s_2 = new SymbString;
	OctString *o_1 = new OctString;
	OctString *o_2 = new OctString;
	system("cls");

	int mode = 0;
	cout << "Choice program mode:\n1) Create var\n2) Delete var\n3) Show vars value\n4) Use operator ( operator - )\n5) Close program\n>>> ";
	cin >> mode;

	while (mode != 5) {

		if (mode == 1) {

			cout << "Choice var type:\n1) SymbString\n2) OctString\n>>> ";
			int sub_mode = 0;
			cin >> sub_mode;
			cin.get();

			if (sub_mode == 1) {
				if (count_s < 2) {

					string new_value;
					cout << "Enter string value from var: ";
					getline(cin, new_value);
					system("cls");

					if (count_s == 0) {
						s_1->set_value(new_value);
						count_s++;
					}
					else {
						if (count_s == 1) {
							s_2->set_value(new_value);
							count_s++;
						}
					}
				}
				else {
					system("cls");
					cout << "Limit SymbString vars!\n\n";
				}
			}
			else {
				if (sub_mode == 2) {
					if (count_o < 2) {

						int new_value_int;
						cout << "Enter int(oct) value from var: ";
						cin >> new_value_int;
						system("cls");

						if (count_o == 0) {
							o_1->set_value(new_value_int);
							count_o++;
						}
						else {
							if (count_o == 1) {
								o_2->set_value(new_value_int);
								count_o++;
							}
						}
					}
					else {
						system("cls");
						cout << "Limit OctString vars!\n\n";
					}
				}
			}
		}
		else {
			if (mode == 2) {

				int type = 0;
				int number = 0;

				system("cls");
				cout << "What type var delete?\n1) SymbString\n2) OctString\n>>>";
				cin >> type;

				if (type == 1){
					if (count_s > 0){
						if (count_s == 1){
							delete s_1;
							count_s--;
						}else{
							if (count_s == 2){
								delete s_2;
								count_s--;
							}
						}
					}else{
						system("cls");
						cout << "You have not SymbString vars!\n\n";
					}
				}else{
					if (type == 2){
						if (count_o > 0){
							if (count_o == 1){
								delete o_1;
								count_o--;
							}else{
								if (count_o == 2){
									delete o_2;
									count_o--;
								}
							}
						}else{
							system("cls");
							cout << "You have not OctString vars!\n\n";
						}
					}
				}

			}
			else {
				if (mode == 3) {

					system("cls");

					if (count_s >= 1) {
						cout << "SymbString 1: " << s_1->get_val() << endl;
					}
					if (count_s == 2) {
						cout << "SymbString 2: " << s_2->get_val() << endl;
					}
					if (count_o >= 1) {
						cout << "OctString 1: " << o_1->get_val() << endl;
					}
					if (count_o == 2) {
						cout << "OctString 2: " << o_2->get_val() << endl;
					}

					cout << endl << endl;

				}
				else {
					if (mode == 4) {
						
						int n_type;
						cout << "Choice var type for use operator:\n1) SymbString\n2) OctString\n>>> ";
						cin >> n_type;

						if (n_type == 1) {
							if (count_s == 2) {
								system("cls");
								cout << "Answer: " << *s_1 - *s_2 << endl << endl;
							}else{
								system("cls");
								cout << "You haven`t 2 vars!\n";
							}
						}else{
							if (n_type == 2) {
								if (count_o == 2) {
									
									system("cls");
									cout << "Answer: " << *o_1 - *o_2 << endl << endl;

								}else{
									system("cls");
									cout << "You haven`t 2 vars!\n";
								}
							}
						}
					}
				}
			}
		}

		cout << "Choice program mode:\n1) Create var\n2) Delete var\n3) Show vars value\n4) Use operator ( operator - )\n5) Close program\n>>> ";
		cin >> mode;

	}
}