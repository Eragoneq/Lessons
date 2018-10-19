#include <iostream>

std::string szyfrAfiniczny(std::string slowo, int mnoznik, int klucz, bool szyfruj){

    std::string  szyfr;

    klucz=klucz%26;

    if(szyfruj) {
        for (char i : slowo) {
            if (64 < int(i) && int(i) < 91) {
                szyfr.append(1, char((mnoznik * (int(i) - 65) + klucz) % 26 + 65));
            } else if (96 < int(i) && int(i) < 123) {
                szyfr.append(1, char((mnoznik * (int(i) - 97) + klucz) % 26 + 97));
            } else {
                szyfr.append(" ");
            }
        }
    }else{
        // powinno byc zastapione rozszerzonym algorytmem euklidesa
        int odwr = 1;
        while((odwr*mnoznik)%26 != 1){
            odwr++;
        }
        //
        for (char i : slowo) {
            if (64 < int(i) && int(i) < 91) {
                szyfr.append(1, char(( odwr * (int(i) - 65 - klucz)) % 26 + 65));
            } else if (96 < int(i) && int(i) < 123) {
                szyfr.append(1, char(( odwr * (int(i) - 97 + klucz)) % 26 + 97));
            } else {
                szyfr.append(" ");
            }
        }
    }
    return szyfr;
}

void runSzyfrAfiniczny(){

    int i, klucz, mnoznik;
    std::string text, wynik;
    //
    std::cout << "Wybierz opcje [1]szyfrowanie, [2]deszyfrowanie: \n";
    std::cin >> i;
    //
    std::cin.ignore();
    std::cout << "Podaj tekst: \n";
    std::getline(std::cin, text);
    //
    std::cout << "Podaj mnoznik: \n";
    std::cin >> mnoznik;
    //
    std::cout << "Podaj klucz: \n";
    std::cin >> klucz;

    switch(i){
        case 1:
            wynik = szyfrAfiniczny(text, mnoznik, klucz, true);
            break;
        case 2:
            wynik = szyfrAfiniczny(text, mnoznik, klucz, false);
            break;
        default:
            std::cout << "BLAD";
            break;
    }

    std::cout << wynik;
}
