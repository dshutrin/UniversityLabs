#include <iostream>
#include <string>

using namespace std;

class AEROFLOT{
public:
    std::string punkt;
    std::string type;
    int number;
};

int posi(std::string a){
    using namespace std;
    char word[(sizeof(a)/6)-1];
    for (int i = 0; i < (sizeof(a)/6)-1; i++){
        word[i] = a[i];
    }
    char azb[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    
    for (int k = 0; k < 26; k++){
        if (word[0] == azb[k]){
            return k;
        }
    }
    
    return -1;
}

string sort(std::string mas[7], int number){
    using namespace std;
    
    int k = -1;
    int *m2 = new int[7];
    for (int i = 0; i < 7; i++)
        m2[i] = i;

    while (mas[k+1] != ""){
        k++;
    }
    k++;
    for (int i = 0; i < 7; i++){
        for (int k = i+1; k < 7; k++){
            if (posi(mas[i]) > posi(mas[k])){
                string l = mas[i];
                mas[i] = mas[k];
                mas[k] = l;
            }
        }
    }
    string ms[7] = {mas[0], mas[1], mas[2], mas[3], mas[4]};

    delete []m2;
    return ms[number];
}

int main(){
    using namespace std;
    AEROFLOT flots[7];
    string *outs = new string[7];
    for (int i = 0; i < 7; i++){
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
    for (int i = 0; i < 7; i++){
        outs[i] = sort(outs, i);
    }
    for (int i = 0; i < 7; i++){
        cout << outs[i] << endl;
    }
    cout << endl << endl;
    string find;
    cout << "Enter find type:" << endl;
    cin >> find;
    bool flag = false;
    for (AEROFLOT a: flots){
        if (a.type == find){
            cout << "Number: " << a.number << " Punkt: " << a.punkt << endl;
            flag = true;
        }
    }
    if (flag == false){
        cout << "Not found!";
    }
    delete [] outs;
}