#include <bits/stdc++.h>
#define int int64_t

using namespace std;

int n, k;

int simulate(int hand, queue<int> q, int l) {
  int cost = 0;
  for (int i = 0; i < l; i++) {
    int card = q.front();
    q.pop();

    if (card > hand) swap(card, hand);
    q.push(card);
    cost += card;
  }
  return cost;
}

int32_t main() {
  cin >> n >> k;

  queue<int> q;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    q.push(a);
  }
  int hand = q.front();
  q.pop();

  int cycle_len = n - 1;
  if (k < 3 * cycle_len) {
    cout << simulate(hand, q, k);
    return 0;
  }

  int cycle_cost = simulate(hand, q, 2 * cycle_len) - simulate(hand, q, cycle_len);
  int res = simulate(hand, q, k % cycle_len + cycle_len) + cycle_cost * (k / cycle_len - 1);
  cout << res;
}
