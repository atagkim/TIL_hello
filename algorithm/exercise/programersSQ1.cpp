#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int current, count;

    for (int i = 0; i < prices.size() - 1; i++) {

        current = prices[i];
        count = 0;
        for (int j = i + 1; j < prices.size(); j++) {

            if (prices[j] >= current) {
                count++;
            }
            else {
                count++;
                break;
            }

        }
        answer.push_back(count);
    }
    answer.push_back(0);


    return answer;
}