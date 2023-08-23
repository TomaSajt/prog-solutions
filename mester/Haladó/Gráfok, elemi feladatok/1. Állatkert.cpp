#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> deg(n + 1);
  while (m--) {
    int u, v;
    cin >> u >> v;
    deg[u]++, deg[v]++;
  }
  cout << count(deg.begin() + 1, deg.end(), 1) << " " << max_element(deg.begin() + 1, deg.end()) - deg.begin();
}
