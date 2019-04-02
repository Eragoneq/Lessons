#ifndef PROJEKCIK_GAME_LIB_H
#define PROJEKCIK_GAME_LIB_H
#include <windows.h>
#include <iostream>
#include <memory>
#include <vector>

struct point{
    point(int x, int y, char znak) : x(x), y(y), znak(znak) {}

    point(int x, int y) : x(x), y(y){}

    point() = default;

    bool operator<(int x){
        return (this->x < x && this->y < x);
    }

    int getX() const {
        return x;
    }

    void setX(int x) {
        point::x = x;
    }

    int getY() const {
        return y;
    }

    void setY(int y) {
        point::y = y;
    }

    char getZnak() const {
        return znak;
    }

    void setZnak(char znak) {
        point::znak = znak;
    }

private:
    int x, y;
    char znak{};
};

struct board{
    explicit board(unsigned int size) : size(size) {
        std::vector<point*> w(size*size);
    }

    void setPlansza(std::vector<char> lista) {
        for (int i = 0; i < lista.size(); ++i) {
            board::plansza.emplace_back(new point(i%size, i/size, lista[i]));
        }
    }

    void addPoint(point* in){
        plansza.emplace_back(in);
    }

    int getSize() const {
        return size;
    }

    int getElements() const {
        return size*size;
    }

    point* getPoint(int x, int y){
        return &*plansza[y*size+x];
    }

    bool inPlansza(point in){
        return in < this->size;
    }

    std::vector<std::shared_ptr<point>> &getPlansza() {
        return plansza;
    }

private:
    std::vector<std::shared_ptr<point>> plansza;
    unsigned int size;
};


HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void cls()
{
    COORD coordScreen = { 0, 0 };    // home for the cursor
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;
    if( !GetConsoleScreenBufferInfo( hConsole, &csbi ))
        return;
    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    if( !FillConsoleOutputCharacter( hConsole, (TCHAR) ' ',
                                     dwConSize, coordScreen, &cCharsWritten ))
        return;
    if( !GetConsoleScreenBufferInfo( hConsole, &csbi ))
        return;
    if( !FillConsoleOutputAttribute( hConsole, csbi.wAttributes,
                                     dwConSize, coordScreen, &cCharsWritten ))
        return;
    SetConsoleCursorPosition( hConsole, coordScreen );
}

void narysujPlanszex(std::string name, int size, board tablica, bool isCheckered) {
    std::string spacing = (size>=10 ? "    " : "   ");
    std::cout << spacing << name << std::endl;
    // Oznaczenia gora
    std::cout << spacing << " ";
    for (int i = 0; i < size; i++) std::cout << " " << char('A' + i) << "  ";
    std::cout << std::endl;
    // gorny bok
    std::cout << spacing << char(201) << char(205) << char(205) << char(205);
    for (int i = 0; i < (size - 1); i++) std::cout << char(203) << char(205) << char(205) << char(205);
    std::cout << char(187) << std::endl;
    // środki
    for (int i = 0; i < (size - 1); i++) {
        std::cout << " " << i + 1 << ((i + 1) < 10 && size >=10 ? "  " : " ");
        for (int j = 0; j < size; j++) {
            std::cout << char(186);
            (i+j)%2==0 && isCheckered ? SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED) : SetConsoleTextAttribute(hConsole, 15);
            std::cout << " " << tablica.getPoint(j, i)->getZnak() << " ";
            (i+j)%2==0 ? SetConsoleTextAttribute(hConsole, 15) : false;
        }
        std::cout << char(186) << std::endl;
        //
        std::cout << spacing << char(204) << char(205) << char(205) << char(205);
        for (int j = 0; j < (size - 1); j++) std::cout << char(206) << char(205) << char(205) << char(205);
        std::cout << char(185) << std::endl;
    }
    //dolny koniec |__
    std::cout << " " << size << " ";
    for (int j = 0; j < size; j++) {
        std::cout << char(186);
        ((size - 1)+j)%2==0 && isCheckered ? SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED) : SetConsoleTextAttribute(hConsole, 15);
        std::cout << " " << tablica.getPoint(j, (size - 1))->getZnak() << " ";
        ((size - 1)+j)%2==0 ? SetConsoleTextAttribute(hConsole, 15) : false;
    }
    std::cout << char(186) << std::endl;
    std::cout << spacing << char(200) << char(205) << char(205) << char(205);
    for (int i = 0; i < (size - 1); i++) std::cout << char(202) << char(205) << char(205) << char(205);
    std::cout << char(188) << std::endl;
}
#endif //PROJEKCIK_GAME_LIB_H
