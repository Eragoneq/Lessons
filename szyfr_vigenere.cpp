#include <iostream>

std::string szyfrVigenere(std::string slowo, std::string klucz, bool szyfruj) {

    std::string szyfr;
    int licznik = 0;
    int mnoznik;
    if(szyfruj){
        mnoznik=1;
    }else{
        mnoznik=-1;
    }

    for (char i : slowo) {
        if (64 < int(i) && int(i) < 91) {
            szyfr.append(1, char((int(i) - 65 * 2 + int(klucz[licznik % klucz.length()])) % 26 + 65));
        } else if (96 < int(i) && int(i) < 123) {
            szyfr.append(1, char((int(i) - 97 * 2 + int(klucz[licznik % klucz.length()])) % 26 + 97));
        } else {
            szyfr.append(" ");
            licznik--;
        }
        licznik++;
    }

    return szyfr;
}

void runSzyfrVigenere() {

    int i;
    std::string text, wynik, klucz;
    //
    std::cout << "Wybierz opcje [1]szyfrowanie, [2]deszyfrowanie: \n";
    std::cin >> i;
    //
    std::cin.ignore();
    std::cout << "Podaj tekst: \n";
    std::getline(std::cin, text);
    //
    std::cout << "Podaj klucz: \n";
    std::cin >> klucz;

    switch (i) {
        case 1:
            wynik = szyfrVigenere(text, klucz, true);
            break;
        case 2:
            wynik = szyfrVigenere(text, klucz, false);
            break;
        default:
            std::cout << "BLAD";
            break;
    }

    std::cout << wynik;
}
