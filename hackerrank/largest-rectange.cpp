#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);

  int n;
  cin >> n;

  vector<int> h(n + 2);
  for (int i = 1; i <= n; i++) cin >> h[i];

  int res = 0;
  stack<int> s;
  for (int i = 1; i <= n + 1; i++) {
    int kitor = i;
    while (!s.empty() && h[s.top()] > h[i]) {
      res = max(res, h[s.top()] * (i - s.top()));
      kitor = s.top();
      s.pop();
    }
    if (s.empty() || h[s.top()] != h[i]) {
      s.push(kitor);
      h[kitor] = h[i];
    }
  }

  cout << res;
}

// N*log(N)
/*

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int n;
  cin >> n;

  vector<array<ll, 2>> vh(n);
  for (int i = 0; i < n; i++) {
    cin >> vh[i][0];
    vh[i][1] = i;
  }
  sort(vh.rbegin(), vh.rend());

  set<pair<int, int>> intervals;
  ll res = 0;
  int max_w = 0;

  for (auto [h, i] : vh) {
    auto it = intervals.insert({i, i}).first;

    if (it != intervals.begin()) {
      auto pit = prev(it);
      if (pit->second + 1 == it->first) {
        int l = pit->first, r = it->second;
        intervals.erase(pit);
        intervals.erase(it);
        it = intervals.insert({l, r}).first;
      }
    }

    auto nit = next(it);
    if (nit != intervals.end()) {
      if (it->second + 1 == nit->first) {
        int l = it->first, r = nit->second;
        intervals.erase(it);
        intervals.erase(nit);
        it = intervals.insert({l, r}).first;
      }
    }

    max_w = max(max_w, it->second - it->first + 1);
    res = max(res, h * max_w);
  }
  cout << res;
}

*/
