#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = 0;
    string ans;
    int pos = 0;
    ans.reserve(3000);

    while ((pos = s.find("zero")) != std::string::npos)
        s.replace(s.find("zero"), 4, "0");
    while ((pos = s.find("one")) != std::string::npos)
        s.replace(s.find("one"), 3, "1");
    while ((pos = s.find("two")) != std::string::npos)
        s.replace(s.find("two"), 3, "2");
    while ((pos = s.find("three")) != std::string::npos)
        s.replace(s.find("three"), 5, "3");
    while ((pos = s.find("four")) != std::string::npos)
        s.replace(s.find("four"), 4, "4");
    while ((pos = s.find("five")) != std::string::npos)
        s.replace(s.find("five"), 4, "5");
    while ((pos = s.find("six")) != std::string::npos)
        s.replace(s.find("six"), 3, "6");
    while ((pos = s.find("seven")) != std::string::npos)
        s.replace(s.find("seven"), 5, "7");
    while ((pos = s.find("eight")) != std::string::npos)
        s.replace(s.find("eight"), 5, "8");
    while ((pos = s.find("nine")) != std::string::npos)
        s.replace(s.find("nine"), 4, "9");

    answer = stoi(s);

    return answer;
}