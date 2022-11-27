#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n, cnt = 0, res = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "_") cnt++;
    }
    for (int i = 0; i < cnt; i++) {
        res *= (27 - n + i);
    }
    cout << res;
}