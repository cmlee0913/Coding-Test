#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, -1));
    
    for (auto a : puddles) {dp[a[1]][a[0]] = 0;}
    
    for (long long i = 1; i < dp.size(); ++i) {
        for (long long j = 1; j < dp[0].size(); ++j) {
            if (dp[i][j] == 0) {continue;}
            if (i == 1 && j == 1) {dp[i][j] = 1;}
            else {
                if (i - 1 == 0) dp[i][j] = dp[i][j-1];
                else if (j - 1 == 0) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
            dp[i][j] = dp[i][j] % 1000000007;
        }
    }
    
    return dp[n][m];
}