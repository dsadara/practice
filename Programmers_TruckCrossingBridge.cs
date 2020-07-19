using System;
using System.Collections.Generic;

public class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        Queue<int> truckWaiting = new Queue<int>();
        Queue<int> truckCrossing = new Queue<int>();
        Queue<int> truckCrossed = new Queue<int>();
        Dictionary<int, int> timer = new Dictionary<int, int>();
        int crossingTruckSum = 0; 
        int answer = 0;
        
        foreach(var truck in truck_weights)
        {
            truckWaiting.Enqueue(truck);
        }
        
        timer.Add(truckWaiting.Peek(), 0);
        truckCrossing.Enqueue(truckWaiting.Dequeue());
        answer++;
        
        while(true)
        {
            if(truckCrossing.Count == 0)
            {
                break; 
            }
            
            foreach(var truck in truckCrossing)
            {
                crossingTruckSum += truck;
            }
            
            if(crossingTruckSum + truckWaiting.Peek() <= weight)
            {
                timer.Add(truckWaiting.Peek(), 0);
                truckCrossing.Enqueue(truckWaiting.Dequeue());
                crossingTruckSum = 0; 
            }
            
            if(timer[truckCrossing.Peek()]  == bridge_length )
            {
                truckCrossed.Enqueue(truckCrossing.Dequeue());
            }
            answer++;
        }
        
        return answer;
    }
}
