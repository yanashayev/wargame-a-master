//
// Created by יאנה on 03/06/2020.
//

#ifndef WARGAME_A_MASTER_PARAMEDICCOMMANDER_H
#define WARGAME_A_MASTER_PARAMEDICCOMMANDER_H

#include "Paramedic.hpp"
#include<string>
#include "Soldier.hpp"
class ParamedicCommander: public virtual Soldier{
public:
    ParamedicCommander(int player):Soldier(player,200,200,200,"ParamedicCommander"){}
    void act(std::vector<std::vector<Soldier*>> board,std::pair<int,int> location);
    void find(std::vector<std::vector<Soldier*>> board,std::pair<int,int> location);
    void check(std::vector<std::vector<Soldier*>> board,std::pair<int,int> location, int player);

};
#endif //WARGAME_A_MASTER_PARAMEDICCOMMANDER_H
