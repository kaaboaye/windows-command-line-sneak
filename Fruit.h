//
// Created by admin on 17.06.2018.
//

#ifndef SNEAK_FRUIT_H
#define SNEAK_FRUIT_H


#include "Cartesian.h"

class Fruit {
    Cartesian position;

public:
    explicit Fruit(Cartesian position);

    const Cartesian &GetPosition() const;
};


#endif //SNEAK_FRUIT_H
