#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  vector<int> cnt(n);
  int s = 0;
  long long res = 0;
  for (int ai : a) {
    s += ai;
    s %= n;
    if (s < 0) s += n;
    res += cnt[s];
    cnt[s]++;
  }
  cout << res;
}
