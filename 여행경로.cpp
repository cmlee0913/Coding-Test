#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;
	sort(tickets.begin(), tickets.end(), greater<vector<string>>());
	unordered_map<string, vector<string>> route;
	for (unsigned int i = 0; i < tickets.size(); i++) {
		route[tickets[i][0]].push_back(tickets[i][1]);
	}
	stack<string> stk;
	stk.push("ICN");
	while (!stk.empty()) {
		string tp = stk.top();
		if (route.find(tp) == route.end() || route[tp].size() == 0) {
			answer.push_back(tp);
			stk.pop();
		}
		else {
			stk.push(route[tp].back());
			route[tp].pop_back();
		}
	}
	reverse(answer.begin(), answer.end());
	return answer;
}