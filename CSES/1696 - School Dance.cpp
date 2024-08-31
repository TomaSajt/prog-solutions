#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> compatible_girls;
vector<int> pair_of_girl;
vector<bool> vis;

bool kuhn(int boy) {
  if (vis[boy]) return 0;
  vis[boy] = 1;
  for (int girl : compatible_girls[boy]) {
    if (pair_of_girl[girl] == -1 || kuhn(pair_of_girl[girl])) {
      pair_of_girl[girl] = boy;
      return 1;
    }
  }
  return 0;
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  compatible_girls.resize(n);
  vis.resize(n);
  pair_of_girl.resize(m, -1);

  while (k--) {
    int boy, girl;
    cin >> boy >> girl;
    compatible_girls[boy - 1].push_back(girl - 1);
  }

  for (int boy = 0; boy < n; boy++) {
    vis.assign(n, 0);
    kuhn(boy);
  }

  cout << m - count(pair_of_girl.begin(), pair_of_girl.end(), -1) << endl;
  for (int girl = 0; girl < m; girl++) {
    if (pair_of_girl[girl] == -1) continue;
    cout << pair_of_girl[girl] + 1 << ' ' << girl + 1 << '\n';
  }
}
