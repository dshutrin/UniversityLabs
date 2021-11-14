#include <fstream>
using namespace std;

void writer(scan_info *scans, int len){
    ofstream file;
    file.open("out.txt");
        file << len;
    for (int i = 0; i < len; i++){
        if ((scans[i].model != "0")&&(scans[i].model != "\n")){
            file << "\n";
            file << scans[i].model;   file << "\t";
            file << scans[i].price;   file << "\t";
            file << scans[i].x_size;  file << "\t";
            file << scans[i].y_size;  file << "\t";
            file << scans[i].optr;    file << "\t";
            file << scans[i].grey;
        }
    }
    file.close();
}