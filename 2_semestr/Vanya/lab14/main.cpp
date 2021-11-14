#include <iostream>
#include <vector>
using namespace std;

struct File{
	int size, start;
	string name;

	File(int size, string name){
		File::size = size;
		File::name = name;
	}
};

int search(File file, bool mas[]){
	for (int i = 0; i < 368640 - file.size; i++){
		int ans = i;
		for (int k = i; k < file.size; k++){
			if (mas[k] == 1)
				ans = -1;
		}
		if (ans != -1)
			return ans;
	}
	return -1;
}

int main(){
	bool mas[368640];
	string name; int size;
	for (bool &a: mas)
		a = false;

	vector<File> files;

	cin >> size;
	cin >> name;
	File a(size, name);
	if ((search(a, mas)) != -1){
		a.start = search(a, mas);
		for (int i = a.start; i < (a.start + a.size); i++)
			mas[i] = 1;
		files.push_back(a);
	}

	for (File &file: files)
		cout << file.name << " " << file.start << "-" << file.start+file.size-1 << endl;

	cin >> name;
	for (File &file: files){
		if (file.name == name){
			for (int i = file.start; i < file.start+file.size; i++)
				mas[i] = 0;
			cout << "Deleted!";
		}
	}

	for (bool &a: mas)
		cout << a << " ";
}