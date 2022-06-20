#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
int main() {
    speed;
    int a, b, n;
    cin >> n;
    while (cin >> a >> b >> n) {
        int c = 0;
        while (a <= n && b <= n) {
            if (a > b) b += a;
            else a += b;
            c++;
        }
        cout << c << endl;
    }
}