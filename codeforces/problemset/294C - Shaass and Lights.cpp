#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

ll fact[1001], i_fact[1001];

ll modexp(ll a, ll x) {
  return x == 0 ? 1 : modexp(a * a % mod, x / 2) * (x % 2 == 0 ? 1 : a) % mod;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, m;
  cin >> n >> m;

  vector<bool> is_on(n + 1, 0);
  for (int i = 1; i <= m; i++) {
    int a;
    cin >> a;
    is_on[a] = 1;
  }

  fact[0] = 1;
  for (int i = 1; i <= 1000; i++) {
    fact[i] = fact[i - 1] * i % mod;
  }
  i_fact[1000] = modexp(fact[1000], mod - 2);
  for (int i = 1000; i > 0; i--) {
    i_fact[i - 1] = i * i_fact[i] % mod;
  }

  vector<int> intervals;
  int start = 1;
  for (int i = 2; i <= n; i++) {
    if (is_on[i - 1] && !is_on[i]) start = i;
    if (!is_on[i - 1] && is_on[i]) intervals.push_back(i - start);
  }
  if (!is_on[n]) intervals.push_back(n + 1 - start);

  ll sum = accumulate(intervals.begin(), intervals.end(), 0);

  ll res = fact[sum];
  for (int i = 0; i < intervals.size(); i++) {
    res = res * i_fact[intervals[i]] % mod;

    if (i == 0 && !is_on[1]) continue;
    if (i == intervals.size() - 1 && !is_on[n]) continue;
    res = res * modexp(2, intervals[i] - 1) % mod;
  }

  cout << res;
}
