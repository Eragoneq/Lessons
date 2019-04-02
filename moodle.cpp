#include <iostream>
#include <fstream>

bool czyDoskonala(int liczba){
    int suma = 0;
    for (int i = 1; i * i <= liczba; i++) {
        if (liczba % i == 0) {
            suma+=i;
            suma+=(liczba/i);
        }
    }
    suma-=liczba;
    return (suma==liczba);
}


void zadanie1(){
    for (int i = 6; i < 900000; ++i) {
        if(czyDoskonala(i)){
            std::cout << i << " ";
        }
    }
}

bool czySkojarzone(int a, int b){
    int suma = 0;
    for (int i = 1; i * i <= a; i++) {
        if (a % i == 0) {
            suma+=i;
            suma+=(a/i);
        }
    }
    suma-=a;
    if(suma==(b+1)){
        suma = 0;
        for (int i = 1; i * i <= b; i++) {
            if (b % i == 0) {
                suma+=i;
                suma+=(b/i);
            }
        }
        suma-=b;
        if(suma==(a+1)) return true;
    }
    return false;
}

void zadanie2(){
    int x,y;
    std::cin >> x >> y;
    if(czySkojarzone(x,y)){
        std::cout << "TAK" << std::endl;
    }else{
        std::cout << "NIE" << std::endl;
    }
}

int euklides(int a, int b){
    if(b==0) return a;
    return euklides(b, a%b);
}

int NWW(int a, int b){
    return ((a*b)/euklides(a,b));
}

void zadanie3(){
    int a,b;
    std::cin >> a >> b;
    std::cout << NWW(a,b);
}

int sumaCyfr(int in){
    int suma;
    suma = 0;
    while(in!=0){
        suma+=in%10;
        in/=10;
    }
    return suma;
}

void zadanie4(){
    std::ifstream in("liczby.txt");
    int liczba;
    int suma = 0;
    int najLiczba = 0;
    while(!in.eof()){
        in >> liczba;
        if(suma < sumaCyfr(liczba)){
            suma = sumaCyfr(liczba);
            najLiczba = liczba;
        }
    }
    std::cout << najLiczba;
}

bool czyRosnaca(int in){
    int poprzednia = 10;
    while(in!=0){
        if(poprzednia<=in%10){
            return false;
        }
        poprzednia = in%10;
        in/=10;
    }
    return true;
}

void zadanie5(){
    std::ifstream in("liczby1.txt");
    int liczba;
    while(!in.eof()){
       in >> liczba;
       if(czyRosnaca(liczba)){
           std::cout << liczba << "\n";
       }
    }
}

bool czyTrzyCzynniki(int in){
    int czynniki[3] = {0};
    if(in%2==0){
        return false;
    }else{
        int i = 3;
        int index = 0;
        while(in != 1){
            if(in%i==0){
                if(czynniki[index]==0){
                    czynniki[index]=i;
                } else if(czynniki[index]!=i){
                    if(index==2){
                        return false;
                    }
                    czynniki[++index]=i;
                }
                in/=i;
            }else{
                if(i>(in/2)){
                    i=in;
                }else i+=2;
            }
        }
    }
    return czynniki[2] != 0;
}

void zadanie6(){
    std::ifstream in("liczby.txt");
    int liczba;
    int licznik = 0;
    while(!in.eof()){
        in >> liczba;
        if(czyTrzyCzynniki(liczba)){
            licznik++;
        }
    }
    std::cout << licznik;
}

void zadanie7(){
    int liczba = 0;
    int liczby[2] = {0};
    int licznik = 0;
    std::ifstream in("liczby3.txt");
    while(!in.eof()){
        in >> liczba;
        if(liczba<1000){
            liczby[1]=liczby[0];
            liczby[0]=liczba;
            licznik++;
        }
    }
    std::cout << licznik << " " << liczby[0] << " " << liczby[1];
}

bool dzielnikiLiczby(int liczba){
    int licznik = 0;
    int dzielniki[18] = {0};
    for (int i = 1; i * i <= liczba; i++) {
        if (liczba % i == 0) {
            if(licznik==9) return false;
            dzielniki[licznik]=i;
            dzielniki[17-licznik]=(liczba/i);
            licznik++;
        }
    }
    if(licznik<9) return false;
    std::cout << liczba << " ";
    for(auto el : dzielniki){
        std::cout << el << " ";
    }
    std::cout << "\n";
    return true;
}

void zadanie8(){
    int liczba;
    std::ifstream in("liczby4.txt");
    while(!in.eof()){
        in >> liczba;
        dzielnikiLiczby(liczba);
    }
}

bool czyWzgledniePierwsza(int* tablica, int index){
    for(int j = 0; j<200; j++){
        if(euklides(tablica[index], tablica[j])!=1 && index!=j){
            return false;
        }
    }
    return true;
}

void zadanie9(){
    int liczba;
    int najw = 0;
    int licznik = 0;
    int tablica[200];
    std::ifstream in("liczby.txt");
    while(!in.eof()){
        in >> liczba;
        tablica[licznik++] = liczba;
    }
    for(int i = 0; i < 200; i++){
        if(czyWzgledniePierwsza(tablica, i)){
            if(najw<tablica[i]){
                najw=tablica[i];
                std::cout << i << " ";
            }
        }
    }
    std::cout << najw;
}

int konwersja(int a){
    int suma = 0;
    for(int i=1;a!=0;i*=8) {
        suma += a%10 * i;
        a/=10;
    }
    return suma;
}

void zadanie10(){
    int liczba1, liczba2;
    int licznik = 0;
    std::ifstream in1("liczby1.txt");
    std::ifstream in2("liczby2.txt");
    while(!in1.eof()){
        in1 >> liczba1;
        in2 >> liczba2;
        if(konwersja(liczba1)==liczba2) licznik++;
    }
    std::cout << licznik;
}

using namespace std;

void zadanie11(){
    string in;
    int licznik = 0;
    char poprzedni = ' ';
    cin >> in;
    for(int i  = 0; i < in.length(); i++){
        if(in[i]==poprzedni) licznik++;
        else if (licznik==2){
            break;
        }else{
            licznik=0;
        }
        poprzedni=in[i];
    }
    if (licznik==2) cout << "TAK";
    else cout << "NIE";
}

void zadanie12(){
    int a,b;
    a=5;
    b=7;
    string in, wynik;
    cin >> in;
    wynik = "";
    for(unsigned int i = 0; i<in.length(); i++){
        char znak = in[i];
        if('a' <= znak){
            wynik+=char(((znak-' ')*a+b-'A')%26+'a');
        } else if ('A' <= znak){
            wynik+=char((znak*a+b-'A')%26+'A');
        }
    }
    cout << wynik;
}

void runZadania() {
//    zadanie1();
//    zadanie2();
//    zadanie3();
//    zadanie4();
//    zadanie5();
//    zadanie6();
//    zadanie7();
//    zadanie8();
//    zadanie9();
//    zadanie10();
//    zadanie11();
//    zadanie12();
}
