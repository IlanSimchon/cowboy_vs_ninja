#ifndef CPP_EX4_CHARACTER_HPP
#define CPP_EX4_CHARACTER_HPP
#include "Point.hpp"
#include "string"
using namespace std;
namespace ariel {
    class Character {
    private:
        Point location;
        int hitPoints;
        string name;
    public:
        Character(string name, Point location);

        Character(const Character& other);
        Character(Character&& other) noexcept;


        virtual ~Character() = default;

        bool isAlive();

        double distance(const Character *other);

        void hit(int hits);

        string getName();

        Point getLocation();

        virtual string print() = 0;

        int getHitPoints();

        void setHitPoints(int hits);


        Character& operator=(const Character& other);
        Character& operator=(Character&& other) noexcept;

    };
}

#endif //CPP_EX4_CHARACTER_HPP
