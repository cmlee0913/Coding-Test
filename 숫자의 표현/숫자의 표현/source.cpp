#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int temp = 0;
    int pivot = 0;

    for (int i = 1; i <= n; i++) {
        temp += i;
        if (temp == n) {
            temp = 0; answer++; pivot++; i = pivot;
        }
        else if (temp > n) {
            temp = 0; pivot++; i = pivot;
        }
    }

    return answer;
}