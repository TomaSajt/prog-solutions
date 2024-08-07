#include <bits/stdc++.h>
using namespace std;

bool solve() {
  int n, s, m;
  cin >> n >> s >> m;

  vector<int> b(n + 2), e(n + 2);
  for (int i = 1; i <= n; i++) cin >> b[i] >> e[i];
  e[0] = 0;
  b[n + 1] = m;

  for (int i = 1; i <= n + 1; i++) {
    if (b[i] - e[i - 1] >= s) return true;
  }
  return false;
}

int main() {
  int t;
  cin >> t;
  while (t--) cout << (solve() ? "YES" : "NO") << '\n';
}
