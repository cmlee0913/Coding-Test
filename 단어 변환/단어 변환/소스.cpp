#include <string>
#include <vector>
#include <stack>
#include <map>
#include <iostream>
#include <queue>
using namespace std;

int dist(int ans, string target_word, map<string, string> pred) {
    int answer = ans;
    if (pred[target_word] == "") return answer;
    else {
        return dist(++answer, pred[target_word], pred);
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
                if (num == 2) temp.push_back(words[j]);
            }
        }
        graph.push_back(temp);
    }

    for (int i = 0; i < graph.size(); ++i) {
        for (auto j : graph[i]) {
            cout << j << " ";
        }
        cout << endl;
    }

    queue<string> s;

    s.push(begin);
    predecessor[begin] = "";

    while (!s.empty()) {
        string curr = s.front();
        predecessor[curr] = curr;
        if (curr == target) return dist(answer, curr, predecessor);
        s.pop();

        visited[curr] = true;

        for (int i = 0; i < graph.size(); ++i) {
            if (graph[i][0] == curr) {
                for (int j = 1; j < graph[i].size(); ++j) {
                    if (!visited[graph[i][j]]) {
                        s.push(graph[i][j]);
                    }
                }
            }
        }
    }
}

int main() {
    cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" });
}