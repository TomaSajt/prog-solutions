#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n;
  cin >> n;
  int a, b;
  cin >> a >> b;

  if (a < 0 && b < 0) {
    cout << "NO" << endl;
  }
  else if (a >= 0 && b >= 0) {
    cout << "YES" << endl;
  }
  else {
    if (b > a) swap(a, b);
    if (b + a / 2 >= 0) {
      cout << "YES" << endl;
    }
    else cout << "NO" << endl;
  }
}

signed main() {
  int t;
  cin >> t;
  while (t--) solve();
}
