#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char board[3][3];

void resetBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void showBoard() {
    printf("\n");
    printf("  1  2  3\n");
    for (int i = 0; i < 3; i++) {
        printf("%d", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("[%c]", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int checkWin(char symbol) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol)
            return 1;
    }

    for (int i = 0; i < 3; i++) {
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)
            return 1;
    }

    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol)
        return 1;

    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)
        return 1;

    return 0;
}

int checkFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

void playerMove(char symbol) {
    int row, col;

    while (1) {
        printf("Enter row (1-3): ");
        scanf("%d", &row);
        printf("Enter column (1-3): ");
        scanf("%d", &col);

        row--;
        col--;

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = symbol;
            break;
        } else {
            printf("Invalid move, please try again.\n");
        }
    }
}

void computerMove(char symbol) {
    printf("Computer is thinking...\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = symbol;
                printf("Computer chose row %d and column %d\n", i + 1, j + 1);
                return;
            }
        }
    }
}

void mainGame(int mode) {
    resetBoard();
    char turn = 'X';

    char nameX[20] = "Player 1";
    char nameO[20];

    if (mode == 1) {
        strcpy(nameO, "Player 2");
    } else {
        strcpy(nameO, "Computer");
    }

    printf("\n=== GAME STARTED ===\n");
    printf("X = Player 1\n");
    if (mode == 1)
        printf("O = Player 2\n\n");
    else
        printf("O = Computer\n\n");

    while (1) {
        showBoard();

        if (turn == 'X') {
            printf("X's turn:\n");
            playerMove('X');
        } else {
            if (mode == 1) {
                printf("O's turn:\n");
                playerMove('O');
            } else {
                computerMove('O');
            }
        }

        if (checkWin(turn)) {
            showBoard();
            if (turn == 'X') {
                printf("CONGRATULATIONS! %s (X) WINS!\n\n", nameX);
            } else {
                printf("CONGRATULATIONS! %s (O) WINS!\n\n", nameO);
            }
            break;
        }

        if (checkFull()) {
            showBoard();
            printf("DRAW! There is no winner.\n\n");
            break;
        }

        turn = (turn == 'X') ? 'O' : 'X';
    }
}

int main() {
    int choice;
    char playAgain;

    srand(time(0));

    do {
        printf("\n");
        printf("===== TIC TAC TOE =====\n");
        printf("1. Player vs Player (PvP)\n");
        printf("2. Player vs Computer (PvE)\n");
        printf("3. Exit\n");
        printf("=======================\n");
        printf("Choose: ");
        scanf("%d", &choice);

        if (choice == 1 || choice == 2) {
            mainGame(choice);
            printf("Play again? (y/n): ");
            scanf(" %c", &playAgain);
        } else if (choice == 3) {
            printf("Thank you for playing!\n");
            break;
        } else {
            printf("Invalid choice!\n");
            playAgain = 'y';
        }
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}