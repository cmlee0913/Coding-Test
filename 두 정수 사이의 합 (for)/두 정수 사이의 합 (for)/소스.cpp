#include <string>
#include <vector>

using namespace std;

long long solution(int A, int B) {
    long long answer = 0;
    int a = A < B ? A : B;
    int b = A < B ? B : A;
    for (int i = a; i <= b; i++)
        answer += i;
    return answer;
}