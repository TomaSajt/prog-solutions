#include <bits/stdc++.h>
using namespace std;

vector<int> month_lengths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector<int> w_month_lengths = {31, 30, 30, 31, 30, 30, 31, 30, 30, 31, 30, 31};

int main() {
  int year, month_ind, month_day_ind;
  cin >> year >> month_ind >> month_day_ind;
  month_day_ind--;
  month_ind--;

  if (year % 4 == 0) {
    month_lengths[1]++;
    w_month_lengths[5]++;
  }

  int day_index = month_day_ind;
  for (int i = 0; i < month_ind; i++) {
    day_index += month_lengths[i];
  }

  int w_month_ind = 0;
  int w_month_day_index = day_index;
  while (w_month_day_index >= w_month_lengths[w_month_ind]) {
    w_month_day_index -= w_month_lengths[w_month_ind];
    w_month_ind++;
  }

  cout << year << ' ' << w_month_ind + 1 << ' ';
  if (w_month_ind == 5 && w_month_day_index == 30) {
    cout << "SZN";
  }
  else if (w_month_ind == 11 && w_month_day_index == 30) {
    cout << "VN";
  }
  else {
    cout << w_month_day_index + 1;
  }
}
