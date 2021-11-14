#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
	студенческая группа
	добавление, удаление студентов
	поиск по параметрам
*/

class Student{
public:
	int age;
	string name, surname, phone;
};

class Group{
public:
	string name;
	vector<Student> students;

	Group(string name){
		this->name = name;
		cout << "Group created with name " << name << endl;
	}

	void add_student(){

		system("cls");
		Student student;

		cout << "Enter student name: ";
		getline(cin, student.name);

		cout << "Enter student surname: ";
		getline(cin, student.surname);

		cout << "Enter student age: ";
		cin >> student.age;
		cin.get();

		cout << "Enter student phone: ";
		getline(cin, student.phone);

		this->students.push_back(student);
	};

	void delete_studednt(){
		system("cls");
		this->show();
		int i = 0, age, pos = -1;
		string name, surname;
		cout << "Enter deleting student name: ";
		getline(cin, name);
		cout << "Enter deleting student surname: ";
		getline(cin, surname);
		cout << "Enter deleting student age: ";
		cin >> age;
		cin.get();

		for (Student &a: this->students){
			if ((a.name == name) and (a.surname == surname) and (a.age == age)){
				pos = i;
			}
			i++;
		}

		if (pos != -1){
			this->students.erase(this->students.begin()+pos);
			cout << "Student deleted!" << endl;
		}else{
			cout << "Student not found!" << endl;
		}
	}

	void show(){
		system("cls");
		cout << "Group " << this->name << "students:" << endl;
		for (Student &a: this->students){
			cout << a.name << " " << a.surname << " " << a.age << " " << a.phone << endl;
		}
	}

	void search_from_name(){
		system("cls");
		string value;
		cout << "Enter searched student name: ";
		getline(cin, value);

		for (Student &a: this->students){
			if (value == a.name){
				cout << a.name << " " << a.surname << " " << a.age << endl;
			}
		}
	}

	void search_from_surname(){
		system("cls");
		string value;
		cout << "Enter searched student surname: ";
		getline(cin, value);

		for (Student &a: this->students){
			if (value == a.surname){
				cout << a.name << " " << a.surname << " " << a.age << endl;
			}
		}
	}

	void search_from_age(){
		system("cls");
		int value;
		cout << "Enter searched student age: ";
		cin >> value;
		cin.get();

		for (Student &a: this->students){
			if (value == a.age){
				cout << a.name << " " << a.surname << " " << a.age << endl;
			}
		}
	}

	void search_from_phone(){
		system("cls");
		string value;
		cout << "Enter searched student phone: ";
		getline(cin, value);

		for (Student &a: this->students){
			if (value == a.phone){
				cout << a.name << " " << a.surname << " " << a.age << endl;
			}
		}
	}
};

int get_mode(){
	int mode;
	cout << "Choice mode: " << endl;
	cout << "1) add student" << endl;
	cout << "2) delete student" << endl;
	cout << "3) search student with name" << endl;
	cout << "4) search student with surname" << endl;
	cout << "5) search student with phone" << endl;
	cout << "6) search student with age" << endl;
	cout << "7) show students" << endl;
	cout << "8) exit\n>>> ";
	cin >> mode;
	cin.get();
	return mode;
};

int main(){
	string name;
	cout << "Enter group name: ";
	getline(cin, name);

	Group my_group(name);
	int mode = get_mode();

	while (mode != 8){
		if (mode == 1){
			my_group.add_student();
		}
		if (mode == 2){
			my_group.delete_studednt();
		}
		if (mode == 3){
			my_group.search_from_name();
			system("pause");
		}
		if (mode == 4){
			my_group.search_from_surname();
			system("pause");
		}
		if (mode == 5){
			my_group.search_from_phone();
			system("pause");
		}
		if (mode == 6){
			my_group.search_from_age();
			system("pause");
		}
		if (mode == 7){
			my_group.show();
			system("pause");
		}

		system("cls");
		mode = get_mode();
	}
}