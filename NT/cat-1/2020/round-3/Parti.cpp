#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio();

  int n;
  cin >> n;

  vector<array<int, 2>> g(n + 1);
  vector<int> in_deg(n + 1);

  for (int i = 1; i <= n; i++) {
    auto& [a, b] = g[i];
    cin >> a >> b;
    in_deg[a]++, in_deg[b]++;
  }

  queue<int> q;  // nodes for removal
  for (int i = 1; i <= n; i++) {
    if (in_deg[i] < 2) q.push(i);
  }

  while (!q.empty()) {
    int i = q.front();
    q.pop();
    auto& [a, b] = g[i];
    if (--in_deg[a] == 1) q.push(a);
    if (--in_deg[b] == 1) q.push(b);
  }

  vector<int> res;
  for (int i = 1; i <= n; i++) {
    if (in_deg[i] >= 2) res.push_back(i);
  }

  cout << res.size() << '\n';
  for (int i : res) cout << i << ' ';
  cout << '\n';
}
