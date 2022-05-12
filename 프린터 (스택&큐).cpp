#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <utility>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    priority_queue<int> pq;
    deque<pair<int, int>> dq;
    
    for (int i = 0; i < priorities.size(); ++i) {
        pq.emplace(priorities[i]);
        dq.push_back(make_pair(i, priorities[i]));
    }
    
    while (!pq.empty()) {
        if (dq.front().second == pq.top() && dq.front().first == location) {
            break;
        }
        else if (dq.front().second == pq.top()) {
            dq.pop_front();
            pq.pop();
            answer++;
        }
        else {
            dq.push_back(dq.front());
            dq.pop_front();
        }
    }        
    
    return answer;
}