#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  vector<int> parent(n + 1, -1);

  for (int i = 0; i < m; i++) {
    int par, self;
    cin >> par >> self;
    parent[self] = par;
  }

  vector<int> child_count(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    if (parent[i] == -1) continue;
    child_count[parent[i]] += 1;
  }

  vector<int> grandchild_count(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    if (parent[i] == -1) continue;
    grandchild_count[parent[i]] += child_count[i];
  }

  auto best_it = max_element(grandchild_count.begin(), grandchild_count.end());

  if (*best_it == 0) {
    cout << "-1";
  }
  else {
    cout << best_it - grandchild_count.begin() << ' ' << *best_it;
  }
}
