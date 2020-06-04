//
// Created by יאנה on 03/06/2020.
//

#ifndef WARGAME_A_MASTER_FOOTSOLDIER_H
#define WARGAME_A_MASTER_FOOTSOLDIER_H
#include<string>
#include "Soldier.hpp"
class FootSoldier : public virtual Soldier{
public:
    FootSoldier(int player):Soldier(player,100,10,100, "FootSoldier"){}
    void act(std::vector<std::vector<Soldier*>> board,std::pair<int,int> location);
    float distance(int x1, int y1, int x2, int y2);

};
#endif //WARGAME_A_MASTER_FOOTSOLDIER_H
