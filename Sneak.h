//
// Created by admin on 17.06.2018.
//

#ifndef SNEAK_SNEAK_H
#define SNEAK_SNEAK_H

#include <list>
#include "Cartesian.h"
#include "Direction.h"

class Sneak {
public:
    class Tail: public std::list<Cartesian> {};

private:
    bool popTail;
    Cartesian position;
    Tail tail;
    Cartesian direction;

public:
    explicit Sneak(Cartesian position);

    void SetDirection(Direction direction);
    void Move();
    void Eat();

    const Cartesian &GetPosition() const;
    const Tail &GetTail() const;
};


#endif //SNEAK_SNEAK_H
