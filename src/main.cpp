#include <iostream>
#include "../headers/Board.h"

void declareWinner(int i);

bool playTurn(int i , Pawn ** players , Board & Game){
    int x;
    printf("---- player %d Turn, choose number: " , i + 1);
    std::cin >> x;
    if (x < 0 || x > 8){
        printf("Illegal input.\n");
        return playTurn(i , players , Game);
    }
    if (!Game.checkValidity(x / 3, x % 3)){
        printf("spot is reserved\n");
        return playTurn(i , players , Game);
    }
    Game.Mark(x / 3 , x % 3 , players[i]);
    return Game.checkWinner(x / 3, x % 3);
}

int main() {
    Board Game; int i = 0;
    Pawn * players[2];      // array including the 2 players of the game.
    players[0] = new X(); players[1] = new O();
    bool winner = false;
    std::cout << " ------- Starting game -------" << std::endl;
    while(!winner && !Game.isFull()){       // the main loop
        Game.printBoard();                  // printing board state
        winner = playTurn(i , players , Game);  // playing turn
        if(winner) declareWinner(i);
        i = (i + 1) % 2;
    }
    if (!winner) cout <<"------ We got a draw ------" << endl;
    delete players[0] , players[1];
    return 0;
}

void declareWinner(int i) {
    std::cout << "--------The Winner is Player " + to_string(i + 1) + "!!! ---------" << std::endl;
}