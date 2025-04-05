#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  vector<int> depnum(n);
  vector<string> names(n);
  map<string, int> name_ids;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> names[i];
    name_ids[names[i]] = i;
  }
  while (m--) {
    string us, c, vs;
    cin >> us >> c >> vs;
    if (c == ">") swap(us, vs);
    g[name_ids[us]].push_back(name_ids[vs]);
    depnum[name_ids[vs]]++;
  }
  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (depnum[i] == 0) q.push(i);
  }

  vector<int> order;
  while (!q.empty()) {
    if (q.size() != 1) {
      cout << "Ketseges";
      return 0;
    }
    int u = q.front();
    q.pop();
    order.push_back(u);
    for (int v : g[u]) {
      depnum[v]--;
      if (depnum[v] == 0) q.push(v);
    }
  }

  for (int u : order) {
    cout << names[u] << ' ';
  }
}
