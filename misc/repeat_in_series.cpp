#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;

int main() {
    speed;
    ll x0, a, b, m, k, n;
    cin >> x0 >> a >> b >> m >> k >> n;
    vector<ll> X(n + 1);
    X[0] = x0;
    unordered_set<ll> appeared;
    ll len = n;
    for (ll i = 1; i <= n;i++) {
        X[i] = (X[i - 1] * a + b) % m;
        if (appeared.find(X[i]) != appeared.end()) {
            len = i - 1;
            break;
        }
        appeared.insert(X[i]);
    }
    vector<ll> Y(len + 1);
    for (ll i = 1; i <= len; i++) Y[i] = X[i] % k;


    unordered_map<ll, ll> last_seen, dists, best_firsts;
    for (ll i = 1; i <= len; i++) {
        ll curr = Y[i];
        if (last_seen.find(curr) != last_seen.end()) {
            ll curr_dist = i - last_seen[curr];
            if (dists.find(curr) == dists.end() || curr_dist > dists[curr]) {
                best_firsts[curr] = last_seen[curr];
                dists[curr] = curr_dist;
            }
        }
        last_seen[curr] = i;
    }
    if (dists.empty()) {
        cout << -1 << endl;
        return 0;
    }
    ll max_key = -1, max_value = -1;
    for (auto& pair : dists) {
        ll key = pair.first, value = pair.second;
        if (max_value < value || (max_value == value && best_firsts[max_key] > best_firsts[key])) {
            max_value = value;
            max_key = key;
        }
    }
    cout << max_key << " " << max_value << endl;
    return 0;
}