#include <string>
#include <vector>

using namespace std;
int student[35];
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    for (int i : reserve) student[i] += 1;
    for (int i : lost) student[i] += -1;
    for (int i = 1; i <= n; i++) {
        if (student[i] == -1) {
            if (student[i - 1] == 1)
                student[i - 1] = student[i] = 0;
            else if (student[i + 1] == 1)
                student[i] = student[i + 1] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
        if (student[i] != -1) answer++;

    return answer;
}

// 다른 풀이
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();

    for (int i = 0; i < lost.size(); i++) {
        for (int j = 0; j < reserve.size(); j++) {
            if (reserve[j] == lost[i]) {
                lost.erase(lost.begin() + (i--));
                reserve.erase(reserve.begin() + (j--));
                answer++;
                break;
            }
            else if (reserve[j] - 1 == lost[i]) {
                lost.erase(lost.begin() + (i--));
                reserve.erase(reserve.begin() + (j--));
                answer++;
                break;
            }
            else if (reserve[j] + 1 == lost[i]) {
                lost.erase(lost.begin() + (i--));
                reserve.erase(reserve.begin() + (j--));
                answer++;
                break;
            }

        }
    }


    return answer;
}