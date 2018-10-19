#include <iostream>

std::string szyfrCezara(std::string slowo, int klucz){

    std::string  szyfr;

    klucz=klucz%26;

    for (char i : slowo) {
        if(64<int(i) && int(i)<91){
            szyfr.append(1, char((int(i)-65 + klucz)%26 + 65));
        }else if(96<int(i) && int(i)<123){
            szyfr.append(1, char((int(i)-97 + klucz)%26 + 97));
        }else{
            szyfr.append(" ");
        }
    }
    return szyfr;
}

void runSzyfrCezara(){

    int i, klucz;
    std::string text, wynik;
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

    switch(i){
        case 1:
            wynik = szyfrCezara(text, klucz);
            break;
        case 2:
            wynik = szyfrCezara(text, -1*(klucz));
            break;
        default:
            std::cout << "BLAD";
            break;
    }

    std::cout << wynik;
}
