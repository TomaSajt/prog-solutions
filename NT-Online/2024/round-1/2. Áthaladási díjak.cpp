#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (int& a : v) cin >> a;
  vector<int> psum(n), psum_pos(n, -1);

  int res = -1;
  int a, b;
  psum[0] = v[0];
  psum_pos[v[0]] = 0;
  for (int i = 1; i < n; i++) {
    int needed = psum[i - 1] - k;
    // cout << "want to find " << needed << endl;
    if (needed >= 0 && psum_pos[needed] != -1) {
      int len = i - psum_pos[needed] + 1;
      if (len > res) {
        res = len;
        a = psum_pos[needed];
        b = i;
        // cout << "New best len: " << len << endl;
        // cout << psum_pos[needed] << ' ' << i << endl;
      }
    }
    psum[i] = v[i] + psum[i - 1];
    if (psum_pos[psum[i]] == -1) psum_pos[psum[i]] = i;
  }
  cout << res - 1 << endl;
  // cout << a << ' ' << b << endl;
  // for (int i = a; i <= b; i++) cout << v[i] << ' ';
}
