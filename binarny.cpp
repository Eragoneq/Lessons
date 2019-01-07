#include <iostream>

int sys2dec(std::string liczba, int system){
    int wynik = 0;
    for (char i : liczba) {
        wynik *= system;
        if((i - '0')<10) {
            wynik += (i - '0');
        }else{
            wynik += int(i)-55;
        }
    }
    return wynik;
}

std::string dec2sys(int liczba, int system) {
    char znaki[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    std::string str;
    while(liczba>0){
        str=znaki[liczba%system] + str;
        liczba/=system;
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

