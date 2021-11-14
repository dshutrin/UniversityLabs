#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include "my_header.h"
using namespace std;

void writer(NOTEBOOK *my_new_notebooks, int g_count){
    ofstream file("data2.txt");
    file << g_count;
    for (int a = 0; a < g_count; a++){
      file << "\n";
      file << my_new_notebooks[a].model; file << "\t";
      file << my_new_notebooks[a].n_size.x; file << "\t";
      file << my_new_notebooks[a].n_size.y; file << "\t";
      file << my_new_notebooks[a].n_size.z; file << "\t";
      file << my_new_notebooks[a].w; file << "\t";
      file << my_new_notebooks[a].hard_drive; file << "\t";
      file << my_new_notebooks[a].price;
    }
    file.close();
}

int char_pos(char lit){
  int pos = 0;
  char alph[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m',
                   'n','o','p','q','r','s','t','u','v','w','x','y','z'};
  for (int i = 0; i < 26; i++)
    if (lit == alph[i])
      pos = i;
  return pos;
}

void main_func(){
  int count, g_count = 0, i = 0;
  string line;
    ifstream read_file("data.txt");
    getline(read_file, line);
    istringstream iss(line);
    iss >> count;

    NOTEBOOK new_scans[count];  // открыть прочитать посчитать сколько нужно места в массиве закрыть переоткрыть заполнить массив

    if (read_file.is_open()){
        
        string line = "";
        while (getline(read_file, line)){
            
            string model = "";
            int x, y, z;
            int price, w, hard_drive;
            istringstream iss(line);
            iss >> model >> x >> y >> z >> w >> hard_drive >> price;
            if (model != "\n"){
                NOTEBOOK sc;
                new_scans[i].model = model;
                new_scans[i].price = price;
                new_scans[i].n_size.x = x;
                new_scans[i].n_size.y = y;
                new_scans[i].n_size.z = z;
                new_scans[i].w = w;
                new_scans[i].hard_drive = hard_drive;
                if (hard_drive < 1){
                  g_count++;
                }
                i++;
                x = 0, y = 0, z = 0;
              price = 0, w = 0, hard_drive = 0;
              model = "";
            }
            
        }
    }else{
        cout << "File not open!" << endl;
    }
    read_file.close();
    i = 0;
    NOTEBOOK my_new_notebooks[g_count];
    for (int k = 0; k < count; k++){
      if (new_scans[k].hard_drive < 1){
        my_new_notebooks[i].model = new_scans[k].model;
        my_new_notebooks[i].price = new_scans[k].price;
        my_new_notebooks[i].n_size.x = new_scans[k].n_size.x;
        my_new_notebooks[i].n_size.y = new_scans[k].n_size.y;
        my_new_notebooks[i].n_size.z = new_scans[k].n_size.z;
        my_new_notebooks[i].w = new_scans[k].w;
        my_new_notebooks[i].hard_drive = new_scans[k].hard_drive;
        i++;
      }
    }

    for (int i = 0; i < g_count-1; i++){
      for (int k = i; k < g_count; k++){
        if (char_pos(my_new_notebooks[i].model[0]) > char_pos(my_new_notebooks[k].model[0])){
          NOTEBOOK note = my_new_notebooks[i];
          my_new_notebooks[i] = my_new_notebooks[k];
          my_new_notebooks[k] = note;
        }
      }
    }

    writer(&my_new_notebooks[0], g_count);
}