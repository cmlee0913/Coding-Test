#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = s;
    char blink = ' ';
    int ch = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            ch = 0;
            continue;
        }
        if (ch % 2 == 0) {
            if (96 < answer[i] && answer[i] < 123)
                answer[i] -= ' ';
        }
        else if (ch % 2 == 1) {
            if (64 < answer[i] && answer[i] < 91)
                answer[i] += ' ';
        }
        ch++;
    }

    return answer;
}