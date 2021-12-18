#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;

int main() {
    speed;
    int x0, a, b, m, k, n;
    cin >> x0 >> a >> b >> m >> k >> n;
    vector<int> X(n), Y(n);
    X[0] = x0;
    cout << x0 << " ";
    for (int i = 1; i < n;i++)cerr << (X[i] = (X[i - 1] * a + b) % m) << " ";
    cout << endl;
    for (int i = 0; i < n;i++)cerr << (Y[i] = X[i] % k) << " ";
    cout << endl;

    int prev = -1;
    for (int i = 0; i < n; i++) {
        if (Y[i] == 2) {
            if (prev != -1) {
                cerr << i - prev;
            }
            prev = i;
        }
    }

    cerr << endl;

}