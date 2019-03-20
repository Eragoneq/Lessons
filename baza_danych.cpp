#include <iostream>
#include <fstream>
#include <string>

std::ifstream plik("baza/osoby.txt");

struct czarodziej{
private:
    std::string imie;
    std::string nazwisko;
    std::string data;
    std::string dom;
public:
    czarodziej(){
        plik >> imie;
        plik >> nazwisko;
        plik >> data;
        plik >> dom;
    }
    czarodziej(std::string imie, std::string nazwisko, std::string data, std::string dom):
    imie(std::move(imie)), nazwisko(std::move(nazwisko)), data(std::move(data)), dom(std::move(dom)){}
    std::string getImie(){
        return imie;
    }
    std::string getNazwisko(){
        return nazwisko;
    }
    std::string getData(){
        return data;
    }
    std::string getDom(){
        return dom;
    }
};
