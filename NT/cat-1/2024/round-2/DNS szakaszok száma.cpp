#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<ll> is_a(n), is_t(n);

  ll a = 0, ag = 0, res = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'A') a++;
    else if (s[i] == 'G') ag += a, a = 0;
    else if (s[i] == 'T') res += ag;
  }
  cout << res;
}
