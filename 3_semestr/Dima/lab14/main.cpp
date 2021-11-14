#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main(){

	vector<string> lines;

	ifstream read_file("out.txt");
    if (read_file.is_open()){

        string line;
        while (getline(read_file, line)){
            lines.push_back(line);
        }

    }else{
        cout << "File not open!" << endl;
    }
    read_file.close();

    vector<char> word;
    vector<string> words;
    for (string line: lines){
    	for (char s: line){
    		if ((s != ' ')&&(s != '\n'))
    			word.push_back(s);
    		else{
    			string n_word(word.begin(), word.end());
    			words.push_back(n_word);
    			word.clear();
    		}
    	}
    	string n_word(word.begin(), word.end());
    	words.push_back(n_word);
    	word.clear();
    }

    int len = (words.size()/2)*2;
    cout << len << endl << endl;
    for (int i = 0; i < len; i += 2){
    	cout << words[i+1] << endl << words[i] << endl;
    }
    if (words.size()%2 != 0)
    	cout << words[len];

}