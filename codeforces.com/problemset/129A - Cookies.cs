using System;

public class Program
{
    public static void Main()
    {
        int N = int.Parse(Console.ReadLine());
        string[] sLine = Console.ReadLine().Split(' ');
        int ptnZsakok = 0;
        int psZsakok = 0;
        bool ptnOsszeg = false;
        for (int i = 0; i < N; i++)
        {
            if (int.Parse(sLine[i]) % 2 != 0)
            {
                ptnZsakok++;
                ptnOsszeg = !ptnOsszeg;
            }
            else
            {
                psZsakok++;
            }
        }
        if (psZsakok + ptnZsakok == 0)
        {
            Console.WriteLine("0");
            return;
        }
        if (ptnOsszeg)
        {
            Console.WriteLine(ptnZsakok);
        }
        else
        {
            Console.WriteLine(psZsakok);
        }
    }
}