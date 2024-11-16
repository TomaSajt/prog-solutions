#include <bits/stdc++.h>
using namespace std;

int board[3][3];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int n;
  cin >> n;

  int curr = 1;
  while (n--) {
    int r, c;
    cin >> r >> c;
    board[r - 1][c - 1] = curr;
    curr = 3 - curr;
  }
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 7; j++) {
      if (i % 2 == 0) {
        if (j % 2 == 0) cout << "+";
        else cout << "-";
      }
      else if (j % 2 == 0) cout << '|';
      else cout << " OX"[board[i / 2][j / 2]];
    }
    cout << '\n';
  }
}
