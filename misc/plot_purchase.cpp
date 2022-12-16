#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;
#pragma GCC optimize ("Ofast")

int main() {
    speed;
    int n;
    cin >> n;
    unordered_map<ll, int> nums;
    vector<ll> numsV(n);
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        nums[a] = i;
        numsV[i] = a;
    }
    sort(numsV.begin(), numsV.end(), greater<ll>());
    for (int i = 0;i < n;i++) {
        int sum = numsV[i];
        for (int j = 0; j < n;j++) {
            int c = numsV[j];
            auto f = nums.find(sum - c);
            if (f != nums.end()) {
                cout << nums[sum] + 1 << " " << sum << endl;
                cout << j + 1 << " " << f->second + 1;
                return 0;
            }
        }
    }
    cout << "-1\n";
}