#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<int> fibonacci(int n) {
    vector<int> fibo_for_1 = { 0 };
    if (n == 1) return fibo_for_1;

    vector<int> fibo{ 2, 0 };
    fibo[0] = 0;
    fibo[1] = 1;

    for (int i = 2; i < n; ++i) {
        int a = fibo[i - 1] + fibo[i - 2];
        fibo.push_back(a);
    }

    return fibo;
}

int maxIndex(int steps, int badIndex) {
    int answer = 0;

    for (int i = 1; i <= steps; ++i) {
        answer += i;
        if (answer == badIndex) answer--;
    }

    return answer;
}

string isPangram(vector<string> pangram) {
    string answer = "";

    for (int i = 0; i < pangram.size(); ++i) {
        string alphabt = "abcdefghijklmnopqrstuvwxyz";
        for (int j = 0; j < pangram[i].size(); ++j) {
            alphabt.erase(remove(alphabt.begin(), alphabt.end(), pangram[i][j]), alphabt.end());
        }
        if (alphabt == "") answer += '1';
        else answer += '0';
    }

    return answer;
}
