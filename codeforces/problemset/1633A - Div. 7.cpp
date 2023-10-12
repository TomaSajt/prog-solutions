#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int sol = n / 7 * 7;
    if (n / 10 != sol / 10) sol += 7;
    cout << sol << '\n';
  }
}
