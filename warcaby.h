#ifndef PROJEKCIK_WARCABY_H
#define PROJEKCIK_WARCABY_H

#include <iostream>

enum class color : char{
    BLANK,
    WHITE,
    BLACK
};
//debug
std::ostream& operator<<(std::ostream& os, const color& other)
{
    switch (other)
    {
        case color::BLANK:
            os << "BLANK";
            break;
        case color::WHITE:
            os << "WHITE";
            break;
        case color::BLACK:
            os << "BLACK";
            break;
        default:
            break;
    }
    return os;
}

enum class type{
    NONE,
    NORMAL,
    KING
};

std::ostream& operator<<(std::ostream& os, const type& other)
{
    switch (other)
    {
        case type::NONE:
            os << "NONE";
            break;
        case type::NORMAL:
            os << "NORMAL";
            break;
        case type::KING:
            os << "KING";
            break;
        default:
            break;
    }
    return os;
}

struct pionek : point{

    explicit pionek(color color): type(type::NORMAL), color(color){};

    pionek(){update();}

    void upgrade(){
        this->type = type::KING;
    }

    void remove(){
        this->type = type::NONE;
        this->color = color::BLANK;
    }

    void update(){
        switch(getZnak()){
            case ' ':
                this->type = type::NONE;
                this->color = color::BLANK;
                break;
            case 'b':
                this->type = type::NORMAL;
                this->color = color::WHITE;
                break;
            case 'c':
                this->type = type::NORMAL;
                this->color = color::BLACK;
                break;
            default:
                this->type = type::NONE;
                this->color = color::BLANK;
                break;
        }
    }

    type getType() const {
        return type;
    }

    color getColor() const {
        return  color;
    }

private:
    color color;
    type type;
};

#endif //PROJEKCIK_WARCABY_H
