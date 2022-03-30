#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long ll;


int DP[3001][3001];

int main() {
    speed;
    string str1, str2;
    cin >> str1 >> str2;
    int n = str1.size(), m = str2.size();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m;j++)
            DP[i][j] = str1[i - 1] == str2[j - 1] ? DP[i - 1][j - 1] + 1 : max(DP[i][j - 1], DP[i - 1][j]);
    stack<char> s;
    while (n != 0 && m != 0)
        if (str1[n - 1] == str2[m - 1]) s.push(str1[n - 1]), n--, m--;
        else if (DP[n - 1][m] > DP[n][m - 1]) n--;
        else m--;
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << endl;

}


//Kókusz
/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    string S, T;
    cin >> S >> T;
    vector<vector<int>> dpS(S.size() + 1, vector<int>(T.size() + 1));
    for (int i = 0; i < S.size(); i++) {
        for (int j = 0; j < T.size(); j++) {
            if (S[i] == T[j]) {
                dpS[i + 1][j + 1] = dpS[i][j] + 1;
            }
            else {
                dpS[i + 1][j + 1] = max(dpS[i][j + 1], dpS[i + 1][j]);
            }
        }
    }
    stack<char> answerS;
    int i = S.size(), j = T.size();
    while (i > 0 && j > 0) {
        if (S[i - 1] == T[j - 1]) {
            answerS.push(S[i - 1]);
            --i;
            --j;
        }
        else if (dpS[i - 1][j] > dpS[i][j - 1]) {
            --i;
        }
        else {
            --j;
        }
    }
    while (!answerS.empty()) {
        cout << answerS.top();
        answerS.pop();
    }
    cout << '\n';
}
*/