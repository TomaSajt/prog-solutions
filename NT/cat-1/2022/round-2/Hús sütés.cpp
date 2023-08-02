#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin >> n;

  vector<int> a(n);
  for (auto& ai : a) cin >> ai;

  sort(a.rbegin(), a.rend());

  int sol = 0;
  for (int i = 0; i < n; i++) {
    sol = max(sol, a[i] + i);
  }

  cout << sol;
}
