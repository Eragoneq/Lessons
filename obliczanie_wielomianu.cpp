#include <iostream>
#include <vector>

double obliczWielomian(std::vector<float> wsp, double x){
    float wynik = 0;
    for (float i : wsp) {
        wynik += i;
        wynik *= x;
    }
    return wynik/x;
}

void runObliczWielomian(){
    std::cout << obliczWielomian({2, -5, 3, -1, 4}, 2);
}