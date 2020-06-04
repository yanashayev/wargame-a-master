//
// Created by יאנה on 03/06/2020.
//

#ifndef WARGAME_A_MASTER_PARAMEDIC_H
#define WARGAME_A_MASTER_PARAMEDIC_H
#include<string>
#include "Soldier.hpp"
#include "Soldier.hpp"
class Paramedic : public virtual Soldier{
public:
    Paramedic(int player):Soldier(player,100,100,100,"Paramedic"){}
    void act(std::vector<std::vector<Soldier*>> board,std::pair<int,int> location);
    void check(std::vector<std::vector<Soldier*>> board,std::pair<int,int> location, int player);
};

#endif //WARGAME_A_MASTER_PARAMEDIC_H
