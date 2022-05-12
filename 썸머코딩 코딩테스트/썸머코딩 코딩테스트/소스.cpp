//#include <string>
//#include <vector>
//
//using namespace std;
//
//int solution(vector<vector<int>> atmos) {
//    int answer = 0;
//    int stack = 0;
//    for (auto a : atmos) {
//        if (stack > 0) stack++;
//
//        if (a[0] >= 81 || a[1] >= 36) {
//            if (a[0] >= 151 && a[1] >= 76) {
//                if (stack == 0) {
//                    answer++;
//                    continue;
//                }
//                else {
//                    stack = 0;
//                    continue;
//                }
//            }
//            if (stack == 0) {
//                stack++;
//                answer++;
//            }
//        }
//
//        if (stack == 3) {
//            stack = 0;
//        }
//    }
//
//    return answer;
//}
//
//int main() {
//    solution({ {80, 35},{70, 38},{100, 41},{75,30},{160,80},{77, 29},{181, 68},{151, 76} });
//}

//XX사 직원들이 근무하는 빌딩은 업무를 위한 사무실이 여러층에 걸쳐 나누어져 있습니다.모든 사무실은 호수로 구분하며, 사무실마다 직원들을 위한 자리가 마련되어 있습니다.XX사의 모든 직원은 각자 지정된 자리를 하나 이상 사용하며, 현재 주인이 없는 빈자리는 없다고 합니다.단, 한 사람이 한 사무실에서 지정된 자리를 두 개 이상 사용하지는 않습니다.
//
//오늘, 사무실 중 한 곳에 새 책상을 들여놓으면서 주인 없는 빈자리가 하나 생겼습니다.이 자리를 기존 직원 중 한 사람에게 다음 규칙에 따라 주려 합니다.
//
//해당 방에 이미 지정 자리가 있는 직원은 제외합니다.
//지정 자리가 제일 적은 직원의 우선순위가 가장 높습니다.
//지정 자리의 개수가 동일한 사람들끼리는 새 자리가 생긴 방에서 가장 가까운 방에 지정 자리가 있는 직원이 우선순위가 더 높습니다.
//한 사람의 지정 자리가 여러 개인 경우, 지정 자리가 있는 방 중에서 새 자리가 생긴 방과 가장 가까운 방을 기준으로 선정합니다.
//방과 방 사이의 거리는 두 방의 호수 차이의 절댓값으로 정의합니다.
//예를 들어 303호와 405호의 거리는 | 303 - 405 | = 102입니다.
//지정 자리 수와 새 자리가 생긴 방까지의 거리도 동일한 경우, 이름이 사전 순으로 빠른 사람이 더 높은 우선순위를 갖습니다.단 사전 순은 대문자가 소문자 보다 사전 순으로 앞섭니다.예를 들어, A~Z, a~z까지 알파벳을 사전 순으로 정렬한 결과는[A, B, ... Z, a, b, ..., z]입니다
//직원들의 지정 자리 정보가 담긴 배열 rooms와 새 자리가 생긴 방 호수 target이 매개변수로 주어집니다.새 자리를 받을 수 있는 사람들을 우선순위가 높은 사람부터 순서대로 배열에 담아 return 하도록 solution 함수를 완성해주세요.
#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> rooms, int target) {
    vector<string> answer;



    return answer;
}