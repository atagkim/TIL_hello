#include <string>
#include <queue>

using namespace std;

int visitTable[110];

void initVisitTable(int n) {

    for (int i = 1; i <= n; i++) {
        visitTable[i] = 0;
    }
}

struct unit {

    int node;
    int dist;
};


int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    vector<vector<int>> edgeTable;
    vector<int> init;

    queue<unit> qqu;

    unit start, current, next;
    int maxlen = 0, checkflag;


    // init
    for (int i = 0; i <= n; i++) {
        edgeTable.push_back(init);
    }

    for (int i = 0; i < results.size(); i++) {
        edgeTable[results[i][0]].push_back(results[i][1]);
    }


    // set start point and init requirements
    for (int i = 1; i <= n; i++) {

        initVisitTable(n);
        
        while (!qqu.empty())
            qqu.pop();

        start.node = i;
        start.dist = 0;
        qqu.push(start);



        //bfs start 
        while (1) {

            if (qqu.empty())
                break;

            current = qqu.front();
            qqu.pop();


            // ½ÎÀÌÅ¬ ÄÆ
            if (current.dist >= n)
                continue;


            checkflag = 0;
            for (int j = 0; j < edgeTable[current.node].size(); j++) {
                next.node = edgeTable[current.node][j];
                next.dist = current.dist + 1;

                if (visitTable[next.node] < next.dist) {
                    visitTable[next.node] = next.dist;

                    qqu.push(next);
                    checkflag = 1;

                }
            }

            if (checkflag == 0) {

                if (maxlen < current.dist) {
                    maxlen = current.dist;

                }
            }

        }
    
    }


    answer = maxlen;

    return answer;
}

int main() {

    vector<vector<int>> results = { {4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5} };
    int n = 5;

    int answer = solution(n, results);

    printf("answer = %d\n", answer);

}