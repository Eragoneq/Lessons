#ifndef CEZAR
#define CEZAR
#include <iostream>

std::string szyfrCezara(){

    int klucz;
    std::string slowo, szyfr;

    std::cout << "Podaj slowo do zaszyfrowania i liczbe jako klucz: \n";
    std::cin >> slowo;
    std::cin >> klucz;

    klucz=klucz%26;

    for (char i : slowo) {
        szyfr.append(1, char((int(i) + klucz)%26));
    }
    return szyfr;
}

#endif
