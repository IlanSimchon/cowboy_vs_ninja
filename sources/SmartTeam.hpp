#ifndef CPP_EX4_SMARTTEAM_HPP
#define CPP_EX4_SMARTTEAM_HPP

#include "Team.hpp"

namespace ariel {
    class SmartTeam: public Team{
    public:
        SmartTeam(Character *leader);

        void add(Character* New) override;
        void attack(Team  *enemy) override;

    };
}
#endif
