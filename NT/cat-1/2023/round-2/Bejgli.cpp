#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), cnts(n + 1);
  for (int& ai : a) cin >> ai;
  for (int i = 0; i < n; i += a[i]) cnts[a[i]]++;
  cout << accumulate(cnts.begin(), cnts.end(), 0) << '\n';
  cout << max_element(cnts.begin(), cnts.end()) - cnts.begin();
}
