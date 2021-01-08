#include <string>
#include <queue>

using namespace std;

struct unit {
    int node;
    int dist;
};
queue<unit> qqu;

int visitTable[20200];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    vector<vector<int>> edgeTable;
    vector<int> init;
    unit fire, current, next;
    bool checkflag;

    int max = 0, maxcount = 0;

    // init
    for(int i=0;i<=n;i++){
        edgeTable.push_back(init);
    }

    for (int i = 0; i < edge.size(); i++) {
        edgeTable[edge[i][0]].push_back(edge[i][1]);
        edgeTable[edge[i][1]].push_back(edge[i][0]);
    }


    // set fire
    fire.node = 1;
    fire.dist = 0;

    visitTable[fire.node] = 1;

    qqu.push(fire);

    while (1) {

        if (qqu.empty())
            break;
      
        current = qqu.front();
        qqu.pop();

        checkflag = 0;
        for (int i = 0; i < edgeTable[current.node].size(); i++) {

            next.node = edgeTable[current.node][i];
            next.dist = current.dist + 1;

            if (visitTable[next.node] == 1)
                continue;
            visitTable[next.node] = 1;

            qqu.push(next);
            checkflag = 1;
        }

        if (checkflag == 0) {
            if (max < current.dist) {
                max = current.dist;
                maxcount = 1;
            }
            else if (max == current.dist)
                maxcount++;
        }
    }

    answer = maxcount;

    return answer;
}

int main() {

    vector<vector<int>> edge = {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}};
    int n = 6;

    int answer = solution(n, edge);

    printf("answer = %d\n", answer);

}