#include <string>
#include <vector>
#include <iostream>

using namespace std;

int ten2two(int num) {
    int result = 0;

    while (num > 0) {
        if (num % 2 == 1)
            result++;
        num /= 2;
    }

    return result;
}

int solution(int n) {
    int answer = 0;
    int a = n + 1;
    int n_one = ten2two(n);

    while (1) {
        int next_one = ten2two(++n);

        if (next_one == n_one) {
            return n;
        }
    }
}

int main() {
    cout << solution(78);

    return 0;
}