#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = LLONG_MAX;



signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> diff(400002);
    while(n--) {
        int s,e;
        cin >> s >> e;
        diff[s]++;
        diff[e+1]--;
    }
    vector<int> pref_sum(400002);
    partial_sum(diff.begin(),diff.end(),pref_sum.begin());
    cout << *max_element(pref_sum.begin(),pref_sum.end());

}
