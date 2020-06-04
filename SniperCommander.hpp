//
// Created by יאנה on 03/06/2020.
//

#ifndef WARGAME_A_MASTER_SNIPERCOMMANDER_H
#define WARGAME_A_MASTER_SNIPERCOMMANDER_H

#include "Sniper.hpp"
#include<string>
#include "Soldier.hpp"
class SniperCommander: public virtual Soldier{
public:
    SniperCommander(int play):Soldier(play,120,100,120,"SniperCommander"){}
    void act(std::vector<std::vector<Soldier*>> board,std::pair<int,int> location); //commend all the other foot soldiers to attack
    void attack(std::vector<std::vector<Soldier*>> board,std::pair<int,int> location); // find the closest soldier and attack
};
#endif //WARGAME_A_MASTER_SNIPERCOMMANDER_H
