#include <string>
#include <queue>

using namespace std;

struct edgeunit {
    int cost;
    int start;
    int end;
};

struct pqcmp {
    bool operator() (edgeunit a, edgeunit b) {
        if (a.cost > b.cost)
            return 1;
        else
            return 0;
    }
};

priority_queue<edgeunit, vector<edgeunit>, pqcmp> pq;

bool visittable[110];


int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    // init
    vector<vector<edgeunit>> edgetable;
    vector<edgeunit> init;
    edgeunit input, current;

    int count = 0, sum = 0;

    for (int i = 0; i < n; i++) {
        edgetable.push_back(init);
    }

    for (int i = 0; i < costs.size(); i++) {
        input.cost = costs[i][2];
        input.end = costs[i][1];

        edgetable[costs[i][0]].push_back(input);

        input.end = costs[i][0];

        edgetable[costs[i][1]].push_back(input);
    }

    
    // fire
    visittable[0] = 1;
    count++;
    
    for (int j = 0; j < edgetable[0].size(); j++) {
        pq.push(edgetable[0][j]);
    }


    // start
    while (count < n) {

        current = pq.top();
        pq.pop();

        if (visittable[current.end] == 1)
            continue;

        visittable[current.end] = 1;
        
        sum += current.cost;
        count++;

        for (int j = 0; j < edgetable[current.end].size(); j++) {
            pq.push(edgetable[current.end][j]);
        }

    }
    

    answer = sum;

    return answer;
}

int main() {

    vector<vector<int>> costs = { {0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8} };
    int n = 4;

    int answer = solution(n, costs);

    printf("answer = %d\n", answer);
}