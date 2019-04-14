//Specyfikacja: baza danych czarodziejow z pliku txt
//Dane wejsciowe: struktura czarodziej

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <windows.h>
#include <unistd.h>

using namespace std;

struct data{
    data(int dzien, int miesiac, int rok) : dzien(dzien), miesiac(miesiac), rok(rok) {}
    data(string dzien, string miesiac, string rok) : dzien(stoi(dzien)), miesiac(stoi(miesiac)), rok(stoi(rok)) {}
    data() = default;
    int dzien, miesiac, rok;

    friend ostream &operator<<(ostream &os, const data &data) {
        if(data.dzien<10) os << "0" << data.dzien;
        else os << data.dzien;
        os << ".";
        if(data.miesiac<10) os << "0" << data.miesiac;
        else os << data.miesiac;
        os << "." << data.rok;
        return os;
    }

    bool operator==(const data &rhs) const {
        return dzien == rhs.dzien &&
               miesiac == rhs.miesiac &&
               rok == rhs.rok;
    }

    bool operator<(const data &rhs) const {
        if (rok < rhs.rok)
            return true;
        if (rhs.rok < rok)
            return false;
        if (miesiac < rhs.miesiac)
            return true;
        if (rhs.miesiac < miesiac)
            return false;
        return dzien < rhs.dzien;
    }
};

struct czarodziej
{
    string imie;
    string nazwisko;
    string dom;
    string patronus;
    data dataUro;
};

void narysujMenu(){
    cout<<"            zeeeee-                                                                                            zeeeee-\n"
        <<"           z$$$$$'                                                                                            z$$$$$'\n"
        <<"          d$$$$$'                                                                                            d$$$$$'\n"
        <<"         d$$$$P             ......................................................................          d$$$$P\n"
        <<"        $$$$$'              .                                                                    .         $$$$$'\n"
        <<"      .$$$$$'               .                                                                    .       .$$$$$'\n"
        <<"     .$$$$$'                .  ____      ____     __________     ____    _____     _____  _____  .      .$$$$$'\n"
        <<"    4$$$$$$$$$$$$$$$$$$'    . |_   |    |   _|   |_   ____  |   |_   |  |_   _|   |_   _||_   _| .     4$$$$$$$$$$$$$$$$$$'\n"
        <<"   z$$$$$$$$$$$$$$$$$$'     .   |   |  |   |       | |    | |     |   |   | |       | |    | |   .    z$$$$$$$$$$$$$$$$$$'\n"
        <<"   ''''''''''''3$$$$'       .   | || || || |       | |__   ||     | || |  | |       | |    | |   .    ''''''''''''3$$$$'\n"
        <<"              z$$$P         .   | | |  | | |       |  __|         | | | | | |       | |    | |   .               z$$$P\n"
        <<"             d$$$'          .   | |  ||  | |       | |     |      | |  | || |       | ' __ ' |   .              d$$$'\n"
        <<"           .$$$'            .  _| |_    _| |_     _| |____| |    _| |_  |   |_       |      |    .            .$$$'\n"
        <<"          .$$$'             . |_____|  |_____|   |__________|   |_____|  |____|       `.__.'     .           .$$$'\n"
        <<"         .$$$'              .                                                                    .          .$$$'\n"
        <<"        .$$'                .                                                                    .         .$$'\n"
        <<"       4$P'                 .                                                                    .        4$P'\n"
        <<"      z$'                   ......................................................................       z$'\n"
        <<"     zP                                                                                                 zP\n"
        <<"    z'                                                                                                 z'\n";
}

void wypiszOpcje(){
    cout<<"Wybierz polecenie z listy: (np. 4)\n\n1)Dodaj osobe\n2)Usun osobe\n3)Sortuj baze danych\n4)Edycja danych\n5)Wyszukaj czarodzieja\n"
        <<"6)Wyswietl wszystkich czarodziejow\n7)Zapisz dane do pliku\n8)Usun cala baze danych\n9)Archiwizuj baze danych\n10)Statystyki\n11)Koniec\n12)Zniszcz ksiege\n";
}

void clear()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD topLeft  = { 0, 0 };
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
}

int filteredIntInput(){
    while(true){
        int in;
        cin >> in;
        if(cin.fail()) {
            cin.clear();
            cin.ignore(256, '\n');
            clear();
            std::cout << "BLEDNE DANE!" << "\n";
            continue;
        }
        return in;
    }
}

