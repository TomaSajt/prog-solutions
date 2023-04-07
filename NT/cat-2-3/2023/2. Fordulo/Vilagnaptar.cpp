#include <bits/stdc++.h>
using namespace std;
#define speed cin.tie(0); ios::sync_with_stdio(0)

vector<int> orig_month_lengths = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
vector<int> new_month_lengths = { 31, 30, 30, 31, 30, 30, 31, 30, 30, 31, 30, 31 };

int main() {
    speed;
    int year, month_ind, month_day_ind;
    cin >> year >> month_ind >> month_day_ind;
    month_day_ind--;
    month_ind--;
    if (year % 4 == 0) {
        orig_month_lengths[1]++;
        new_month_lengths[5]++;
    }
    int day_index = month_day_ind;
    for (int i = 0; i < month_ind; i++) {
        day_index += orig_month_lengths[i];
    }
    int new_month_ind = 0;
    while (day_index >= new_month_lengths[new_month_ind]) {
        day_index -= new_month_lengths[new_month_ind];
        new_month_ind++;
    }
    int new_month_day_index = day_index;
    cout << year << ' ' << new_month_ind + 1 << ' ';
    if (new_month_ind == 5 && new_month_day_index == 30) cout << "SZN";
    else if (new_month_ind == 11 && new_month_day_index == 30) cout << "VN";
    else cout << new_month_day_index + 1;

    return 0;
}
