#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> v(n), ps(n);
  for (auto &a : v)
    cin >> a;
  partial_sum(v.begin(), v.end(), ps.begin());
  int target = ps.back() / n;
  int res = 0;
  for (int i = 0; i < n; i++)
    res += ps[i] != target * (i + 1);
  cout << res;
}
