#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n;
    string s;
    cin >> n;
    set<char> mem;
    while (cin >> s) {
        int res = 0;
        mem.clear();
        for (char& c : s) {
            if (mem.find(c) == mem.end()) {
                if (mem.size() == 3) mem.clear(), res++;
                mem.insert(c);
            }
        }
        cout << res + 1 << '\n';
    }
}