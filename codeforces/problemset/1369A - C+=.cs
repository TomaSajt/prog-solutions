using System;
class Program
{
    static void Main(string[] args)
    {
        var output = "";
        int T = int.Parse(Console.ReadLine());
        for (int i = 0; i < T; i++)
        {
            var lSplit = Console.ReadLine().Split(' ');
            output += Solve(int.Parse(lSplit[0]), int.Parse(lSplit[1]), int.Parse(lSplit[2])) + "\n";
        }
        Console.Write(output);
    }
    static int Solve(int a, int b, int n)
    {
        int iters = 0;
        while (a <= n && b <= n)
        {
            if (a > b) b += a;
            else a += b;
            iters++;
        }
        return iters;
    }
}