#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);

  int n;
  cin >> n;

  vector<int> pies(n);
  for (int& p : pies) cin >> p;

  vector<int> f(n + 1), s(n + 1);
  for (int i = n - 1; i >= 0; i--) {
    int a = s[i + 1] + pies[i];
    int b = f[i + 1];
    f[i] = max(a, b);
    s[i] = min(a, b);
  }

  cout << s[0] << ' ' << f[0];
}
