#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

vector<vector<bool>> board;

void dfs(int x, int y) {
    if (!board[x][y]) return;
    board[x][y] = 0;
    dfs(x - 1, y);
    dfs(x + 1, y);
    dfs(x, y - 1);
    dfs(x, y + 1);
}

int main() {
    speed;
    int n, m;
    cin >> n >> m;
    board.resize(n + 2, vector<bool>(m + 2));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c; cin >> c;
            board[i][j] = c == '.';
        }
    }
    int c = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (board[i][j]) {
                dfs(i, j);
                c++;
            }
        }
    }
    cout << c;
}