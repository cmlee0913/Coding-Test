#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    string watermelon;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            watermelon = "¼ö";
        }
        else if (i % 2 == 1) {
            watermelon = "¹Ú";
        }
        answer += watermelon;
    }
    return answer;
}