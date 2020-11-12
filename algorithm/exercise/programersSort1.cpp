#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;

    for (int i = 0; i < commands.size(); i++) {
        int start = commands[i][0];
        int end = commands[i][1];
        int select = commands[i][2];

        int idx = start - 1;
        for (int i = 0; i < end - start + 1; i++) {
            temp.push_back(array[idx]);
            idx++;
        }
        sort(temp.begin(), temp.end());

        answer.push_back(temp[select - 1]);

        temp.clear();
    }


    return answer;
}