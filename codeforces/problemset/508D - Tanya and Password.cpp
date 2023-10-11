#include <bits/stdc++.h>
using namespace std;

map<string, queue<string>> g;
map<string, int> degdiff;
stack<string> path;

void dfs(string u) {
  while (!g[u].empty()) {
    string v = g[u].front();
    g[u].pop();
    dfs(v);
  }
  path.push(u);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    string u = s.substr(0, 2), v = s.substr(1, 2);
    g[u].push(v);
    degdiff[u]++, degdiff[v]--;
  }

  string start = "";
  for (auto [k, d] : degdiff) {
    if (abs(d) > 1) {
      cout << "NO";
      return 0;
    }
    if (d == 1) {
      if (start != "") {
        cout << "NO";
        return 0;
      }
      start = k;
    }
  }
  // if indeg==outdeg everywhere, choose any start vertex
  if (start == "") start = degdiff.begin()->first;

  dfs(start);

  if (path.size() != n + 1) {
    cout << "NO";
    return 0;
  }

  cout << "YES\n";
  cout << path.top()[0];
  while (!path.empty()) {
    cout << path.top()[1];
    path.pop();
  }
}
