#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    int k = 0;
    for (int i = left; i <= right; i++) {
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) {
                k++;
            }
        }
        if (k % 2 == 0) {
            answer = answer + i;
        }
        else if (k % 2 == 1) {
            answer = answer - i;
        }
        k = 0;
    }


    return answer;
}