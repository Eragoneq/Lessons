#include <iostream>
#include <cmath>
///
///  NIE DOKONCZONEEEE
///
float pierwiastek(float input, float x){
    float i;
    if(input>=2){
        i=input/2;
    }else{
        i=input;
    }

    while(std::fabs(i-input/i)>0.001){
        i = (pow(i, x)  + input/pow(i, x))/2;
    }

    return i;
}

void runPierwiastek(){
    float x;
    int y;
    std::cout << "Podaj liczbe do spierwiastkowania: \n";
    std::cin >> x;
    std::cout << "Podaj stopien pierwiastka: \n";
    std::cin >> y;

    std::cout << pierwiastek(x, y);
}
