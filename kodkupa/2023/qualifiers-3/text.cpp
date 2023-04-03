// 100/100

#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n, k;
    cin >> n >> k;
    vector<string> texts(n);
    vector<map<char, int>> cnts(k);
    for (auto& s : texts) {
        cin >> s;
        for (int i = 0; i < k; i++) {
            cnts[i][s[i]]++;
        }
    }
    vector<int> scores(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            scores[i] += cnts[j][texts[i][j]];
        }
    }
    cout << max_element(scores.begin(), scores.end()) - scores.begin();
}