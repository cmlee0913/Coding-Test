#include <string>
#include <vector>
using namespace std;

string str_day[] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
int month_day[] = { 31,29,31,30,31,30,31,31,30,31,30,31 };

string solution(int a, int b) {
    int total_day = 0;
    
    // 달
    for(int i = 1; i < a; i++)
    {
        total_day += month_day[i-1];
    }
    // 일
    total_day += b - 1;
 
    // 2016.1.1 = 금
    int answer_day = (5 + total_day) % 7;
 
    return str_day[answer_day];
}