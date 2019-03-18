#include <iostream>
#include <vector>


std::vector<int> uzupelnij(int ile){
    std::vector<int> w;
    for(int i = 0; i<=ile; i++){ w.insert(w.end(), i, i); }
    return w;
}

void runVector(){
    std::vector<int> w = uzupelnij(5);
    for(auto el : w) std::cout << el << " ";
}
