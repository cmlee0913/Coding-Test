#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    
    for (int i = 0; i < 10; i++) {
        if(!any_of(numbers.begin(), numbers.end(), [&](int a) { return a == i; }))
          answer += i;  
    }
    return answer;
}