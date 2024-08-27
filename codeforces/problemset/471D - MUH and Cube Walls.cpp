#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(vector<int> s) {
  int n = s.size();
  vector<int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}

int main() {
  int n, w;
  cin >> n >> w;
  vector<int> a(n), b(w), q(n + w - 1, INT_MAX);
  for (int& x : a) cin >> x;
  for (int& x : b) cin >> x;
  for (int i = 0; i < w - 1; i++) q[i] = b[i + 1] - b[i];
  for (int i = 0; i < n - 1; i++) q[w + i] = a[i + 1] - a[i];
  vector<int> pi = prefix_function(q);
  cout << count(pi.begin(), pi.end(), w - 1);
}
