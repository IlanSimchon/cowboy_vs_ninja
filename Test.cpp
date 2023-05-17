#include "doctest.h"
#include "sources/Team.hpp"
#include "sources/Team2.hpp"
#include "sources/SmartTeam.hpp"
#include <stdexcept>

using namespace ariel;
using namespace std;

TEST_CASE("Point class tests") {
    Point point1(2.3, 5.1);
    Point point2(8.4, 2.7);
    Point point3(5.3, 11.2);
    Point point4(-4.1, 12.4);

    CHECK_EQ(point1.distance(point2), 6.56);
    CHECK_EQ(point3.distance(point4), 9.48);

    Point point5(1, 1);
    Point point6(7, 1);

    for (int i = 10; i > 5; --i) {
        CHECK_EQ(Point::moveTowards(point5, point6, i) , point6);
    }
    for (int i = 5; i < 0; --i) {
        CHECK_EQ(Point::moveTowards(point5, point6, i) , Point(6, 1));
    }
}

TEST_CASE("Cowboy test"){
    Point point1(2.3 , 5.4);
    Cowboy cowboy1("Yossi" , point1);
    Cowboy cowboy2("forShoot" , Point(7.7, 6.6));


    CHECK_EQ(cowboy1.getName() , "Yossi");
    CHECK_EQ(cowboy1.getLocation() , point1);

    CHECK_EQ(cowboy1.getHitPoints() , 110);

    CHECK(cowboy1.hashBullets());

    CHECK(cowboy1.isAlive());

    cowboy1.hit(50);

    CHECK_EQ(cowboy1.getHitPoints() , 60);


    CHECK(cowboy1.isAlive());

    cowboy1.hit(60);

    CHECK_EQ(cowboy1.getHitPoints() , 0);


    CHECK_FALSE(cowboy1.isAlive());

    for (int i = 0; i < 6 ; ++i) {
        cowboy1.shoot(&cowboy2);
        CHECK(cowboy1.hashBullets());
    }
    CHECK_FALSE(cowboy1.hashBullets());

    cowboy1.reload();

    CHECK(cowboy1.hashBullets());

    CHECK_EQ(cowboy1.distance(&cowboy2) , 5.53);

    CHECK_THROWS_AS(cowboy1.hit(-20) , invalid_argument);
    CHECK_NOTHROW(cowboy1.print());

}

TEST_CASE("Ninja test"){
    Point point1(3.3,6.5);
    Point point2(2.3 , 8.9);
    Point point3(7.9 , 1.5);
    YoungNinja young("Yossi" , point1);
    TrainedNinja trained("Moshe" , point2);
    OldNinja old("Shlomo" , point3);
    Cowboy enemy("enemy" , Point(22.6 , 14.5));

    CHECK_EQ(young.getName() , "Yossi");
    CHECK_EQ(trained.getName() , "Moshe");
    CHECK_EQ(old.getName() , "Shlomo");

    CHECK_EQ(young.getLocation() , point1);
    CHECK_EQ(trained.getLocation() , point2);
    CHECK_EQ(old.getLocation() , point3);

    CHECK_EQ(young.getHitPoints() , 100);
    CHECK_EQ(trained.getHitPoints() , 120);
    CHECK_EQ(old.getHitPoints() , 150);

    CHECK(young.isAlive());
    CHECK(trained.isAlive());
    CHECK(old.isAlive());

    young.hit(80);
    trained.hit(80);
    old.hit(90);

    CHECK_EQ(young.getHitPoints() , 20);
    CHECK_EQ(trained.getHitPoints() , 40);
    CHECK_EQ(old.getHitPoints() , 60);

    CHECK(young.isAlive());
    CHECK(trained.isAlive());
    CHECK(old.isAlive());

    young.hit(20);
    trained.hit(40);
    old.hit(60);

    CHECK_FALSE(young.isAlive());
    CHECK_FALSE(trained.isAlive());
    CHECK_FALSE(old.isAlive());

    CHECK_EQ(young.getHitPoints() , 0);
    CHECK_EQ(trained.getHitPoints() , 0);
    CHECK_EQ(old.getHitPoints() , 0);

    CHECK_EQ(young.distance(&enemy) , 20.89);
    CHECK_EQ(trained.distance(&enemy) , 21.06);
    CHECK_EQ(old.distance(&enemy) , 19.62);

    young.move(&enemy);
    trained.move(&enemy);
    old.move(&enemy);

    CHECK_EQ(young.distance(&enemy) , 6.89);
    CHECK_EQ(trained.distance(&enemy) , 9.06);
    CHECK_EQ(old.distance(&enemy) , 11.62);

    young.move(&enemy);
    trained.move(&enemy);
    old.move(&enemy);


    young.slash(&enemy);
    CHECK_EQ(enemy.getHitPoints() , 70);

    young.slash(&enemy);
    CHECK_EQ(enemy.getHitPoints() , 30);

    young.slash(&enemy);
    CHECK_EQ(enemy.getHitPoints() , 30);

    young.slash(&enemy); // for kill him

    CHECK_EQ(enemy.getHitPoints() , -10);
    CHECK_FALSE(enemy.isAlive());

    CHECK_NOTHROW(young.print());
    CHECK_NOTHROW(trained.print());
    CHECK_NOTHROW(old.print());

    CHECK_THROWS_AS(young.hit(-10) , invalid_argument);
    CHECK_THROWS_AS(trained.hit(-20) , invalid_argument);
    CHECK_THROWS_AS(old.hit(-30) , invalid_argument);
}

