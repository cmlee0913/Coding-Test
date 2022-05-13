#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int truck_count = 0;
    queue<int> crossing_truck;

    int left_weight = weight;
    
    while (true) {
        if (truck_count == truck_weights.size()) break;

        if (crossing_truck.size() == bridge_length) {
            left_weight += crossing_truck.front();
            crossing_truck.pop();
        }

        if (left_weight >= truck_weights[truck_count]) {
            left_weight -= truck_weights[truck_count];
            crossing_truck.push(truck_weights[truck_count++]);
        }
        else {
            crossing_truck.push(0);
        }

        answer++;
    }
    
    return answer + bridge_length;
}