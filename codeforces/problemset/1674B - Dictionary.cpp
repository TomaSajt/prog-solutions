#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;

int main() {
    speed;
    int t;
    cin >> t;
    char a, b;
    while (cin >> a >> b) {
        cout << (a - 'a') * 25 + (b - 'a') - (a < b) + 1 << endl;
    }

}