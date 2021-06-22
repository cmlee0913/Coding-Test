#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> a;

    while (n) {
        a.push_back(n % 3);
        n /= 3;
    }

    reverse(a.begin(), a.end());

    for (int i = 0; i < a.size(); i++)
        answer += pow(3, i) * a[i];

    return answer;
}