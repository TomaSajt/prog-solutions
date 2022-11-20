// 100/100 - sorted set iterator moment

#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
#define int long long


#undef int
int main() {
#define int long long
    speed;
    int n, m, a, b;
    cin >> n >> m;

    set<pair<int, int>> s;
    while (n--) {
        cin >> a >> b;
        auto pos = s.insert({ a,b }).first;
        bool mp = pos != s.begin() && prev(pos)->second + 1 == pos->first;
        bool mn = next(pos) != s.end() && next(pos)->first - 1 == pos->second;
        if (mp || mn) {
            auto pr = prev(pos), ne = next(pos);
            s.erase({ a,b });
            if (mp) s.erase(pr), a = pr->first;
            if (mn) s.erase(ne), b = ne->second;
            s.insert({ a,b });
        }
        cout << s.size() << endl;
    }



    /* lassú
        set<pair<int, int>> s;
        while (n--) {
            int a, b;
            cin >> a >> b;
            s.insert({ a,b });
            auto it = s.begin();
            int c = 1;
            while (next(it) != s.end()) {
                if (next(it)->first - it->second != 1) {
                    c++;
                }
                it++;
            }
            cout << c << endl;
        }*/
}