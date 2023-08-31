#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (int& ai : a) cin >> ai;
  for (int& bi : b) cin >> bi;

  auto it1 = min_element(a.begin(), a.end());
  auto it2 = max_element(b.begin(), b.end());
  if (*it1 > *it2) {
    cout << "IGEN";
    return 0;
  }

  cout << "NEM\n";
  cout << it1 - a.begin() + 1 << '\n';
  cout << it2 - b.begin() + 1;
}
