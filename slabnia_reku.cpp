#include <iostream>

int slabnia(int x){
    if(x==0){
        return 0;
    }else if(x<0){
        std::cout << "BLAD";
    }
    return slabnia(x - 1) + x;
}

void runSlabnia(){
    int x;
    std::cout << "Podaj liczbe dla silni: \n";
    std::cin >> x;
    std::cout << slabnia(x);
}

