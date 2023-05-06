#include <bits/stdc++.h>
using namespace std;
#define speed cin.tie(0), ios::sync_with_stdio(0)
const int mod = 2023;

int main() {
    speed;
    int n, k; cin >> n >> k;
    vector<int> height(n);
    for(auto& a : height) cin >> a;
    vector<int> peaks;
    for(int i = 1; i < n - 1; i++) {
	if(height[i] > height[i - 1] && height[i] > height[i + 1]) peaks.push_back(i);
    }
    if(peaks.size() < k) {
	cout << -1;
	return 0;
    }
    vector<int> bef(peaks.size()), aft(peaks.size());
    for(int i = 0; i < peaks.size(); i++) {
	int pre = i == 0 ? -1 : peaks[i - 1];
	int nex = i == peaks.size() - 1 ? n : peaks[i + 1];
	bef[i] = peaks[i] - pre - 1;
	aft[i] = nex - peaks[i] - 1;
    }
    int res = 0;
    for(int i = 0; i < peaks.size() - k + 1; i++) {
	int j = i + k - 1;
	res += (bef[i] % mod) * (aft[j] % mod);
	res %= mod;
    }
    cout << res;
}

