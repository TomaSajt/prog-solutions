#include <bits/stdc++.h>
using namespace std;

vector<int> range_maxes(const vector<int>& v, int n, int k) {
  vector<int> maxes(n - k + 1);
  deque<int> dq;
  for (int i = 0; i < n; i++) {
    while (!dq.empty() && v[dq.back()] <= v[i]) dq.pop_back();
    while (!dq.empty() && i - dq.front() >= k) dq.pop_front();
    dq.push_back(i);
    if (i >= k - 1) maxes[i - k + 1] = v[dq.front()];
  }
  return maxes;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int i;
    vector<int> v(n);
    for (int& a : v) cin >> a;
    for (int m : range_maxes(v, n, k)) cout << m << ' ';
    cout << '\n';
  }
}
