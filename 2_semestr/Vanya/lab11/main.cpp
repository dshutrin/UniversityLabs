#include <iostream>     
#include <iterator>   
#include <algorithm>    
#include <string>
#include <fstream>
using namespace std;

int count(string line){// считает сколько слов в предложении
	int ans = 1;
	if (line[0] == ' ')
		ans--;
	for (char &a: line)
		if (a == ' ')
			ans++;
	return ans;
}

int main () {
	system("chcp 65001");
	int need;
	cout << "Input need len: ";
	cin >> need;
    string s;
    ifstream rsd;
    rsd.open("tx.txt");
    while(!rsd.eof()) {
        getline(rsd,s,'.');
        if (count(s) == need){
        	if (s[0] == ' '){
        		int k = -1;// считаем сколько букв
        		for (char &a: s)//в предложении
        			k++;//без учёта первого пробела
        		for (int i = 1; i <= k; i++){
        			cout << s[i];
        		}
        		cout << endl;
        	}else{
		        cout << s << endl;
        	}
        }
    }
    rsd.close();
    return 0;
}