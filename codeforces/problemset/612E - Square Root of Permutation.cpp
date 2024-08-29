
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int n;
  cin >> n;

  vector<int> p(n);
  vector<bool> volt(n);

  vector<vector<vector<int>>> ciklusok(n + 1);
  for (int& x : p) {
    cin >> x;
    x--;
  }

  for (int i = 0; i < n; ++i) {
    if (volt[i]) continue;
    vector<int> ciklus;
    int akt = i;
    while (!volt[akt]) {
      volt[akt] = true;
      ciklus.push_back(akt);
      akt = p[akt];
    }
    ciklusok[ciklus.size()].push_back(ciklus);
  }

  vector<vector<int>> gyokciklusok;
  for (int l = 1; l <= n; ++l) {
    if (ciklusok[l].empty()) continue;
    if (l % 2 == 0) {
      if (ciklusok[l].size() % 2 != 0) {
        cout << -1;
        return 0;
      }
      int N = ciklusok[l].size() / 2;
      auto& cl = ciklusok[l];
      for (int i = 0; i < N; ++i) {
        vector<int> akt;
        for (int j = 0; j < l; j++) {
          akt.push_back(cl[2 * i][j]);
          akt.push_back(cl[2 * i + 1][j]);
        }
        gyokciklusok.push_back(akt);
      }
    }
    else {
      auto& cl = ciklusok[l];
      for (int i = 0; i < cl.size(); ++i) {
        vector<int> akt(l);
        for (int j = 0; j < l; j++) {
          akt[2 * j % l] = cl[i][j];
        }
        gyokciklusok.push_back(akt);
      }
    }
  }

  vector<int> q(n);
  for (auto& x : gyokciklusok) {
    for (int i = 0; i < x.size(); ++i) {
      q[x[i]] = x[(i + 1) % x.size()];
    }
  }
  for (int x : q) cout << x + 1 << ' ';
}
