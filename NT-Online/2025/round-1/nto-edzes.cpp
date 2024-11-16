#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int& ai : a) cin >> ai;

  long long res = a[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    a[i] = min(a[i], a[i + 1]);
    res += a[i];
  }

  cout << res;
}
