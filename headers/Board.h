//
// Created by Ofir on 15/08/2017.
//

#ifndef FIRSTGAME_BOARD_H
#define FIRSTGAME_BOARD_H

#include <stdlib.h>
#include<stdio.h>
#include<iostream>
#include "../headers/Pawn.h"
#include "../headers/X.h"
#include "../headers/O.h"

class Board {
public:
    Board();//ctor
    ~Board();
    void printBoard(); // printing the current board.
    bool checkWinner(int i, int j); // standard check for winner
    void Mark (int i , int j , Pawn * player); // Marking spot
    bool checkValidity(int i, int j);
    bool isFull();

private:
    Pawn * board [3][3]; // play board
    int placed;         // ntotal pawns on board

    void init();
};


#endif //FIRSTGAME_BOARD_H
