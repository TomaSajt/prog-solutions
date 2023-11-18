#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  string s;
  cin >> n >> s;

  int cnt = 0;
  for (int i = 0; i < 2 * n; i++) {
    if (s[i] == "FL"[i % 2]) cnt++;
  }
  cout << min(cnt, 2 * n - cnt) / 2;
}
