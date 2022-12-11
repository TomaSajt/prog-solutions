#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n; cin >> n;
    char c;
    int res = 1;
    set<char> dirs;
    map<char, char> ops;
    ops['U'] = 'D';
    ops['D'] = 'U';
    ops['L'] = 'R';
    ops['R'] = 'L';
    cin >> c;
    dirs.insert(c);
    while (cin >> c) {
        if (dirs.size() == 1) {
            char other = *dirs.begin();
            if (ops[other] == c) {
                res++;
                dirs.clear();
            }
        }
        else if (dirs.size() == 2) {
            if (!dirs.count(c)) {
                res++;
                dirs.clear();
            }
        }
        dirs.insert(c);
    }
    cout << res;
}