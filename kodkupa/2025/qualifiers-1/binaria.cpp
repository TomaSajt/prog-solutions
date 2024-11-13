// NOTE: it is recommended to use this even if you don't understand
// the following code.
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long N, hatvany = 1;
    cin >> N;

    long long B = 0;
    vector<long long> v(N);
    for (int i = 0; i < N; ++i) { cin >> v[i]; }
    int i = 0;
    while (i < v.size()) {
        if (v[i] > hatvany) {
            v[i] -= hatvany;
            hatvany *= 2;
        } else {
            B += hatvany - v[i];
            i++;
            hatvany = 1;
        }
    }
    cout << B << '\n';

    return 0;
}
