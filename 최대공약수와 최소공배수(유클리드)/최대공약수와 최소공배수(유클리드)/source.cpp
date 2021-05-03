#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int a = n;
    int b = m;

    int min;
    int max;

    int r;

    while (m != 0) {
        r = n % m;
        n = m;
        m = r;
    }

    max = n;
    min = (a * b) / max;

    answer.push_back(max);
    answer.push_back(min);

    return answer;
}