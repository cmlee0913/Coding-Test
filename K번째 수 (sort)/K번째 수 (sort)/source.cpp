#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int i = 0; i < commands.size(); i++) {
        vector<int> s;
        for (int j = commands[i][0]; j <= commands[i][1]; j++) {
            s.push_back(array[j - 1]);
        }
        sort(s.begin(), s.end());
        answer.push_back(s[commands[i][2] - 1]);
    }
    return answer;
}