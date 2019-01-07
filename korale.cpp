#include <iostream>

void koraliki(int n){
    if(n%2==0){
        koraliki(n/2);
        std::cout << "@";
    }else if(n==1){
        std::cout << "O";
    }else if(n%2==1){
        koraliki((n-1)/2);
        std::cout << "O";
    }else{
        std::cout << "X";
    }
}

void runKoraliki(){
    int n;
    std::cout << "Podaj liczbe naturalna: \n";
    std::cin >> n;
    koraliki(n);
}