// 100/100 - average bracket pair enjoyer

#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;

int main() {
    speed;
    int n, l = 0;
    char f, c;
    stack<int> s;
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        cin >> c;
        if (s.empty()) f = c;
        if (c == f) s.push(i);
        else l += i - s.top(), s.pop();
    }
    cout << l;
}