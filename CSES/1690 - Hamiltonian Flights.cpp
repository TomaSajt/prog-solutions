#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

vector<vector<int>> mem;
vector<vector<int>> gt;

int get_ways(int mask, int pos) {
  if (mem[mask][pos] != -1)
    return mem[mask][pos];
  int ways = 0;
  int prev_mask = mask & ~(1 << pos);
  for (int prev : gt[pos]) {
    if ((mask >> prev) & 1) {
      ways += get_ways(prev_mask, prev);
      ways %= MOD;
    }
  }
  return mem[mask][pos] = ways;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  gt.resize(n);
  mem.resize(1 << (n - 1), vector<int>(n - 1, -1));
  mem[1][0] = 1;
  while (m--) {
    int u, v;
    cin >> u >> v;
    if (u != v)
      gt[v - 1].push_back(u - 1);
  }
  int ways = 0;
  for (int prev : gt[n - 1]) {
    ways += get_ways((1 << (n - 1)) - 1, prev);
    ways %= MOD;
  }
  cout << ways;
}
