#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char board[3][3];

void resetboard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void showboard() {
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

int cekmenang(char simbol) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == simbol && board[i][1] == simbol && board[i][2] == simbol)
            return 1;
    }
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == simbol && board[1][i] == simbol && board[2][i] == simbol)
            return 1;
    }

    if (board[0][0] == simbol && board[1][1] == simbol && board[2][2] == simbol)
        return 1;
    if (board[0][2] == simbol && board[1][1] == simbol && board[2][0] == simbol)
        return 1;
    return 0;
} 

int cekfull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

void gerakanplayer(char simbol) {
    int b, k;

    while (1) {
        printf("Masukkan baris/bagian horizontal (1-3): ");
        scanf("%d", &b);
        printf("Masukkan kolom/bagian vertikal (1-3): ");
        scanf("%d", &k);

        b--;
        k--;

        if (b >= 0 && b < 3 && k >= 0 && k < 3 && board [b][k] == ' ') {
            board[b][k] = simbol;
            break;
        } else {
            printf("Pilihan tidak valid, coba lagi.\n");
        }
    }
}

void gerakancomp(char simbol) {
    printf("Computer is thinking...\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = simbol;
                printf("Computer memilih baris %d dan kolom %d\n", i + 1, j + 1);
                return;
            }
        }
    }
}

void maingame(int mode) {
    resetboard();
    char giliran = 'X';

    char namaX[20] = "Player 1";
    char namaO[20];

    if (mode == 1) {
        strcpy(namaO, "Player 2");
    } else {
        strcpy(namaO, "Computer");
    }

    printf("\n=== GAME DIMULAI ===\n");
    printf("X = Player 1\n");
    if (mode == 1)
        printf("O = Player 2\n\n");
    else
        printf("O = Computer\n\n");
    while (1) {
        showboard();

        if (giliran == 'X') {
            printf("Giliran X:\n");
            gerakanplayer('X');
        } else {
            if (mode == 1){
                printf("Giliran O: \n");
                gerakanplayer('O');
            } else {
                gerakancomp('O');
            }
        }
        if (cekmenang(giliran)) {
            showboard();
            if (giliran == 'X') {
                printf("SELAMAT! %s (X) MENANG!\n\n", namaX);
            } else {
                printf("SELAMAT! %s (O) MENANG!\n\n", namaO);
            }
            break;
        }
        if (cekfull()) {
            showboard();
            printf("SERI! Tidak ada pemenang.\n\n");
            break;
        }
        giliran = (giliran == 'X') ? 'O' : 'X';
    }
}

int main() {
    int pilihan;
    char mainlagi;

    srand(time(0));

    do {
        printf("\n");
        printf("===== TIC TAC TOE =====\n");
        printf("1. Player vs Player (PvP)\n");
        printf("2. Player vs Computer (PvE)\n");
        printf("3. Keluar\n");
        printf("=======================\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        if (pilihan == 1 || pilihan == 2) {
            maingame(pilihan);
            printf("Main lagi? (y/n): ");
            scanf(" %c", &mainlagi);
        } else if (pilihan == 3) {
            printf("Terima kasih sudah bermain!\n");
            break;
        } else {
            printf("Pilihan tidak valid!\n");
            mainlagi = 'y';
        }
    } while (mainlagi == 'y' || mainlagi == 'Y');
    return 0;
}