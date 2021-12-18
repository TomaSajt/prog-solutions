#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;
int n;

// The function returns maximum
// circular contiguous sum in a[]
int maxCircularSum(vector<int> a) {

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    // Initialize every variable with first value of array.
    int curr_max = a[0], best_max = a[0], curr_max_start = 0, best_max_start = 0, best_max_end = 0;
    int curr_min = a[0], best_min = a[0], curr_min_start = 0, best_min_start = 0, best_min_end = 0;

    // Concept of Kadane's Algorithm
    for (int i = 1; i < n; i++) {
        if (curr_max + a[i] < a[i]) {
            curr_max = a[i];
            curr_max_start = i;
        }
        else curr_max += a[i];
        if (best_max < curr_max) {
            best_max = curr_max;
            best_max_start = curr_max_start;
            best_max_end = i;
        }

        if (curr_min + a[i] > a[i]) {
            curr_min = a[i];
            curr_min_start = i;
        }
        else curr_min += a[i];
        if (best_min > curr_min) {
            best_min = curr_min;
            best_min_start = curr_min_start;
            best_min_end = i;
        }
    }
    cerr << "best_max: " << best_max << " start: " << best_max_start << " end: " << best_max_end << endl;
    cerr << "best_min: " << best_min << " start: " << best_min_start << " end: " << best_min_end << endl;
    return max(best_max, sum - best_min);
}

int main() {
    speed;
    cin >> n;
    vector<int> arr(n);
    for (auto& i : arr) {
        int a;
        cin >> a >> i;
        i -= a;
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    // Initialize every variable with first value of array.
    int curr_max = arr[0], best_max = arr[0], curr_max_start = 0, best_max_start = 0, best_max_end = 0;
    int curr_min = arr[0], best_min = arr[0], curr_min_start = 0, best_min_start = 0, best_min_end = 0;

    // Concept of Kadane's Algorithm
    for (int i = 1; i < n; i++) {
        if (curr_max + arr[i] < arr[i]) {
            curr_max = arr[i];
            curr_max_start = i;
        }
        else curr_max += arr[i];
        if (best_max < curr_max) {
            best_max = curr_max;
            best_max_start = curr_max_start;
            best_max_end = i;
        }

        if (curr_min + arr[i] > arr[i]) {
            curr_min = arr[i];
            curr_min_start = i;
        }
        else curr_min += arr[i];
        if (best_min > curr_min) {
            best_min = curr_min;
            best_min_start = curr_min_start;
            best_min_end = i;
        }
    }
    cerr << "best_max: " << best_max << " start: " << best_max_start << " end: " << best_max_end << endl;
    cerr << "best_min: " << best_min << " start: " << best_min_start << " end: " << best_min_end << endl;
    int smbm = sum - best_min;
    if (best_max > smbm) {
        cout << best_max << endl << best_max_start + 1 << " " << best_max_end + 1 << endl;
    }
    else {
        if (!smbm) {
            cout << -1 << endl;
            return 0;
        }
        cout << smbm << endl << (best_min_end + 1) % n + 1 << " " << (best_min_start + n - 1) % n + 1 << endl;
    }
}