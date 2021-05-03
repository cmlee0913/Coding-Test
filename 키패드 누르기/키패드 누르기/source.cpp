#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    vector<vector<int>> pad = { {1,2,3},{4,5,6},{7,8,9},{10,11,12} };
    string answer = "";

    int lNow = 10;
    int rNow = 12;

    int x = 1;
    int y = 1;

    int lDist = 0;
    int rDist = 0;

    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer.push_back('L');
            lNow = numbers[i];
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer.push_back('R');
            rNow = numbers[i];
        }

        else if (numbers[i] == 2 || numbers[i] == 5 || numbers[i] == 8 || numbers[i] == 0) {

            if (numbers[i] == 0) {
                numbers[i] = 11;
            }

            int l = abs(numbers[i] - lNow);
            int r = abs(numbers[i] - rNow);

            lDist = (l / 3 + l % 3);
            rDist = (r / 3 + r % 3);

            if (rDist > lDist) {

                answer.push_back('L');
                lNow = numbers[i];
            }
            else if (rDist < lDist) {
                answer.push_back('R');
                rNow = numbers[i];
            }
            else if (rDist == lDist) {
                if (hand == "right") {
                    answer.push_back('R');
                    rNow = numbers[i];
                }
                else if (hand == "left") {
                    answer.push_back('L');
                    lNow = numbers[i];
                }
            }
        }
    }


    return answer;
}
