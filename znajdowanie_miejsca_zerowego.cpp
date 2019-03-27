#include <iostream>
#include <fstream>

double f(float x){
    return (x+8)*(x-(2*3.14))*(x*x + 2*x + 5)*2137;
}

float obliczMiejsceZerowe(float a, float b){
    if(f(a)*f(b)>0){
        std::cout << "Blad" << std::endl;
        return 0;
    }
    while(b-a > 0.00001){
        float roznica = (b-a)/2;
        a+=roznica;
        if(f(a)*f(b)>0){
            a-=roznica;
            b-=roznica;
        }else if(f(a)==0){
            return a;
        }
    }
    return (b+a)/2;
}

void runObliczanieMiejscaZerowego(){
    std::ofstream out("miejsce_zerowe.txt");
    float a,b;
    std::cout << "Podaj zakres a, b: \n";
    std::cin >> a >> b;

    std::cout << obliczMiejsceZerowe(a, b);
    out << obliczMiejsceZerowe(a, b);
    out.close();
}