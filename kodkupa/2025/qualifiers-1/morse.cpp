#include <bits/stdc++.h>
#ifdef LOCAL
#include <debug.h>
#else
#define DB(...)
#endif

using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()

const ll INF = 2e9, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 1
void solve() {
    int N;
    cin >> N;
    vector<int> a;
    string S;
    cin >> S;
    for (char c : S) {
        if (c == '.') {
            if (a.empty())
                a.push_back(1);
            else
                a.back()++;
        } else {
            a.push_back(0);
        }
    }
    vector<int> b;
    for (int x : a)
        if (x) b.push_back(x);
    cout << b.size() << " ";

    sort(b.rbegin(), b.rend());
    int t = 0, result = 0;
    for (int x : b) {
        t++;
        result = max(result, x / 2 + t);
    }
    cout << result << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
