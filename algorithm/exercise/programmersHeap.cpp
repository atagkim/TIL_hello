#include <stdio.h>
#include <queue>

using namespace std;

struct cmp {
    bool operator ()(int a, int b) {
        return a > b ? 1 : 0;
    }
};

priority_queue<int, vector<int>, cmp> pq;

int solution(vector<int> scoville, int K) {
    int answer = 0, current, second;

    for (int i = 0; i < scoville.size(); i++) {

        pq.push(scoville[i]);
    }

    while (1) {

        current = pq.top();
        pq.pop();

        if (current >= K)
            break;

        if (pq.empty()) {

            answer = -1;
            break;
        }

        second = pq.top();
        pq.pop();

        current = current + second * 2;

        pq.push(current);
        answer++;
    }


    return answer;
}


int main() {

    vector<int> scoville = { 1,2,3,9,10,12 };
    int k = 7;

    int revalue = solution(scoville, k);

    printf("%d", revalue);

}