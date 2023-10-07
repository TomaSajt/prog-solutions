#include <bits/stdc++.h>
using namespace std;

int n, mem[100001], a[100001];

int winner(int i) {
  if (mem[i]) return mem[i];
  for (int j = i + a[i]; j < n; j += a[i]) {
    if (a[j] > a[i] && winner(j) == 2) return mem[i] = 1;
  }
  for (int j = i - a[i]; j >= 0; j -= a[i]) {
    if (a[j] > a[i] && winner(j) == 2) return mem[i] = 1;
  }
  return mem[i] = 2;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cout << " AB"[winner(i)];
}
