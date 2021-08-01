#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_map<string, int> phone_b;

    for (int i = 0; i < phone_book.size(); i++) {
        phone_b[phone_book[i]] = 1;
    }

    for (int i = 0; i < phone_book.size(); i++) {
        string num = "";
        for (int j = 0; j < phone_book[i].size(); j++) {
            num += phone_book[i][j];
            if (phone_b[num] && num != phone_book[i])
                return false;
        }
    }

    return true;
}

int main() {

    printf("%d", solution({"119", "97674223", "1195524421"}));

    return 0;
}

// 다른 풀이
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool solution(vector<string> phoneBook) {
    bool answer = true;

    sort(phoneBook.begin(), phoneBook.end());

    for (int i = 0; i < phoneBook.size() - 1; i++)
    {
        if (phoneBook[i] == phoneBook[i + 1].substr(0, phoneBook[i].size()))
        {
            answer = false;
            break;
        }
    }

    return answer;
}