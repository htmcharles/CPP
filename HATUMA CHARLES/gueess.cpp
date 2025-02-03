#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

// Function declarations
void playWordGuessingGame(std::map<std::string, int>& scores);
void playNumberGuessingGame(std::map<std::string, int>& scores);
void playColorGuessingGame(std::map<std::string, int>& scores);
void displayShootingMan(int mistakes);

int main() {
    std::cout << "Welcome to the Shooting Man Guessing Game!\n";
    
    // Maps to store scores for each game
    std::map<std::string, int> wordGameScores;
    std::map<std::string, int> numberGameScores;
    std::map<std::string, int> colorGameScores;
    
    int gameChoice;
    bool keepPlaying = true;
    
    // Main loop to allow the user to play multiple games
    while (keepPlaying) {
        std::cout << "Choose a game to play:\n";
        std::cout << "1. Word Guessing Game\n";
        std::cout << "2. Number Guessing Game (1 to 10)\n";
        std::cout << "3. Color Guessing Game\n";
        std::cout << "Enter the number of your choice: ";
        std::cin >> gameChoice;
        
        // Switch case to choose which game to play
        switch (gameChoice) {
            case 1:
                playWordGuessingGame(wordGameScores); // Word guessing game
                break;
            case 2:
                playNumberGuessingGame(numberGameScores); // Number guessing game
                break;
            case 3:
                playColorGuessingGame(colorGameScores); // Color guessing game
                break;
            default:
                playWordGuessingGame(wordGameScores); // Word guessing game
                break;
        }

        // Ask the user if they want to play again
        char playAgain;
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;
        if (playAgain == 'n' || playAgain == 'N') {
            keepPlaying = false; 
        }
        else if (playAgain == 'y' || playAgain == 'Y') {
            keepPlaying = true; 
        }
        else{
        	std::cout << "Invalid input \n";
		}
    }

    return 0;
}

// Word Guessing Game function
void playWordGuessingGame(std::map<std::string, int>& scores) {
    // List of possible words for the game
    std::vector<std::string> words;
    words.push_back("apple");
    words.push_back("banana");
    words.push_back("elephant");
    words.push_back("guitar");
    words.push_back("computer");

    std::srand(static_cast<unsigned int>(std::time(0))); // Seed the random number generator
    int randomIndex = std::rand() % words.size(); // Random index to select a word
    std::string secretWord = words[randomIndex]; // Selected secret word
    std::string guess;
    int attempts = 0; // Track number of attempts
    int mistakes = 0; // Track number of mistakes
    int hintsUsed = 0; // Track how many hints were used
    const int maxMistakes = 5; // Max allowed mistakes
    int hintsRemaining = maxMistakes - 1; // Calculate remaining hints

    std::cout << "Guess the Word!\n";
    // Create a hint (initially only the first letter is shown)
    std::string hint(secretWord.size(), '-');
    hint[0] = secretWord[0];
    int hintLevel = 1; // Level of hints

    // Game loop for guessing the word
    while (true) {
        std::cout << "\nHint: " << hint << "\n";
        std::cout << "Mistakes: " << mistakes << "/" << maxMistakes << "    Hints: " << hintsRemaining << "\n";
        displayShootingMan(mistakes); // Show the current state of the "shooting man"

        std::cout << "Enter your guess (or type 'hint' for an extra letter): ";
        std::cin >> guess;
        attempts++;

        // Check if the user asks for a hint
        if (guess == "hint") {
            if (hintsRemaining > 0) {
                // Reveal the next letter if possible
                if (hintLevel < secretWord.size()) {
                    hint[hintLevel] = secretWord[hintLevel];
                    hintLevel++;
                    hintsRemaining--;
                    hintsUsed++;
                } else {
                    std::cout << "All letters are already revealed.\n";
                }
            } else {
                std::cout << "No hints left! Use your guesses wisely.\n";
            }
            continue;
        }

        // If the guess is correct
        if (guess == secretWord) {
            std::cout << "\nCongratulations! You guessed the word '" << secretWord << "' in " << attempts << " attempts.\n";
            
            // Calculate score: Start with 100 points, subtract 10 for each hint and mistake
            int score = 100 - (hintsUsed * 10) - (mistakes * 10);
            std::string playerName;
            std::cout << "Enter your name: ";
            std::cin >> playerName;
            scores[playerName] = score;

            // Display the scores from other players
            std::cout << "Scores from other players:\n";
            for (std::map<std::string, int>::iterator it = scores.begin(); it != scores.end(); ++it) {
                std::cout << it->first << " - Score: " << it->second << "\n";
            }

            break;
        } else {
            mistakes++;
            std::cout << "Incorrect guess! Mistakes: " << mistakes << "/" << maxMistakes << "\n";
        }

        // If the player has exceeded the allowed number of mistakes
        if (mistakes >= maxMistakes) {
            std::cout << "\nYou've made too many mistakes!\n";
            std::cout << "The shooting man shoots you...\n";
            displayShootingMan(mistakes); // Show the shooting man animation
            std::cout << "Game Over! The correct word was: " << secretWord << "\n";
            break;
        }
    }
}

