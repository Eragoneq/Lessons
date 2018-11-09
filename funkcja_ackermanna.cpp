#include <iostream>

int ackermann(int m, int n){
    if(m==0){
        return n+1;
    }else if(m>0 && n==0){
        ackermann(m-1, 1);
    }else if(m>0 && n>0) {
        return ackermann(m - 1, ackermann(m, n - 1));
    }
}

void runAckermann(){
    int m, n;
    std::cout << "Podaj wspolczynniki (m, n) dla funkji Ackermanna\n";
    std::cin >> m >> n;

    std::cout << ackermann(m,n);
}