using System;
using System.Collections.Generic;
using System.Text;

namespace Cover_it_
{
    class Program
    {
        static StringBuilder sb = new StringBuilder();
        static List<int>[] neighbours;
        static List<int> odds = new List<int>();
        static List<int> evens = new List<int>();
        static void Main(string[] args)
        {
            var t = int.Parse(Console.ReadLine());
            for (int k = 0; k < t; k++)
            {
                var sLine = Console.ReadLine().Split(' ');
                var n = int.Parse(sLine[0]);
                var m = int.Parse(sLine[1]);
                neighbours = new List<int>[n];
                for (int i = 0; i < n; i++) neighbours[i] = new List<int>();
                for (int i = 0; i < m; i++)
                {
                    var sLine2 = Console.ReadLine().Split(' ');
                    var s = int.Parse(sLine2[0]) - 1;
                    var e = int.Parse(sLine2[1]) - 1;
                    neighbours[s].Add(e);
                    neighbours[e].Add(s);
                }
                odds.Clear();
                evens.Clear();
                var visited = new bool[n];
                var oddDistance = new bool[n];
                var queue = new Queue<int>();
                oddDistance[0] = false;
                visited[0] = true;
                queue.Enqueue(0);
                while (queue.Count != 0)
                {
                    var currVert = queue.Dequeue();
                    if (oddDistance[currVert]) odds.Add(currVert + 1);
                    else evens.Add(currVert + 1);

                    for (int i = 0; i < neighbours[currVert].Count; i++)
                    {
                        if (visited[neighbours[currVert][i]]) continue;
                        visited[neighbours[currVert][i]] = true;
                        oddDistance[neighbours[currVert][i]] = !oddDistance[currVert];
                        queue.Enqueue(neighbours[currVert][i]);
                    }
                }
                if (odds.Count < evens.Count)
                {
                    sb.AppendLine(odds.Count.ToString());
                    sb.AppendLine(string.Join(' ', odds));
                }
                else
                {
                    sb.AppendLine(evens.Count.ToString());
                    sb.AppendLine(string.Join(' ', evens));
                }
            }

            Console.Write(sb);
        }
    }
}