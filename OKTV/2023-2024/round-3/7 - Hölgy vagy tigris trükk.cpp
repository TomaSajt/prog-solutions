// DOESN'T WORK
// 0/45

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = LLONG_MAX;

using guess = pair<int,char>;
using guess_tuple = array<guess,3>;


signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n,m;
        cin >> n >> m;
        vector<guess_tuple> guess_tuples(m);
        for(int i = 0; i<m;i++) {
            auto& [a,b,c] = guess_tuples[i];
            auto& [ai,ag] = a;
            auto& [bi,bg] = b;
            auto& [ci,cg] = c;
            cin >> ai >> ag >> bi >> bg >>ci >> cg;
        }
        bool found = 0;
        for(int mask = 0; mask<(1<<n); mask++) {
            bool bad = 0;
            for(int i = 0; i<m;i++) {
                auto& [a,b,c] = guess_tuples[i];
                auto& [ai,ag] = a;
                auto& [bi,bg] = b;
                auto& [ci,cg] = c;
                int cnt = 0;
                if(ag == "HT"[(mask>>ai)&1]) cnt++;
                if(bg == "HT"[(mask>>bi)&1]) cnt++;
                if(cg == "HT"[(mask>>ci)&1]) cnt++;
                if(cnt < 2){
                    bad = 1;
                    break;
                }
            }
            if(bad) continue;
            for(int i = 0; i<n;i++) {
                cout << "HT"[(mask >> i) & 1] << ' ';
            }
            cout << endl;
            found = 1;
            break;
        }
        if(!found) {
            cout << "-1" << endl;
        }
    }
}
