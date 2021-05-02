#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int crain[board.size() * board[0].size()];
    int i = 0;
    int result = 0;

    for (int k = 0; k < moves.size(); k++) {
        for (int j = 0; j < board.size(); j++) {
            if (board[j][moves[k] - 1] == 0) {

            }
            if (board[j][moves[k] - 1] != 0) {
                crain[i] = board[j][moves[k] - 1];
                board[j][moves[k] - 1] = 0;
                if (i > 0) {
                    if (crain[i] == crain[i - 1]) {
                        crain[i] = NULL;
                        crain[i - 1] = NULL;
                        result = result + 2;
                        i = i - 2;
                    }
                }
                i++;
                j = board.size();
            }
        }
    }
    return result;
}