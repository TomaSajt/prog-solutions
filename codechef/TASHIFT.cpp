#include <bits/stdc++.h>
using namespace std;

vector<int> z_function(const string& s) {
  int n = s.size();
  vector<int> z(n);
  int l = 0, r = 0;
  for (int i = 1; i < n; i++) {
    if (i < r) {
      z[i] = min(r - i, z[i - l]);
    }
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      z[i]++;
    }
    if (i + z[i] > r) {
      l = i;
      r = i + z[i];
    }
  }
  return z;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  vector<int> z = z_function(a + "#" + b + b);
  auto start = z.begin() + n + 1;
  cout << max_element(start, z.end()) - start;
}
