#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> in_deg(n + 1);
  vector<int> target(n + 1, -1);
  vector<bool> removed(n + 1);
  for (int i = 1; i <= n; i++) {
    char c;
    cin >> c;
    if (c == 'R')
      continue;
    int t;
    cin >> t;
    target[i] = t;
    in_deg[t]++;
  }
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (in_deg[i] == 0)
      q.push(i);
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (target[u] == -1 || removed[target[u]])
      continue;
    removed[target[u]] = true;

    int tt = target[target[u]];
    if (tt == -1)
      continue;

    in_deg[tt]--;
    if (in_deg[tt] == 0) {
      q.push(tt);
    }
  }
  cout << count(removed.begin() + 1, removed.end(), false) << endl;
  for (int i = 1; i <= n; i++) {
    if (!removed[i])
      cout << i << ' ';
  }
}
