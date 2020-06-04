//
// Created by יאנה on 03/06/2020.
//

#include "ParamedicCommander.hpp"
void ParamedicCommander::find(std::vector<std::vector<Soldier*>> board,std::pair<int,int> location){
    int x=location.first;
    int y=location.second;
    // check line up and sizes
    if((x-1)>=0){
        check(board, {(x-1),y},board[x][y]->getPlayer());
        if((y+1)<board[x].size()){
            check(board, {(x-1),(y+1)},board[x][y]->getPlayer());
            check(board, {x,(y+1)},board[x][y]->getPlayer());
        }
        if((y-1)>=0){
            check(board, {(x-1),(y-1)},board[x][y]->getPlayer());
            check(board, {x,(y-1)},board[x][y]->getPlayer());

        }
    }
//check line down
    if((x+1)>board.size()){
        check(board, {(x+1),y},board[x][y]->getPlayer());
        if((y+1)<board[x].size()){
            check(board, {(x+1),(y+1)},board[x][y]->getPlayer());
        }
        if((y-1)>=0){
            check(board, {(x+1),(y-1)},board[x][y]->getPlayer());

        }
    }

}
void ParamedicCommander::act(std::vector<std::vector<Soldier*>> board,std::pair<int,int> location){
    find(board,location); // attacking the closest soldier
    for( int i=0; i<board.size();i++){
        for (int j = 0; j <board[0].size() ; j++){
            if(board[i][j]!= nullptr){
                if(board[location.first][location.second]->getPlayer()==board[i][j]->getPlayer()){
                    if(board[i][j]->getType()=="Paramedic"){
                        board[i][j]->act(board,{i,j});
                    }
                }
            }
        }
    }

}

void ParamedicCommander::check(std::vector<std::vector<Soldier*>> board,std::pair<int,int> location, int player){
    if(board[location.first][location.second]!= nullptr){
        if(board[location.first][location.second]->getPlayer()==player){
            board[location.first][location.second]->setPoints(board[location.first][location.second]->getHealth());
        }
    }
}