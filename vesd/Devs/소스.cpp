#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> quest) {
    int answer = 0;
    int exp = 0;
    bool checked[10] = {false};


    for (int i = 0; i < quest.size(); ++i) {
        if (quest[i][0] <= exp && !checked[i]) {
            checked[i] = true;
            exp += quest[i][1];
            answer++;
            i = -1;
        }
    }

    return answer;
}

int main() {
    cout << solution({ {7, 4},{2, 4},{13, 5},{0, 3},{14, 10} }) << endl;

    return 0;
}


//////


#include <string>
#include <vector>

using namespace std;

int search(int x, int y, vector<vector<int>> field, int farmSize) {
    int rock_num = 0;

    for (int i = 0; i < farmSize; ++i) {
        for (int j = 0; j < farmSize; ++j) {
            if (field[y + i][x + j] == 2) return -1;
            if (field[y + i][x + j] == 1) rock_num++;
        }
    }

    return rock_num;
}

int solution(vector<vector<int>> field, int farmSize) {
    int answer = -1;

    for (int i = 0; i <= field[0].size() - farmSize; ++i) {
        for (int j = 0; j <= field.size() - farmSize; ++j) {
            int rock_num = search(i, j, field, farmSize);

            if (answer == -1 && -1 < rock_num)
                answer = rock_num;
            else if (answer != -1 && rock_num < answer && rock_num != -1)
                answer = rock_num;
        }
    }

    return answer;
}