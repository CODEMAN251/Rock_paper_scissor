#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random choice for the computer
int getComputerChoice() {
    return rand() % 3;
}

// Function to display the choices
void printChoices() {
    printf("\t\t\tPlease choose one of the following options:\n");
    printf("\t\t\t0. Rock\n");
    printf("\t\t\t1. Paper\n");
    printf("\t\t\t2. Scissors\n");
}

// Function to determine the winner of the game
int determineWinner(int player, int computer) {
    if (player == computer)
        return 0; // Draw
    if ((player == 0 && computer == 2) || (player == 1 && computer == 0) || (player == 2 && computer == 1))
        return 1; // Player wins
    return -1; // Computer wins
}

void saveGameResults(int results[], int count) {
    FILE *file = fopen("game_results.txt", "w");
    if (file == NULL) {
        printf("Error opening the file for writing.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "Round %d: ", i + 1);
        if (results[i] == 0) {
            fprintf(file, "Draw\n");
        } else if (results[i] == 1) {
            fprintf(file, "Player wins\n");
        } else {
            fprintf(file, "Computer wins\n");
        }
    }

    fclose(file);
}

int RockPaperScissorsGame() {
    int computer, player;
    int result;
    int gameResults[100]; // Assuming a maximum of 100 games

    srand(time(NULL)); // Seed the random number generator

    int gameCount = 0;

    while (1) {
        printf("\n\t\t\tWelcome to Rock Paper Scissors Game\n\n\n");
        printChoices();

        printf("\t\t\tYour Choice: ");
        if (scanf("%d", &player) != 1 || player < 0 || player > 2) {
            printf("\n\t\t\tInvalid input. Please enter a number between 0 and 2.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        computer = getComputerChoice();

        printf("\t\t\tComputer's choice is: %s\n", (computer == 0) ? "Rock" : (computer == 1) ? "Paper" : "Scissors");

        result = determineWinner(player, computer);

        if (result == 0)
            printf("\n\t\t\tIt's a draw!\n");
        else if (result == 1)
            printf("\n\t\t\tYou win!\n");
        else
            printf("\n\t\t\tComputer wins!\n");

        gameResults[gameCount] = result;
        gameCount++;

        char ch;
        printf("\n\t\t\tDo you want to play again (y/n): ");
        scanf(" %c", &ch);
        if (ch != 'y' && ch != 'Y')
            break;
    }

    saveGameResults(gameResults, gameCount);

    return 0;
}

int main() {
    RockPaperScissorsGame();
    return 0;
}
