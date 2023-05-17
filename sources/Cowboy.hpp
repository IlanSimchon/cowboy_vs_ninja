#ifndef CPP_EX4_COWBOY_HPP
#define CPP_EX4_COWBOY_HPP

#include "Character.hpp"

namespace ariel {
    class Cowboy: public Character{
    private:
        int numOfBullets;
    public:
        Cowboy(string name, Point *location);
        void shoot(Character *enemy);
        bool hashBullets();
        void reload();
        virtual string print();

    };
}


#endif //CPP_EX4_COWBOY_HPP
