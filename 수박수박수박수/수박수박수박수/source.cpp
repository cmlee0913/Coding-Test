#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    string watermelon;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            watermelon = "��";
        }
        else if (i % 2 == 1) {
            watermelon = "��";
        }
        answer += watermelon;
    }
    return answer;
}