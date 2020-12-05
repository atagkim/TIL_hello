#include <string>
#include <queue>

using namespace std;


struct unit {
    int id;
    int value;
};

queue<unit> qqu;
priority_queue<int> order;

int solution(vector<int> priorities, int location) {
    int answer = 1;

    int currentOrder;
    unit input, current;

    for (int i = 0; i < priorities.size(); i++) {
        order.push(priorities[i]);

        input.value = priorities[i];
        input.id = i;
        qqu.push(input);
    }

    while (!qqu.empty()) {

        current = qqu.front();
        qqu.pop();

        currentOrder = order.top();

        
        if (current.value == currentOrder) {
            if (location == current.id)
                break;
            else 
                answer++;

            order.pop();
        }
        else
            qqu.push(current);
    }

    while (!qqu.empty()) {
        qqu.pop();
    }
    while (!order.empty()) {
        order.pop();
    }

    return answer;
}

int main() {

    vector<int> priorities = { 2,1,3,2 };
    int location = 2;

    int revalue = solution(priorities, location);
    printf("%d", revalue);
}