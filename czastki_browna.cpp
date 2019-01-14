#include <iostream>
#include <fstream>
#include <math>
#include "random.h"

#define SIZE 100

void genCzastkiBrowna(){
    std::ofstream out("brown.xlsx");
    float x, y;
    x = 0;
    y = 0;
    out<<x<<"\t"<<y<<std::endl;
    for(int i = 0; i<SIZE; i++){
        float alfa = randFloat(0, 2*M_PI);
        x = x + cos(alfa);
        y+=sin(alfa);
    }
    
}
