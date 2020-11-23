#include <string>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

bool compare(vector<string> a, vector<string> b) {
    
    if (a[0] == b[0])
       return a[1] < b[1] ? 1 : 0;
    return a[0] < b[0] ? 1 : 0;
}

struct cmp {
    bool operator()(string a, string b) {
        return a > b ? 1 : 0;
    }
};

priority_queue<string, vector<string>, cmp> pq;
unordered_map<string, int> idTable;

vector<string> idToString;
unordered_map<string, int> stringToId;

vector<vector<int>> edge;
vector<int> degree;


vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    string current;
    int idIdx = 0, ticketSize = tickets.size(), visitCount = 0, fire, next, end = -1;

    for (int i = 0; i < tickets.size(); i++) {
        for (int j = 0; j < tickets[i].size(); j++) {
            
            idTable[tickets[i][j]]++;
            if (idTable[tickets[i][j]] == 1) {
                pq.push(tickets[i][j]);
            }
        }
    }

    while (!pq.empty()) {
        current = pq.top();
        pq.pop();

        stringToId[current] = idIdx;
        idToString.push_back(current);
        
        idIdx++;

        vector<int> init;
        edge.push_back(init);
        degree.push_back(0);
    }

    sort(tickets.begin(), tickets.end(), compare);

    for (int i = 0; i < tickets.size(); i++) {
        edge[stringToId[tickets[i][0]]].push_back(stringToId[tickets[i][1]]);
        
        degree[stringToId[tickets[i][0]]]++;
        degree[stringToId[tickets[i][1]]]++;
    }

    fire = stringToId["ICN"];
    answer.push_back("ICN");

    while (visitCount < ticketSize) {

        for (int i = 0; i < edge[fire].size(); i++) {
            if (degree[edge[fire][i]] == 1 && ticketSize - visitCount != 1) {
                continue;
            }

            next = edge[fire][i];
            answer.push_back(idToString[next]);

            degree[fire]--;
            degree[next]--;
            edge[fire].erase(edge[fire].begin() + i);
            visitCount++;

            fire = next;
            break;
        }

    }
  
    return answer;
}

int main() {

    vector<vector<string>> tickets = { {"ICN", "COO"}, {"ICN", "BOO" }, {"COO", "ICN" }, {"BOO", "DOO" } };
    vector<string> answer = solution(tickets);
    for (int i = 0; i < answer.size(); i++) {
        printf("%s\n", answer[i].c_str());
    }
    return 0;
}