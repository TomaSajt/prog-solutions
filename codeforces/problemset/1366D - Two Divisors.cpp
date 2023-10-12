#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX_A = 1e7;

int prime_div[MAX_A + 1];

array<int, 2> solve(int a) {
  if (prime_div[a] == a) return {-1, -1};
  int b = a;
  while (b % prime_div[a] == 0) b /= prime_div[a];
  if (b == 1) return {-1, -1};
  // these two are co-prime with eachother, so they are co-prime with their sums too
  return {prime_div[a], b};
}

int main() {
  for (int i = 2; i <= MAX_A; i++) {
    if (prime_div[i] != 0) continue;
    prime_div[i] = i;
    for (ll j = (ll)i * i; j <= MAX_A; j += i) prime_div[j] = i;
  }

  ios::sync_with_stdio(0), cin.tie(0);

  int n;
  cin >> n;
  vector<array<int, 2>> sols(n);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    sols[i] = solve(a);
    cout << sols[i][0] << ' ';
  }
  cout << '\n';
  for (int i = 0; i < n; i++) cout << sols[i][1] << ' ';
}
