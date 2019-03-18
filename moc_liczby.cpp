#include <fstream>
#include <iostream>
#include <map>

int iloczyn(int liczba){
    int iloczyn = 1;
    while(liczba>0){
        iloczyn*=(liczba%10);
        liczba/=10;
    }
    return iloczyn;
}

int obliczMoc(int liczba){
    int moc = 0;
    while(liczba>9){
        moc++;
        liczba=iloczyn(liczba);
    }
    return moc;
}

void runMoc(){
    std::ifstream in("liczby59.txt");
    std::ofstream out("liczby_out.txt");
    std::map<int, int> map;
    int liczba, moc;
    while(!in.eof()){
        in >> liczba;
        moc = obliczMoc(liczba);
        out << moc << " " << liczba << "\n" ;
        map[moc]++;
    }
    for(auto elem : map)
    {
        std::cout << elem.first << " " << elem.second << "\n";
    }
    in.close();
    out.close();
}

