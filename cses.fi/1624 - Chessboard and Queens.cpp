#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int c = 0;
vector<bool> pduse(15), nduse(15), rowuse(8);
vector<vector<bool>> rsrv(8, vector<bool>(8));

void solve(int col) {
    if (col == 8) {
        c++;
        return;
    }
    for (int row = 0; row < 8; row++) {
        int nd = col - row + 7;
        int pd = col + row;
        if (nduse[nd] || pduse[pd] || rowuse[row] || rsrv[row][col]) continue;
        nduse[nd] = pduse[pd] = rowuse[row] = 1;
        solve(col + 1);
        nduse[nd] = pduse[pd] = rowuse[row] = 0;
    }
}

int main() {
    speed;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char c;
            cin >> c;
            rsrv[i][j] = c == '*';
        }
    }
    solve(0);
    cout << c;
}