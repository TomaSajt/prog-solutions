#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  vector<int> diff(n, 0);
  for (int i = 0; i < m; i++) {
    int s, e;
    cin >> s >> e;
    diff[s - 1] += 1;
    diff[e - 1] -= 1;
  }

  vector<int> v(n);
  partial_sum(diff.begin(), diff.end(), v.begin());
  cout << count(v.begin(), v.end(), 0) - 1;
}
