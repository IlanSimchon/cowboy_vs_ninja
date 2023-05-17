#ifndef CPP_EX4_TEAM2_HPP
#define CPP_EX4_TEAM2_HPP
#include "Team.hpp"

namespace ariel{
    class Team2: public Team{
    public:
    Team2(Character *leader);
    virtual void add(Character* New);
    virtual void attack(Team  *enemy);
    virtual void print();

    };
}
#endif //CPP_EX4_TEAM2_HPP
