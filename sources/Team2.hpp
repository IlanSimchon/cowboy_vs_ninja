#ifndef CPP_EX4_TEAM2_HPP
#define CPP_EX4_TEAM2_HPP
#include "Team.hpp"

namespace ariel{
    class Team2: public Team{
    public:

    Team2(Character *leader);
    void add(Character* New) override;

    };
}
#endif
