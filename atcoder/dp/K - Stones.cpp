#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> steps(n);
  for (int& s : steps) cin >> s;

  vector<bool> win(k + 1, false);

  
  for (int i = 1; i <= k; i++) {
    for (int s : steps) {
      if (i - s >= 0 && !win[i - s]) {
        win[i] = true;
        break;
      }
    }
  }

  /*for (int i = 0; i < k; i++) {
    if (win[i]) continue;
    for (int s : steps) {
      if (i + s <= k) win[i + s] = true;
    }
  }*/

  cout << (win[k] ? "First" : "Second");
}
