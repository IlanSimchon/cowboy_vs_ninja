#ifndef CPP_EX4_COWBOY_HPP
#define CPP_EX4_COWBOY_HPP

#include "Character.hpp"

namespace ariel {
    class Cowboy: public Character{
    private:
        int numOfBullets;
    public:
        Cowboy(string name, Point location);
        bool isCowboy() override;
        void shoot(Character *enemy);
        bool hasboolets();
        void reload();
        string print() override;

    };
}


#endif
