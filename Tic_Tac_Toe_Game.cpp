#include <cstdio>

char grid[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
char current_marker;
int current_player;

void drawBoard() {
    printf("  %c | %c | %c\n", grid[0][0], grid[0][1], grid[0][2]);
    printf(" ---|---|---\n");
    printf("  %c | %c | %c\n", grid[1][0], grid[1][1], grid[1][2]);
    printf(" ---|---|---\n");
    printf("  %c | %c | %c\n", grid[2][0], grid[2][1], grid[2][2]);
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (grid[row][col] != 'X' && grid[row][col] != 'O') {
        grid[row][col] = current_marker;
        return true;
    } else {
        return false;
    }
}

int winner() {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][0] != ' ') {
            return current_player;
        }
    }
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] && grid[0][i] != ' ') {
            return current_player;
        }
    }
    // Check diagonals
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] != ' ') {
        return current_player;
    }
    if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[0][2] != ' ') {
        return current_player;
    }
    return 0;
}

void swapPlayerAndMarker() {
    if (current_marker == 'X') {
        current_marker = 'O';
    } else {
        current_marker = 'X';
    }

    if (current_player == 1) {
        current_player = 2;
    } else {
        current_player = 1;
    }
}

void game() {
    printf("Player 1 is X and Player 2 is O\n");

    current_player = 1;
    current_marker = 'X';

    drawBoard();
    int player_won = 0;

    for (int i = 0; i < 9; i++) {
        printf("It's player %d's turn. Enter your slot (1-9): ", current_player);
        int slot;
        scanf("%d", &slot);

        if (slot < 1 || slot > 9) {
            printf("Invalid slot! Try again.\n");
            i--;
            continue;
        }

        if (!placeMarker(slot)) {
            printf("Slot already taken! Try again.\n");
            i--;
            continue;
        }

        drawBoard();
        player_won = winner();

        if (player_won == 1) {
            printf("Player 1 wins!\n");
            break;
        } else if (player_won == 2) {
            printf("Player 2 wins!\n");
            break;
        }

        swapPlayerAndMarker();
    }

    if (player_won == 0) {
        printf("It's a tie!\n");
    }
}

int main() {
    game();
    return 0;
}
