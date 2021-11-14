#include <iostream>
#include <list>
#include <string>

using namespace std;

class Date{
public:

	int day, month, year;

	Date(int day=0, int month=0, int year=0){
		this->day = day;
		this->month = month;
		this->year = year;
	}
};

class Request{
public:
	string punkt;
	Date date;
	int number;
	string name;
	string surname;
	string patronymic;

	Request(string punkt = "", Date date = Date(0,0,0), int number = 0, string name = "", string surname = "", string patronymic = ""){
		this->punkt = punkt;
		this->date = date;
		this->number = number;
		this->name = name;
		this->surname = surname;
		this->patronymic = patronymic;
	}
};

int get_mode(){
	system("cls");
	int new_mode = 0;
	cout << "Choice action:\n1) Add request\n2) Delete request\n3) Show requests with date\n4) Show requests with number\n5) Show all requests\n6) Exit\n>>> ";
	while (new_mode == 0){
		cin.clear();
		cin >> new_mode;
	}
	return new_mode;
}

Request get_request(){
	string punkt;
	Date date;
	int number;
	string name;
	string surname;
	string patronymic;

	cout << "Enter punkt: " << endl;
	getline(cin, punkt);
	cout << "Enter date(10 06 2002): " << endl;
	cin >> date.day; cin >> date.month; cin >> date.year;
	cout << "Enter reis number: " << endl;
	cin >> number;
	cout << "Enter your name: " << endl;
	cin >> name;
	cout << "Enter your surname: " << endl;
	cin >> surname;
	cout << "Enter your patronymic: " << endl;
	cin >> patronymic;

	return Request(punkt, date, number, name, surname, patronymic);
}

int main(){
	list<Request> requests;
	int mode = 0;


	while (mode != 6){
		mode = get_mode();
		cin.get();
		if (mode == 1){
			requests.push_back(get_request());
			cout << "Success!" << endl;
			system("pause");
		}else{
			if (mode == 2){
				cout << "Enter reis number from delete: " << endl;
				int num, pos = 0, flag = 0;
				cin >> num;
				list<Request> new_list;
				for (Request &req: requests){
					if (req.number != num)
						new_list.push_back(req);
				}
				requests.clear();
				requests = new_list;
				system("pause");
			}else{
				if (mode == 3){
					cout << "Enter reis date from search: " << endl;
					int day, month, year;
					cin >> day; cin >> month; cin >> year;
					for (Request &req: requests){
						if ((req.date.day == day) && (req.date.month == month) && (req.date.year == year)){
							cout << "Punkt: " << req.punkt << endl;
							cout << "Date: " << req.date.day << " " << req.date.month << " " << req.date.year << endl;
							cout << "Number: " << req.number << endl;
							cout << "Name: " << req.name << endl;
							cout << "Surname: " << req.surname << endl;
							cout << "Patronymic: " << req.patronymic << endl << endl << endl;
						}
					}
					system("pause");
				}else{
					if (mode == 4){
						cout << "Enter reis number from search: " << endl;
						int num;
						cin >> num;
						for (Request &req: requests){
							if (req.number == num){
								cout << "Punkt: " << req.punkt << endl;
								cout << "Date: " << req.date.day << " " << req.date.month << " " << req.date.year << endl;
								cout << "Number: " << req.number << endl;
								cout << "Name: " << req.name << endl;
								cout << "Surname: " << req.surname << endl;
								cout << "Patronymic: " << req.patronymic << endl << endl << endl;
							}
						}
						system("pause");
					}else{
						if (mode == 5){
							for (Request &a: requests){
								cout << "Punkt: " << a.punkt << endl;
								cout << "Date: " << a.date.day << " " << a.date.month << " " << a.date.year << endl;
								cout << "Number: " << a.number << endl;
								cout << "Name: " << a.name << endl;
								cout << "Surname: " << a.surname << endl;
								cout << "Patronymic: " << a.patronymic << endl << endl << endl;
							}
							system("pause");
						}
					}
				}
			}
		}
	}

}