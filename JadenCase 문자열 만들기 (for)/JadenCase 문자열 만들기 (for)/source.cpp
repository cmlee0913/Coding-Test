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
            // ���� ���� ù���� or �� ù����
            if (s[i - 1] == ' ' || i == 0) {
                // ù���ڰ� �ҹ����� ��� -> �빮��
                if ('a' <= s[i] && s[i] <= 'z') {
                    s[i] = s[i] - 'a' + 'A';
                }
            }
            // �̾����� ���ڰ� �빮���� ��� -> �ҹ���
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

// �ٸ� Ǯ��
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