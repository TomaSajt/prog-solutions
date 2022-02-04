#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;

int main() {
    speed;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int die = 1; die <= 6; die++) {
        int ind = 0;
        int c = 0;
        while (ind < n) {
            c++;
            ind += die;
            while (arr[ind] > 0 && ind < n) {
                ind += arr[ind];
            }
        }
        cout  << c << " ";
    }
}