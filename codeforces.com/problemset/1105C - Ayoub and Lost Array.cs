using System;

class A
{
    static void Main(string[] args)
    {
        var lSplit = Console.ReadLine().Split(' ');
        var n = int.Parse(lSplit[0]);
        var l = int.Parse(lSplit[1]);
        var r = int.Parse(lSplit[2]);
        var rem0 = r / 3 - (l - 1) / 3;
        var rem1 = (r + 2) / 3 - (l + 1) / 3;
        var rem2 = (r + 1) / 3 - l / 3;
        var DP = new long[n + 1, 3];
        DP[0, 0] = 1;
        for (int i = 1; i <= n; i++)
        {
            DP[i, 0] = (DP[i - 1, 0] * rem0 + DP[i - 1, 1] * rem2 + DP[i - 1, 2] * rem1) % 1000000007;
            DP[i, 1] = (DP[i - 1, 1] * rem0 + DP[i - 1, 2] * rem2 + DP[i - 1, 0] * rem1) % 1000000007;
            DP[i, 2] = (DP[i - 1, 2] * rem0 + DP[i - 1, 0] * rem2 + DP[i - 1, 1] * rem1) % 1000000007;
        }
        Console.WriteLine(DP[n, 0]);
    }
}