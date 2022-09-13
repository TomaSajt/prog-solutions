#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n, c = 0;
    cin >> n;
    for (int f = 5; n / f > 0; f *= 5) c += n / f;
    cout << c;
}