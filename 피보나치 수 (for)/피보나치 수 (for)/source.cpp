// 시간 초과
#include <string>
#include <vector>

using namespace std;

int fibo(int num) {
    if (num == 0) return 0;
    else if (num == 1) return 1;
    return fibo(num - 2) + fibo(num - 1);
}

int solution(int n) {
    return fibo(n) % 1234567;
}

// for 문 사용
#include <string>
#include <vector>

using namespace std;

int fibo(int num) {
    if (num == 1 || num == 2) return 1;
    int temp = 0;
    int a = 1;
    int b = 1;

    for (int i = 3; i <= num; i++) {
        temp = (a + b) % 1234567;
        a = b;
        b = temp;
    }

    return temp;
}

int solution(int n) {
    return fibo(n);
}