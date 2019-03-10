#include <iostream>
#include <vector>
#include <algorithm>
#include <dirent.h>

//wypisuje nazwy wszystkich plikow w directory
void wypiszDir(std::string dirr){
//    std::ofstream out("../../eragon_tu_byl.kek");
//    out << "LUL";
//    out.close();
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (dirr)) != nullptr) {
        /* print all the files and directories within directory */
        while ((ent = readdir (dir)) != nullptr) {
            printf ("%s\n", ent->d_name);
        }
        closedir (dir);
    } else {
        /* could not open directory */
        std::cout << "NOT FOUND";
}

// wypisuje srodkowe elementy ze stringa
std::string get_middle(std::string input) {
    std::string s;
    s = "";
    if (input.length() % 2 == 0) {
        s.push_back(input[input.length() / 2]);
        return s;
    } else {
        s.push_back(input[input.length() / 2]);
        s.push_back(input[input.length() / 2 + 1]);
        return s;
    }
}


// podaje sume wartosci w rzedzie kolumny skaldajacej sie z kolejnych liczb nieparzystch
// po doglebszej analizie mozemy ten problem zmniejszyc do postaci x^3
long long rowSumOddNumbers(unsigned n) {
    int licz = 0;
    int wynik = 0;
    for (int i = 1; i < n; i++) {
        licz += i;
    }
    std::cout << licz << ' ';
    for (int i = 0; i < n; i++) {
        wynik += 2 * (licz + i) + 1;
    }
    return wynik;
}

// funkcja interpretujaca liczby rzymskie i zamienia je na liczbe calkowita
int romanParser(std::string roman) {
    int wynik = 0;
    for (int i = 0; i < roman.length(); i++) {
        switch (roman[i]) {
            case 'M':
                wynik += 1000;
                break;
            case 'D':
                wynik += 500;
                break;
            case 'C':
                if (roman[i + 1] == 'M' && i < roman.length()) {
                    wynik += 900;
                    i += 1;
                } else if (roman[i + 1] == 'D' && i < roman.length()) {
                    wynik += 400;
                    i += 1;
                } else {
                    wynik += 100;
                }
                break;
            case 'L':
                if (roman[i + 1] == 'X' && roman[i + 2] == 'L' && i < roman.length()) {
                    wynik += 40;
                    i += 2;
                } else {
                    wynik += 50;
                }
                break;
            case 'X':
                if (roman[i + 1] == 'C' && i < roman.length()) {
                    wynik += 90;
                    i += 1;
                } else if (roman[i + 1] == 'L' && i < roman.length()) {
                    wynik += 40;
                    i += 1;
                } else {
                    wynik += 10;
                }
                break;
            case 'V':
                if (roman[i + 1] == 'I' && roman[i + 2] == 'V' && i < roman.length()) {
                    wynik += 4;
                    i += 2;
                } else {
                    wynik += 5;
                }
                break;
            case 'I':
                if (roman[i + 1] == 'X' && i < roman.length()) {
                    wynik += 9;
                    i += 1;
                } else if (roman[i + 1] == 'V' && i < roman.length()) {
                    wynik += 4;
                    i += 1;
                } else {
                    wynik += 1;
                }
                break;
            default:

                break;
        }
    }
    return wynik;
}