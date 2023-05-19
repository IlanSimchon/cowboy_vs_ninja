#ifndef CPP_EX4_TEAM_HPP
#define CPP_EX4_TEAM_HPP

#include "Point.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "vector"

namespace ariel{
    class Team{
    private:
        vector<Character*> Characters;
        Character *leader;
    public:
        Team(Character *leader);
        Team(const Team& other);
        Team(Team&& other) noexcept;

        virtual ~Team();
        virtual void add(Character* New);
        void attack(Team  *enemy);
        int stillAlive();
        void print();
        vector<Character*> getCharacters();
        void setCharacters(Character* New);
        void updateLeader();


        Team& operator=(const Team& other);
        Team& operator=(Team&& other) noexcept;
    };

}
#endif
