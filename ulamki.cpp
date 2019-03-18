#include <fstream>
#include <iostream>
#include <cmath>

void najmniejszyUlamek(){
    int liczba1, liczba2, liczbaMin[2];
    std::ifstream in("dane/dane_ulamki.txt");
    liczbaMin[0] = 1;
    liczbaMin[1] = 1;
    while(!in.eof()){
        in >> liczba1;
        in >> liczba2;
        if(liczba1*liczbaMin[1] < liczba2*liczbaMin[0]){
            liczbaMin[0]=liczba1;
            liczbaMin[1]=liczba2;
        }else if(liczba1*liczbaMin[1] == liczba2*liczbaMin[0]){
            if(liczba2 < liczbaMin[1]){
                liczbaMin[0]=liczba1;
                liczbaMin[1]=liczba2;
            }
        }
    }
    std::cout << liczbaMin[0] << " " << liczbaMin[1] << " ma wartosc " << (double)liczbaMin[0]/(double)liczbaMin[1];
}

int euklides(int a, int b) {
    if (b == 0) return a;
    return euklides(b, a % b);
}

void iloscUlamkowNieskracalnych(){
    int liczba1, liczba2, licznik;
    licznik = 0;
    std::ifstream in("dane/dane_ulamki.txt");
    while(!in.eof()){
        in >> liczba1;
        in >> liczba2;
        if(euklides(liczba1, liczba2)==1){
            licznik++;
        }
    }
    std::cout << licznik;
}
void runUlamki(){
    iloscUlamkowNieskracalnych();
}

