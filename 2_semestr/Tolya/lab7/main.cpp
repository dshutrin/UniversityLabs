#include <iostream>
#include <string>

using namespace std;

struct AEROFLOT {
    std::string punkt;
    std::string type;
    int number;
};

int posi(std::string a) {
    using namespace std;
    char word[(sizeof(a) / 6) - 1];
    for (int i = 0; i < (sizeof(a) / 6) - 1; i++) {
        word[i] = a[i];
    }
    char azb[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };

    for (int k = 0; k < 26; k++) {
        if (word[0] == azb[k]) {
            return k;
        }
    }

    return -1;
}

string sort(std::string mas[5], int number) {
    using namespace std;

    int k = -1;
    int* m2 = new int[5];
    for (int i = 0; i < 5; i++)
        m2[i] = i;

    while (mas[k + 1] != "") {
        k++;
    }
    k++;
    for (int i = 0; i < 5; i++) {
        for (int k = i + 1; k < 5; k++) {
            if (posi(mas[i]) > posi(mas[k])) {
                string l = mas[i];
                mas[i] = mas[k];
                mas[k] = l;
            }
        }
    }

    delete[]m2;
    return mas[number];
}

int main() {
    system("chcp 65001");
    using namespace std;
    AEROFLOT *flots = new AEROFLOT[5];
    string* outs = new string[5];
    for (int i = 0; i < 5; i++) {
        cout << "Enter reis number: ";
        cin >> flots[i].number;
        cout << "Enter reis type: ";
        cin >> flots[i].type;
        cout << "Enter reis punkt: ";
        cin >> flots[i].punkt;
        cout << "\n\n";
        outs[i] = flots[i].punkt;
    }
    system("cls");
    for (int i = 0; i < 5; i++) {
        outs[i] = sort(outs, i);
    }
    for (int i = 0; i < 5; i++) {
        cout << outs[i] << endl;
    }
    cout << endl << endl;
    string find;
    cout << "Enter find type:" << endl;
    cin >> find;
    bool flag = false;
    for (int i = 0; i < 5; i++) {
        if (flots[i].type == find) {
            cout << "Number: " << flots[i].number << " Punkt: " << flots[i].punkt << endl;
            flag = true;
        }
    }
    if (flag == false) {
        cout << "Not found!";
    }
    delete[] flots;
    delete[] outs;
}