#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    string token = "";
    vector<int> v;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            v.push_back(atoi(token.c_str()));
            token.clear();
        }

        else {
            token += s[i];
        }
    }
    v.push_back(atoi(token.c_str()));
    sort(v.begin(), v.end());

    answer += to_string(v[0]) + " " + to_string(v[v.size() - 1]);

    return answer;
}