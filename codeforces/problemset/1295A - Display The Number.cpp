#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
int main() {
    speed;
    int n; cin >> n;
    while (cin >> n) {
        cout << "17"[n % 2] << string(n / 2 - 1, '1') << endl;
    }
}