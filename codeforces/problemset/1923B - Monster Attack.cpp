#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  int my_pos = 0;
  int first_alive = 0;
  vector<array<int, 2>> monsters(n);
  for (auto& [x, a] : monsters) cin >> a;
  for (auto& [x, a] : monsters) {
    cin >> x;
    x = abs(x);
  }

  sort(monsters.begin(), monsters.end());

  while (true) {
    int rem = k;
    while (rem >= monsters[first_alive][1]) {
      if (first_alive >= n) {
        cout << "YES\n";
        return;
      }
      rem -= monsters[first_alive][1];
      monsters[first_alive][1] = 0;
      first_alive++;
    }
    monsters[first_alive][1] -= rem;
    my_pos++;
    if (monsters[first_alive][0] <= my_pos) {
      cout << "NO\n";
      return;
    }
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
