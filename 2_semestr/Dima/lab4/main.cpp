#include <iostream>
#include <math.h>

int main(){
    using namespace std;
    int len = 10;
    double *mas = new double[len];
    double max, last, a, b, sum = 0;
    cout << "Enter a: " << endl;
    cin >> a;
    cout << "Enter b: " << endl;
    cin >> b;
    cout << "Mas: ";
    for (int i = 0; i < len; i++){ // Ищем максимальный элемент
        cout << mas[i] << " ";
        if (i == 0) max = mas[i];
        if (mas[i] > max) max = mas[i];
    }

    for (int i = len-1; i > 0; i--){ // Сумма всех элементов до последнего положительного
        if (mas[i] > 0){
            last = i;
            for (int k = 0; k < last; k++)
                sum += mas[k];
            break;
        }
    }

    for (int i= 0; i < len; i++){ // Зануляем элементы x, (a < |x| < b)
        if ((std::abs(mas[i]) >= a) and (std::abs(mas[i]) <= b))
            mas[i] = 0;
    }

    // sort
    for (int i = 1; i < len; i++){
        for (int k = i; k < len; k++){
            int is = 0;
            if ((mas[i] == 0) & (mas[i+1] != 0)){
                double j = mas[i];
                mas[i] = mas[k];
                mas[k] = j;
            }else{
                if ((mas[i] == 0) & (mas[i+1] == 0)){
                    int flag = 0;
                    for (int u = k+1; u < len; u++){
                        if (flag == 0){
                            if (mas[u] != 0){
                                is = u;
                                flag = 1;
                            }
                        }
                    }
                    if (flag){
                        mas[i] = mas[is];
                        mas[is] = 0;
                    }
                }
            }
        } 
    }
    // end sort

    cout << endl << "Max: " << max << endl << "Sum: " << sum << endl << "Sorted mas: ";
    for (int i = 0; i < len; i++){
        cout << mas[i] << " ";
    }
    delete mas;
    cout << endl;
    return 0;
}