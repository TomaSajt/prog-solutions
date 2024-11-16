
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int n;
  cin >> n;

  int win = 0;
  int loss = 0;
  int start = -1;
  for (int i = 0; i < n; i++) {
    if (loss >= win) {
      loss = 0;
      win = 0;
      start = i;
    }
    char c;
    cin >> c;
    if (c == 'G') win++;
    if (c == 'A') loss++;
    cout << win << '-' << loss << '\n';
  }
}
