#include <fstream>
#include <iostream>

int odwroc(int in){
    int i = 0;
    while(in!=0){
        i = i * 10 + in%10;
        in/=10;
    }
    return i;
}

void runOdwracanie(){
    std::ifstream in("liczby59.txt");
    int liczba, i;
    int licznik = 0;
    while(!in.eof()){
        in >> liczba;
        i = odwroc(liczba);
        if((liczba+i) == odwroc(liczba + i)){
            licznik++;
        }
    }
    in.close();
    std::cout << licznik << std::endl;
}
