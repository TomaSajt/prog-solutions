#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, battery, accumulatorCapacity;
    cin >> n >> battery >> accumulatorCapacity;
    int accumulator = accumulatorCapacity, currPos = 0;
    vector<bool> isLit(n);
    for (int i = 0, temp; i < n; i++)
    {
        cin >> temp;
        isLit[i] = temp == 1;
    }
    while (currPos != n && (accumulator || battery))
    {
        if (battery && accumulator != accumulatorCapacity && isLit[currPos])
        {
            battery--;
            accumulator++;
        }
        else if (accumulator)
            accumulator--;

        else if (battery)
            battery--;
        currPos++;
    }
    cout << currPos << endl;
}