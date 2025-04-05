#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  size_t res = 0;
  queue<int> q;
  for (int i = 0; i < n; i++) {
    int ai;
    cin >> ai;
    while (!q.empty() && ai - q.front() >= k) q.pop();
    q.push(ai);
    res = max(res, q.size());
  }
  cout << res;
}