void uzupelnijTablice(vector<czarodziej> *czarodzieje)
{
    ifstream plik("bazadanych.txt");
    while(!plik.eof())
    {
        czarodziej temp;
        string in;
        cout << in;
        plik>>in;
        temp.imie = in;
        plik>>in;
        temp.nazwisko = in;
        plik>>in;
        temp.dom = in;
        plik>>in;
        temp.patronus = in;
        plik>>in;
        temp.dataUro = {in.substr(0,2), in.substr(3,2), in.substr(6,4)};
        (*czarodzieje).emplace_back(temp);
    }


}
void dodajOsobe(vector<czarodziej> *czarodzieje){
    clear();
    czarodziej temp;
    string in;
    cout << "Podaj imie: ";
    cin >> in;
    temp.imie = in;
    cout << "Podaj nazwisko: ";
    cin >> in;
    temp.nazwisko = in;
    cout << "Podaj dom: ";
    cin >> in;
    temp.dom = in;
    cout << "Podaj patronusa: ";
    cin >> in;
    temp.patronus = in;
    cout << "Podaj date urodzenia (format DD.MM.RRRR): ";
    cin >> in;
    temp.dataUro = {in.substr(0,2), in.substr(3,4), in.substr(6,9)};
    (*czarodzieje).emplace_back(temp);
}

void wypisz(vector<czarodziej> czarodzieje){
    int licznik = 1;
    for(auto osoba : czarodzieje){
        cout << licznik++ << ")\nImie i nazwisko czarodzieja: " << osoba.imie << " " << osoba.nazwisko << "\nDom w Hogwarcie: "
             << osoba.dom << "\nPatronus: " << osoba.patronus << "\nData urodzenia: " << osoba.dataUro << "\n\n";
    }
}

void wyswietlOsoby(vector<czarodziej> czarodzieje){
    clear();
    wypisz(czarodzieje);
    cout << "Kliknij dowolny przycisk aby powrocic do menu!\n";
    cin.get();
    cin.get();
}

void usunOsobe(vector<czarodziej> *czarodzieje){
    clear();
    wypisz(*czarodzieje);
    cout << "Podaj nr osoby ktora chcesz usunac: ";
    int in = filteredIntInput();
    (*czarodzieje).erase(czarodzieje->begin()+in-1);
}

bool compareImie(czarodziej &in1, czarodziej &in2){
    return in1.imie < in2.imie;
}
bool compareNazw(czarodziej &in1, czarodziej &in2){
    return in1.nazwisko < in2.nazwisko;
}
bool compareDom(czarodziej &in1, czarodziej &in2){
    return in1.dom < in2.dom;
}
bool comparePatronus(czarodziej &in1, czarodziej &in2){
    return in1.patronus < in2.patronus;
}
bool compareData(czarodziej &in1, czarodziej &in2){
    return in1.dataUro < in2.dataUro;
}

void sortujBazeDanych(vector<czarodziej> *czarodzieje){
    clear();
    cout << "Podaj nr kategorii wedlug ktorej chcesz posortowac baze: \n1 imie\n2 nazwisko\n3 dom\n4 patronus\n5 data urodzenia\n";
    int in = filteredIntInput();
    switch(in){
        case 1:
            sort(czarodzieje->begin(), czarodzieje->end(), compareImie);
            break;
        case 2:
            sort(czarodzieje->begin(), czarodzieje->end(), compareNazw);
            break;
        case 3:
            sort(czarodzieje->begin(), czarodzieje->end(), compareDom);
            break;
        case 4:
            sort(czarodzieje->begin(), czarodzieje->end(), comparePatronus);
            break;
        case 5:
            sort(czarodzieje->begin(), czarodzieje->end(), compareData);
            break;
        default:
            break;
    }
}

