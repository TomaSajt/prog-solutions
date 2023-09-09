#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  map<int, int> cnts;
  while (n--) {
    int a;
    cin >> a;
    cnts[a]++;
  }
  cnts.erase(cnts.begin());  // don't use the lowest number, as it will alway be next to its negative version after sorting
  long long res = 1;
  for (auto& [x, c] : cnts) {
    res *= c + 1;  // we can select 0 to c instances of a number to be negative, thus having c+1 options
    res %= mod;
  }
  cout << res;
}
