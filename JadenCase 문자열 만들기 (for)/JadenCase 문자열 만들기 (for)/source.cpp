#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            answer += s[i];
            continue;
        }
        else {
            // 공백 이후 첫문자 or 맨 첫문자
            if (s[i - 1] == ' ' || i == 0) {
                // 첫문자가 소문자인 경우 -> 대문자
                if ('a' <= s[i] && s[i] <= 'z') {
                    s[i] = s[i] - 'a' + 'A';
                }
            }
            // 이어지는 문자가 대문자인 경우 -> 소문자
            else {
                if ('A' <= s[i] && s[i] <= 'Z') {
                    s[i] = s[i] - 'A' + 'a';
                }
            }
        }
        answer += s[i];
    }

    return answer;
}

// 다른 풀이
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    answer += toupper(s[0]);
    for (int i = 1; i < s.size(); i++) {
        s[i - 1] == ' ' ? answer += toupper(s[i]) : answer += tolower(s[i]);
    }

    return answer;
}