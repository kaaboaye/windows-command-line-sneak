//
// Created by admin on 17.06.2018.
//

#include "GameController.h"

GameController::GameController() {
    isContinue = true;
    score = 0;
    sneak = new Sneak(Cartesian{WIDTH / 2, HEIGHT / 2});

    fruit = new Fruit(Cartesian{rand() % WIDTH, rand() % HEIGHT});
}

#include "GameController.h"

void GameController::Run() {
    while (isContinue) {
        input();
        physicsUpdate();
        update();
        Sleep(100);
    }
}

void GameController::input() {
    if (_kbhit()) {
        switch (tolower(_getch())) {
            case 'w':
                sneak->SetDirection(UP);
                break;

            case 's':
                sneak->SetDirection(DOWN);
                break;

            case 'a':
                sneak->SetDirection(LEFT);
                break;

            case 'd':
                sneak->SetDirection(RIGHT);
                break;

            case 'x':
                isContinue = false;
                break;

            default:break;
        }
    }
}

void GameController::physicsUpdate() {
    const Cartesian position = sneak->GetPosition();

    // Check collision with walls
    if (
            position.x > WIDTH ||
            position.x < 0 ||
            position.y > HEIGHT ||
            position.y < 0
            ) {
        isContinue = false;
        return;
    }

    // Check collision with tail
    for (const auto &scale : sneak->GetTail()) {
        if (position == scale) {
            isContinue = false;
            return;
        }
    }

    // Move snake
    sneak->Move();

    // Eat fruit
    if (position == fruit->GetPosition()) {
        score += 10;
        sneak->Eat();

        delete fruit;
        fruit = new Fruit(Cartesian{rand() % WIDTH, rand() % HEIGHT});
    }
}

void GameController::update() {
    system("cls");

    std::cout << std::string(WIDTH, '#') << std::endl;

    Cartesian current = {0, 1};
    for (; current.x < HEIGHT; ++current.x) {

        std::cout << '#';

        for (; current.y < WIDTH - 1; ++current.y) {

            // Print head
            if (current == sneak->GetPosition()) {
                std::cout << '0';
                continue;
            }

            // Print fruit
            if (current == fruit->GetPosition()) {
                std::cout << 'F';
                continue;
            }

            // Print tail
            bool isNotTail = true;
            for (const auto &scale : sneak->GetTail()) {
                if (current == scale) {
                    std::cout << 'o';
                    isNotTail = false;
                    break;
                }
            }

            if (isNotTail) {
                std::cout << ' ';
            }
        }

        std::cout << '#' << std::endl;
    }

    std::cout << std::string(WIDTH, '#') << std::endl
            << "Wynik: " << score << std::endl;

}

GameController::~GameController() {
    delete sneak;
    delete fruit;
}
