#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin >> n;

  string a, b;
  cin >> a >> b;

  int sol = 1;
  for (int i = 1; i < n; i++) {
    if ((a[i - 1] == b[i - 1]) != (a[i] == b[i])) {
      sol += 1;
    }
  }

  if (a[n - 1] == b[n - 1]) {
    sol -= 1;
  }

  cout << sol;
}
