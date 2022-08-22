#include <bits/stdc++.h>
using namespace std;

class min_sliding_window {
    vector<int> values;
    deque<int> deque;
    int lo, hi;
public:
    min_sliding_window(const vector<int>& values, int start = 0) : values(values), lo(start), hi(start) {}

    void advance() {
        if (lo <= hi) {
            // delete all indices with value more than the value of the next index to be appended
            // this will make the deque monotonically increasing from front to back
            while (!deque.empty() && values[deque.back()] > values[hi]) deque.pop_back();
            deque.push_back(hi);
        }
        hi++;
    }
    void shrink() {
        if (!deque.empty() && deque.front() <= lo) deque.pop_front();
        lo++;
    }
    int curr_min() {
        if (lo >= hi) return INT_MAX;
        return values[deque.front()];
    }
};


int main() {
    min_sliding_window idk({ 10,20,5,30,20,10 });
    cout << idk.curr_min() << '\n';
    idk.shrink();
    cout << idk.curr_min() << '\n';
    idk.advance();
    cout << idk.curr_min() << '\n';
    idk.advance();
    cout << idk.curr_min() << '\n';
    idk.shrink();
    cout << idk.curr_min() << '\n';
    idk.advance();
    cout << idk.curr_min() << '\n';
    idk.advance();
    cout << idk.curr_min() << '\n';
    idk.advance();
    cout << idk.curr_min() << '\n';
    idk.shrink();
    cout << idk.curr_min() << '\n';
    idk.shrink();
    cout << idk.curr_min() << '\n';
    idk.shrink();
    cout << idk.curr_min() << '\n';
    idk.shrink();
    cout << idk.curr_min() << '\n';
}