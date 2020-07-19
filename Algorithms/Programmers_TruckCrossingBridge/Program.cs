using System;
using System.Collections.Generic;
using System.Linq;

namespace Programmers_TruckCrossingBridge
{
    class Program
    {
        public static int solution(int bridge_length, int weight, int[] truck_weights)
        {
            Queue<int> truckWaiting = new Queue<int>();
            Queue<int> truckCrossing = new Queue<int>();
            Queue<int> truckCrossed = new Queue<int>();
            Dictionary<int, int> timer = new Dictionary<int, int>();
            int crossingTruckSum = 0;
            int answer = 0;

            foreach (var truck in truck_weights)
            {
                truckWaiting.Enqueue(truck);
            }

            timer.Add(truckWaiting.Peek(), 1);
            truckCrossing.Enqueue(truckWaiting.Dequeue());
            answer++;

            while (true)
            {
                if (truckCrossing.Count == 0)
                {
                    break;
                }

                if (timer[truckCrossing.Peek()] == bridge_length)
                {
                    truckCrossed.Enqueue(truckCrossing.Dequeue());
                }

                foreach (var truck in truckCrossing)
                {
                    crossingTruckSum += truck;
                }

                int peekResult;
                if (truckWaiting.TryPeek(out peekResult))
                {
                    if (crossingTruckSum + peekResult <= weight)
                    {
                        timer.Add(truckWaiting.Peek(), 0);
                        truckCrossing.Enqueue(truckWaiting.Dequeue());

                    }
                    crossingTruckSum = 0;
                }

                foreach (var truck in timer.ToList())
                {
                    timer[truck.Key]++;
                }
                answer++;
            }

            return answer;
        }
        static void Main(string[] args)
        {
            int[] a = new int[] { 7, 4, 5, 6};
            Console.WriteLine(solution(2,10,a));
            a = new int[] { 10 };
            Console.WriteLine(solution(100, 100, a));
            a = new int[] { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
            Console.WriteLine(solution(100, 100, a));
        }
    }
}
