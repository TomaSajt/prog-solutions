#include <bits/stdc++.h>
using namespace std;
#define speed cin.tie(0), ios::sync_with_stdio(0)

int main() {
    speed;
    int n; cin >> n;
    vector<int> cost(n + 1);
    for(int i = 1; i <= n; i++) cin >> cost[i];
    vector<int> a(n + 1, INT_MAX);
    a[1] = cost[1];
    for(int i = 2; i <= n; i++) {
        a[i] = min(a[i - 1], a[i - 2]) + cost[i];
    }
    cout << a[n] << '\n';
    int curr = n;
    int isA = true;
    stack<int> res;
    while(curr != 1) {
        res.push(curr);
        curr -= a[curr - 2] < a[curr - 1] ? 2 : 1;
    }
    cout << '1';
    while(!res.empty()) {
        cout << ' ' << res.top();
        res.pop();
    }
}

