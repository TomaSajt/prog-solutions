#include <bits/stdc++.h>
using namespace std;

int cmp(int a, int b) {
  return (a > b) - (a < b);
}

bool is_win(int a1, int a2, int b1, int b2) {
  int score_diff = cmp(a1, b1) + cmp(a2, b2);
  return score_diff > 0;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    int w = 0;
    w += is_win(a1, a2, b1, b2);
    w += is_win(a2, a1, b1, b2);
    w += is_win(a1, a2, b2, b1);
    w += is_win(a2, a1, b2, b1);
    cout << w << '\n';
  }
}
