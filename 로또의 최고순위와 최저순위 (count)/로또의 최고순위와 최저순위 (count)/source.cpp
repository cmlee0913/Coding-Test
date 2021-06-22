#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int zero = count(lottos.begin(), lottos.end(), 0);
    answer.push_back(7);
    answer.push_back(7);

    for (int i = 0; i < lottos.size(); i++) {
        int a = count(win_nums.begin(), win_nums.end(), lottos[i]);
        answer[0] = answer[0] - a;
        answer[1] = answer[1] - a;
    }

    answer[0] = answer[0] - zero;

    if (answer[1] == 7)
        answer[1] = 6;
    if (answer[0] == 7)
        answer[0] = 6;

    return answer;
}

// �ٸ� Ǯ��
//#include <string>
//#include <vector>
//
//using namespace std;
//
///*
//0�� ������ ���� ����� �޶���
//
//(1) 0 : 1��
//    5�� ��ġ : 1, 2
//    4�� ��ġ : 2, 3
//    3�� ��ġ : 3, 4
//    2�� ��ġ : 4, 5
//    1�� ��ġ : 5, 6
//    0�� ��ġ : 6, 6
//
//(2) 0 : 2��
//    4�� ��ġ : 1, 3
//    3�� ��ġ : 2, 4
//    2�� ��ġ : 3, 5
//    1�� ��ġ : 4, 6
//    0�� ��ġ : 5, 6
//
//(3) 0 : 3��
//    3�� ��ġ : 1, 4
//    2�� ��ġ : 2, 5
//    1�� ��ġ : 3, 6
//    0�� ��ġ : 4, 6
//
//(4) 0 : 4��
//    2�� ��ġ : 1, 5
//    1�� ��ġ : 2, 6
//    0�� ��ġ : 3, 6
//
//(5) 0 : 5��
//    1�� ��ġ : 1, 6
//    0�� ��ġ : 2, 6
//
//(6) 0 : 6��
//    0�� ��ġ : 1, 6
//
//(7) 0 : ����
//    �ܼ� �񱳸� �ϸ��, �ְ� ���� = ��������
//
//*/
//
//int func(int n) {
//    if (n == 6) return 1;
//    else if (n == 5) return 2;
//    else if (n == 4) return 3;
//    else if (n == 3) return 4;
//    else if (n == 2) return 5;
//    else return 6;
//}
//
//vector<int> solution(vector<int> lottos, vector<int> win_nums) {
//    vector<int> answer;
//
//    // 0�� ������ ��� ����
//    int zero = 0;
//    for (int i = 0; i < lottos.size(); i++) {
//        if (lottos[i] == 0) zero++;
//    }
//
//    // lottos�� win_nums���� ��ġ�ϴ� ��ȣ ������ ��� ����
//    int check = 0;
//    int visited[6] = { 0, };
//    for (int i = 0; i < lottos.size(); i++) {
//        for (int j = 0; j < win_nums.size(); j++) {
//            if (visited[i] == 0 && lottos[i] == win_nums[j]) {
//                visited[i] = 1;
//                check++;
//            }
//        }
//    }
//
//    answer.push_back(func(zero + check));
//    answer.push_back(func(check));
//    return answer;
//}