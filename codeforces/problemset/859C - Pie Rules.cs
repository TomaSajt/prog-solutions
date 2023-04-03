using System;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        var N = int.Parse(Console.ReadLine());
        var pies = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        var F = new int[N];
        var S = new int[N];
        F[N - 1] = pies[N - 1];
        S[N - 1] = 0;
        for (int i = N - 2; i >= 0; i--)
        {
            if (S[i + 1] + pies[i] > F[i + 1])
            {
                F[i] = S[i + 1] + pies[i];
                S[i] = F[i + 1];
            }
            else
            {
                F[i] = F[i + 1];
                S[i] = S[i + 1] + pies[i];
            }
        }
        Console.WriteLine(S[0] + " " + F[0]);
    }
}