using System;
using System.Collections.Generic;
using System.Linq;


class Program
{
    static void Main(string[] args)
    {
        int len = int.Parse(Console.ReadLine());
        int[] a = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        int[] solutions = new int[len];
        List<int>[] edgesFrom = new List<int>[len];
        for (int i = 0; i < len; i++)
        {
            solutions[i] = -1;
            edgesFrom[i] = new List<int>();
        }
        for (int i = 0; i < len; i++)
        {
            if (i - a[i] >= 0) edgesFrom[i - a[i]].Add(i);
            if (i + a[i] < len) edgesFrom[i + a[i]].Add(i);
        }
        bool[] visited = new bool[len];
        var posQueue = new Queue<int>();
        var distQueue = new Queue<int>();
        for (int i = 0; i < len; i++)
        {
            if (a[i] % 2 == 0)
            {
                visited[i] = true;
                posQueue.Enqueue(i);
                distQueue.Enqueue(0);
            }
        }
        while (posQueue.Count > 0)
        {
            var currPos = posQueue.Dequeue();
            var currDist = distQueue.Dequeue();
            if (solutions[currPos] == -1) solutions[currPos] = currDist == 0 ? -1 : currDist;
            for (int i = 0; i < edgesFrom[currPos].Count; i++)
            {
                if (visited[edgesFrom[currPos][i]]) continue;
                visited[edgesFrom[currPos][i]] = true;
                posQueue.Enqueue(edgesFrom[currPos][i]);
                distQueue.Enqueue(currDist + 1);
            }
        }
        visited = new bool[len];
        for (int i = 0; i < len; i++)
        {
            if (a[i] % 2 == 1)
            {
                visited[i] = true;
                posQueue.Enqueue(i);
                distQueue.Enqueue(0);
            }
        }
        while (posQueue.Count > 0)
        {
            var currPos = posQueue.Dequeue();
            var currDist = distQueue.Dequeue();
            if (solutions[currPos] == -1) solutions[currPos] = currDist == 0 ? -1 : currDist;
            for (int i = 0; i < edgesFrom[currPos].Count; i++)
            {
                if (visited[edgesFrom[currPos][i]]) continue;
                visited[edgesFrom[currPos][i]] = true;
                posQueue.Enqueue(edgesFrom[currPos][i]);
                distQueue.Enqueue(currDist + 1);
            }
        }
        Console.WriteLine(string.Join(' ', solutions));
    }
}