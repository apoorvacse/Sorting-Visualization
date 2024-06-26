                        //NUMBER GUESSING GAME
/*Create a program that generates a random number and asks the
user to guess it. Provide feedback on whether the guess is too
high or too low until the user guesses the correct number.*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>
#include <limits>

using namespace std;

void printStars(int count) {
    for (int i = 0; i < count; ++i) {
        cout << "**";
    }
    cout << endl;
}

void moraleBoostMessage(int attempts) {
    if (attempts >= 10) {
        cout << "TRAIN YOUR BRAIN" << endl;
    } else if (attempts < 10 && attempts > 5) {
        cout << "BRAIN IS THINKING!" << endl;
    } else if (attempts >= 2 && attempts <= 5) {
        cout << "BRAVO" << endl;
    } else {
        cout << "BRAIN STORM" << endl;
    }
}

int main() {
    srand(time(0)); 
    int number = rand() % 100 + 1;
    int guess = 0;
    int attempts = 0;
    int highScore = numeric_limits<int>::max(); 
    set<int> guessedNumbers; 
    bool playing = true;

    cout << "           Chosen a number between 1 and 100." << endl;
    cout << "Type '0' if you want to quit." << endl;

    printStars(30);
    cout << "Let's check your guess!" << endl;
    printStars(30);

    while (playing) {
        cout << "Enter your lucky number: ";
        cin >> guess;

        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid input. Please enter a number between 1 and 100." << endl;
            continue;
        }

       
        if (guess == 0) {
            cout << "You have chosen to quit the game." << endl;
            playing = false;
            break;
        }

       
        if (guess < 1 || guess > 100) {
            cout << "Invalid number. Please enter a number between 1 and 100." << endl;
            continue;
        }

        if (guessedNumbers.find(guess) != guessedNumbers.end()) {
            cout << "You have already guessed this number. Try a different number." << endl;
            continue;
        }

        guessedNumbers.insert(guess);
        attempts++;

        if (guess > number) {
            cout << "\033[31m" << "Too high! Subtract a few numbers." << "\033[0m" << endl; // Red color for incorrect guess
        } else if (guess < number) {
            cout << "\033[31m" << "Too low! Add a few numbers." << "\033[0m" << endl; // Red color for incorrect guess
        } else {
            cout << "\033[32m" << "Congratulations! You guessed the number in " << attempts << " attempts." << "\033[0m" << endl; // Green color for correct guess

            printStars(30);

            if (attempts < highScore) {
                highScore = attempts;
                cout << "New high score: " << highScore << " attempts!" << endl;
            } else {
                cout << "Your high score: " << highScore << " attempts." << endl;
            }

            moraleBoostMessage(attempts);

            char playAgain;
            cout << "Do you want to play again? (y/n): ";
            cin >> playAgain;
            if (playAgain == 'y' || playAgain == 'Y') {
                number = rand() % 100 + 1; 
                attempts = 0;
                guessedNumbers.clear();
                cout << "I have chosen a new number between 1 and 100. Try to guess it!" << endl;

                printStars(30);
                cout << "Let's check your guess!" << endl;
                printStars(30);
            } else {
                playing = false;
            }
        }
    }

    cout << "Thanks for playing! Your high score was " << highScore << " attempts." << endl;
    moraleBoostMessage(highScore);

    return 0;
}
