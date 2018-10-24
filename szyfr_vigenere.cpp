#include <iostream>

std::string szyfrVigenere(std::string slowo, std::string klucz, bool szyfruj) {

    std::string szyfr;
    int licznik = 0;
    int mnoznik;
    if(szyfruj){
        mnoznik=1;
    }else{
        mnoznik=(-1);
    }

    for (char i : slowo) {
        int x;
        if (64 < int(i) && int(i) < 91) {
            x = (int(i) - 65) + mnoznik*(int(klucz[licznik % klucz.length()]) - 65);
            szyfr.append(1, char(x % 26 + (x % 26 < 0 ? 26 : 0) + 65));
        } else if (96 < int(i) && int(i) < 123) {
            x = (int(i) - 65) + mnoznik*(int(klucz[licznik % klucz.length()]) - 65);
            szyfr.append(1, char(x % 26 + (x % 26 < 0 ? 26 : 0) + 97));
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
