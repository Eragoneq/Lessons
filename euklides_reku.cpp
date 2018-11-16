#include <iostream>

int euklides(int a, int b){
    if(b==0) return a;
    return euklides(b, a%b);
}

void runEuklidesReku(){
    int a,b;
    std::cout << "Podaj dwie liczby by znalezc ich NWD: \n";
    std::cin >> a >> b;
    std::cout << euklides(a,b);
}