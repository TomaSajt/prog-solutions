#include <bits/stdc++.h>
using namespace std;

vector<bool> started(26), done(26);
vector<set<int>> graph(26);
stack<int> s;
int back_edge_cnt = 0;

void dfs(int u) {
  started[u] = true;
  for (auto v : graph[u]) {
    if (!started[v]) dfs(v);
    else if (!done[v]) {
      back_edge_cnt++;
    }
  }
  s.push(u);
  done[u] = true;
}

int main() {
  int n;
  cin >> n;

  string prevName, currName;
  cin >> prevName;
  for (int j = 1; j < n; j++) {
    cin >> currName;
    int minSize = min(currName.size(), prevName.size());
    for (int i = 0; i < minSize; i++) {
      if (prevName[i] != currName[i]) {
        graph[prevName[i] - 'a'].insert(currName[i] - 'a');
        break;
      }

      if (i == minSize - 1 && currName.size() < prevName.size()) { // currName is a proper prefix of prevName
        cout << "Impossible\n";
        return 0;
      }
    }
    prevName = currName;
  }

  for (int i = 0; i < 26; i++) {
    if (!started[i]) dfs(i);
  }

  if (back_edge_cnt != 0) {
    cout << "Impossible\n";
    return 0;
  }

  while (!s.empty()) {
    cout << (char)(s.top() + 'a');
    s.pop();
  }
  cout << '\n';
  return 0;
}
