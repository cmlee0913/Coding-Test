#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int s = nums.size() / 2;

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    if (nums.size() < s) {
        return nums.size();
    }
    else {
        return s;
    }
}

// 다른 풀이
//#include <vector>
//#include <unordered_map>
//
//using namespace std;
//
//int solution(vector<int> nums)
//{
//    unordered_map<int, int> hash;
//
//    for (auto num : nums) {
//        hash[num] += 1;
//    }
//
//    return min(hash.size(), nums.size() / 2);
//
//}