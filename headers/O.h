//
// Created by Ofir on 15/08/2017.
//

#ifndef FIRSTGAME_O_H
#define FIRSTGAME_O_H

#include "../headers/Pawn.h"

class O : public Pawn {
public:
    O();
    O (const O & obj) = default;
    inline virtual std::string toString();
};


#endif //FIRSTGAME_O_H
