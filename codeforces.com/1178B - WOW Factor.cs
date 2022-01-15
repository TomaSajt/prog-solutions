using System;
public class Test
{
    public static void Main()
    {
        string str = Console.ReadLine();
        int n = str.Length;
        long ans = 0;
        int[] vvBal = new int[n];
        int[] vvJobb = new int[n];
        if (n > 0) vvBal[0] = 0;
        if (n > 1) vvBal[1] = 0;
        for (int i = 2; i < n; i++)
        {

            vvBal[i] = vvBal[i - 1];
            if (str[i - 1] == 'v' && str[i - 2] == 'v')
            {
                vvBal[i]++;
            }
        }
        if (n > 0) vvJobb[n - 1] = 0;
        if (n > 1) vvJobb[n - 2] = 0;
        for (int i = n - 3; i >= 0; i--)
        {

            vvJobb[i] = vvJobb[i + 1];
            if (str[i + 1] == 'v' && str[i + 2] == 'v')
            {
                vvJobb[i]++;
            }
        }
        for (int i = 2; i < n - 2; i++)
        {
            if (str[i] == 'o')
            {
                ans += (long)vvJobb[i] * (long)vvBal[i];
            }
        }
        Console.WriteLine(ans);

    }
}