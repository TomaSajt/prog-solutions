#include <bits/stdc++.h>
using namespace std;

int dist_sum(int a, int b, int c) {
  return abs(a - b) + abs(b - c) + abs(a - c);
}

int main() {
  ios::sync_with_stdio(), cin.tie(0);
  int p, q, r;
  cin >> p >> q >> r;
  vector<int> pv(p), qv(q), rv(r);
  for (int& pa : pv) cin >> pa;
  for (int& qa : qv) cin >> qa;
  for (int& ra : rv) cin >> ra;
  int pi = 0, qi = 0, ri = 0;
  int bpi = 0, bqi = 0, bri = 0;
  int bd = dist_sum(pv[pi], qv[qi], rv[ri]);
  while (true) {
    if (pv[pi] <= qv[qi] && pv[pi] <= rv[ri]) {
      pi++;
      if (pi >= p) break;
    }
    else if (qv[qi] <= pv[pi] && qv[qi] <= rv[ri]) {
      qi++;
      if (qi >= q) break;
    }
    else {
      ri++;
      if (ri >= r) break;
    }
    int d = dist_sum(pv[pi], qv[qi], rv[ri]);
    if (d < bd) bd = d, bpi = pi, bqi = qi, bri = ri;
  }
  cout << pv[bpi] << ' ' << qv[bqi] << ' ' << rv[bri];
}
