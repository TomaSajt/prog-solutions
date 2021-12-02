#include <vector>
#include <iostream>
using namespace std;
int main()
{
    int n, currPos;
    while (true)
    {
        cin >> n;
        if (n == 0)
            break;
        vector<int> nextPos(n + 1);
        nextPos[n] = 1;
        for (int i = 1; i < n; i++) nextPos[i] = i + 1;
        currPos = n;
        cout << "Discarded cards: ";
        while (true)
        {
            cout << nextPos[currPos];
            nextPos[currPos] = nextPos[nextPos[currPos]];
            currPos = nextPos[currPos];
            if(currPos == nextPos[currPos]) break;
            cout << ", ";
        }
        cout << endl << "Remaining card: " << currPos << endl;
    }
}