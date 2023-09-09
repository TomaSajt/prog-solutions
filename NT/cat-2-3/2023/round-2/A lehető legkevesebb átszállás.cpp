#include <bits/stdc++.h>
using namespace std;

struct line {
  int s, e;
};

int main() {
  cin.tie(0), ios::sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  vector<line> lines(n);
  for (auto& [s, e] : lines) cin >> s >> e;

  int pos = 1, i = 0;
  vector<int> sol;
  while (pos < m && i < n) {
    int bestI = -1;
    while (i < n && lines[i].s <= pos) {
      if (bestI == -1 || lines[i].e > lines[bestI].e) bestI = i;
      i++;
    }
    if (bestI == -1) break;
    pos = lines[bestI].e;
    sol.push_back(bestI);
  }

  if (pos < m) {
    cout << "-1";
    return 0;
  }

  cout << sol.size() - 1 << '\n';
  for (int j : sol) cout << j + 1 << ' ';
}
