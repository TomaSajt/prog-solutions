#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, k;
  cin >> k >> a >> b;
  vector<array<int, 2>> sols;
  int x = 0;
  int dx = 1;
  while (k - x * a >= 0) {
    if ((k - x * a) % b == 0) {
      sols.push_back({x, (k - x * a) / b});
    }
    if (sols.size() == 2) {
      dx = sols[1][0] - sols[0][0];
    }
    x += dx;
  }
  cout << sols.size() << '\n';
  for (auto [xi, yi] : sols) cout << xi << ' ' << yi << '\n';
}
