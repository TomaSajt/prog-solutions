#include <bits/stdc++.h>
using namespace std;
bool mat[101][101];

int main() {
  int n, a, b;
  cin >> n;
  while (cin >> a >> b) mat[a][b] = 1;

  vector<int> path;
  for (int i = 1; i <= n; i++) {
    auto it = path.begin();
    while (it != path.end() && mat[i][*it]) it++;
    path.insert(it, i);
  }

  for (int x : path) cout << x << ' ';
}
