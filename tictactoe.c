#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

static void draw_board(const char board[9]) {
    puts("");
    for (int row = 0; row < 3; ++row) {
        printf(" %c | %c | %c \n", board[row * 3], board[row * 3 + 1], board[row * 3 + 2]);
        if (row < 2) puts("---+---+---");
    }
    puts("");
}

static int has_won(const char board[9], char mark) {
    static const int lines[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
        {0, 4, 8}, {2, 4, 6}
    };
    for (int i = 0; i < 8; ++i)
        if (board[lines[i][0]] == mark && board[lines[i][1]] == mark && board[lines[i][2]] == mark)
            return 1;
    return 0;
}

int main(void) {
    char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char line[64];
    char player = 'X';
    int moves = 0;

    puts("Tic-Tac-Toe — two players, one keyboard");
    puts("Choose a square by entering its number (1-9).\n");

    while (moves < 9) {
        draw_board(board);
        printf("Player %c, choose a square: ", player);
        fflush(stdout);

        if (!fgets(line, sizeof(line), stdin)) {
            puts("\nGame ended.");
            return 0;
        }
        char *p = line;
        while (isspace((unsigned char)*p)) ++p;
        char *end = NULL;
        long choice = strtol(p, &end, 10);
        while (end && isspace((unsigned char)*end)) ++end;
        if (end == p || (end && *end != '\0') || choice < 1 || choice > 9) {
            puts("Please enter a number from 1 to 9.");
            continue;
        }

        int square = (int)choice - 1;
        if (board[square] == 'X' || board[square] == 'O') {
            puts("That square is already taken. Choose an empty one.");
            continue;
        }

        board[square] = player;
        ++moves;
        if (has_won(board, player)) {
            draw_board(board);
            printf("Player %c wins!\n", player);
            return 0;
        }
        player = (player == 'X') ? 'O' : 'X';
    }

    draw_board(board);
    puts("It's a draw!");
    return 0;
}
