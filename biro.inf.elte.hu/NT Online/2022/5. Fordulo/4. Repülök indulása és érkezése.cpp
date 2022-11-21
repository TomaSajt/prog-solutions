// 95/100 - xddd, nem is csinálok semmi checket a while-on belül, csak mohón menjenek a repülők. outplayed.

#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;

int main() {
    speed;
    int n, p, m, v, ne = 0, w = 0;
    cin >> n >> p;
    queue<int> qu, qd;
    for (int i = 0, j;i<n && cin >> j;i++) qu.push(j);
    cin >> m >> v;
    for (int i = 0, j;i<m && cin >> j;i++) qd.push(j);
    for (int i = 0; i < m;i++) {
        int l = qd.front(); qd.pop(); qd.push(l);
        if (ne > l + v) {
            cout << "-1\n";
            return 0;
        }
        ne = max(l, ne) + p;
    }
    qu.push(INT_MAX);
    qd.push(INT_MAX);
    ne = 0;
    while (qu.size() + qd.size() > 2) {
        int t;
        if (qu.front() < qd.front()) t = qu.front(), qu.pop();
        else t = qd.front(), qd.pop();
        if (ne > t) w += ne - t;
        else ne = t;
        ne += p;
    }
    cout << w << endl;
}