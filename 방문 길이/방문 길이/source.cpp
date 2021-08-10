#include <string>
#include <set>
using namespace std;
int toIdx(char ch) {
    switch (ch) {
    case 'R': return 0;
    case 'L': return 1;
    case 'U': return 2;
    case 'D': return 3;
    }
}
int solution(string dirs) {
    char ch;
    int answer = 0, i, x = 0, y = 0, ty, tx, dy[] = { 0,0,1,-1 }, dx[] = { 1,-1,0,0 }, idx, a, b;
    set<pair<int, int>> ans;
    for (i = 0; i < dirs.length(); i++) {
        ch = dirs[i];
        idx = toIdx(ch);
        tx = x + dx[idx], ty = y + dy[idx];
        if (!(-5 <= ty && ty <= 5 && -5 <= tx && tx <= 5)) continue;
        a = x * 10000 + y;
        x = tx, y = ty;
        b = x * 10000 + y;
        if (ans.find({ a,b }) == ans.end() && ans.find({ b,a }) == ans.end())
            ans.insert({ a,b });
    }
    return answer = (int)ans.size();
}