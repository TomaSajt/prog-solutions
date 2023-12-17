#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  set<int> s;
  for (int i = 1; i <= n; i++) s.insert(i);
  bool skip = true;
  while (!s.empty()) {
    auto it = s.begin();
    while (it != s.end()) {
      if (skip) ++it;
      else {
        cout << *it << ' ';
        it = s.erase(it);
      }
      skip = !skip;
    }
  }
}
