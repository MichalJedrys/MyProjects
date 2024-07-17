#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <string>

class Game
{
public:
    /*
    * @brief Setup function for variables.
    */
    void Setup() noexcept;

    /*
    * @brief Function to draw the board.
    */
    void Draw() noexcept;

    /*
    * @brief Input management.
    */
    void Input() noexcept;

    /*
    * @brief Menu input management.
    */
    void InputMenu() noexcept;

    /*
    * @brief Logic of the game.
    */
    void Logic() noexcept;

    /*
    * @brief Check if game is over.
    */
    bool isGameOver() noexcept;

    /*
    * @brief Check if player wants to close the app.
    */
    bool exitGame() noexcept;

    /*
    * @brief Check if player wants to close the app.
    */
    uint16_t getScore() noexcept;

private:
    // Check whether the game is over.
    bool gameOver = false;
    // Check whether if player wants to close the app.
    bool exit = false;
    // Constants width and height of the game board.
    static const uint8_t width = 40;
    static const uint8_t height = 20;
    // Snake's head position.
    uint8_t x = 0; 
    uint8_t y = 0; 
    // Position of the fruit.
    uint8_t fruitX = 0; 
    uint8_t fruitY = 0; 
    // Player's score.
    uint16_t score = 0; 
    // Length of the snake.
    uint32_t nTail = 0;
    // Max length of the snake.
    static const uint32_t maxTailLen = width * height;
    //Arrays to store the positions of the snake's tail segments.
    uint8_t tailX[maxTailLen];
    uint8_t tailY[maxTailLen];
    // Enumeration representing the direction of the snake (STOP, LEFT, RIGHT, UP, DOWN).
    enum enumDir { STOP = 0, LEFT, RIGHT, UP, DOWN };
    // Current direction of the snake.
    enumDir dir = STOP;
};