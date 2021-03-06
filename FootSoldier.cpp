//
// Created by יאנה on 03/06/2020.
//

#include "FootSoldier.hpp"
#include <math.h>

void FootSoldier::act(std::vector<std::vector<Soldier*>> board,std::pair<int,int> location){
    float near=1000;
    std::pair<int,int> temp;
    for(int i=0; i<board.size() ; i++){
        for (int j=0 ; j<board[0].size(); j++){
            if (board[i][j]!= nullptr){
                if(board[i][j]!=board[location.first][location.second]){
                    if(board[i][j]->getPlayer() != board[location.first][location.second]->getPlayer()){
                        if( near> distance(location.first,location.second,i,j)){
                            near=distance(location.first,location.second,i,j);
                            temp.first=i;
                            temp.second=j;
                        }
                    }
                }
            }
        }


    }
    board[temp.first][temp.second]->setPoints( board[temp.first][temp.second]->getPoints()-board[location.first][location.second]->getDamage());
    if(board[temp.first][temp.second]->getPoints()<=0){
        board[temp.first][temp.second]= nullptr;
    }

}


float FootSoldier::distance(int x1, int y1, int x2, int y2)
{
    // Calculating distance
    return sqrt(pow(x2 - x1, 2) +
                pow(y2 - y1, 2) * 1.0);
}
