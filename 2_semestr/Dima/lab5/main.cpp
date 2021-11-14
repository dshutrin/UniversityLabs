#include <iostream>

void part1(){
    using namespace std;
    int side = 5;
    
    int **mas = new int*[side];
    for (int i = 0; i < side; i++){
        mas[i] = new int[side];
    }
    for (int i = 0; i < side; i++){
        for (int k = 0; k < side; k++){
            mas[i][k] = rand()%10;
        }
    }



    int mas2[side];
    for (int i = 0; i < side; i++)
        mas2[i] = 1;
    
    int sum = 0;
    for (int i = 0; i < side; i++){
        for (int k = 0; k < side; k++){
            if (mas[i][k] < 0)
                mas2[k] = 0;
        }
    }

    int sums[side];
    for (int i = 0; i < side; i++){
        sums[i] = 0;
    }

    for (int i = 0; i < side; i++){
        for (int k = 0; k < side; k++){
            if (mas2[k] == 1){
                sums[k] += mas[i][k];
            }
        }
    }

    for (int i = 0; i < side; i++){
        if(mas2[i] == 1)
            cout << i+1 << " : " << sums[i] << endl;
    }

    for (int i = 0; i < side; i++){
        delete mas[i];
    }
    delete mas;

}

void part2(){
    using namespace std;
    int side = 6;
    int **mas = new int*[side];
    for (int i = 0; i < side; i++){
        mas[i] = new int[side];
    }
    for (int i = 0; i < side; i++){
        for (int k = 0; k < side; k++){
            mas[i][k] = rand()%10-5;
        }
    }

    int sums[(2*side)-1];
    for (int i = 0; i < ((2*side)-1); i++){
        sums[i] = 0;
    }
    int flag = 0;
    for (int i = 0; i < (((2*side))-1)/2; i++){
        
        int k = i;
        for (int z = 0; z <= i; z++){
            sums[flag] += mas[z][k];
            k -= 1;
        }
        flag++;
    }

    for (int i = (((2*side))-1)/2; i >= 0 ; i--){
        int k = i;
        for (int z = 0; z <= i; z++){
            sums[flag] += mas[side-z-1][side-k-1];
            k -= 1;
        }
        flag++;
    }

    int min = std::abs(sums[0]);
    for (int i = 0; i < (sizeof(sums)/4); i++)
        if (min > (std::abs(sums[i])))
            min = std::abs(sums[i]);

    for (int i = 0; i < side; i++){
        for (int k = 0; k < side; k++){
            cout << mas[i][k] << "\t";
        }
        cout << endl << endl;
    }

    cout << endl;
    for (int i = 0; i < (sizeof(sums)/sizeof(sums[0])); i++)
        cout << sums[i] << " ";

    cout << endl << min;
    for (int i = 0; i < side; i++){
        delete mas[i];
    }
    delete mas;
}

int main(){
    
    //part1();
    part2();

}