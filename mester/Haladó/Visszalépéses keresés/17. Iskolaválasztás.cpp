#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> wishes;
vector<int> capacities, selected;

bool solve(int i) {
  if (i > n) return true;
  for (int wish : wishes[i]) {
    if (capacities[wish] == 0) continue;
    capacities[wish]--;
    selected[i] = wish;
    if (solve(i + 1)) return true;
    selected[i] = 0;
    capacities[wish]++;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;

  wishes.assign(n + 1, {});
  for (int i = 1; i <= n; i++) {
    int a, b;
    cin >> a >> b;
    wishes[i].push_back(a);
    if (b != 0) wishes[i].push_back(b);
  }

  capacities.resize(m + 1);
  for (int i = 1; i <= m; i++) cin >> capacities[i];

  selected.assign(n + 1, 0);
  solve(1);

  for (int i = 1; i <= n; i++) cout << selected[i] << ' ';
  cout << '\n';
}
