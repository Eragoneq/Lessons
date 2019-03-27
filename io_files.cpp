#include <fstream>
#include <iostream>
#include <cmath>

bool czyPierwsza(int x){
    for(int i = 2; i < (int)sqrt(x); i++){
        if(x%i==0){
            return false;
        }
    }
    return true;
}

bool czyPalindrom(std::string text){
    for(int i = 0; i<=(text.length()/2); i++){
        if(text[i] != text[(text.length()-1) - i]) return false;
    }
    return true;
}


void runDzialania(){
    std::ifstream in("dane_geny.txt");
    std::string text;
    int licznik = 0;
    while(!in.eof()){
        in >> text;
        if(czyPalindrom(text)){
            licznik++;
        }
    }
    std::cout << licznik;
    in.close();
}
