// 45/100 - 3 cases throw error after creating the 2nd vector<vector<int>> wtf??? also difficult af


#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;



int main() {
    speed;
    int m, n;
    string str1, str2;
    cin >> m >> ws;
    getline(cin, str1);
    cin >> n >> ws;
    getline(cin, str2);



    vector<vector<int>> matches(m + 1, vector<int>(n + 1));
    vector<vector<int>> half_matches(m + 1, vector<int>(n + 1));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int dist = abs(str1[i - 1] - str2[j - 1]);
            if (dist == 0) {
                matches[i][j] = matches[i - 1][j - 1] + 1;
                half_matches[i][j] = half_matches[i - 1][j - 1];
            }
            else if (dist == 1 || dist == 25) {
                matches[i][j] = matches[i - 1][j - 1];
                half_matches[i][j] = half_matches[i - 1][j - 1] + 1;
            }
            else {
                if (half_matches[i - 1][j] + 2 * matches[i - 1][j] > half_matches[i][j - 1] + matches[i][j - 1] * 2) {
                    matches[i][j] = matches[i - 1][j];
                    half_matches[i][j] = half_matches[i - 1][j];
                }
                else {
                    half_matches[i][j] = half_matches[i][j - 1];
                    matches[i][j] = matches[i][j - 1];
                }
            }
        }
    }

    /*

        cout << "    ";
        for (char& c : str2) cout << c << ' ';
        cout << endl;
        for (int i = 0;i <= m;i++) {
            cout << (i == 0 ? ' ' : str1[i - 1]) << ' ';
            for (int j = 0;j <= n;j++) {
                cout << mtc[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;


        cout << "    ";
        for (char& c : str2) cout << c << ' ';
        cout << endl;
        for (int i = 0;i <= m;i++) {
            cout << (i == 0 ? ' ' : str1[i - 1]) << ' ';
            for (int j = 0;j <= n;j++) {
                cout << psmtc[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    */

    int i = m, j = n;
    int stmtc = matches[i][j];
    int stpsmtc = half_matches[i][j];
    while (i > 0 && j > 0) {
        if (matches[i][j - 1] == stmtc && half_matches[i][j - 1] == stpsmtc) {
            j--;
        }
        else if (matches[i - 1][j] == stmtc && half_matches[i - 1][j] == stpsmtc) {
            i--;
        }
        else {
            break;
        }
    }

    int bottom = i, right = j;
    int top = i, left = i;
    while (i > 0 && j > 0) {
        int dist = abs(str1[i - 1] - str2[j - 1]);
        if (dist == 0 || dist == 1 || dist == 25) {
            top = i; left = j;
            //cout << str1[i - 1] << ':' << str2[j - 1] << endl;
            i--; j--;
        }
        else if (half_matches[i - 1][j] + 2 * matches[i - 1][j] > half_matches[i][j - 1] + matches[i][j - 1] * 2) {
            i--;
        }
        else {
            j--;
        }
    }
    top--;
    left--;
    int span2 = right - left + 1, span1 = bottom - top + 1;
    int center_junk1 = span1 - half_matches[bottom][right] - matches[bottom][right] - 1;
    int center_junk2 = span2 - half_matches[bottom][right] - matches[bottom][right] - 1;

    int padding_modify_cost = top + left + (m - bottom) + (n - right);
    cout << padding_modify_cost + half_matches[bottom][right] + (center_junk1 + center_junk2) * 2 << endl;
}