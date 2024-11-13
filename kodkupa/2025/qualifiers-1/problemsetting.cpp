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
    vector<ll> A(N), B(N);
    for (ll& x : A) cin >> x;
    for (int i = 0; i < N - 1; i++) cin >> B[i];

    auto f = [](ll goal, int N, vector<ll> A,
                vector<ll> B) {
        for (int i = 0; i < N; i++) {
            if (A[i] >= goal) continue;
            ll nmn = goal - A[i];
            if (i) {
                if (B[i - 1] >= nmn) {
                    continue;
                } else {
                    nmn -= B[i - 1];
                    if (B[i] >= nmn) {
                        B[i] -= nmn;
                        continue;
                    } else {
                        return false;
                    }
                }
            } else {
                if (B[i] >= nmn) {
                    B[i] -= nmn;
                    continue;
                } else {
                    return false;
                }
            }
        }
        return true;
    };

    ll l = 0, r = 3e9;
    while (r - l > 1) {
        ll m = (l + r) / 2;
        if (f(m, N, A, B)) {
            l = m;
        } else {
            r = m;
        }
    }

    cout << l << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
