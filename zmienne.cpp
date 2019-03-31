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
    t[3]=7;
    return t;
}
void tablica(){
    int tab[4];
    int *wsk;
    wsk = funkcja(tab);
    std::cout << wsk << "\n";
    std::cout << wsk+1 << "\n";
    std::cout << *wsk << " " << *(wsk+1);
}

struct uczen{
    std::string name;
    float srednia;
};

void struktura(){
    uczen a;
    uczen* wsk;
    wsk = &a;
    a.name = "kek";
    std::cout << wsk->name << " " << sizeof(wsk);
}
void runZmienne(){
    tablica();
}

