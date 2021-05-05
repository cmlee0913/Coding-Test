#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int min = 1000;

    if (arr.size() > 1) {
        for (int i = 0; i < arr.size(); i++) {
            if (min > arr[i]) {
                min = arr[i];
            }
        }
        for (int j = 0; j < arr.size(); j++) {
            if (arr[j] != min) {
                answer.push_back(arr[j]);
            }
        }
    }

    else if (arr.size() == 1) {
        answer.push_back(-1);
    }

    return answer;
}