#include <string>
#include <vector>
#include <iostream>
using namespace std;

string replace_all(
    __in const std::string& message,
    __in const std::string& pattern,
    __in const std::string& replace
) {
    std::string result = message;
    std::string::size_type pos = 0;
    std::string::size_type offset = 0;
    while ((pos = result.find(pattern, offset)) != std::string::npos)
    {
        result.replace(result.begin() + pos, result.begin() + pos + pattern.size(), replace);
        offset = pos + replace.size();
    }
    return result;
}

int solution(string s) {
    string ss = s;
    
    ss = replace_all(ss, "zero", "0");
    ss = replace_all(ss, "one", "1");
    ss = replace_all(ss, "two", "2");
    ss = replace_all(ss, "three", "3");
    ss = replace_all(ss, "four", "4");
    ss = replace_all(ss, "five", "5");
    ss = replace_all(ss, "six", "6");
    ss = replace_all(ss, "seven", "7");
    ss = replace_all(ss, "eight", "8");
    ss = replace_all(ss, "nine", "9");

    return stoi(ss);
}

int main() {
    int a = solution("one4seveneight");
    cout << a;

    return 0;
}