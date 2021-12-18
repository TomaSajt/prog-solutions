#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define pb push_back
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;

int main() {
    speed;
    int n;
    cin >> n;
    map<ll, int, greater<ll>> nums;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        nums.insert({ a,i });
    }
    for (auto&& sum_pair : nums) {
        for (auto&& comp_pair : nums) {
            if (nums.count(sum_pair.first - comp_pair.first)) {
                cout << sum_pair.second + 1 << " " << sum_pair.first << endl;
                cout << comp_pair.second + 1 << " " << nums[sum_pair.first - comp_pair.first] + 1;
                return 0;
            }
        }
    }
    cout << "-1\n";
}