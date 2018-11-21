#include <iostream>
#include <algorithm>

int sys2dec(std::string liczba, int system){
    int wynik = 0;
    int x = system;
    for (char i : liczba) {
        wynik += int(i)-48;
        wynik *= x;
    }
    return wynik/x;
}

std::string dec2sys(int liczba, int system) {
    int wynik[32]={};
    std::string str = "";
    int x = system;
    int i;
    for(i = 0; liczba!=0; i++){
        wynik[i]=liczba%x;
        liczba/=x;
    }
    for(int j = i-1; j>=0; j--){
        str+=char(wynik[j])+48;
    }
    return str;
}


void runBinary(){
    std::string str;
    int dec, sys;
    std::cout << "Podaj liczbe i system do zmiany: \n";
    std::cin >> str >> sys;

    std::cout << sys2dec(str, sys);

    std::cout << "\nPodaj liczbe z systemu dziesietnego i system do zamiany: \n";
    std::cin >> dec >> sys;

    std::cout << dec2sys(dec, sys);
}

