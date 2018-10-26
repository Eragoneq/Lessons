#include <iostream>
int sumaCyfr(int in){

    int suma;

    while(in!=0){
        suma+=in%10;
        in/=10;
    }

    return suma;
}

void runSumaCyfr(){
    int in;

    std::cout << "Podaj liczbe: \n";
    std::cin >> in;

    std::cout << sumaCyfr(in);
}