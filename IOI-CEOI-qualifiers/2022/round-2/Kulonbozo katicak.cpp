#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subordinates;
vector<int> boss, spots, parity, range_start, range_end;
bool impossible = false;

void range_dfs(int u) {
  for (int v : subordinates[u]) {
    range_dfs(v);
    range_start[u] = max(range_start[u], range_start[v] - 1);
    range_end[u] = min(range_end[u], range_end[v] + 1);
    if (parity[u] == -1 && parity[v] != -1)
      parity[u] = !parity[v];
    if (parity[u] != -1 && parity[u] == parity[v])
      impossible = true;
  }
  if (range_start[u] > range_end[u])
    impossible = true;
}

void fill_dfs(int u) {
  if (spots[u] == -1) {
    int bs = spots[boss[u]];
    spots[u] = bs + 1 <= range_end[u] ? bs + 1 : bs - 1;
  }
  for (int v : subordinates[u])
    fill_dfs(v);
}

int main() {
  int n;
  cin >> n;
  subordinates.resize(n + 1);
  boss.resize(n + 1);
  spots.resize(n + 1);
  parity.resize(n + 1, -1);
  range_start.resize(n + 1, INT_MIN / 2);
  range_end.resize(n + 1, INT_MAX / 2);
  for (int i = 1; i <= n; i++) {
    cin >> boss[i];
    subordinates[boss[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    cin >> spots[i];
    if (spots[i] != -1) {
      parity[i] = spots[i] % 2;
      range_start[i] = range_end[i] = spots[i];
    }
  }
  range_dfs(1);
  if (impossible) {
    cout << "NEM";
    return 0;
  }
  fill_dfs(1);
  cout << "IGEN\n";
  for (int i = 1; i <= n; i++)
    cout << spots[i] << ' ';
}
