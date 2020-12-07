#include <string>
#include <vector>

using namespace std;

int lostTable[40];
int reserveTable[40];

int solution(int n, vector<int> lost, vector<int> reserve) {

    int answer = n;
    int idx = 1;

    for (int i = 0; i < lost.size(); i++) {
        lostTable[lost[i]] = 1;

        answer--;
    }

    for (int i = 0; i < reserve.size(); i++) {
        if (lostTable[reserve[i]] == 1) {
            lostTable[reserve[i]] = 0;
            answer++;
        }
        else
            reserveTable[reserve[i]] = 1;
    }

    while (idx <= n) {

        if (idx != 1) {
            if (lostTable[idx - 1] && reserveTable[idx]) {
                reserveTable[idx] = 0;
                lostTable[idx - 1] = 0;

                answer++;
            }
        }

        if (idx != n) {
            if (lostTable[idx + 1] && reserveTable[idx]) {
                reserveTable[idx] = 0;
                lostTable[idx + 1] = 0;

                answer++;
            }
        }

        idx++;
    }

    return answer;
}

int main() {

    int n = 5;
    vector<int> lost = { 2,4 }, reserve = { 3 };

    int revalue = solution(n, lost, reserve);

    printf("%d", revalue);

}