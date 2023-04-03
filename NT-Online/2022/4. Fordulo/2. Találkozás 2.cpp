// 100/100 - damn that's crazy
#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;

int main() {
    speed;
    int a, b, ax = 0, bx = 0;
    char d;
    cin >> a >> a >> b;
    for (int i = 0;i < a;i++) {
        cin >> d;
        ax += d == 'J';
    }
    for (int i = 0;i < b;i++) {
        cin >> d;
        bx += d == 'J';
    }
    cout << min(ax > bx ? a + bx - ax : a, bx > ax ? b + ax - bx : b) + 1 << endl;
}