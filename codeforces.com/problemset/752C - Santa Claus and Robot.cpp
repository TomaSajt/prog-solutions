#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n; cin >> n;
    char c;
    int res = 1;
    map<char, char> ops;
    string a = "UDLR", b = "DURL";
    set<char> dirs;
    for (int i = 0; i < 4; i++) ops[a[i]] = b[i];
    while (cin >> c) {
        if ((dirs.size() == 1 && ops[c] == *dirs.begin()) || (dirs.size() == 2 && !dirs.count(c))) {
            res++;
            dirs.clear();
        }
        dirs.insert(c);
    }
    cout << res;
}