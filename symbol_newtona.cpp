#include <iostream>
#include "silnia_reku.cpp"

int obliczSymbol(int n, int k){
    int product = (int) silnia(n)/(silnia(k)*silnia(n-k));
    return product;
}

int obliczSymbolReku(int n, int k){
    if (n == k || k==0 ) return 1;
    return obliczSymbolReku(n-1, k) + obliczSymbolReku(n-1, k-1);
}

void runObliczSymbol(){
    int n,k;
    std::cout << "Podaj wspolczynniki dla symbolu Newtona: \n";
    std::cin >> n >> k;

    std::cout << obliczSymbolReku(n,k);
}