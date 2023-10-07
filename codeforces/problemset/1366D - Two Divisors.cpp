#include <bits/stdc++.h>
using namespace std;
const int MAX_A = 1e7;

vector<int> primes;
bool is_comp[MAX_A + 1];

array<int, 2> solve(int a) {
  if (!is_comp[a]) return {-1, -1};
  int d = 1;
  for (int p : primes) {
    if (a % p != 0) continue;
    while (a % p == 0) {
      d *= p;
      a /= p;
    }
    break;
  }
  if (a == 1) return {-1, -1};
  return {d, a};
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  for (int i = 2; i * i <= MAX_A; i++) {
    if (is_comp[i]) continue;
    primes.push_back(i);
    for (int j = i * i; j <= MAX_A; j += i) is_comp[j] = 1;
  }
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
