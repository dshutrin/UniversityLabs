#include <iostream>
#include <vector>
using namespace std;

class Triad{
public:
	
	int first, second, thrid;

	Triad(int a = 0, int b = 0, int c = 0){
		Triad::first = a;
		Triad::second = b;
		Triad::thrid = c;
	}

	virtual void add_first(){};
	virtual void add_second(){};
	virtual void add_third(){};
	virtual void normalize(){};
};

class Date: public Triad{// считается, что в каждом месяце по 30 дней
public:

	Date(int a = 0, int b = 0, int c = 0){
		Date::first = a;
		Date::second = b;
		Date::thrid = c;
		Date::normalize();
	}

	void info(){
		Date::normalize();
		cout << "Date: " << Date::first << "/" << Date::second << "/" << Date::thrid << endl;
	}

	void add_first(){
		Date::first++;
		Date::normalize();
	}

	void add_second(){
		Date::second++;
		Date::normalize();
	}

	void add_third(){
		Date::thrid++;
		Date::normalize();
	}

	void normalize(){
		if (Date::thrid > 30){
			Date::thrid = 1;
			Date::second++;
		}
		if (Date::second > 12){
			Date::second = 1;
			Date::first++;
		}
	}
};

class Time: public Triad{
public:

	Time(int a = 0, int b = 0, int c = 0){
		Time::first = a;
		Time::second = b;
		Time::thrid = c;
	}

	void add_first(){
		Time::first++;
		Time::normalize();
	}

	void add_second(){
		Time::second++;
		Time::normalize();
	}

	void add_third(){
		Time::thrid++;
		Time::normalize();
	}

	void normalize(){
		if (Time::thrid > 59){
			Time::thrid = 0;
			Time::second++;
		}
		if (Time::second > 59){
			Time::second = 0;
			Time::thrid = 0;
			Time::first++;
		}
		if (Time::first > 23){
			Time::first = 0;
			Time::second = 0;
			Time::thrid = 0;
		}
	}

	void info(){
		Time::normalize();
		cout << "Time: " << Time::first << ":" << Time::second << ":" << Time::thrid << endl;
	}
};

class Memories{
private:
	int len;
	vector<int> body;
public:
	Memories (Date date, Time time){
		Memories::add(date, time);
		Memories::len = 1;
	}

	void add(Date date, Time time){
		Memories::body.push_back(date.first);
		Memories::body.push_back(date.second);
		Memories::body.push_back(date.thrid);
		Memories::body.push_back(time.first);
		Memories::body.push_back(time.second);
		Memories::body.push_back(time.thrid);
		Memories::len += 1;
	}

	void show_first_date(){
		cout << "First date:" << endl;
		int find_i = 0;
		Date n_date; Time n_time;
		for (int i = 0; i < Memories::len; i++){
			if (i == 0){
				find_i = i;
				n_date = Date(Memories::body[find_i*6 + 0], Memories::body[find_i*6 + 1], Memories::body[find_i*6 + 2]);
				n_time = Time(Memories::body[find_i*6 + 3], Memories::body[find_i*6 + 4], Memories::body[find_i*6 + 5]);
			}else{
			if (Memories::body[i*6 + 0] < n_date.first){
				find_i = i;
			}else{
			if (Memories::body[i*6 + 0] == n_date.first){

			if (Memories::body[i*6 + 1] < n_date.second){
				find_i = i;
			}else{
			if (Memories::body[i*6 + 1] == n_date.second){

			if (Memories::body[i*6 + 2] < n_date.thrid){
				find_i = i;
			}else{
			if (Memories::body[i*6 + 2] == n_date.thrid){

			if (Memories::body[i*6 + 3] < n_time.first){
				find_i = i;
			}else{
			if (Memories::body[i*6 + 3] == n_time.first){

			if (Memories::body[i*6 + 4] < n_time.second){
				find_i = i;
			}else{
			if (Memories::body[i*6 + 4] == n_time.second){

			if (Memories::body[i*6 + 5] < n_time.thrid){
				find_i = i;
			}}}}}}}}}}}}
		}
		n_date = Date(Memories::body[find_i*6 + 0], Memories::body[find_i*6 + 1], Memories::body[find_i*6 + 2]);	
		n_time = Time(Memories::body[find_i*6 + 3], Memories::body[find_i*6 + 4], Memories::body[find_i*6 + 5]);
		n_date.info();
		n_time.info();
	}

	void show_last_date(){
		cout << "Last date:" << endl;
		int find_i = 0;
		Date n_date; Time n_time;
		for (int i = 0; i < Memories::len; i++){
			if (i == 0){
				find_i = i;
				n_date = Date(Memories::body[find_i*6 + 0], Memories::body[find_i*6 + 1], Memories::body[find_i*6 + 2]);
				n_time = Time(Memories::body[find_i*6 + 3], Memories::body[find_i*6 + 4], Memories::body[find_i*6 + 5]);
			}else{
			if (Memories::body[i*6 + 0] > n_date.first){
				find_i = i;
			}else{
			if (Memories::body[i*6 + 0] == n_date.first){

			if (Memories::body[i*6 + 1] > n_date.second){
				find_i = i;
			}else{
			if (Memories::body[i*6 + 1] == n_date.second){

			if (Memories::body[i*6 + 2] > n_date.thrid){
				find_i = i;
			}else{
			if (Memories::body[i*6 + 2] == n_date.thrid){

			if (Memories::body[i*6 + 3] > n_time.first){
				find_i = i;
			}else{
			if (Memories::body[i*6 + 3] == n_time.first){

			if (Memories::body[i*6 + 4] > n_time.second){
				find_i = i;
			}else{
			if (Memories::body[i*6 + 4] == n_time.second){

			if (Memories::body[i*6 + 5] > n_time.thrid){
				find_i = i;
			}}}}}}}}}}}}
		}
		n_date = Date(Memories::body[find_i*6 + 0], Memories::body[find_i*6 + 1], Memories::body[find_i*6 + 2]);	
		n_time = Time(Memories::body[find_i*6 + 3], Memories::body[find_i*6 + 4], Memories::body[find_i*6 + 5]);
		n_date.info();
		n_time.info();
	}

	void info(){
		cout << Memories::len << endl;
		for (int i = 0; i < Memories::len; i++){
			cout << "Datetime: ";
			for (int k = 0; k < 3; k++){
				cout << Memories::body[i*6 + k] << "/";
			}
			cout << " ";
			for (int k = 3; k < 5; k++){
				cout << Memories::body[i*6 + k] << ":";
			}
			cout << Memories::body[i*6 + 5];
			cout << endl;
		}
	}
};

int main(){

	cout << "==========================" << endl;
	Date a(2021, 11, 1);
	a.info();
	for (int i = 0; i < 60; i++)//добавляем 60 дней (2 месяца)
		a.add_third();
	a.info();

	cout << "==========================" << endl;
	Time c(0, 0, 0);
	c.info();
	for (int i = 0; i < 60; i++)//добавляем 60 сек (1 мин)
		c.add_third();
	c.info();

	cout << "==========================" << endl;
	Memories ff(Date(2021, 6, 10), Time(10, 11, 12));
	ff.info();

	cout << "==========================" << endl;
	ff.add(Date(2021, 6, 10), Time(10, 11, 13));
	ff.info();

	cout << "==========================" << endl;
	ff.show_first_date();
	ff.show_last_date();
}