TEST_CASE("Team test"){
    Cowboy cowboy1("1" , Point(1.4, 8.5));
    Cowboy cowboy2("2", Point(4.1, 7.2));
    Cowboy cowboy3("3", Point(1.4, 8.5));
    Cowboy cowboy4("4", Point(67.4, 18.5));



    YoungNinja young1("1", Point(9.1, 4.2));
    YoungNinja young2("2", Point(2.5, 9.1));
    YoungNinja young3("3", Point(4.3, 1.6));
    YoungNinja young4("4", Point(1.3, 8.5));

    TrainedNinja trained1("1", Point(2.8, 5.5));
    TrainedNinja trained2("2", Point(12.4, 9.2));
    TrainedNinja trained3("3", Point(44.4, 82.5));
    TrainedNinja trained4("4", Point(12.4, 85.2));


    OldNinja old1("1", Point(14.4, 28.5));
    OldNinja old2("2", Point(41.4, 82.5));
    OldNinja old3("3", Point(19.4, 88.5));
    OldNinja old4("4", Point(58.4, 23.5));


    // constructor

    Team team1(&cowboy1);

    CHECK_THROWS_AS(Team team2(&cowboy1) , invalid_argument);

    Team team2(&young1);

    CHECK_EQ(team1.stillAlive() , 1);
    CHECK_EQ(team2.stillAlive() , 1);


    // add

    CHECK_NOTHROW(team1.add(&cowboy2));
    CHECK_NOTHROW(team1.add(&cowboy3));
    CHECK_NOTHROW(team1.add(&young2));
    CHECK_NOTHROW(team1.add(&young3));
    CHECK_NOTHROW(team1.add(&trained1));
    CHECK_NOTHROW(team1.add(&trained2));
    CHECK_NOTHROW(team1.add(&trained3));
    CHECK_NOTHROW(team1.add(&old1));
    CHECK_NOTHROW(team1.add(&old2));
    CHECK_NOTHROW(team1.add(&old3));

    CHECK_THROWS_AS(team1.add(&cowboy4) , overflow_error);

    CHECK_THROWS_AS(team2.add(&cowboy2)  , invalid_argument);

    CHECK_NOTHROW(team2.add(&cowboy4));
    CHECK_NOTHROW(team2.add(&young4));
    CHECK_NOTHROW(team2.add(&trained4));
    CHECK_NOTHROW(team2.add(&old4));


    CHECK_EQ(team1.stillAlive() , 10);
    CHECK_EQ(team2.stillAlive() , 5);


    // attack

    team1.attack(&team2);
    CHECK((young4.getHitPoints() < 90)); // is very soon to the captain, and the captain shoots him

    while(team2.stillAlive() > 0) {
        CHECK_NOTHROW(team1.attack(&team2));
    }
    CHECK_THROWS(team1.attack(&team2));
    CHECK_EQ(team2.stillAlive() , 0);

    CHECK_THROWS_AS(team1.attack(&team1) , invalid_argument);


    CHECK_THROWS_AS(Team2 team3(&trained2) , invalid_argument);
    CHECK_THROWS_AS(smartTeam team4(&trained3) , invalid_argument);

    Cowboy cowboy5("1" , Point(9.9,8.3));
    Cowboy cowboy6("2" , Point(12.4,65.3));

    CHECK_NOTHROW(Team2 team3(&cowboy5));
    CHECK_NOTHROW(Team2 team4(&cowboy6));

}
