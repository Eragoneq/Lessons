#include <iostream>

float srednia(float a, float b){
    return (a+b)/2;
}

void runSrednia(){

    float a, b;

    std::cout << "Podaj dwie liczby:\n";
    std::cin >> a >> b;

    std::cout << srednia(a,b);
}