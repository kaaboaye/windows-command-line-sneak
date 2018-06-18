//
// Created by admin on 17.06.2018.
//

#ifndef SNEAK_GAMECONTROLLER_H
#define SNEAK_GAMECONTROLLER_H

#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include "Sneak.h"
#include "Fruit.h"

#define HEIGHT 25
#define WIDTH 25

class GameController {
    bool isContinue;
    int score;
    Sneak *sneak;
    Fruit *fruit;

public:
    GameController();

    void Run();

    ~GameController();

private:
    void input();
    void physicsUpdate();
    void update();
};


#endif //SNEAK_GAMECONTROLLER_H
