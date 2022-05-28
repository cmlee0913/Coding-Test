#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int dist(int& ans, string target_word, map<string, string> pred) {
    if (pred[target_word] == "") return ans;
    else {
        ans++;
        dist(ans, pred[target_word], pred);
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    vector<vector<string>> graph;
    map<string, bool> visited;
    map<string, string> predecessor;
    words.push_back(begin);
    
    for (int i = 0; i < words.size(); ++i) {
        visited[words[i]] = false;
    }
    
    for (int i = 0; i < words.size(); ++i) {
        vector<string> temp(1, words[i]);
        for (int j = 0; j < words.size(); ++j) {
            if (temp[0] == words[j]) continue;
            else {
                int num = 0;
                for (int k = 0; k < words[j].size(); k++) {
                    if (temp[0][k] == words[j][k]) num++;
                }
                if (num == 1) temp.push_back(words[j]);
            }
        }
        graph.push_back(temp);
    }
    
    queue<string> q;
    
    q.push(begin);
    predecessor[begin] = "";
    
    while(!q.empty()) {
        string curr = q.front();
        if (curr == target) dist(answer, curr, predecessor);
        q.pop();
        
        visited[curr] = true;
        
        for (int i = 0; i < graph.size(); ++i) {
            if (graph[i][0] == curr) {
                for (int j = 1; j < graph[i].size(); ++j) {
                    if (!visited[graph[i][j]]) {
                        q.push(graph[i][j]);
                        predecessor[graph[i][j]] = curr;
                    }
                }
            }
        }
    }
    
    return answer;
}