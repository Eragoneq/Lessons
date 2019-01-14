#include <iostream>
#include "random.h"
#include <vector>

float obliczPi(int dokladnosc){
    std::vector<std::pair<float, float>> vec;
    for(int i = 0; i<=dokladnosc; i++){
        vec.emplace_back(std::make_pair(randFloat(0.0, 1.0), randFloat(0, 1.0)));
    }
    int licznik = 0;
    for(std::pair<float, float> t : vec){
        if(t.first*t.first + t.second*t.second <= 1.0) {
            licznik++;
        }
    }
    return (4*licznik)/(float)dokladnosc;
}

void runObliczPi(){
    int dokladnosc;
    std::cout << "Podaj dokladnosc:\n";
    std::cin >> dokladnosc;

    std::cout << obliczPi(dokladnosc);
}