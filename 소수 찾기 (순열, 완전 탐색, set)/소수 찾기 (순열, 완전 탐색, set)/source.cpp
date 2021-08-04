#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool sosu(int num) {
    if (num < 2) return false;
    int a = (int)sqrt(num);
    for (int i = 2; i <= a; i++) if (num % i == 0) return false;
    return true;
}

int solution(string numbers) {
    unordered_set<int> a;
    int temp = 0;

    sort(numbers.begin(), numbers.end());

    do {
        for (int i = 1; i <= numbers.size(); i++) {
            temp = stoi(numbers.substr(0, i));
            if (sosu(temp))
                a.insert(temp);
        }

    } while (next_permutation(numbers.begin(), numbers.end()));

    return a.size();
}