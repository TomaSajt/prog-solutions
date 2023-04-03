using System;
class Program
{
    static void Main(string[] args)
    {
        var sLine = Console.ReadLine().Split(' ');
        var n = int.Parse(sLine[0]);
        var m = int.Parse(sLine[1]);
        var k = int.Parse(sLine[2]);
        var DP = new long[n + 1, k + 1];
        DP[1, 0] = m;
        for (int l = 2; l <= n; l++)
        {
            for (int s = 0; s <= k; s++)
            {
                DP[l, s] = DP[l - 1, s];
                if (s != 0) DP[l, s] += DP[l - 1, s - 1] * (m - 1);
                DP[l, s] %= 998244353;
            }
        }
        Console.WriteLine(DP[n, k]);
    }
}