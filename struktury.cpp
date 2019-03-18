#include <iostream>
#include <vector>
#include <algorithm>
#include "random.h"

struct point{
private:
    float x;
    float y;
public:
    point(float x, float y): x(x), y(y){}
    point(): x(randInt(-10, 10)),y(randInt(-10, 10)){}
    float getX() {return x;}
    float getY() {return y;}
    void randCoords(){
        this->x = randFloat(-10, 10);
        this->y = randFloat(-10, 10);
    }
};

point srodekOdcinka(point a, point b){
    return {(a.getX()+b.getX())/2, (a.getY()+b.getY())/2};
}

bool warunekSortowania(point a, point b){
    return a.getX()<b.getX();
}

std::vector<point> sortRandPoints(int ilosc) {
    std::vector<point> points;
    for(int i = 0; i<ilosc; i++){
        points.emplace_back();
    }
    for(auto el : points){
        std::cout << el.getX() << " " << el.getY() << "\n";
    }
    std::sort(points.begin(), points.end(), warunekSortowania);
    return points;
}

void runStruktura(){
    std::vector<point> points = sortRandPoints(22);
    std::cout << "\n //////////////// \n\n";
    for(auto el : points){
        std::cout << el.getX() << " " << el.getY() << "\n";
    }
}
