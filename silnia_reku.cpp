#include <iostream>

long long silnia(int x){
    if(x==0){
        return 1;
    }else if(x<0){
        std::cout << "BLAD";
    }
    return silnia(x - 1) * x;
}

void runSilnia(){
    int x;
    std::cout << "Podaj liczbe dla silni: \n";
    std::cin >> x;
    std::cout << silnia(x);
}