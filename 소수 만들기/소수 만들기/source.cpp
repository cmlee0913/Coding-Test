#include <vector>
#include <iostream>
using namespace std;

bool isPrime(int num) {
    if (num == 0 || num == 1) return false;
    for (int s = 2; s < num / 2; s++)
        if ((num % s) == 0) return false;
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;

    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                int num = nums[i] + nums[j] + nums[k];
                if (isPrime(num) == true) answer++;
            }
        }
    }


    return answer;
}