#include <utility>

#include <utility>

#include <utility>

#include <iostream>
#include <fstream>
#include <string>

std::ifstream plik("baza/osoby.txt");

struct osoba{
private:
    std::string imie;
    std::string nazwisko;
    std::string pesel;
    std::string miasto;
public:
    osoba(){
        plik >> imie;
        plik >> nazwisko;
        plik >> pesel;
        plik >> miasto;
    }
    osoba(std::string imie, std::string nazwisko, std::string pesel, std::string miasto):
    imie(std::move(imie)), nazwisko(std::move(nazwisko)), pesel(std::move(pesel)), miasto(std::move(miasto)){}
    std::string getName(){
        return imie;
    }
    std::string getSurname(){
        return nazwisko;
    }
    std::string getPESEL(){
        return pesel;
    }
    std::string getCity(){
        return miasto;
    }
    std::string getSex(){
        if(pesel[10]%2==0){
            return "K";
        }
        return "M";
    }
    std::string getBirth(){

    }
};
