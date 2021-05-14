#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";

    answer = s;

    for (int i = 0; i < answer.size(); i++) {
        if (answer[i] == ' ') {
            continue;
        }
        else {
            if (('A' <= answer[i] && answer[i] <= 'Z')) {
                answer[i] += n;
                if (answer[i] > 'Z')
                    answer[i] -= 26;
            }
            else if (('a' <= answer[i] && answer[i] <= 'z')) {
                answer[i] += n;
                if (answer[i] > 'z')
                    answer[i] -= 26;
                else if (answer[i] < 0) {
                    answer[i] -= 26;
                }
            }
        }
    }

    return answer;
}