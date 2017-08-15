//
// Created by Ofir on 15/08/2017.
//

#include "../headers/Board.h"
// ctor
Board::Board() : placed(0){
    init();
}
// intialize the board spots with NULL
void Board::init() {
    for(int i = 0 ; i < 3 ; i++){
        for (int j = 0 ; j < 3; j++){
            board[i][j] = NULL;
        }
    }
}
// delete all exiting pawns
Board::~Board() {
    /*
    for (int i = 0 ; i < 3 ; i++){
        for (int j = 0 ; j < 3 ; j++){
            if (board[i][j] != NULL)
                delete board[i][j];
        }
    }
     */
}

 bool Board::checkValidity(int i, int j) {
    return (board[i][j] == NULL);
}

bool Board::isFull() {
    return (placed == 9);
}

// print current state of playing board : checked
void Board::printBoard() {
    std::cout << "board state:" << std::endl;
    for(int i = 0 ; i < 5 ; i++){
        for (int j = 0 ; j < 4 ; j++){
            if (i < 1 || i > 3){cout << "_"; continue;}
            if (j > 2){cout << "|"; continue;}
            string tmp = (board[i - 1][j] != NULL) ? (board[i - 1][j]) -> toString() : to_string((i - 1) * 3 + j);
            cout << "|" + tmp;
        }
        std::cout << "" <<std::endl;
    }
}

bool Board::checkWinner(int i, int j) {
    bool ans = false;
    ans = ans | ((board[i][j] == board[(i + 1) % 3] [j]) && (board[(i + 2) % 3][j] == board[i][j]));
    ans = ans | ((board[i][j] == board[i][(j + 1) % 3])&& (board[i][j] == board[i][(j + 2) % 3]));
    ans = ans | ((board[i][j] == board[(i + 1) % 3][(j + 1) % 3]) && (board[i][j] == board[(i + 2) % 3][(j + 2) % 3]));
    return ans;
}

void Board::Mark(int i, int j, Pawn * player) {
    board[i][j] = player;
    ++ placed;
}
