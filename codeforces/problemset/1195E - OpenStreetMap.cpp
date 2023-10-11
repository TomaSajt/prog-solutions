#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll board[3001][3001];

void range_mins_inplace(ll *row, int n, int k) {
  deque<ll> dq;
  for (int i = 0; i < n; i++) {
    while (!dq.empty() && row[dq.back()] >= row[i]) dq.pop_back();
    dq.push_back(i);
    if (i - dq.front() >= k) dq.pop_front();
    if (i - k + 1 >= 0) row[i - k + 1] = row[dq.front()];
  }
  // fill(row + n - k + 1, row + n, 0);
}

int main() {
  int n, m, a, b;
  cin >> n >> m >> a >> b;

  ll gc, x, y, z;
  cin >> gc >> x >> y >> z;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      board[i][j] = gc;
      gc = (gc * x + y) % z;
    }
    range_mins_inplace(board[i], m, b);
  }

  // transpose
  for (int i = 0; i <= 3000; i++) {
    for (int j = i + 1; j <= 3000; j++) {
      swap(board[i][j], board[j][i]);
    }
  }

  ll sum = 0;
  for (int j = 0; j < m - b + 1; j++) {
    range_mins_inplace(board[j], n, a);
    for (int i = 0; i < n - a + 1; i++) {
      sum += board[j][i];
    }
  }

  cout << sum;
}
