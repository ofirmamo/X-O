//
// Created by Ofir on 15/08/2017.
//

#ifndef FIRSTGAME_X_H
#define FIRSTGAME_X_H

#include "../headers/Pawn.h"
#include "../headers/X.h"
#include <stdlib.h>
#include <iostream>

class X : public Pawn {
public:
    X();
    X(const X & obj) = default;
    inline virtual std::string toString();
};


#endif //FIRSTGAME_X_H
