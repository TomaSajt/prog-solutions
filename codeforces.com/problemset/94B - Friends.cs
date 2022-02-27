using System;
public class Test
{
    static bool[,] adjacent;
    public static void Main()
    {//Barátok
        int n = int.Parse(Console.ReadLine());
        adjacent = new bool[5, 5];
        for (int y = 0; y < 5; y++)
        {
            for (int x = 0; x < 5; x++)
            {
                adjacent[x, y] = false;
            }
        }
        for (int i = 0; i < n; i++)
        {
            string[] sLine = Console.ReadLine().Split(' ');
            int a = int.Parse(sLine[0]);
            int b = int.Parse(sLine[1]);

            adjacent[a - 1, b - 1] = true;
            adjacent[b - 1, a - 1] = true;
        }
        Console.WriteLine(HarmasKapcsolat() || HarmasNemKapcsolat() ? "WIN" : "FAIL");
    }

    static bool HarmasKapcsolat()
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (!adjacent[i, j]) continue;
                for (int k = 0; k < 5; k++)
                {
                    if (!adjacent[i, k]) continue;
                    if (!adjacent[j, k]) continue;
                    return true;
                }
            }
        }
        return false;
    }
    static bool HarmasNemKapcsolat()
    {
        for (int i = 0; i < 5; i++)
        {
            //Első szomszéd
            for (int j = 0; j < 5; j++)
            {
                if (i == j) continue;
                if (adjacent[i, j]) continue;
                for (int k = 0; k < 5; k++)
                {
                    if (i == k) continue;
                    if (j == k) continue;
                    if (adjacent[i, k]) continue;
                    if (adjacent[j, k]) continue;
                    return true;
                }
            }
        }
        return false;
    }
}