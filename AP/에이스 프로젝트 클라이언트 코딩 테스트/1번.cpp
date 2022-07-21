//1¹ø

//#include <string>
//#include <vector>
//#include <stdlib.h>
//#include <numeric>
//#include <algorithm>
//
//using namespace std;
//vector<int> answer_list;
//
//int solution(int n, vector<int> v) {
//    int answer = 0;
//
//    for (int i = 0; i < n + 1; ++i) {
//        int l_sum, r_sum = 0;
//
//        if (i == 0 || i == n) {
//            answer_list.push_back(accumulate(v.begin(), v.end(), 0));
//        }
//        else {
//            l_sum = accumulate(v.begin(), v.begin() + i, 0);
//            r_sum = accumulate(v.begin() + i, v.end(), 0);
//
//            answer_list.push_back(abs(l_sum - r_sum));
//        }
//    }
//
//    return min_element(answer_list.begin(), answer_list.end()) - answer_list.begin();
//}
//
//int main() {
//    printf("%d", solution(5, {1, 2, 1, 2, 1}));
//}


// 2¹ø


//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//string solution(string s) {
//    string answer = "";
//    int temp = 0;
//
//    while (temp < s.size()) {
//        temp = max_element(s.begin() + temp, s.end()) - (s.begin());
//        answer += s[temp];
//        temp++;
//    }
//
//    return answer;
//}
//
//#include <string>
//#include <vector>
//#include <map>
//#include <algorithm>
//
//using namespace std;
//map<int, char> m;
//
//bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
//    if (a.second == b.second) return a.first < b.first;
//    return a.second > b.second;
//}
//
//string solution(string s) {
//    string answer = "";
//    int temp = 0;
//    int last_index = 0;
//
//    for (char i : s) {
//        m[temp++] = i;
//    }
//
//    vector<pair<int, char>> v(m.begin(), m.end());
//    sort(v.begin(), v.end(), cmp);
//
//    for (int i = 0; i < v.size(); ++i) {
//        if (v[i].first < last_index) {
//            continue;
//        }
//        else {
//            last_index = v[i].first;
//        }
//        answer += v[i].second;
//    }
//
//    return answer;
//}

#include <string>
#include <vector>

using namespace std;

int solution(int n, int maxhp, vector<int> times, vector<int> effects) {
    int answer = 0;
    int timer = 0;
    int total_heal = 0;
    int item_num = 0;
    int curr_hp = maxhp;

    while (timer - 1 != times[n - 1] + 1) {
        curr_hp += total_heal;

        if (curr_hp <= 0) {
            curr_hp = 0;
            answer++;
        }
        else if (curr_hp > maxhp) {
            curr_hp = maxhp;
            answer++;
        }

        if (item_num < effects.size() && timer == times[item_num]) {
            total_heal += effects[item_num++];
        }
        timer++;
    }

    return answer;
}