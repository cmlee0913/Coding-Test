///프로그래머스 스택/큐 다리를 지나는 트럭

using System;
using System.Collections.Generic;

public class Solution
{
    public int solution(int bridge_length, int weight, int[] truck_weights)
    {
        int answer = 0;
        int truckCount = 0;
        int allweight = 0;
        int time = 0;
        
        Queue<int> q = new Queue<int>();
        
        while(true)
        {
            //트럭 카운트와 받아온 배열의 길이가 같으면 반복문 탈출
            if (truckCount == truck_weights.Length) break;
            
            //큐 카운트와 다리의 길이가 같으면 총 무게에서 큐 제거
            //즉, 다리를 건넜다는 뜻
            if (q.Count == bridge_length) allweight -= q.Dequeue();
            
            //총 무게 + 현재 트럭의 무게가 제한 무게 보다 작거나 같을 시
            //즉, 트럭을 더 다리에 올릴 수 있을 시
            if (allweight + truck_weights[truckCount] <= weight)
            {
                //총 무게 + 현재 트럭의 무게
                //큐 데이터 삽입
                //트럭 카운트 더하기
                allweight += truck_weights[truckCount];
                q.Enqueue(truck_weights[truckCount]);
                truckCount++;
            }
            //트럭을 다리에 올릴 수 없을 시, 기존 트럭만 이동
            else {
                q.Enqueue(0);
            }
            //시간 초 더하기
            time++;
        }
        //위 반복문을 탈출하기 전까지 time은 마지막 트럭의 탑승 시각
        //마지막 트럭의 탈출 시간 = 마지막 트럭의 탑승 시각 + 다리 길이
        answer = time + bridge_length;
        return answer;
    }
}