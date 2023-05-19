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
        bool isPlay;
    public:
        Character(string name, Point location);

        Character(const Character& other);
        Character(Character&& other) noexcept;

        virtual ~Character() = default;

        bool isAlive();

        virtual bool isCowboy() = 0;

        double distance(const Character *other);

        void hit(int hits);

        string getName();

        Point getLocation();

        void setLocation(Point newPoint);

        bool getIsPlay();

        void setIsPlay();

        virtual string print() = 0;

        int getHitPoints();

        void setHitPoints(int hits);

        static bool compare(Character* char1 , Character* char2);

        static bool compare2(Character* char1 , Character* char2);


        Character& operator=(const Character& other);
        Character& operator=(Character&& other) noexcept;

    };
}

#endif
