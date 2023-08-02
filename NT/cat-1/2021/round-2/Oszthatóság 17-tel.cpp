#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll n;
  cin >> n;
  vector<ll> steps;

  while (true) {
    ll m = n / 10 - 5 * (n % 10);
    if (m >= 0) {
      steps.push_back(m);
      n = m;
    }
    if (m <= 0) break;
  }

  cout << (n % 17 == 0 ? "IGEN" : "NEM") << '\n';
  for (ll s : steps) cout << s << ' ';
  cout << '\n';
}
