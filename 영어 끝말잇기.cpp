#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    for (int i = 1; i < words.size(); i++) {
        int number = (i % n) + 1;
        int turn = (i / n) + 1;
        int word_count = count(words.begin(), words.begin() + i, words[i]);
        
        if (word_count > 0 || (words[i][0] != words[i-1][words[i - 1].size() - 1])) {
            answer.push_back(number);
            answer.push_back(turn);
            return answer;
        }
    }

    answer.push_back(0);
    answer.push_back(0);
    
    return answer;
}