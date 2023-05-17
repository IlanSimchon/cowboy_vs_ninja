#ifndef CPP_EX4_NINGA_HPP
#define CPP_EX4_NINGA_HPP
#include "Character.hpp"

namespace ariel{
    class Ninja: public Character{
    private:
        int speed;
    public:
        Ninja(string name, Point *location);
        void move(Character *enemy);
        void slash(Character *enemy);
        void setSpeed(int speed);
        virtual string print();
    };
}



#endif //CPP_EX4_NINGA_HPP
