#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e9;

vector<int> make_dist(vector<vector<int>>& g, int s) {
  int n = g.size();
  vector<int> dist(n, INF);
  queue<int> q;
  q.push(s);
  dist[s] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : g[u]) {
      if (dist[v] == INF) {
        q.push(v);
        dist[v] = dist[u] + 1;
      }
    }
  }
  return dist;
}

void pr(vector<int>& v) {
  //for (auto x : v) cout << x << ' ';
  //cout << endl;
}

signed main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> a_dist = make_dist(g, 0), b_dist = make_dist(g, n - 1);
  pr(a_dist);
  pr(b_dist);

  vector<int> b_dist_cnts(300000);
  for (int i = 0; i <= n - 1; i++) {
    b_dist_cnts[b_dist[i]]++;
  }
  pr(b_dist_cnts);
  vector<int> b_dist_cnts_pref = b_dist_cnts;
  for (int i = 1; i < 300000; i++) {
    b_dist_cnts_pref[i] += b_dist_cnts_pref[i - 1];
  }
  pr(b_dist_cnts_pref);

  int d = a_dist[n - 1];

  int res = 0;

  
  for (int i = 0; i <= n - 1; i++) {
    int d_leq = d - a_dist[i] - 2;
    //cout << d_leq << endl;
    if (d_leq >= 0) {
      res += b_dist_cnts_pref[d_leq];
    }
  }
  

 /* for (int i = 0; i <= n - 1; i++) {
    for (int j = 0; j <= n - 1; j++) {
      if (a_dist[i] + b_dist[j] + 1 < d) {
        res++;
        cout << i << ' ' << j << endl;
      }
    }
  }
  */

  cout << n * (n - 1) / 2 - m - res;
}
