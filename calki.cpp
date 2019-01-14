#include <iostream>
#include <vector>
#include "obliczanie_wielomianu.cpp"

double calka(std::vector<float> wsp, float a, float b, int dokladnosc){
    double dx = (b-a)/dokladnosc;
    double pole = 0;
    for(int i = 0; i<dokladnosc; i++){
        pole += (obliczWielomian(wsp, (a+i*dx))+obliczWielomian(wsp, (a+(i+1)*dx)))/2 * dx;
    }
    return pole;
}

void runCalka(){
    std::vector<float> in = {2, 0, 5};
    std::cout << calka(in, 1, 10, 999);
}