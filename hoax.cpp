#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    map<int, int> map;
    int n, l, a, min, max;
    long long tot;
    cin >> n;
    while (n) {
        map.clear();
        tot = 0;
        while (n--) {
            cin >> l;
            while (l--) {
                cin >> a;
                map[a]++;
            }
            min = map.begin()->first;
            max = map.rbegin()->first;
            tot += max - min;
            if (!--map[min]) map.erase(min);
            if (!--map[max]) map.erase(max);
        }
        cout << tot << endl;
        cin >> n;
    }
}