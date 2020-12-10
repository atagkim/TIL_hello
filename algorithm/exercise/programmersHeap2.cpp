#include <string>
#include <queue>

using namespace std;

struct unit {
    int start;
    int end;
};

struct cmp {
    bool operator()(unit a, unit b) {
        return a.end - a.start > b.end - b.start ? 1 : 0;
    }
};

bool sortcmp(vector<int> a, vector<int> b) {

    return a[0] < b[0] ? 1 : 0;
}


priority_queue<unit, vector<unit>, cmp> pq;

int solution(vector<vector<int>> jobs) {
    int answer = 0, max = 0, min = 987654321;
    int currentStatus = 0;
    unit init, current;

    vector<vector<int>> newjobs;
    vector<int> init2;

    for (int i = 0; i < jobs.size(); i++) {

        if (jobs[i][0] > max) 
            max = jobs[i][0];
        if (jobs[i][0] < min)
            min = jobs[i][0];
    }

    for (int i = 0; i <= max; i++) {
        newjobs.push_back(init2);
    }


    sort(jobs.begin(), jobs.end(), sortcmp);
    
    for (int i = 0; i < jobs.size(); i++) {
        newjobs[jobs[i][0]].push_back(jobs[i][1]);
    }

    for (int i = min; i <= max; i++) {
        for (int j = 0; j < newjobs[i].size(); j++) {
            init.start = i;
            init.end = newjobs[i][j];

            pq.push(init);
        }

        if (currentStatus == 0) {
            currentStatus = 1;

            current = pq.top();
            pq.pop();
        }

        else {
            current.start++;

            if (current.end - current.start <= 0) {

            }
            else {

            }
        }

    }

    return answer;
}

int main() {

    vector<vector<int>> jobs = { {0,3}, {1,9}, {2,6} };

    int revalue = solution(jobs);

    printf("%d", revalue);

    return 0;
}