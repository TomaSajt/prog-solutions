#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int x, p;
    cin >> x >> p;
    multiset<int> len;
    set<int> pos;
    pos.insert(0), pos.insert(x);
    len.insert(x);
    while (cin >> p) {
        auto it = pos.insert(p).first;
        auto l = *prev(it), r = *next(it);
        len.erase(len.find(r - l));
        len.insert(p - l);
        len.insert(r - p);
        cout << *len.rbegin() << ' ';
    }
}