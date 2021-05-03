#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    string s = to_string(x);
    int a = 0;

    for (int i = 0; i < s.size(); i++) {
        a += s[i] - '0'; // -49
    }

    if (x % a == 0) {
        answer = true;
    }
    else {
        answer = false;
    }
    return answer;
}

// a += x%10;
// x /= 10;   단순 계산시