#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<int>> job_inds_that_start_at(n + 1);
  vector<array<int, 2>> jobs(m + 1);
  for (int i = 1; i <= m; i++) {
    cin >> jobs[i][0] >> jobs[i][1];
    job_inds_that_start_at[jobs[i][0]].push_back(i);
  }

  vector<array<int, 2>> sol;
  priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
  for (int ts = 1; ts <= n; ts++) {
    for (int ind : job_inds_that_start_at[ts]) {
      pq.push({jobs[ind][1], ind});
    }
    int c = 0;
    while (!pq.empty() && c < k) {
      if (pq.top()[0] >= ts) {
        sol.push_back({pq.top()[1], ts});
        c++;
      }
      pq.pop();
    }
  }

  cout << sol.size() << '\n';
  for (auto [ind, ts] : sol) {
    cout << ind << ' ' << ts << '\n';
  }
}
