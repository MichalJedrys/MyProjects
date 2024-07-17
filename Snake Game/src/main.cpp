#include "../include/Game.hpp"

int main() {
    Game game;
    while(!game.exitGame())
    {
        if(!game.isGameOver()) {
            game.Draw();
            game.Input();
            game.Logic();
            Sleep(100);
        }else{
            system("cls");
            std::cout << "GAME OVER" << std::endl;
            std::cout << "YOUR SCORE: " << game.getScore() << "!" << std::endl;
            std::cout << "Do you want to play again? Y/N" << std::endl;
            game.InputMenu();
            Sleep(100);
        }
    }
    return 0;
}
