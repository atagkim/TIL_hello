#include <string>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool sortcmp(string a, string b) {
    if (a < b)
        return 1;
    else
        return 0;
}

struct pqcmp {
    bool operator()(int a, int b) {
        if (a > b)
            return 1;
        else
            return 0;
    }
};

int visitTable[10100];

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;


    vector<string> nameTable;
    unordered_map<string, int> checkTable;
    unordered_map<string, int> idTable;

    vector<vector<int>> edgeTable;
    vector<int> init;

    vector<priority_queue<int, vector<int>, pqcmp>> nodepq;
    priority_queue<int, vector<int>, pqcmp> pqinit;

    string from, to;
    int fromid, toid;
    int fireid;

    int maxnode, nodecount = 0;
    int current, next;

    // name => id 테이블
    for (int i = 0; i < tickets.size(); i++) {

        from = tickets[i][0];
        to = tickets[i][1];

        if (checkTable[from] == 0) {
            checkTable[from] = 1;

            nameTable.push_back(from);
        }
        if (checkTable[to] == 0) {
            checkTable[to] = 1;

            nameTable.push_back(to);
        }
    }

    sort(nameTable.begin(), nameTable.end(), sortcmp);
        
    for (int i = 0; i < nameTable.size(); i++) {

        idTable[nameTable[i]] = i;

        edgeTable.push_back(init);
        nodepq.push_back(pqinit);
    }

    maxnode = nameTable.size();


    // 그래프 만들기
    for (int i = 0; i < tickets.size(); i++) {

        from = tickets[i][0];
        to = tickets[i][1];

        fromid = idTable[from];
        toid = idTable[to];

        edgeTable[fromid].push_back(toid);
    }

    for (int i = 0; i < edgeTable.size(); i++) {
        for (int j = 0; j < edgeTable[i].size(); j++) {
            nodepq[i].push(edgeTable[i][j]);
        }
    }


    // set fire
    fireid = idTable["ICN"];
    answer.push_back("ICN");
    
    current = fireid;

    while (1) {

        if (nodepq[current].empty()) {

            break;
        }

        next = nodepq[current].top();
        nodepq[current].pop();

        answer.push_back(nameTable[next]);

        current = next;
    }

    return answer;
}

int main() {

    vector<vector<string>> tickets = {{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL", "SFO"}};

    vector<string> answer = solution(tickets);

    for (int i = 0; i < answer.size(); i++) {
        printf("%s ", answer[i].c_str());
    }


}