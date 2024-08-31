#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> solve_right(int n, const vector<ll>& x) {
  vector<ll> res(n, LLONG_MAX);

  vector<ll> pref_sum(n);
  partial_sum(x.begin(), x.end(), pref_sum.begin());

  vector<int> last_same(n);
  last_same[n - 1] = n - 1;
  for (int i = n - 2; i >= 0; i--) {
    if (x[i + 1] == x[i]) last_same[i] = last_same[i + 1];
    else last_same[i] = i;
  }

  for (int i = 0; i < n - 1; i++) {
    if (x[i] < x[i + 1]) {
      res[i] = 1;
      continue;
    }

    auto it = upper_bound(pref_sum.begin() + last_same[i + 1] + 1, pref_sum.end(), pref_sum[i] + x[i]);
    if (it == pref_sum.end()) continue;
    res[i] = it - pref_sum.begin() - i;
  }

  return res;
}

void solve() {
  int n;
  cin >> n;
  vector<ll> x(n);
  for (ll& a : x) cin >> a;

  vector<ll> res1 = solve_right(n, x);
  reverse(x.begin(), x.end());
  vector<ll> res2 = solve_right(n, x);
  reverse(res2.begin(), res2.end());

  for (int i = 0; i < n; i++) {
    ll v = min(res1[i], res2[i]);
    cout << (v == LLONG_MAX ? -1 : v) << ' ';
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
