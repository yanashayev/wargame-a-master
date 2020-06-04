//
// Created by יאנה on 03/06/2020.
//

#ifndef WARGAME_A_MASTER_FOOTCOMMANDER_H
#define WARGAME_A_MASTER_FOOTCOMMANDER_H
#include "Soldier.hpp"
#include "FootSoldier.hpp"

class FootCommander: public virtual Soldier{
public:
    FootCommander(int play):Soldier(play,150,20,150,"FootCommander"){}
    void act(std::vector<std::vector<Soldier*>> board,std::pair<int,int> location); //commend all the other foot soldiers to attack
    void attack(std::vector<std::vector<Soldier*>> board,std::pair<int,int> location); // find the closest soldier and attack
    float distance(int x1, int y1, int x2, int y2);

};
#endif //WARGAME_A_MASTER_FOOTCOMMANDER_H
