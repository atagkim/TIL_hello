#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> hahash;
    for (string name : participant) {
        hahash[name]++;
    }
    for (string name : completion) {
        hahash[name]--;
    }
    for (auto pair : hahash) {
        if (pair.second > 0) {
            answer += pair.first;
        }
    }

    return answer;
}

vector<string> parti{"aaa", "bbb", "ccc"};
vector<string> comple{"aaa", "bbb"};

int main() {

    string revalue = solution(parti, comple);
    cout << revalue;

}