#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  priority_queue<int, vector<int>, greater<int>> pq; // smallest first
  while (n--) {
    int a;
    cin >> a;
    pq.push(a);
  }
  int total_cost = 0;
  vector<pair<int, int>> pairs;
  while (pq.size() >= 2) {
    int a = pq.top();
    pq.pop();
    int b = pq.top();
    pq.pop();
    pq.push(a + b);
    total_cost += a + b;
    pairs.push_back({a + b, a});
  }
  reverse(pairs.begin(), pairs.end());
  cout << total_cost << '\n';
  for (auto [ab, a] : pairs) cout << ab << ' ' << a << '\n';
}
