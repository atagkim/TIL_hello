#include <string>
#include <queue>
#include <algorithm>

using namespace std;

struct pqcmp {
    bool operator()(vector<int> a, vector<int> b) {
        if (a[1] < b[1])
            return 0;
        else
            return 1;
    }
};

priority_queue<vector<int>, vector<vector<int>>, pqcmp> possible;

struct currentunit {
    bool exist;
    int id;
    int start;
    int remain;
};

int currenttime = 0;
int jobsidx = 0;

long long sum;

bool sortcmp(vector<int> a, vector<int> b) {

    if (a[0] > b[0])
        return 0;
    else
        return 1;
}

void findpossible(vector<vector<int>> jobs) {
       
    int jobsnum = jobs.size();

    for (int i = jobsidx; i < jobsnum; i++) {
        
        if (jobs[i][0] <= currenttime) {
            jobs[i].push_back(i);
            possible.push(jobs[i]);

            jobsidx = i + 1;
        }
        else{
            jobsidx = i;
            break;
        }
    }
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
 
    int jobsnum = jobs.size(), completedjob = 0;
    currentunit current;
    current.exist = 0;

    sort(jobs.begin(), jobs.end(), sortcmp);


    while (completedjob < jobsnum) {

        findpossible(jobs);

        if (current.exist == 0 && !possible.empty()) {
            
            current.exist = 1;
            current.id = possible.top()[2];
            current.start = possible.top()[0];
            current.remain = possible.top()[1];
            
            possible.pop();

        }
        
        currenttime++;
        
        if (current.exist == 1) {
            current.remain--;

            if (current.remain <= 0) {
                sum += currenttime - current.start;
                current.exist = 0;

                completedjob++;
            }
        }
    }

    answer = sum / jobsnum;

    return answer;
}

int main() {

    vector<vector<int>> jobs = { {0,3}, {1,9}, {2,6} };

    int revalue = solution(jobs);

    printf("%d", revalue);

    return 0;
}