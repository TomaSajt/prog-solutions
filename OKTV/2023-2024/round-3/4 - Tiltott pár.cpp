#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = LLONG_MAX;



signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    map<int,vector<int>> poses;
    for(int i = 0; i<n;i++) {
        int v; cin >>v;
        poses[v].push_back(i);
    }

    int q;
    cin >> q;

    while(q--) {
        int v1, v2;
        cin >> v1 >> v2;
        const auto& ps1 = poses[v1];
        const auto& ps2 = poses[v2];

        auto is_good = [&](int moves) {
            if(moves >= ps1.size() || moves >= ps2.size()) return true;
            return ps1[moves] > ps2[ps2.size()-1-moves];
        };

        int curr_move = -1;
        for(int i = 32; i>=0; i--) {
            int next_move = curr_move + (1ll << i);
            if(!is_good(next_move)) curr_move=next_move;
        }
        cout << curr_move+1 << '\n';
    }
}

