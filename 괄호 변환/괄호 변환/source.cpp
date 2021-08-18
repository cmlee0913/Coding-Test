#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool isBalance(string s) {
    int balance = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            balance--;
        }
        else {
            balance++;
        }
        if (balance == 0) {
            return true;
        }
        else if (balance > 0) {
            return false;
        }
    }
}

string balanceBracket(string s) {
    if (s == "") return s;
    int balance = 0;
    string u;
    string v;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            balance--;
        }
        else {
            balance++;
        }
        if (balance == 0) {
            u = s.substr(0, i + 1);
            v = s.substr(i + 1);
            break;
        }
    }

    if (isBalance(u)) {
        return u + balanceBracket(v);
    }

    else if (!isBalance(u)) {
        string str;
        str = "(" + balanceBracket(v) + ")";
        u = u.substr(1, u.length() - 2);
        for (int i = 0; i < u.size(); i++) {
            if (u[i] == '(') 
                str += ')';
            else 
                str += '(';
        }
        return str;
    }
}

string solution(string p) {
    return balanceBracket(p);
}

int main() {
    cout << solution("()))((()");

    return 0;
}