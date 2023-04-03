    using System;
    using System.Collections.Generic;
     
    public class Test
    {
      static long koltseg = 0;
      static bool[] voltMar;
      static new List<long>[] szomszedok;
      static long[] c;
      static long N, M;
    	public static void Main()
    	{
        string[] sLine = Console.ReadLine().Split(' ');
        N = long.Parse(sLine[0]);
        szomszedok = new List<long>[N];
        
        voltMar = new bool[N];
        c = new long[N];
        
        M = long.Parse(sLine[1]);
        string[] cStr = Console.ReadLine().Split(' ');
        for(long i = 0; i < N; i++) {
          c[i] = long.Parse(cStr[i]);
          szomszedok[i] = new List<long>();
        }
        for(long i = 0; i < M; i++) {
          var sLine2 = Console.ReadLine().Split(' ');
          long u = long.Parse(sLine2[0]);
          long v = long.Parse(sLine2[1]);
          szomszedok[u-1].Add(v-1);
          szomszedok[v-1].Add(u-1);
        }
        
        for(long i = 0; i < N; i++) {
          if(!voltMar[i]) {
            koltseg+=MinKoltseg(i);
          }
        }
        Console.WriteLine(koltseg);
        
    	}
      
      static long MinKoltseg(long start) {
        long min = long.MaxValue;
        BejarMin(start, ref min);
        return min;
      }
      
      static void BejarMin(long p, ref long min) {
        voltMar[p] = true;
        if(c[p] < min) min=c[p];
        foreach(long n in szomszedok[p]) {
          if(voltMar[n]) continue;
          BejarMin(n, ref min);
        }
      }
      
      
    }