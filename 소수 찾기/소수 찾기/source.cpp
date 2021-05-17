#include <string>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

// 보편적인 방법

//int solution(int n) {
//    int answer = 0;
//    int a = 0;
//    for (int i = 2; i <= n; i++) {
//        a = 1;
//        for (int j = 2; j <= sqrt(i); j++) {
//            if (i % j == 0) {
//                a = 0;
//                break;
//            }
//        }
//        if (a == 1) {
//            answer++;
//        }
//    }
//
//    return answer;
//}

// 에라토스테네스의 체

//#include <string>
//#include <vector>
//
//using namespace std;
//
//int solution(int n) {
//    int answer = 0;
//    vector<int> arr(n + 1);
//
//    for (int i = 2; i < arr.size(); i++) {
//        arr[i] = i;
//    }
//
//    for (int i = 2; i <= n; i++) {
//        if (arr[i] == 0) {
//            continue;
//        }
//        for (int j = i * 2; j <= n; j = j + i) {
//            arr[j] = 0;
//        }
//    }
//
//    for (int i = 2; i <= n; i++) {
//        if (arr[i] != 0) {
//            answer++;
//        }
//    }
//
//    return answer;
//}