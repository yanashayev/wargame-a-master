//
// Created by יאנה on 03/06/2020.
//

#ifndef WARGAME_A_MASTER_SOLDIER_H
#define WARGAME_A_MASTER_SOLDIER_H

#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include "Soldier.hpp"

class Soldier{
protected:
    int points;
    int damage;
    int player;
    int health;
    std::string type;
public:
    virtual ~Soldier(){}


//constractor
    Soldier(int play, int h, int d,int p, std::string t) : player(play),health(h), damage(d),points(p), type(t){};

    virtual void act(std::vector<std::vector<Soldier*>> board,std::pair<int,int> location) {};



    int getPlayer(){
        return player;
    }

    int getPoints(){
        return points;
    }

    void setPoints(int p){
        points=p;
    }
    int getHealth(){
        return health;
    }
    int getDamage(){
        return damage;
    }
    std::string getType(){
        return type;
    }



};

#endif //WARGAME_A_MASTER_SOLDIER_H
