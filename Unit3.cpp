#include <iostream>
#include <cstdlib>
#include <ctime>

class NumberGuessingGame {
private:
    int secretNumber;
    int maxAttempts;

public:
    NumberGuessingGame(int maxAttempts) {
        this->maxAttempts = maxAttempts;
        srand(time(0));  // Seed for random number generation
        secretNumber = rand() % 100 + 1;  // Random number between 1 and 100
    }

    void playGame() {
        int guess;
        int attempts = 0;
        bool guessedCorrectly = false;

        std::cout << "Welcome to Tony's Number Guessing Game!" << std::endl;
        std::cout << "I have selected a number between 1 and 100." << std::endl;
        std::cout << "You have " << maxAttempts << " attempts to guess the correct number." << std::endl;

        while (attempts < maxAttempts && !guessedCorrectly) {
            std::cout << "Enter your guess: ";
            std::cin >> guess;
            attempts++;

            if (guess < secretNumber) {
                std::cout << "Too low!" << std::endl;
            } else if (guess > secretNumber) {
                std::cout << "Too high!" << std::endl;
            } else {
                std::cout << "Congratulations! You guessed the correct number in " << attempts << " attempts." << std::endl;
                guessedCorrectly = true;
            }
        }

        if (!guessedCorrectly) {
            std::cout << "Sorry, you've used all your attempts. The correct number was " << secretNumber << "." << std::endl;
        }
    }
};

int main() {
    NumberGuessingGame game(10);  // Create a game object with 10 max attempts
    game.playGame();  // Start the game
    return 0;
}
