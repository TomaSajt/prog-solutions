#include <bits/stdc++.h>
using namespace std;

int main() {
    string x;
    for (cin >> x; cin >> x;) {
        set<char> s;
        int r = x.size();
        for (char c : x) {
            if (!s.insert(c).second) {
                s.clear();
                r -= 2;
            }
        }
        cout << r << '\n';
    }
}