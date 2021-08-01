// O(n^2)

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());

    for (int i = 0; i < prices.size(); i++) {
        for (int j = i + 1; j < prices.size(); j++) {
            if (prices[i] <= prices[j]) {
                answer[i]++;
            }
            else {
                answer[i]++;
                break;
            }
        }
    }

    return answer;
}

// 스택 O(n)
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer(prices.size());
    stack<int> s;
    int size = prices.size();

    for (int i = 0; i < size; i++)
    {
        // 스텍이 차있으면서 가격이 떨어지기 시작하면
        while (!s.empty() && prices[s.top()] > prices[i])
        {
            answer[s.top()] = i - s.top();
            s.pop();
        }

        // 가격이 올라갈때동안 스텍에 넣음
        s.push(i);
    }

    // 스텍에 남은것들을 계산해줌
    while (!s.empty())
    {
        answer[s.top()] = size - s.top() - 1;
        s.pop();
    }

    return answer;
}