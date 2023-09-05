# Rock, Paper, Scissors Game

This is a simple command-line implementation of the classic Rock, Paper, Scissors game in C.

Table of Contents

- Introduction
- Usage
- How to Play
- File Output
- Build and Run

## Introduction

This program allows you to play Rock, Paper, Scissors against a computer opponent. It randomly selects the computer's choice and determines the winner of each round based on the game's rules.

## Usage

To play the game, follow these steps:

1. Compile the program (see [Build and Run](#build-and-run) section).
2. Run the compiled executable.
3. Follow the on-screen instructions to make your choice (Rock, Paper, or Scissors) by entering a number between 0 and 2.
4. The computer will also make a random choice.
5. The program will display the result of the round, indicating whether you won, lost, or if it's a draw.
6. You can choose to play again or exit the game.

## How to Play

- Enter `0` for Rock.
- Enter `1` for Paper.
- Enter `2` for Scissors.

The winner of each round is determined as follows:

- Rock beats Scissors.
- Scissors beat Paper.
- Paper beats Rock.

## File Output

The program saves the results of each round in a file named "game_results.txt" in the same directory where the program is run. The file contains information about the outcome of each game round.

## Build and Run

To build and run the program, follow these steps:

1. Open your terminal or command prompt.
2. Navigate to the directory containing the source code.
3. Compile the code using a C compiler (e.g., GCC):

   shell
   gcc -o rock_paper_scissors game.c
   
4. Run the executable:

   shell
   ./rock_paper_scissors
   
5. Follow the on-screen instructions to play the game.

