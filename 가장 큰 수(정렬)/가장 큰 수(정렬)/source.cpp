#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool bigger(string a, string b) {
    return a + b > b + a; // 두개를 더해서 큰 수를 리턴
}



string solution(vector<int> numbers) {
    string answer = "";
    vector<string> num_to_str;

    for (int i = 0; i < numbers.size(); i++) {
        num_to_str.push_back(to_string(numbers[i]));
    }

    sort(num_to_str.begin(), num_to_str.end(), bigger);
    if (num_to_str[0] == "0") return "0";

    for (int i = 0; i < num_to_str.size(); i++) 
        answer += num_to_str[i];

    return answer;
}

int main() {
    string s = solution({ 3, 30, 34, 5, 9 });
    cout << s;

    return 0;
}