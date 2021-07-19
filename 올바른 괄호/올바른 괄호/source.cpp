#include <string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int n = 0;

    for (char a : s) {
        if (a == '(') {
            n++;
        }
        else {
            n--;
        }
        if (n < 0) {
            return false;
        }
    }
    if (n == 0) {
        return true;
    }
    else {
        return false;
    }
}