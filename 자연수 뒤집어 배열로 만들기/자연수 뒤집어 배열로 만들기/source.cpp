#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    string s;

    s = to_string(n);

    reverse(begin(s), end(s));

    for (int i = 0; i < s.size(); i++) 
        answer.push_back(s[i] - '0');

    return answer;
}