#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &ai : a) cin >> ai;
  vector<int> b(n, -1);
  vector<bool> used(n + 1);

  for (int i = 0; i < n; i++) {
    int ap = i == 0 ? 0 : a[i - 1];
    if (ap > a[i] || a[i] > i + 1) {
      cout << "NEM";
      return 0;
    }
    if (ap < a[i]) {
      b[i] = a[i - 1];
      used[b[i]] = true;
    }
  }
  used[a[n - 1]] = true;  // don't use last value
  int val = 0;
  for (int i = 0; i < n; i++) {
    if (b[i] != -1) continue;
    while (used[val]) val++;
    b[i] = val;
    used[val] = true;
  }
  cout << "IGEN\n";
  for (int &bi : b) cout << bi << ' ';
  return 0;
}
