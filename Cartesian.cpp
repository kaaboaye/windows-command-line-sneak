//
// Created by admin on 17.06.2018.
//

#include "Cartesian.h"

bool Cartesian::operator==(const Cartesian &right) const {
    return (x == right.x) && (y == right.y);
}

bool Cartesian::operator!=(const Cartesian &right) const {
    return (x != right.x) || (y != right.y);
}

Cartesian Cartesian::operator+(const Cartesian &c) {
    x += c.x;
    y += c.y;

    return *this;
}

Cartesian Cartesian::operator*(const Cartesian::Unit &mul) {
    x *= mul; // mnozenie z liczba
    y *= mul;

    return *this;
}

Cartesian Cartesian::operator+=(const Cartesian &c) {
    x += c.x;
    y += c.y;

    return *this;
}
