#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n, x;
  cin >> n >> x;
  vector<ll> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  map<ll, int> cnt;
  ll s = 0;
  ll res = 0;
  for (int ai : a) {
    s += ai;
    res += cnt[s - x];
    cnt[s]++;
  }
  cout << res;
}
