//
// Created by giow on 6/15/19.
//
#include "Matrix.hpp"
#include "Position.hpp"
#include "ObjTypes.h"

class PlayerObjLogic
{
    Pos player_pos;
    Pos next_pos;
    Matrix* game_board_ref;

    PlayerObjLogic(const Pos& pos, Matrix* game_board): player_pos(pos.x_, pos.y_)
    {
        game_board_ref = game_board;
    }
    bool is_tile(const Pos &pos)
    {
        return game_board_ref->at(pos.x_, pos.y_) == TILE;
    }

    bool can_move(int direction)
    {
        //Check directions of the movement
        switch (direction)
        {
            case UP:
                next_pos.x_ = player_pos.x_;
                next_pos.y_ = player_pos.y_ - 1;
                break;
            case DOWN:
                next_pos.x_ = player_pos.x_;
                next_pos.y_ = player_pos.y_ + 1;
                break;
            case LEFT:
                next_pos.x_ = player_pos.x_ - 1;
                next_pos.y_ = player_pos.y_;
                break;
            case RIGHT:
                next_pos.x_ = player_pos.x_ + 1;
                next_pos.y_ = player_pos.y_;
                break;
            default:
                break;
        }

        // If the position is valid return true
        if(next_pos.x_ > 0 && next_pos.y_ > 0)
        {
            if (next_pos.x_ < game_board_ref->rows_
                && next_pos.y_ < game_board_ref->cols_)
            {
                if(is_tile(Pos(next_pos)))
                    return true;
            }
        }
        return false;
    }

};