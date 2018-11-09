#include <iostream>
#include <vector>

float obliczWielomianReku(std::vector<float> wsp, float x, int index){
    if(index == 0){
        return wsp[0];
    }
    return obliczWielomianReku(wsp, x, index-1) * x + wsp[index];
}

void runObliczWielomianReku(){
    std::vector<float> in{2, -3, 5, -2};
    std::cout << obliczWielomianReku(in, -1, in.size()-1);
}