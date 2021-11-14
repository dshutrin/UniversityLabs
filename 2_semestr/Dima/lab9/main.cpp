#include <iostream>
using namespace std;

void fill_array(int *arr, int len){
    int count = 0;
    for (int i = 0; i < len; i++){
        for (int k = 0; k < len; k++){
            arr[i*len + k] = (rand()+((int)__TIME__)%100)%20-5;
        }
    }
}

void nul_sum(int* arr, int len){
    int mas[len];
    for (int &a: mas)
        a = -1;
    int ans[len];
    for (int &a: ans)
        a = 1;
    int mas2[len];
    for (int &a: mas2)
        a = 0;
    // ищем какие столбцы не имеют отрицательные элементы
    for (int i = 0; i < len; i++){
        for (int k = 0; k < len; k++){
            if (arr[i*len + k] < 0){
                mas[k] = -1;
                ans[k] = 0;
            }
            if (mas[k] == 1)
                ans[k] += arr[i*len + k];
            if (i == len-1){
                if (k == 0){
                    cout << endl << "ans: ";
                }
            }
        }
    }
    cout << endl;
    for (int i = 0; i < len; i++){
        for (int k = 0; k < len; k++){
            if (ans[k] == 1)
                mas2[k] += arr[i*len + k];
        }
    }
    for (int i = 0; i < len; i++){
        if (ans[i] == 1)
            cout << mas2[i] << " ";
        else
            cout << "(not done)  ";
    }
    //
}

void show(int *mas, int len){
    for (int i = 0; i < len; i++){
        for (int k = 0; k < len; k++){
            cout << mas[i*len + k] << "\t";
        }
        cout << endl << endl;
    }
}

void diags(int* mas, int len){
    cout << endl;
    int sums[(2*len)-1];
    for (int i = 0; i < ((2*len)-1); i++){
        sums[i] = 0;
    }

    int counter = 0;

    for (int i = 1; i < len+1; i++){
        for (int k = 0; k < len-(len-i); k++){
            sums[counter] += *(mas + (i-k-1)*len + k);
        }
        counter++;
    }

    int flag = 0;
    for (int i = ((((2*len))-1)/2)-1; i >= 0 ; i--){
        
        int k = i;
        for (int z = 0; z <= i; z++){
            sums[counter] += *(mas + (len-z-1)*len + (len-k-1));
            k--;
        }
        flag++;
        counter++;
    }
    cout << endl;
    
    int min = abs(sums[0]);
    for (int &a: sums)
        if (abs(a) < min)
            min = abs(a);

    for (int &a: sums)
        cout << a << " ";
    cout << endl << "min: " << min;
}

int main(){
    int len;
    cout << "Enter mas len: ";
    cin >> len;

    int mas[len][len];
    fill_array(*mas, len);//заплняем
    show(*mas, len);//выводим на экран массив
    nul_sum(*mas, len);//выводим суммы столбцов
    diags(*mas, len);
}