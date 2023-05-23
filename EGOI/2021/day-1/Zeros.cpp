#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  ll a, b, n2 = 0, n5 = 0;
  cin >> a >> b;
  for (ll p = 2; b / p - (a - 1) / p; p *= 2, n2++) {}
  for (ll p = 5; b / p - (a - 1) / p; p *= 5, n5++) {}
  cout << min(n2, n5) << endl;
}
