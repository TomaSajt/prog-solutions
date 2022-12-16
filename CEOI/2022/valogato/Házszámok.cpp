#include <bits/stdc++.h>
using namespace std;
#define speed    \
    cout.tie(0); \
    cin.tie(0);  \
    ios::sync_with_stdio(0)

int k;

vector<int> budget;
vector<int> digits;
map<int, long long> mem;
long long pn(int e)
{
    if (mem[e])
        return mem[e];
    long long h = pn(e / 2);
    return mem[e] = (e % 2 == 0 ? h * h : h * h * k);
}

long long f(int d)
{
    return (d + 1) * pn(d);
}
long long g(int d)
{
    if (d == 0)
        return 0;
    return (k - 1) * f(d - 1) + g(d - 1);
}

int calcDig(int i)
{
    int a = f(i - 1);
    for (int j = 1; j < k; j++)
    {
        for (int l = 0; l < k; l++)
        {
            budget[l] -= a;
        }
        bool o = false;
        for (int l = 0; l < k; l++)
        {
            if (budget[l] < 0)
            {
                o = true;
                break;
            }
        }
        if (!o)
            continue;
        for (int l = 0; l < k; l++)
        {
            budget[l] += a;
        }
        return j - 1;
    }
    return k - 1;
}
int main()
{
    speed;
    mem[0] = 1;
    cin >> k;
    budget.resize(k);
    for (int &a : budget)
        cin >> a;
    int dig;
    for (int i = 0;; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int c = j == 0 ? g(i) : f(i);
            if (budget[j] < c)
            {
                dig = i;
                goto after;
            }
        }
    }
after:
    digits.resize(dig + 1);
    for (int i = dig; i >= 0; i--)
    {
        digits[i] = calcDig(i);
    }
    digits[0]--;
    int res = 0;
    for (int i = dig; i >= 0; i--)
    {
        res *= k;
        res += digits[i];
    }
    cout << res << endl;
}

//   1
//   2
//   3
//  10
//  11
//  12
//  13
//  20
//  21
//  22
//  23
//  30
//  31
//  32
//  33
// 100