#include "../include/Game.hpp"

int main() {
    Game game;
    game.Setup();
    while (!game.isGameOver()) {
        
        game.Draw();
        game.Input();
        game.Logic();
        Sleep(100);
        
    }
    return 0;
}
