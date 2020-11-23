#include <string>
#include <queue>
#include <iostream>

using namespace std;

int dpTable[55];
int dpCount;
int currentSolution;

struct unit {
    string word;
    int count;
};

queue<unit> qqu;

int checkPossible(string current, string next) {

    int stringLen = current.size(), flag = 0;
    for (int i = 0; i < stringLen; i++) {
        if (current[i] != next[i]) {
            flag++;
            if (flag > 1)
                return 0;
        }
    }
    return 1;
}

void bfs(string begin, string target, vector<string> words) {

    unit current, next;
    int wordsSize = words.size();

    unit fire;
    fire.word = begin;
    fire.count = 0;

    qqu.push(fire);

    while (!qqu.empty()) {

        current = qqu.front();
        qqu.pop();
        
        if (target == current.word) {
            currentSolution = current.count;
            break;
        }

        for (int i = 0; i < wordsSize; i++) {
            if (dpTable[i] == 0 && checkPossible(current.word, words[i])) {
                dpTable[i] = current.count + 1;
                
                next.count = current.count + 1;
                next.word = words[i];

                qqu.push(next);
            }
        }

    }

    while (!qqu.empty()) {
        qqu.pop();
    }
    return;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    bfs(begin, target, words);
    
    answer = currentSolution;
    return answer;
}

int main() {

    string begin = "hit";
    string target = "cog";
    vector<string> words = { "hot","dot", "dog", "lot", "log", "cog" };

    int revalue = solution(begin, target, words);
    cout << revalue;

}