#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> m;

    for (vector<string> c : clothes) {
        m[c[1]]++;
    }

    unordered_map<string, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        answer *= it->second + 1;
    }

    return answer - 1;
}



// 다른 풀이

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    unordered_map <string, int> attributes;
    for (int i = 0; i < clothes.size(); i++)
        attributes[clothes[i][1]]++;
    for (auto it = attributes.begin(); it != attributes.end(); it++)
        answer *= (it->second + 1);
    answer--;

    return answer;
}