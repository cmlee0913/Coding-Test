#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size());
    unordered_map<string, int> reported_num;
    unordered_map<string, vector<string>> report_pair;

    report.erase(unique(report.begin(), report.end()), report.end());

    for (int i = 0; i < id_list.size(); i++) {
        reported_num.insert(pair<string, int>(id_list[i], 0));
        report_pair.insert(pair<string, vector<string>>(id_list[i], {}));
    }

    for (int i = 0; i < report.size(); i++) {
        string reporter = report[i].substr(0, report[i].find(" "));
        string reported = report[i].substr(report[i].find(" ") + 1, -1);

        report_pair[reporter].push_back(reported);
        reported_num[reported]++;
    }

    for (int i = 0; i < id_list.size(); i++) {
        if (reported_num[id_list[i]] >= k) {
            for (int j = 0; j < id_list.size(); j++) {
                if (any_of(report_pair[id_list[j]].begin(),
                    report_pair[id_list[j]].end(),
                    [&](const string& elem) { return elem == id_list[i]; })) {
                    answer[j]++;
                }
            }
        }
    }

    return answer;
}

int main() {
    for (auto a : solution({ "muzi", "frodo", "apeach", "neo" }, { "muzi frodo", "frodo apeach", "apeach neo", "neo apeach", "muzi apeach", "neo apeach" }, 3)) {
        cout << a;
    }
    return 0;
}


// 왜 안풀려??????????????????????????????????