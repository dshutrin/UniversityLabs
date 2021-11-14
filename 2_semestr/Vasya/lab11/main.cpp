#include <iostream>
#include <fstream>
using namespace std;

bool is_digit(char x){
	char mas[10] = {'0','1','2','3','4','5','6','7','8','9'};
	bool ans = false;
	for (char &a: mas)
		if (a == x)
			ans = true;
	return ans;
}

int main(){
	ifstream file("data.txt");
	string line = "";

	while (getline(file, line)){
		int ans = 0;
		if (line.length() > 2){
			for (int i = 1; i < line.length()-2; i++){
				if ((is_digit(line[i-1]) == 0) & (is_digit(line[i]) == true) & (is_digit(line[i+1]) == true) & (is_digit(line[i+2]) == 0)){
					ans = 1;
				}
			}
			if ((is_digit(line[0]) == 1) & (is_digit(line[1]) == 1) & (is_digit(line[2]) == 0)){
				ans = 1;
			}
			if ((is_digit(line[line.length()-1]) == 1) & (is_digit(line[line.length()-2]) == 1) & (is_digit(line[line.length()-3]) == 0)){
				ans = 1;
			}
		}

		if (line.length() == 2){
			if ((is_digit(line[0]) == 1) & (is_digit(line[1]) == 1)){
				ans = 1;
			}
		}

		if (ans == 1){
			cout << line << endl;
		}
		
	}

}