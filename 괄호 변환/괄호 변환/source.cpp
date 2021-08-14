#include <string>
#include <vector>

using namespace std;

string solution(string p) {
    string answer = "";
    int balance = 0;

    for (auto Bracket : p) {
        if (Bracket == '(') {
            balance--;
        }
        else {
            balance++;
        }
    }

    return answer;
}