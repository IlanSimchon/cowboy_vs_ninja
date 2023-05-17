#ifndef CPP_EX4_SMARTTEAM_HPP
#define CPP_EX4_SMARTTEAM_HPP
#include "Team.hpp"

namespace ariel {
    class SmartTeam: public Team{
    public:
        SmartTeam(Character *leader);
        virtual void add(Character* New);
        virtual void attack(Team  *enemy);
        virtual void print();

    };
}
#endif
