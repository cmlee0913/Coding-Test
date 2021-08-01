#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    string temp[3]{ "4", "1", "2" };
    while (n) {
        answer = temp[n % 3] + answer;
        if (!(n % 3))
            n = n / 3 - 1;
        else
            n = n / 3;
    }
    return answer;
}

#include<iostream>
#include<vector>

using namespace std;

string change124(int no)
{
    string answer = "";
    int a;
    while (no > 0) {
        a = no % 3;
        no = no / 3;
        if (a == 0) {
            no -= 1;
        }
        answer = "412"[a] + answer;
    }

    return answer;
}