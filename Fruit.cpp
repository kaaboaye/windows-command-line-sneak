//
// Created by admin on 17.06.2018.
//

#include "Fruit.h"

const Cartesian &Fruit::GetPosition() const {
    return position;
}

Fruit::Fruit(Cartesian position) {
    this->position = position;
}
