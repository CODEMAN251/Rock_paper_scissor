#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GAMES 100
#define LEVEL_UP_WINS 3
#define STREAK_BONUS 20 

int currentStreak = 0;
int streakBonus = 5;    // Example bonus for each consecutive win.
int score = 0;          // Global score variable
int level = 1;          // Starting level
int playerStreak = 0;   // Track the player's winning streak

int getComputerChoice() {
    return rand() % 3;
}

void printChoices() {
    printf("\t\t\tPlease choose one of the following options:\n");
    printf("\t\t\t0. Rock\n");
    printf("\t\t\t1. Paper\n");
    printf("\t\t\t2. Scissors\n");
}

int determineWinner(int player, int computer) {
    if (player == computer)
        return 0; // Draw
    if ((player == 0 && computer == 2) || (player == 1 && computer == 0) || (player == 2 && computer == 1))
        return 1; // Player wins
    return -1; // Computer wins
}

void saveGameResults(int results[], int level[], int score[], int streaks[], int count) {
    FILE *file = fopen("game_results.txt", "w");
    if (file == NULL) {
        printf("Error opening the file for writing.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "Round %d (Level: %d, Score: %d): ", i + 1, level[i], score[i]);
        
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
    int gameResults[MAX_GAMES];
    int gameLevels[MAX_GAMES];
    int gameScores[MAX_GAMES];
    int gameStreaks[MAX_GAMES];
    int winCount = 0;


    srand(time(NULL)); // Seed the random number generator

    int gameCount = 0;

    while (1) {
        printf("\n\t\t\tWelcome to Rock Paper Scissors Game\n");
        printf("\t\t\tLevel: %d\tScore: %d\n\n", level, score);
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
        {
            printf("\n\t\t\tIt's a draw!\n");
            score += 1;
            playerStreak = 0; // Reset streak on draw
        } 
        else if (result == 1) 
        {
            printf("\n\t\t\tYou win!\n");
            score += 10;
            winCount++;
            playerStreak++; // Increment streak on player win

        // Check for streak bonus
            if (playerStreak == 3) 
            {
                printf("\n\t\t\tStreak Bonus! +20 Points\n");
                score += STREAK_BONUS;
                playerStreak = 0; // Reset streak after awarding bonus
            }
        } 
        else 
        {
            printf("\n\t\t\tComputer wins!\n");
            score -= 5;
            playerStreak = 0; // Reset streak on loss
        } 
    

        gameLevels[gameCount] = level;
        gameScores[gameCount] = score;
        gameResults[gameCount] = result;
        gameStreaks[gameCount] = currentStreak;
        gameCount++;
        
        // Level up condition
        if (winCount == LEVEL_UP_WINS) {
            level++;
            printf("\n\t\t\tCongratulations! You've moved to level %d.\n", level);
            winCount = 0; // Reset win count for next level
        }

        char ch;
        printf("\n\t\t\tDo you want to play again (y/n): ");
        scanf(" %c", &ch);
        if (ch != 'y' && ch != 'Y') {
            printf("\n\t\t\tYour final score: %d\n", score);
            break;
        }
    }

    saveGameResults(gameResults, gameLevels, gameScores, gameStreaks, gameCount);

    return 0;
}

int main() {
    RockPaperScissorsGame();
    return 0;
}
