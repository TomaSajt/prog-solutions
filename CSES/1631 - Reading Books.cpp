#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<long long> v(n);
  for (auto &a : v)
    cin >> a;
  cout << max(*max_element(v.begin(), v.end()) * 2, accumulate(v.begin(), v.end(), 0ll));
}
