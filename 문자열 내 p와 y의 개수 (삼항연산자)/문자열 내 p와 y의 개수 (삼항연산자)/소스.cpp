#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int p, y = 0;

    for (int i = 0; i < s.size(); i++) {
        s[i] == 'p' ? p++ : p = p;
        s[i] == 'P' ? p++ : p = p;
        s[i] == 'y' ? y++ : y = y;
        s[i] == 'Y' ? y++ : y = y;
    }

    answer = (p == y) ? true : false;

    return answer;
}