void edytujDane(vector<czarodziej> *czarodzieje) {
    clear();
    wypisz(*czarodzieje);
    cout << "Podaj nr osoby ktora chcesz edytowac\n";
    int in = filteredIntInput();
    if (in <= czarodzieje->size()) {
        clear();
        czarodziej *osoba = &(*czarodzieje)[in - 1];
        cout << "Imie i nazwisko czarodzieja: " << osoba->imie << " " << osoba->nazwisko << "\nDom w Hogwarcie: "
             << osoba->dom << "\nPatronus: " << osoba->patronus << "\nData urodzenia: " << osoba->dataUro << "\n\n";
        cout << "Podaj nr cechy ktora chcesz edytowac: \n1 imie\n2 nazwisko\n3 dom\n4 patronus\n5 data urodzenia\n";
        int in2 = filteredIntInput();
        string in3;
        switch (in2) {
            case 1:
                cout << "Podaj nowe imie:\n";
                cin >> in3;
                osoba->imie = in3;
                break;
            case 2:
                cout << "Podaj nowe nazwisko:\n";
                cin >> in3;
                osoba->nazwisko = in3;
                break;
            case 3:
                cout << "Podaj nowy dom:\n";
                cin >> in3;
                osoba->dom = in3;
                break;
            case 4:
                cout << "Podaj nowego patronusa:\n";
                cin >> in3;
                osoba->patronus = in3;
                break;
            case 5:
                cout << "Podaj nowa date urodzenia:\n";
                cin >> in3;
                osoba->dataUro = {in3.substr(0,2), in3.substr(3,2), in3.substr(6,4)};
                break;
            default:
                break;
        }
    }
}

void wyszukajCzarodzieja(vector<czarodziej> czarodzieje){
    clear();
    cout << "Podaj nr kategorii wedlug ktorej chcesz przeszukac baze: \n1 imie\n2 nazwisko\n3 dom\n4 patronus\n5 data urodzenia\n";
    int in = filteredIntInput();
    string in2;
    vector<czarodziej> znaleziono = {};
    data temp = {};
    switch(in){
        case 1:
            cout << "Podaj imie jakiego szukasz:\n";
            cin >> in2;
            for(auto osoba : czarodzieje){
                if(osoba.imie == in2) znaleziono.emplace_back(osoba);
            }
            clear();
            cout << "Znaleziono:\n";
            wypisz(znaleziono);
            break;
        case 2:
            cout << "Podaj nazwisko jakiego szukasz:\n";
            cin >> in2;
            for(auto osoba : czarodzieje){
                if(osoba.nazwisko == in2) znaleziono.emplace_back(osoba);
            }
            clear();
            cout << "Znaleziono:\n";
            wypisz(znaleziono);
            break;
        case 3:
            cout << "Podaj dom jakiego szukasz:\n";
            cin >> in2;
            for(auto osoba : czarodzieje){
                if(osoba.dom == in2) znaleziono.emplace_back(osoba);
            }
            clear();
            cout << "Znaleziono:\n";
            wypisz(znaleziono);
            break;
        case 4:
            cout << "Podaj patronusa jakiego szukasz:\n";
            cin >> in2;
            for(auto osoba : czarodzieje){
                if(osoba.patronus == in2) znaleziono.emplace_back(osoba);
            }
            clear();
            cout << "Znaleziono:\n";
            wypisz(znaleziono);
            break;
        case 5:
            cout << "Podaj date jakiej szukasz:\n";
            cin >> in2;
            temp = {in2.substr(0,2), in2.substr(3,2), in2.substr(6,4)};
            for(auto osoba : czarodzieje){
                if(osoba.dataUro == temp) znaleziono.emplace_back(osoba);
            }
            clear();
            cout << "Znaleziono:\n";
            wypisz(znaleziono);
            break;
        default:
            break;
    }
    cout << "Kliknij dowolny przycisk aby powrocic do menu!\n";
    cin.get();
    cin.get();
}

void zapiszDane(vector<czarodziej> czarodzieje){
    clear();
    string name;
    cout << "Podaj nazwe pliku pod jakim chcesz zapisac dane:\n";
    cin >> name;
    ofstream plik(name + ".txt");
    for(int i = 0; i<czarodzieje.size(); i++){
        czarodziej osoba = czarodzieje[i];
        plik << osoba.imie << " " << osoba.nazwisko << " " << osoba.dom << " " << osoba.patronus << " " << osoba.dataUro << (i==(czarodzieje.size()-1) ? "" : "\n");
    }
    plik.close();
}

void archiwizujDane(vector<czarodziej> czarodzieje){
    mkdir("backup");
    ifstream  src("projekcik.exe", ios::binary);
    ofstream  dst("backup/ksiega_kopia.exe", ios::binary);
    dst << src.rdbuf();
    dst.close();
    ofstream plik("backup/bazadanych.txt");
    for(int i = 0; i<czarodzieje.size(); i++){
        czarodziej osoba = czarodzieje[i];
        plik << osoba.imie << " " << osoba.nazwisko << " " << osoba.dom << " " << osoba.patronus << " " << osoba.dataUro << (i==(czarodzieje.size()-1) ? "" : "\n");
    }
    plik.close();
}

