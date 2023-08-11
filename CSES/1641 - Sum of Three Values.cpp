#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> v(n);

  for (auto& i : v)
    cin >> i;

  map<int, int> hash;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (hash.count(x - v[i] - v[j])) {
        cout << hash[x - v[i] - v[j]] + 1 << ' ' << i + 1 << ' ' << j + 1;
        return 0;
      }
    }
    hash[v[i]] = i;
  }
  cout << "IMPOSSIBLE" << endl;
}
