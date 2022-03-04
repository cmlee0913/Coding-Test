using System;

class Solution
{
    public long solution(int price, int money, int count)
    {
        long answer = money;
        
        for (int i = 1; i <= count; ++i) {
            long nowPrice = price * i;
            answer -= nowPrice;
        }
        
        return answer <= 0 ? -answer : 0;
    }
}