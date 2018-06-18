//
// Created by admin on 17.06.2018.
//

#include "Sneak.h"

Sneak::Sneak(Cartesian position) {
    this->position = position;
    this->direction = {0, 0};
    this->velocity = 1;
}

void Sneak::SetDirection(Direction direction) {
    switch (direction) {
        case STOP:
            this->direction = {0, 0};
            break;

        case UP:
            this->direction = {1, 0};
            break;

        case DOWN:
            this->direction = {-1, 0};
            break;

        case LEFT:
            this->direction = {0, -1};
            break;

        case RIGHT:
            this->direction = {0, 1};
            break;
    }
}

const Cartesian &Sneak::GetPosition() const {
    return position;
}

const Sneak::Tail &Sneak::GetTail() const {
    return tail;
}

void Sneak::Move() {
    position += direction * velocity;
}

void Sneak::Eat() {
    tail.push_front(position);
}

