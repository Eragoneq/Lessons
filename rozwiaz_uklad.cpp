#include <iostream>
#include <array>

float wyznacznik(float a, float b, float c, float d){
    return (a*d)-(b*c);
}

std::array<float, 2> rozwiazRownanie(float a, float b, float c,
                                     float d, float e, float f){
    std::array<float, 2> wynik{};

    float W, Wx, Wy;

    W  = wyznacznik(a,b,
                    d,e);
    Wx = wyznacznik(c,b,
                    f,e);
    Wy = wyznacznik(a,c,
                    d,f);

    if(W!=0){
        wynik[0]=Wx/W;
        wynik[1]=Wy/W;
    }else if(Wx==0 && Wy==0){
        std::cout << "Uklad nieoznaczony\n";
    }else{
        std::cout << "Uklad sprzeczny\n";
    }
    return wynik;
}

void runRozwiazRownanie(){
    float a,b,c,d,e,f;
    std::array<float, 2> wynik{};
    std::cout << "Podaj dla: ax+by=c, dx+ey=f\nW kolejnosci a, b, c, d, e, f\n";
    std::cin >> a >> b >> c >> d >> e >> f;
    wynik = rozwiazRownanie(a,b,c,d,e,f);
    std::cout << "X = " << wynik[0] << "\n";
    std::cout << "Y = " << wynik[1] << "\n";
}