void statystyki(vector<czarodziej> czarodzieje){
    clear();
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    int rok = 1900+now->tm_year;
    float sredniaWieku = 0;
    int iloscDzieci = 0;
    int statyDomu[4] = {0};
    czarodziej najm = czarodzieje[0];
    czarodziej najst = czarodzieje[0];
    for(auto osoba : czarodzieje){
        int wiek = rok-osoba.dataUro.rok;
        if(najm.dataUro < osoba.dataUro) {
            najm = osoba;
        }
        if(osoba.dataUro < najst.dataUro){
            najst = osoba;
        }
        sredniaWieku += wiek;
        if(wiek<18){
            iloscDzieci++;
        }
        if(osoba.dom == "Gryffindor") statyDomu[0]++;
        else if(osoba.dom == "Ravenclaw") statyDomu[1]++;
        else if(osoba.dom == "Hufflepuff") statyDomu[2]++;
        else if(osoba.dom == "Slytherin") statyDomu[3]++;
    }
    sredniaWieku/=czarodzieje.size();
    cout << "Najmlodsza osoba:\nImie i nazwisko czarodzieja: " << najm.imie << " " << najm.nazwisko << "\nDom w Hogwarcie: "
        << najm.dom << "\nPatronus: " << najm.patronus << "\nData urodzenia: " << najm.dataUro << "\n\n";
    cout << "Najstarsza osoba:\nImie i nazwisko czarodzieja: " << najst.imie << " " << najst.nazwisko << "\nDom w Hogwarcie: "
         << najst.dom << "\nPatronus: " << najst.patronus << "\nData urodzenia: " << najst.dataUro << "\n\n";
    cout << "Srednia wieku: " << sredniaWieku << "\n\n";
    cout << "Ilosc dzieci: " << iloscDzieci << "\n\n";
    cout << "Statystyki domow:\nGryffindor: " << statyDomu[0] << "\nRavenclaw: " << statyDomu[1] << "\nHufflepuff: " << statyDomu[2] << "\nSlytherin: " << statyDomu[3] << "\n\n";
    cin.get();
    cin.get();
}

int main()
{
// lista czarodziejow
vector<czarodziej> czarodzieje = {};
//funkcja uzupelniajaca tablice ludzmi z pliku
uzupelnijTablice(&czarodzieje);
//narysowanie menu i pokazanie mozliwych opcji
//narysujMenu();
//sleep(1);
//clear();
wypiszOpcje();
//
while(true) {
    int wejscie = filteredIntInput();
    switch (wejscie) {
        case 1:
            dodajOsobe(&czarodzieje);
            clear();
            wypiszOpcje();
            cout << "Dodano nowego czarodzieja!" << "\n";
            break;
        case 2:
            usunOsobe(&czarodzieje);
            clear();
            wypiszOpcje();
            cout << "Usunieto czarodzieja!" << "\n";
            break;
        case 3:
            sortujBazeDanych(&czarodzieje);
            clear();
            wypiszOpcje();
            cout << "Posortowano liste!" << "\n";
            break;
        case 4:
            edytujDane(&czarodzieje);
            clear();
            wypiszOpcje();
            cout << "Edytowano dane!" << "\n";
            break;
        case 5:
            wyszukajCzarodzieja(czarodzieje);
            clear();
            wypiszOpcje();
            cout << "Zakonczono wyszukiwanie!" << "\n";
            break;
        case 6:
            wyswietlOsoby(czarodzieje);
            clear();
            wypiszOpcje();
            break;
        case 7:
            zapiszDane(czarodzieje);
            clear();
            wypiszOpcje();
            cout << "Zapisano dane!" << "\n";
            break;
        case 8:
            czarodzieje = {};
            cout << "Usunieto cala baze danych!" << "\n";
            break;
        case 9:
            archiwizujDane(czarodzieje);
            cout << "Zarchiwizowano dane!" << "\n";
            break;
        case 10:
            statystyki(czarodzieje);
            clear();
            wypiszOpcje();
            break;
        case 11:
            return 0;
        case 12:
            break;
        default:
            clear();
            wypiszOpcje();
            std::cout << "BLEDNE DANE!" << "\n";
            break;
    }
}
}
