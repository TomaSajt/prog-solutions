#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;
/*
void print_map(const map<long long, long long> &m)
{
    for (const auto &kvp : m)
    {
        cerr << kvp.first << " = " << kvp.second << "; ";
    }
    cerr << "\n";
}*/

int main()
{
    map<long long, long long> map;
    long long n, k;
    cin >> n >> k;
    for (long long i = 0; i < n; i++)
    {
        long long a;
        cin >> a;
        if (map.find(a) == map.end())
            map.insert({a, 0});

        map[a]++;
    }

    while (map.size() > 1)
    {
        if (map.begin()->second < map.rbegin()->second)
        {
            auto firstIter = map.begin();
            auto secondIter = next(map.begin());
            auto firstkey = firstIter->first;
            auto firstval = firstIter->second;
            auto secondkey = secondIter->first;
            auto secondval = secondIter->second;
            auto diff = secondkey - firstkey;

            if (k / firstval < diff)
            {
                cout << (map.rbegin()->first - map.begin()->first - k / firstval) << endl;
                return 0;
            }

            k -= firstval * diff;

            secondIter->second += firstval;
            map.erase(firstkey);
        }
        else
        {
            auto rfirstIter = map.rbegin();
            auto rsecondIter = next(map.rbegin());
            auto rfirstkey = rfirstIter->first;
            auto rfirstval = rfirstIter->second;
            auto rsecondkey = rsecondIter->first;
            auto rsecondval = rsecondIter->second;
            auto diff = rfirstkey - rsecondkey;

            if (k / rfirstval < diff)
            {
                cout << (map.rbegin()->first - map.begin()->first - k / rfirstval) << endl;
                return 0;
            }

            k -= rfirstval * diff;

            rsecondIter->second += rfirstval;
            map.erase(rfirstkey);
        }
    }
    cout << 0 << endl;
}
