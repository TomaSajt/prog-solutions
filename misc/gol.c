#include <stdio.h>
#include <windows.h>
#define N 16
int board[N][N], nei[N][N];

void print() {
    for (int i = 0; i < N + 2; i++) putc('@', stdout);
    putc('\n', stdout);
    for (int i = 0; i < N; i++) {
        putc('@', stdout);
        for (int j = 0; j < N; j++) {
            putc(" #"[board[i][j]], stdout);
        }
        putc('@', stdout);
        putc('\n', stdout);
    }
    for (int i = 0; i < N + 2; i++)  putc('@', stdout);
    putc('\n', stdout);
    putc('\n', stdout);
}

int main() {
    board[13][3] = 1;
    board[13][4] = 1;
    board[14][4] = 1;
    board[14][5] = 1;
    board[15][3] = 1;
    print();
    for (int t = 0; t < 20; t++) {
        Sleep(300);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                nei[i][j] = 0;
                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {
                        nei[i][j] += board[x][y];
                    }
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                board[i][j] = nei[i][j] == 3 || (board[i][j] && nei[i][j] == 4);
            }
        }
        print();
    }
}