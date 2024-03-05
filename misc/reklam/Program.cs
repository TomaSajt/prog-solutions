var records = File.ReadAllLines("rendel.txt")
    .Select(x => x.Split())
    .Select(x => new { Day = int.Parse(x[0]), City = x[1], Count = int.Parse(x[2]) }).ToList();

int osszes(string city, int day) => records.Where(x => x.City == city && x.Day == day).Sum(x => x.Count);

System.Console.WriteLine("2. feladat:");
System.Console.WriteLine($"A rendelések száma: {records.Count}");

System.Console.WriteLine("3. feladat:");
System.Console.Write("Kérem, adjon meg egy napot: ");
int day = int.Parse(Console.ReadLine()!);
System.Console.WriteLine($"A rendelések száma az adott napon: {records.Count(x => x.Day == day)}");

System.Console.WriteLine("4. feladat:");
var cnt = 30 - records.Where(x => x.City == "NR").DistinctBy(x => x.Day).Count();
if (cnt == 0) System.Console.WriteLine("Minden nap volt rendelés a reklámban nem érintett városból");
else System.Console.WriteLine($"{cnt} nap nem volt a reklámban nem érintett városból rendelés");

System.Console.WriteLine("5. feladat:");
var maxRecord = records.MaxBy(x => x.Count)!;
System.Console.WriteLine($"A legnagyobb darabszám: {maxRecord.Count}, a rendelés napja: {maxRecord.Day}");

System.Console.WriteLine("7. feladat:");
System.Console.WriteLine($"A rendelt termékek darabszáma a 21. napon PL: {osszes("PL", 21)} TV: {osszes("TV", 21)} NR: {osszes("NR", 21)}");

System.Console.WriteLine("8. feladat:");
System.Console.WriteLine("Napok\t1..10\t11..20\t21..30");

foreach (string city in new List<string> { "PL", "TV", "NR" })
{
    Console.Write(city);
    for (int i = 0; i < 3; i++)
    {
        Console.Write($"\t{records.Count(x => x.City == city && x.Day > 10 * i && x.Day <= 10 * (i + 1))}");
    }
    Console.WriteLine();
}
