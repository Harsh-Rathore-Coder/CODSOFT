#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize random seed
    srand(time(0));

    // Generate a random number between 1 and 100
    int numberToGuess = rand() % 100 + 1;
    int userGuess = 0;
    int numberOfAttempts = 0;

    printf("Welcome to the Guess the Number Game!\n");
    printf("I have selected a number between 1 and 100.\n");
    printf("Can you guess what it is?\n");

    // Loop until the user guesses the correct number
    while (userGuess != numberToGuess) {
        printf("Enter your guess: ");
        scanf("%d", &userGuess);
        numberOfAttempts++;

        if (userGuess > numberToGuess) {
            printf("Too high! Try again.\n");
        } else if (userGuess < numberToGuess) {
            printf("Too low! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number in %d attempts.\n", numberOfAttempts);
        }
    }

    return 0;
}
