#include <iostream>

int F(int x, unsigned int n){
    int k;
    if(n==1){
        return x;
    }else{
        if(n%3==0){
            k = F(x, n/3);
            return k*k*k;
        }else{
            return x*F(x, n-1);
        }
    }
}

void runCiekaweMnozenia(){
    int x;
    unsigned int n;
    std::cout << "Podaj liczbe calkowita i calkowita dodatnia: \n";
    std::cin >> x >> n;

    std::cout << F(x, n);
}