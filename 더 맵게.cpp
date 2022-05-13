#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int i = 0; i < scoville.size(); ++i) {
        pq.push(scoville[i]);
    }

    while(true) {
        if (pq.top() >= K) break;

        int less = pq.top();
        pq.pop();
        if (pq.empty()) return -1;
        int less2 = pq.top();
        pq.pop();
        pq.push(less + less2 * 2);
        answer++;
    }
    
    return answer;
}