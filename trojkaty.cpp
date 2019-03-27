#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include "basic_sort.cpp"

void zadanie80_1(){
    std::ifstream in("dane/dane_trojkaty.txt");
    int liczba;
    std::vector<int> lista{};
    std::vector<int> liczby{};
    while(!in.eof()){
        in >> liczba;
        lista.emplace_back(liczba);
    }
    for(int i = 0; i < lista.size()-2; i++){
        liczby.emplace_back(lista[i]);
        liczby.emplace_back(lista[i+1]);
        liczby.emplace_back(lista[i+2]);
        liczby = bubbleSort(liczby);
        if(liczby[2]*liczby[2] == liczby[1]*liczby[1] + liczby[0]*liczby[0]){
            std::cout << liczby[2] << " " << liczby[1] << " " << liczby[0] << std::endl;
        }
        liczby.clear();
    }
    in.close();
}

void zadanie80_2(){
    std::ifstream in("dane/dane_trojkaty.txt");
    int liczba;
    std::vector<int> lista{};
    while(!in.eof()){
        in >> liczba;
        lista.emplace_back(liczba);
    }
    lista = bucketSort(lista);
    std::reverse(lista.begin(), lista.end());
}
void runTrojkaty(){
    zadanie80_1();

}