#include <string>
#include <queue>
#include <algorithm>

using namespace std;

struct currentunit {

    bool exist;
    int id;
    int start;
    int remain;
};

int timetable[510];

struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        if (a[1] < b[1])
            return 0;
        else
            return 1;
    }
};

priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
queue<vector<int>> qqu;

bool compare(vector<int> a, vector<int> b) {

    if (a[0] > b[0])
        return 0;
    else
        return 1;
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;

    int currenttime = 0;
    
    currentunit current;
    current.exist = 0;

    sort(jobs.begin(), jobs.end(), compare);

    for (int i = 0; i < jobs.size(); i++) {

    }


    return answer;
}

int main() {

    vector<vector<int>> jobs = { {0,3}, {1,9}, {2,6} };

    int revalue = solution(jobs);

    printf("%d", revalue);

    return 0;
}