#include <bits/stdc++.h>
using namespace std;
int t, n, a, c, m, h;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    set<int> s;
    while (t--) {
        cin >> n;
        s.clear();
        c = 0;
        while (n--) {
            cin >> a;
            if (a % 2 == 0) s.insert(a);
        }
        while (s.size() != 0) {
            m = *(s.rbegin());
            s.erase(m);
            h = m / 2;
            if (h % 2 == 0) s.insert(h);
            c++;
        }
        cout << c << endl;
    }
}