// Number Guessing Game function (guess a number between 1 and 10)
void playNumberGuessingGame(std::map<std::string, int>& scores) {
    int secretNumber = std::rand() % 10 + 1; // Random number between 1 and 10
    int guess;
    int attempts = 0;
    int mistakes = 0;
    int hintsUsed = 0;
    const int maxMistakes = 5;

    std::cout << "Guess the Number (between 1 and 10)!\n";

    // Game loop for guessing the number
    while (true) {
        std::cout << "\nEnter your guess: ";
        std::cin >> guess;
        
        // Validate the guess input (should be within range)
        if (guess < 1 || guess > 10) {
            std::cout << "Invalid input! Please guess a number between 1 and 10.\n";
            continue;
        }

        attempts++;

        // If the guess is correct
        if (guess == secretNumber) {
            std::cout << "\nCongratulations! You guessed the number '" << secretNumber << "' in " << attempts << " attempts.\n";
            
            // Calculate score: Start with 100 points, subtract 10 for each hint and mistake
            int score = 100 - (hintsUsed * 10) - (mistakes * 10);
            std::string playerName;
            std::cout << "Enter your name: ";
            std::cin >> playerName;
            scores[playerName] = score;

            // Display the scores from other players
            std::cout << "Scores from other players:\n";
            for (std::map<std::string, int>::iterator it = scores.begin(); it != scores.end(); ++it) {
                std::cout << it->first << " - Score: " << it->second << "\n";
            }

            break;
        } else {
            mistakes++;
            if (guess < secretNumber) {
                std::cout << "Your guess is too low! Mistakes: " << mistakes << "/" << maxMistakes << "\n";
            } else {
                std::cout << "Your guess is too high! Mistakes: " << mistakes << "/" << maxMistakes << "\n";
            }
            displayShootingMan(mistakes); // Show the shooting man animation
        }

        // If the player has exceeded the allowed number of mistakes
        if (mistakes >= maxMistakes) {
            std::cout << "\nYou've made too many mistakes!\n";
            std::cout << "The shooting man shoots you...\n";
            displayShootingMan(mistakes); // Show the shooting man animation
            std::cout << "Game Over! The correct number was: " << secretNumber << "\n";
            break;
        }
    }
}

// Color Guessing Game function
void playColorGuessingGame(std::map<std::string, int>& scores) {
    // List of possible colors for the game
    std::vector<std::string> colors;
    colors.push_back("red");
    colors.push_back("blue");
    colors.push_back("green");
    colors.push_back("yellow");    colors.push_back("orange");
    colors.push_back("purple");
    colors.push_back("pink");
    colors.push_back("brown");
    
    std::srand(static_cast<unsigned int>(std::time(0))); // Seed the random number generator
    int randomIndex = std::rand() % colors.size(); // Random index to select a color
    std::string secretColor = colors[randomIndex]; // Selected secret color
    std::string guess;
    int attempts = 0;
    int mistakes = 0;
    int hintsUsed = 0;
    const int maxMistakes = 5;

    std::cout << "Guess the Color!\n";
    
    // Game loop for guessing the color
    while (true) {
        std::cout << "\nEnter your guess: ";
        std::cin >> guess;

        // Check if the guess is correct
        if (guess == secretColor) {
            std::cout << "\nCongratulations! You guessed the color '" << secretColor << "' in " << attempts << " attempts.\n";
            
            // Calculate score: Start with 100 points, subtract 10 for each hint and mistake
            int score = 100 - (hintsUsed * 10) - (mistakes * 10);
            std::string playerName;
            std::cout << "Enter your name: ";
            std::cin >> playerName;
            scores[playerName] = score;

            // Display the scores from other players
            std::cout << "Scores from other players:\n";
            for (std::map<std::string, int>::iterator it = scores.begin(); it != scores.end(); ++it) {
                std::cout << it->first << " - Score: " << it->second << "\n";
            }

            break;
        } else {
            mistakes++;
            std::cout << "Incorrect guess! Mistakes: " << mistakes << "/" << maxMistakes << "\n";
            displayShootingMan(mistakes); // Show the shooting man animation
        }

        // If the player has exceeded the allowed number of mistakes
        if (mistakes >= maxMistakes) {
            std::cout << "\nYou've made too many mistakes!\n";
            std::cout << "The shooting man shoots you...\n";
            displayShootingMan(mistakes); // Show the shooting man animation
            std::cout << "Game Over! The correct color was: " << secretColor << "\n";
            break;
        }
    }
}


// Function to display the "shooting man" graphic based on the number of mistakes

void displayShootingMan(int mistakes) {
    std::string bullet = "*                   ";
    if (mistakes == 1) bullet = "    *               ";
    else if (mistakes == 2) bullet = "      *             ";
    else if (mistakes == 3) bullet = "         *          ";
    else if (mistakes == 4) bullet = "             *      ";
    else if (mistakes == 5) bullet = "                    *";

    std::string gun = "===== ";

    std::cout << "\n\n";
    std::cout << gun << bullet << "O     \n";
    std::cout << "                         /|\\    \n";
    std::cout << "                         / \\    \n";
    std::cout << "\n";
}
