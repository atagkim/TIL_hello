#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> realAnswer;

    int current;
    int countTable[110] = { 0, };
    int max;

    for (int i = 0; i < progresses.size(); i++) {
        current = 100 - progresses[i];
        if (current % speeds[i] == 0)
            current = current / speeds[i];
        else
            current = current / speeds[i] + 1;

        if (i != 0 && current < answer[i - 1])
            answer.push_back(answer[i - 1]);
        else
            answer.push_back(current);
    }

    sort(answer.begin(), answer.end());
    
    max = answer[answer.size() - 1];


    for (int i = 0; i < answer.size(); i++) {
        countTable[answer[i]]++;
    }

    for (int i = 0; i <= max; i++) {
        if(countTable[i]!=0)
            realAnswer.push_back(countTable[i]);
    }

    return realAnswer;
}




int main() {

    vector<int> progresses = { 93, 30, 55 };
    vector<int> speeds = { 1, 30, 5 };

    vector<int> answer = solution(progresses, speeds);

    for (int i = 0; i < answer.size(); i++) {
        printf("%d ", answer[i]);
    }
    
}