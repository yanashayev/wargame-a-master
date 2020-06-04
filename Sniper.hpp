//
// Created by יאנה on 03/06/2020.
//

#ifndef WARGAME_A_MASTER_SNIPER_H
#define WARGAME_A_MASTER_SNIPER_H
#include<string>
#include "Soldier.hpp"
class Sniper : public virtual Soldier{
public:
    Sniper(int play): Soldier(play, 100, 50,100, "Sniper"){}
    void act(std::vector<std::vector<Soldier*>> board,std::pair<int,int> location);
};

#endif //WARGAME_A_MASTER_SNIPER_H
