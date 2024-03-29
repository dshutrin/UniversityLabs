#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "my_header.h"
#include "writer.cpp"
using namespace std;

int main(){
    int mode;
    while (mode != 4){
        cout << "\n\nWhat do you want to do?:\n1) Read file\n2) Write file\n3) Compact file\n4) Exit\n\n>>> ";
        cin >> mode;
        if (mode == 2){
            int len;
            cout << "How many scanners do you want to record?: ";
            cin >> len;
            scan_info scans[len];
        
            for (int i = 0; i < len; i++){
                cout << "Enter " << i + 1 << "`scanner model: ";    cin >> scans[i].model;
                cout << "Enter " << i + 1 << "`scanner price: ";    cin >> scans[i].price;
                cout << "Enter " << i + 1 << "`scanner x_size: ";   cin >> scans[i].x_size;
                cout << "Enter " << i + 1 << "`scanner y_size: ";   cin >> scans[i].y_size;
                cout << "Enter " << i + 1 << "`scanner optr: ";     cin >> scans[i].optr;
                cout << "Enter " << i + 1 << "`scanner grey: ";     cin >> scans[i].grey;
                cout << endl << endl;
            }

            writer(&scans[0], len);// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        }else if (mode == 1){
            int count = 0;
            ifstream read_file("out.txt");
            if (read_file.is_open()){

                string line;
                while (getline(read_file, line)){
                    if (count != 0){
                        string model;
                        double x_size, y_size;
                        int price, optr, grey;

                        istringstream iss(line);

                        iss >> model >> price >> x_size >> y_size >> optr >> grey;
                        cout << model << " " << price << " " << x_size << " " << y_size << " " << optr << " " << grey << endl;
                    }else{
                        count++;
                    }
                }

            }else{
                cout << "File not open!" << endl;
            }
            read_file.close();
        }else if (mode == 3){
            int count = 0, flag = 0;
            string line;
            ifstream read_file("out.txt");
            getline(read_file, line);
            istringstream iss(line);
            iss >> count;
            int i = 0, n_count = 0;

            scan_info new_scans[count];

            if (read_file.is_open()){
                
                string line;
                while (getline(read_file, line)){
                    
                    string model;
                    double x_size, y_size;
                    int price, optr, grey;

                    istringstream iss(line);

                    iss >> model >> price >> x_size >> y_size >> optr >> grey;
                    if ((model != "0")&&(model != "\n")){
                        cout << model << " " << price << " " << x_size << " " << y_size << " " << optr << " " << grey << endl;
                        scan_info sc;
                        new_scans[i].model = model;
                        new_scans[i].price = price;
                        new_scans[i].x_size = x_size;
                        new_scans[i].y_size = y_size;
                        new_scans[i].optr = optr;
                        new_scans[i].grey = grey;
                        n_count++;
                        i++;
                    }
                    
                }
                flag = 1;
            }else{
                cout << "File not open!" << endl;
            }
            if (flag){
                cout << "rewriting...";
                writer(&new_scans[0], n_count);  //  !!!!!!!!!!!!!!!!!!!!!!!!!!
            }
        }
    }
}