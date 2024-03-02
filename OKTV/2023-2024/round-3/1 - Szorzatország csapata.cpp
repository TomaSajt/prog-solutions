#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = LLONG_MAX;


signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> x(n);
    for(int& a : x) cin >> a;
    if(n==1) {
        cout << "1 1";
        return 0;
    }

    x.push_back(0);


    int best = -1;
    int best_l = -1, best_r = -1;
    int l = 0;
    while(l<=n) {
        int r = l;
        while(x[r]!=0) r++;
        r--;
        int s = 1;
        int twos = 0;
        for(int i = l; i<=r; i++) {
            if(x[i] < 0) s*=-1;
            if(abs(x[i])==2)twos++;
            if(s == 1 && best < twos) {
                best = twos;
                best_l = l;
                best_r = i;
            }
        }
        twos = 0;
        s = 1;
        for(int i = r; i>=l; i--) {
            if(x[i] < 0) s*=-1;
            if(abs(x[i])==2)twos++;
            if(s == 1 && best < twos) {
                best = twos;
                best_l = i;
                best_r = r;
            }
        }

        l=r+2;
    }
    if(best == -1) {
        int i = find(x.begin(),x.end(),0)-x.begin();
        if(i==n) {
            cout <<1/0;
        }
        cout <<i+1 << ' ' <<i + 1;
        return 0;
    }
    cout << best_l+1 << ' ' << best_r+1;
}
