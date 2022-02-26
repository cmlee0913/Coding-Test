// 소숫점 계산 불가

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    unordered_map<string, int> money;

    for (int i = 0; i < enroll.size(); ++i) {
        money[enroll[i]] = 0;
    }

    for (int i = 0; i < seller.size(); ++i) {
        money[seller[i]] += amount[i] * 100;
    }

    for (int i = enroll.size() - 1; i >= 0; --i) {
        if (money[enroll[i]] != 0 && (referral[i] != "-")) {
            money[referral[i]] += money[enroll[i]] / 10;
        }

        money[enroll[i]] *= 0.9;
    }

    for (int i = 0; i < enroll.size(); ++i) {
        answer.push_back(money[enroll[i]]);
    }

    return answer;
}
// 소숫점 계산 가능
#include <string>
#include <vector>
#include <map>
using namespace std;
// 0108 ~ 0135
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer(enroll.size());
    map<string,string> parent;
    map<string,int> number_map;
    for(int i=0;i<referral.size();i++)
    {
        parent[enroll[i]] = referral[i];
        number_map[enroll[i]] = i;
    }
    for(int i=0;i<seller.size();i++)
    {
        int price = 100 * amount[i];
        int part = price/10;
        string next = parent[seller[i]];
        int n = number_map[seller[i]];
        answer[n] += price - part;
        price = part;
        part = price/10;
        while(price > 0 && next != "-")
        {
            n = number_map[next];
            answer[n] += price - part;
            price = part;
            part = price/10;
            next = parent[next];
        }
    }
    return answer;
}
