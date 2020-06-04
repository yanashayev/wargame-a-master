//
// Created by יאנה on 03/06/2020.
//

#include "SniperCommander.hpp"
void SniperCommander::attack(std::vector<std::vector<Soldier*>> board,std::pair<int,int> location){
    std::pair<int,int> temp;
    int stronger=0;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(board[i][j]!= nullptr){
                if(board[i][j]->getPlayer()!=board[location.first][location.second]->getPlayer()){
                    if(board[i][j]->getPoints()>stronger){
                        temp.first=i;
                        temp.second=j;
                        stronger=board[i][j]->getPoints();
                    }
                }
            }
        }
    }
    board[temp.first][temp.second]->setPoints(board[temp.first][temp.second]->getPoints()-board[location.first][location.second]->getDamage());
    if(board[temp.first][temp.second]->getPoints()<=0){
        board[temp.first][temp.second]= nullptr;
    }

}

void SniperCommander::act(std::vector<std::vector<Soldier*>> board,std::pair<int,int> location){
    attack(board,location); // attacking the closest soldier
    for( int i=0; i<board.size();i++){
        for (int j = 0; j <board[0].size() ; j++){
            if(board[i][j]!= nullptr){
                if(board[location.first][location.second]->getPlayer()==board[i][j]->getPlayer()){
                    if(board[i][j]->getType()=="Sniper"){
                        board[i][j]->act(board,{i,j});
                    }

                }
            }
        }
    }

}
 // find the closest soldier and attack