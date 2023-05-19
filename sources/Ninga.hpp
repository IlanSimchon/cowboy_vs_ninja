#ifndef CPP_EX4_NINGA_HPP
#define CPP_EX4_NINGA_HPP
#include "Character.hpp"

namespace ariel{
    class Ninja: public Character{
    private:
        int speed;
    public:
        Ninja(string name, Point location);
        bool isCowboy() override;
        void move(Character *enemy);
        void slash(Character *enemy);
        void setSpeed(int speed);
        string print() override;
    };
}



#endif //CPP_EX4_NINGA_HPP
