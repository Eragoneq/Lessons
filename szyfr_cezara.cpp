#include <iostream>

std::string szyfrCezara(){

    int klucz;
    std::string slowo, szyfr;

    std::cout << "Podaj slowo do zaszyfrowania i liczbe jako klucz: \n";
    std::cin >> slowo;
    std::cin >> klucz;

    klucz=klucz%26;

    for (char i : slowo) {
        if(64<int(i) && int(i)<91){
            szyfr.append(1, char((int(i)-65 + klucz)%26 + 65));
        }else if(96<int(i) && int(i)<123){
            szyfr.append(1, char((int(i)-97 + klucz)%26 + 97));
        }else{
            std::cout << "NIEWLASCIWE ZNAKI";
        }
    }
    return szyfr;
}
