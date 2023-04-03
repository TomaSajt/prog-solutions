#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    string s;
    cin >> s;
    char pc = '#';
    int best = 0, curr = 0;
    for (char c : s) {
        if (pc != c) curr = 0;
        best = max(best, ++curr);
        pc = c;
    }
    cout << best;
}