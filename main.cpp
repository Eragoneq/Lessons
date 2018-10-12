#include <iostream>

int main() {

    int klucz;
    std::string slowo, szyfr;

    std::cout << "Podaj slowo do zaszyfrowania i liczbe jako klucz: \n";
    std::cin >> slowo;
    std::cin >> klucz;

    klucz=klucz%26;

    for (char i : slowo) {
        szyfr.append(1, char(int(i) + klucz));
    }
    std::cout << szyfr;
}