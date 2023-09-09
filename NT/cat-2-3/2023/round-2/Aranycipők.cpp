#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> v(n);
  for (int& a : v) cin >> a;
  int m = *max_element(v.begin(), v.end());
  cout << m << '\n';
  cout << count(v.begin(), v.end(), m) << '\n';
  for (int i = 0; i < n; i++) {
    if (v[i] == m) cout << i + 1 << '\n';
  }
}
