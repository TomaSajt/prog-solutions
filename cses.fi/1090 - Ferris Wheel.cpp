#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    int w[n];
    for (int i = 0; i < n; i++) cin >> w[i];
    sort(w, w + n);
    int a = 0, l = 0, r = n - 1;
    for (; l < r; r--, a++) if (w[l] + w[r] <= x) l++;
    cout << a + (l == r);
}