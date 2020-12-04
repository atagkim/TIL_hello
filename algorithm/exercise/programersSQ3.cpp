#include <string>
#include <queue>

using namespace std;

struct unit {
    int id;
    int length;
};

vector<unit> currentBridge;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1;
    
    int left = 0, right = 0, sum = 0;
    int size = truck_weights.size();
    
    unit fire;
    fire.length = bridge_length;

    while (left < size) {

        if (right < size && sum + truck_weights[right] <= weight) {

            sum += truck_weights[right];

            fire.id = right;
            currentBridge.push_back(fire);

            right++;
        }

        for (int i = left; i < right; i++) {
            if (currentBridge[i].length == 1) {
                sum -= truck_weights[i];
                left++;
            }
            else
                currentBridge[i].length--;
        }

        answer++;
    }
    
    return answer;
}

int main() {

    int bridgeLen = 2;
    int weight = 10;
    vector<int> truck = { 7,4,5,6 };

    int revalue = solution(bridgeLen, weight, truck);

    printf("%d", revalue);

}