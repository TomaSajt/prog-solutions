#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (long long i = 0; i < n; i++) cout << (i * i - i + 2) * (i + 5) * i / 2 << '\n';
}