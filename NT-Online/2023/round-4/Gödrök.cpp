#include <bits/stdc++.h>
using namespace std;
#define speed cin.tie(0), ios::sync_with_stdio(0)

int main() {
    speed;
    int n; cin >> n;
    vector<int> holes(n);
    for(auto& a : holes) cin >> a;
    int m; cin >> m;
    vector<int> steps(m);
    for(auto& a : steps) cin >> a;
    int l = holes.back() + steps.back() + 2; // idk
    vector<int> prev(l, -1);
    int e = -1;
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int curr = q.front(); q.pop();
        auto itc = lower_bound(holes.begin(), holes.end(), curr);
        if(itc == holes.end()) {
            e = curr;
            break;
        }
        for(int s : steps) {
            int next = curr + s;
            if(prev[next] != -1) continue;
            auto itn = lower_bound(holes.begin(), holes.end(), next);
            if(itn != holes.end() && next == *itn) continue; // stepped in hole
            if(itn - itc != 1) continue;
            prev[next] = curr;
            q.push(next);
        }
    }
    if(e == -1) {
        cout << -1;
        return 0;
    }
    stack<int> path;
    while(e != 0) {
        path.push(e);
        e = prev[e];
    }
    while(!path.empty()) {
        cout << path.top() << ' '; path.pop();
    }
}

