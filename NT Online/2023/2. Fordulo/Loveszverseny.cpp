#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int a; cin >> a >> a;
    set<int> better, worse;
    int maxLess = INT_MIN;
    int minGreater = INT_MAX;
    for (int i = 2, b; cin >> b; i++) {
        if (b == a) continue;
        if (b < a && b >= maxLess) {
            maxLess = b;
            worse.insert(i);
        }
        if (b > a && b <= minGreater) {
            minGreater = b;
            better.insert(i);
        }
    }
    cout << better.size() << '\n';
    for (int i : better) cout << i << ' ';
    cout << '\n' << worse.size() << '\n';
    for (int i : worse) cout << i << ' ';
}