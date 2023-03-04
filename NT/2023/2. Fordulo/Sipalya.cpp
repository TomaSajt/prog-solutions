#include <bits/stdc++.h>
using namespace std;
#define speed cin.tie(0); ios::sync_with_stdio(0)
typedef long long ll;

vector<ll> range_maxes(const vector<ll>& data, int k) {
    int n = data.size();
    vector<ll> res(n - k + 1);
    deque<int> dq;
    for (int i = 0; i < n; i++) {
        while (!dq.empty() && i - dq.front() >= k) dq.pop_front();
        while (!dq.empty() && data[dq.back()] <= data[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) {
            res[i - k + 1] = data[dq.front()];
        }
    }
    return res;
}

vector<ll> range_sums(const vector<ll>& data, int k) {
    int n = data.size();
    vector<ll> res(n - k + 1);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
        if (i >= k) {
            sum -= data[i - k];
        }
        if (i >= k - 1) {
            res[i - k + 1] = sum;
        }
    }
    return res;
}

int main() {
    speed;
    int n, k; cin >> n >> k;
    vector<ll> data(n);
    for (auto& a : data) cin >> a;
    for (int i = 0; i < n; i++) data[i] += i;
    vector<ll> maxes = range_maxes(data, k);
    vector<ll> sums = range_sums(data, k);
    ll best = LLONG_MAX;
    for (int i = 0; i <= n - k; i++) {
        ll cost = k * maxes[i] - sums[i];
        best = min(best, cost);
    }
    cout << best;
    return 0;
}
