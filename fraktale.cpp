#include <iostream>
#include <fstream>
#include <cmath>
#include "random.h"

#define SIZE 200000

void genCzastkiBrowna(){
    std::ofstream out("brown.xls");
    float x, y;
    x = 0;
    y = 0;
    out<<x<<"\t"<<y<<std::endl;
    for(int i = 0; i<SIZE; i++){
        double alfa = randFloat(0, 2*M_PI);
        x+=cos(alfa);
        y+=sin(alfa);
        out<<x<<"\t"<<y<<std::endl;
    }
    
}

void genSmok(){
    std::ofstream out("smok.xls");
    double x, y;
    x = 0;
    y = 0;
    out<<x<<"\t"<<y<<std::endl;
    for(int i = 0; i<SIZE; i++){
        double x1 = x;
        if(randInt(0,1)){
            x = 0.76*x - 0.4*y;
            y = 0.4*x1 + 0.76*y;
        }else{
            x = -0.4*x - 1;
            y = -0.4*y + 0.1;
        }
        out<<x<<"\t"<<y<<std::endl;
    }
    out.close();
}

void genPaprotkaBarsleya(){
    std::ofstream out("paprotka.xls");
    double x, y;
    x = 0;
    y = 0;
    out<<x<<"\t"<<y<<std::endl;
    for(int i = 0; i<SIZE; i++){
        double x1 = x;
        int los = randInt(0, 100);
        if(los<73){
            x = 0.849*x + 0.037*y + 0.075;
            y = - 0.037*x1 + 0.849*y + 0.183;
        }else if(los < 86){
            x = 0.197*x + -0.226*y + 0.4;
            y = 0.226*x1 + 0.197*y + 0.049;
        }else if(los < 97){
            x = -0.150*x + 0.283*y + 0.575;
            y = 0.260*x1 + 0.237*y - 0.084;
        }else{
            x = 0.5;
            y = 0.16*y;
        }
        out<<x<<"\t"<<y<<std::endl;
    }
    out.close();

}

