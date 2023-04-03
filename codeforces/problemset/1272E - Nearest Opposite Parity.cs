using System;
using System.Collections.Generic;
using System.Linq;


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
int[] dist = new int[len];
var posQueue = new Queue<int>();
for (int i = 0; i < len; i++)
{
    if (a[i] % 2 == 0)
    {
        visited[i] = true;
        posQueue.Enqueue(i);
        dist[i] = 0;
    }
}
while (posQueue.Count > 0)
{
    var currPos = posQueue.Dequeue();
    if (solutions[currPos] == -1) solutions[currPos] = a[currPos] % 2 == 0 ? -1 : dist[currPos];
    for (int i = 0; i < edgesFrom[currPos].Count; i++)
    {
        var nei = edgesFrom[currPos][i];
        if (visited[nei]) continue;
        visited[nei] = true;
        posQueue.Enqueue(nei);
        dist[nei] = dist[currPos] + 1;
    }
}
visited = new bool[len];
dist = new int[len];
for (int i = 0; i < len; i++)
{
    if (a[i] % 2 == 1)
    {
        visited[i] = true;
        posQueue.Enqueue(i);
        dist[i] = 0;
    }
}
while (posQueue.Count > 0)
{
    var currPos = posQueue.Dequeue();
    if (solutions[currPos] == -1) solutions[currPos] = a[currPos] % 2 == 1 ? -1 : dist[currPos];
    for (int i = 0; i < edgesFrom[currPos].Count; i++)
    {
        var nei = edgesFrom[currPos][i];
        if (visited[nei]) continue;
        visited[nei] = true;
        posQueue.Enqueue(nei);
        dist[nei] = dist[currPos] + 1;
    }
}
Console.WriteLine(string.Join(' ', solutions));