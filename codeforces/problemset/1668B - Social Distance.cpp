#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll& ai : a) cin >> ai;
    sort(a.begin(), a.end());
    ll best = n;
    for (int i = 0; i < n; i++) best += max(a[i], a[(i + 1) % n]);
    cout << (best <= m ? "YES" : "NO") << '\n';
  }
}
