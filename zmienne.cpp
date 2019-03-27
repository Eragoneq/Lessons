#include <iostream>
#include <vector>

void wskazniki(){
    int a = 1;
    int b = 9;
    int *wskb, *wska;
    wskb = &b;
    wska = &a;
    std::cout << wskb << " " << wska << "\n";
    //wartosc przed
    std::cout << *wskb << " " << *wska << "\n";
    //wartosc po zmianie
    std::cout << ++(*wskb) << " " << (*wskb)++ << "\n";
    b=9;
    //zmiana wartosci w inny sposob
    std::cout << ++(*wskb) << " ";
    std::cout << (*wskb)++ << "\n";
    //ostateczna wartosc
    std::cout << *wskb << "\n";
}

int* funkcja(int t[]){
    t[0]=2;
    t[1]=1;
    t[2]=3;
    t[4]=7;
    return t;
}
void tablica(){
    int tab[4];
    std::cout << funkcja(tab) << "\n";
    std::cout << tab+1;
}

struct uczen{
    std::string name;
    float srednia;
};

void struktura(){
    uczen a;
    uczen* wsk;
    wsk = &a;
}
void runZmienne(){

}

