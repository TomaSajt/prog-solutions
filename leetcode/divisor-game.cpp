#include <bits/stdc++.h>

using namespace std;

bool divisorGame(int n) {
    return 1-n%2;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << divisorGame(n) << endl;
    }
}
