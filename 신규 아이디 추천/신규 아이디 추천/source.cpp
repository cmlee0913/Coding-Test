#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string new_id) {

    for (int i = 0; i < new_id.length(); i++)
        if (new_id[i] >= 'A' && new_id[i] <= 'Z')
            new_id[i] = tolower(new_id[i]);
 
    for (int i = 0; i < new_id.length(); ) {
        if ((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9')
            || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
        {
            i++;
            continue;
        }

        new_id.erase(new_id.begin() + i);
    }

    for (int i = 1; i < new_id.length(); ) {
        if (new_id[i] == '.' && new_id[i - 1] == '.') {
            new_id.erase(new_id.begin() + i);
            continue;
        }
        else i++;
    }

    for (int i = 1; i < new_id.length(); ) {
        if (new_id[i] == '.' && new_id[i - 1] == '.') {
            new_id.erase(new_id.begin() + i);
            continue;
        }
        else i++;
    }

    if (new_id.front() == '.') new_id.erase(new_id.begin());
    if (new_id.back() == '.') new_id.erase(new_id.end() - 1);

    if (new_id.length() == 0)
        new_id = "a";

    if (new_id.length() >= 16) {
        while (new_id.length() != 15) {
            new_id.erase(new_id.begin() + 15);
        }
    }
    if (new_id.back() == '.') new_id.erase(new_id.end() - 1);

    if (new_id.length() <= 2) {
        while (new_id.length() != 3) {
            new_id += new_id.back();
        }
    }
    return new_id;
}

// 다른 풀이
//#include <bits/stdc++.h>
//using namespace std;
//
//string solution(string new_id) {
//    for (char& ch : new_id) if ('A' <= ch && ch <= 'Z') ch |= 32;
//
//    string ret;
//    for (char& ch : new_id) {
//        if ('a' <= ch && ch <= 'z' ||
//            '0' <= ch && ch <= '9' ||
//            strchr("-_.", ch)) ret += ch;
//    }
//
//    new_id = ret;
//    ret.clear();
//    for (char& ch : new_id) {
//        if (!ret.empty() && ret.back() == '.' && ch == '.') continue;
//        ret += ch;
//    }
//
//    if (ret.front() == '.') ret.erase(ret.begin());
//    if (ret.back() == '.') ret.pop_back();
//
//    if (ret.empty()) ret = "a";
//    if (ret.size() >= 16) ret = ret.substr(0, 15);
//    if (ret.back() == '.') ret.pop_back();
//    while (ret.size() <= 2) ret += ret.back();
//
//    return ret;
//}