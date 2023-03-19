#include <bits/stdc++.h>
using namespace std;
#define speed cin.tie(0), ios::sync_with_stdio(0)

int main() {
    speed;
    int n, m; cin >> n >> m;
    map<int,int> SEMap;
    SEMap[1] = n;
    while(m--) {
        int xs, xe; cin >> xs >> xe;
        auto it = SEMap.upper_bound(xs);
        it--;
        auto [s,e] = *it;
        SEMap.erase(it);
        int ls = s, le = xs - 1;
        int rs = xe + 1, re = e;
        if(ls <= le) SEMap[ls] = le;
        if(rs <= re) SEMap[rs] = re;
        cout << SEMap.size() << '\n';
    }
}

