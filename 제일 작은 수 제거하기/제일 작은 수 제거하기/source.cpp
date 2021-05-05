#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int min;

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > arr[i - 1]) {
            min = arr[i - 1];
        }
        else if (arr[i] < arr[i - 1]) {
            min = arr[i];
        }
        else {
            min = arr[i];
        }
    }



    return answer;
}