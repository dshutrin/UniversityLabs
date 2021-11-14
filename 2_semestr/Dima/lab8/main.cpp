#include <iostream>
using namespace std;

int main(){
    int count;
    cin >> count;
    int *mas = new int[count];
    int max;
    for (int i = 0; i < count; i++){
        mas[i] = rand()%100;
        if (i == 0){
            max = mas[i];
        }
        if (mas[i] > max){
            max = mas[i];
        }
    }
    delete mas;
    std::cout << max;
}