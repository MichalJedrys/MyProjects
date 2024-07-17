#include "../include/Game.hpp"

void Game::Setup() noexcept {
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    tailX[0] = x;
    tailY[0] = y;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

void Game::Draw() noexcept  {
    system("cls");
    std::cout << "Use WASD to control. Press X to exit." << std::endl;
    for (int i = 0; i < width + 2; i++)
        std::cout << "#";
    std::cout << std::endl;

    std::string line = "";

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width + 1; j++) {
            if (j == 0 || j == width)
                line = line + "#";
            if (i == y && j == x)
                line = line + "O";
            else if (i == fruitY && j == fruitX)
                line = line + "F";
            else {
                bool print = false;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        line = line + "O";
                        print = true;
                    }
                }
                if (!print && j < width)
                    line = line + " ";
            }
        }
        std::cout << line << std::endl;
        line = "";
    }

    for (int i = 0; i < width + 2; i++)
        std::cout << "#";
    std::cout << std::endl;

    std::cout << "Score: " << score << std::endl;
}

void Game::Input() noexcept  {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            if (dir != RIGHT)
            {
                dir = LEFT;
            }
            break;
        case 'd':
            if (dir != LEFT)
            {
                dir = RIGHT;    
            }
            break;
        case 'w':
            if (dir != DOWN)
            {
                dir = UP;
            }
            break;
        case 's':
            if (dir != UP)
            {
                dir = DOWN;
            }
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

void Game::Logic() noexcept  {
    int prevX = tailX[0];
    int prevY = tailY[0];
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < nTail; i++) {
        tailX[i] = tailX[i] ^ prevX; 
        prevX = tailX[i] ^ prevX; 
        tailX[i] = tailX[i] ^ prevX; 

        tailY[i] = tailY[i] ^ prevY; 
        prevY = tailY[i] ^ prevY; 
        tailY[i] = tailY[i] ^ prevY; 
    } 

    switch (dir) {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    if (x >= width || x < 0 || y >= height ||  y < 0) {
        gameOver = true;
    }

    for (int i = 1; i < nTail; i++){
        if (tailX[i] == x && tailY[i] == y){
            gameOver = true; 
        }
    }

    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}

bool Game::isGameOver() noexcept 
{
    return gameOver;
}