#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    a[0] = 1;
    b[0] = 0;
    a[1] = 1;
    b[1] = 2;
    for (int i = 2; i <= n; i++) {
        a[i] = a[i - 2] + a[i - 1] + b[i - 2];
        b[i] = b[i - 1] + 2 * a[i - 1];
    }
    cout << a[n];
}