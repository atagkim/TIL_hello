#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

struct pqcmp {
    bool operator() (int a, int b) {
        if (a > b)
            return 1;
        else
            return 0;
    }
};

priority_queue<int> maxpq;
priority_queue<int, vector<int>, pqcmp> minpq;

unordered_map<string, int> hahash;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    string currentstr, topstring;
    int currentnum;
    int maxsol = 0, minsol = 0;

    for (int i = 0; i < operations.size(); i++) {

        // Insert
        if (operations[i][0] == 'I') {

            currentstr = operations[i].substr(2);
            currentnum = stoi(currentstr);

            maxpq.push(currentnum);
            minpq.push(currentnum);

            hahash[currentstr]++;
        }
        // Delete
        else {
            
            // min
            if (operations[i][2] == '-') {

                while (!minpq.empty()) {

                    topstring = to_string(minpq.top());
                                      
                    if (hahash[topstring] > 0) {
                    
                        minpq.pop();
                        hahash[topstring]--;

                        break;
                    }
                    else {
                        minpq.pop();
                    }
                }

            }

            // max
            else {
                while (!maxpq.empty()) {
                    topstring = to_string(maxpq.top());
                    
                    if (hahash[topstring] > 0) {
                        maxpq.pop();
                        hahash[topstring]--;

                        break;
                    }
                    else {
                        maxpq.pop();
                    }
                }
            }

        }

    }

    while (!maxpq.empty()) {

        topstring = to_string(maxpq.top());
        if (hahash[topstring] > 0) {

            maxsol = maxpq.top();
            break;
        }
        else
            maxpq.pop();
    }

    while (!minpq.empty()) {

        topstring = to_string(minpq.top());
        if (hahash[topstring] > 0) {

            minsol = minpq.top();
            break;
        }
        else
            minpq.pop();
    }

    answer.push_back(maxsol);
    answer.push_back(minsol);

    return answer;
}

int main() {

    vector<string> operations = {"I 7","I 5","I -5" ,"D -1" };

    vector<int> answer = solution(operations);

    printf("%d %d", answer[0], answer[1]);

}