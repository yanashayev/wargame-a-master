//
// Created by יאנה on 03/06/2020.
//
#include <exception>
#include "Board.hpp"
#include <iostream>
#include "Soldier.hpp"

using namespace std;

namespace WarGame {
    Soldier *& Board::operator[](std::pair<int, int> location) {
        if (location.first < 0 || location.first > this->board.size() || location.second < 0 ||
            location.second > this->board[0].size()) {
            throw std::invalid_argument("out_of_range");

        }
        return this->board[location.first][location.second];
    }
    Soldier* Board::operator[](std::pair<int,int> location) const{
        if (location.first < 0 || location.first > this->board.size() || location.second < 0 ||
            location.second > this->board[0].size()) {
            throw std::invalid_argument("out_of_range");

        }
        return this->board[location.first][location.second];

    }

    void Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction){
        if (source.first < 0 || source.first >this->board.size() || source.second < 0 ||
            source.second > this->board[0].size()) {
            throw std::invalid_argument("out_of_range");

        }
        if(this->board[source.first][source.second]== nullptr){
            throw std::invalid_argument("there is no soldier in the source location");
        }
         if(this->board[source.first][source.second]->getPlayer()!=player_number){
            throw std::invalid_argument("the soldier in the source belong to the other player");
        }
        if( board[source.first][source.second]!= nullptr && board[source.first][source.second]->getPlayer() == player_number) {
            switch (direction) {
                case Up:
                    if ((source.first + 1) >= this->board.size()) {
                        throw std::invalid_argument("out_of_range");
                    } else if (this->board[source.first + 1][source.second] != nullptr) {
                        throw std::invalid_argument("there is already a soldier in the  target location");
                    } else {

                        this->board[source.first + 1][source.second] = this->board[source.first][source.second];
                        this->board[source.first][source.second] = nullptr;
                        this->board[source.first + 1][source.second]->act(board, {source.first + 1, source.second});
                        check();
                    }
                    break;

                case Down:
                    if ((source.first - 1) <0) {
                        throw std::invalid_argument("out_of_range");
                    } else if (this->board[source.first - 1][source.second] != nullptr) {
                        throw std::invalid_argument("there is already a soldier in the  target location");
                    } else {
                        this->board[source.first - 1][source.second] = this->board[source.first][source.second];
                        this->board[source.first][source.second] = nullptr;
                        this->board[source.first - 1][source.second]->act(board, {source.first - 1, source.second});
                        check();
                    }
                    break;

                case Right:
                    if ((source.second + 1) >= this->board[0].size()) {
                        throw std::invalid_argument("out_of_range");
                    } else if (this->board[source.first][source.second + 1] != nullptr) {
                        throw std::invalid_argument("there is already a soldier in the  target location");
                    } else {
                        this->board[source.first][source.second + 1] = this->board[source.first][source.second];
                        this->board[source.first][source.second] = nullptr;
                        this->board[source.first][source.second + 1]->act(board, {source.first, source.second + 1});
                        check();
                    }

                    break;

                case Left:
                    if ((source.second - 1) < 0) {
                        throw std::invalid_argument("out_of_range");
                    } else if (this->board[source.first][source.second - 1] != nullptr) {
                        throw std::invalid_argument("there is already a soldier in the  target location");
                    } else {
                        this->board[source.first][source.second - 1] = this->board[source.first][source.second];
                        this->board[source.first][source.second] = nullptr;
                        this->board[source.first][source.second - 1]->act(board, {source.first, source.second - 1});
                        check();
                    }
                    break;

                default:
                    break;

            }
        }
        else
        {
            throw std::invalid_argument("place is not belong to you");
        }

    }
    void Board::check() {
        for(int i=0; i<this->board.size();i++){
            for(int j=0;j<this->board[0].size();j++) {
                if (this->board[i][j] != nullptr) {
                    if (this->board[i][j]->getPoints() <= 0) {
                        this->board[i][j]= nullptr;
                    }
                }
            }
        }

    }
    bool Board::has_soldiers(uint player_number) const{
        for(int i=0; i<this->board.size();i++){
            for(int j=0;j<this->board[0].size();j++) {
                if (this->board[i][j] != nullptr) {
                    if (this->board[i][j]->getPlayer() == (int)player_number) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
}