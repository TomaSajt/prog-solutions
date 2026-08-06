#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  vector<pair<ll, ll>> v(n);
  for (auto& [a, d] : v) cin >> a >> d;
  sort(v.begin(), v.end());
  ll t = 0, s = 0;
  for (auto& [a, d] : v) {
    t += a;
    s += d - t;
  }
  cout << s;
}
