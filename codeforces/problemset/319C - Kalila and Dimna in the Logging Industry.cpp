#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct line {
  ll slope, y_offset;
  double op; // overtaking_point
};

int main() {
  int n;
  cin >> n;

  vector<ll> h(n), c(n);
  for (ll& hi : h) cin >> hi;
  for (ll& ci : c) cin >> ci;

  vector<ll> dp(n, LLONG_MAX / 2); // dp[i] The minimum cost of cutting the ith tree
  dp[0] = 0;

  // naive solution
  // for (int i = 1; i < n; i++)
  //   for (int j = 0; j < i; j++)
  //     dp[i] = min(dp[i], c[j] * h[i] + dp[j]);
  //   }
  // }

  // using the convex hull trick

  vector<line> lines = {{c[0], dp[0], DBL_MIN}};

  // only works if lines added in monotonically decreasing slope order
  auto add_line = [&](ll slope, ll y_offset) {
    while (lines.size() > 1) {
      line& l = lines.back();
      if (slope * l.op + y_offset >= l.slope * l.op + l.y_offset) break;
      lines.pop_back();
    }
    double op = (double)(lines.back().y_offset - y_offset) / (slope - lines.back().slope);
    lines.push_back({slope, y_offset, op});
  };

  auto get_min = [&](ll x) {
    auto l = lower_bound(lines.begin(), lines.end(), x, [](line& a, double x) { return a.op < x; }) - 1;
    return l->slope * x + l->y_offset;
  };

  for (int i = 1; i < n; i++) {
    dp[i] = get_min(h[i]);
    add_line(c[i], dp[i]);
  }

  cout << dp[n - 1];
}
