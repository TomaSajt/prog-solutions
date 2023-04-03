#include <bits/stdc++.h>
using namespace std;
int main() {
#define int long long
    int n;
    cin >> n >> ws;
    vector<int> m(n);
    for (int i = 0; i <= n; i++) {
        cin >> m[i] >> ws;
    }
    vector<int> x(n);
    int maxP = 0;
    int maxS = 0;
    for (int p = 0; p < n; p++) {
        int s = m[p];
        for (int i = 0; i < n; i++) {
            x[i] = m[i];
        }
        for (int i = p - 1; i >= 0; i--) {
            x[i] = x[i + 1] < x[i] ? x[i + 1] : x[i];
            s += x[i];
        }
        for (int i = p + 1; i < n; i++) {
            x[i] = x[i - 1] < x[i] ? x[i - 1] : x[i];
            s += x[i];
        }
        if (maxS < s) {
            maxS = s;
            maxP = p;
        }
    }
    for (int i = 0; i < n; i++) {
        x[i] = m[i];
    }
    for (int i = maxP - 1; i >= 0; i--) {
        x[i] = x[i + 1] < x[i] ? x[i + 1] : x[i];
    }
    for (int i = maxP + 1; i < n; i++) {
        x[i] = x[i - 1] < x[i] ? x[i - 1] : x[i];
    }
    for (int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;

    return 0;
}