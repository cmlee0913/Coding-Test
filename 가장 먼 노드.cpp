#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> v(n+1, vector<int>(0));
    queue<int> q;
    vector<int> dist(n+1, 0);
    
    for (int i = 0; i < edge.size(); ++i) {v[edge[i][0]].push_back(edge[i][1]);}
    
    bool visited[20001];
    q.push(1);
    dist[1] = 0;
    
    while(!q.empty()) {
        int temp = q.front();
        q.pop();
            
        visited[temp] = true;
        
        for (int i = 0; i < v[temp].size(); ++i) {
            if (!visited[v[temp][i]]) {
                q.push(v[temp][i]);
                dist[v[temp][i]] = dist[temp] + 1;
            }
        }
    }
    
    int maximum = *max_element(dist.begin(), dist.end());
    for (auto a : dist) {
        if (a == maximum) answer++;
    }
    return answer;
}

int main() {
    solution(6, {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}});
}