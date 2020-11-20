#include <string>
#include <queue>

using namespace std;

int visitTable[220];
int currentSolution;

queue<int> qqu;

void bfs(int n, vector<vector<int>> computers, int fire) {

    int current;

    if (visitTable[fire] == 0) {
        visitTable[fire] = 1;
        qqu.push(fire);
        
        currentSolution++;
    }
    while (!qqu.empty()) {

        current = qqu.front();
        qqu.pop();

        for (int i = 0; i < n; i++) {
            if (i == current)
                continue;

            if (computers[current][i] == 1 && visitTable[i] == 0) {
                visitTable[i] = 1;
                qqu.push(i);
            }
        }

    }
    return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0, fire;
    
    for (int i = 0; i < n; i++) {
        fire = i;
        bfs(n, computers, i);
    }
    
    answer = currentSolution;
    return answer;
}

int main() {

    vector<vector<int>> computers = { {1,1,0},{1,1,0},{0,0,1} };
    int n = 3;

    int revalue = solution(n, computers);
    printf("%d", revalue);

}
