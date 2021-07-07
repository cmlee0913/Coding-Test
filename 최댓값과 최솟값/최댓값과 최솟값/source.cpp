#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> v;

    for (int i = 0; i < s.size(); i++) {
        string token = "";
        if (i == 0) {
            if (s[i] == '-') {
                token += s[i];
                token += s[i + 1];
            }
            else {
                token += s[i];
            }
        }
        if (s[i] == ' ') {
            if (i > 0) {
                if (s[i + 1] == '-') {
                    token += s[i + 1];
                    token += s[i + 2];
                }
                else {
                    token += s[i + 1];
                }
            }
        }
        v.push_back(stoi(token));
    }
    sort(v.begin(), v.end());

    answer += to_string(v[0]);
    answer += to_string(v[v.size() - 1]);

    return answer;
}

int main() {
    cout << solution("1 2 3 4");

    return 0;
}