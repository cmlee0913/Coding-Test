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

// ���� O(n)
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
        // ������ �������鼭 ������ �������� �����ϸ�
        while (!s.empty() && prices[s.top()] > prices[i])
        {
            answer[s.top()] = i - s.top();
            s.pop();
        }

        // ������ �ö󰥶����� ���ؿ� ����
        s.push(i);
    }

    // ���ؿ� �����͵��� �������
    while (!s.empty())
    {
        answer[s.top()] = size - s.top() - 1;
        s.pop();
    }

    return answer;
}