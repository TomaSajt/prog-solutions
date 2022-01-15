
#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main() {
#define int long long
    speed;
    int n;
    int sum = 0;
    cin >> n;
    vector<int> pref(n + 1);
    for (int i = 0;i < n;i++) {
        cin >> pref[i + 1];
        sum += pref[i + 1];
        pref[i + 1] += pref[i];
    }
    if (sum % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }
    int t = sum / 3;
    vector<int> prefTwice(n + 1);
    for (int i = 0; i < n; i++) {
        prefTwice[i + 1] = prefTwice[i] + (pref[i] == t * 2);
    }
    int a = 0;
    for (int i = 1; i < n - 1; i++) {
        if (pref[i] == t) {
            a += prefTwice[n] - prefTwice[i + 1];
        }
    }
    cout << a << endl;
    return 0;
}
