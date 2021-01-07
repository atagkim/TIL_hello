#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool sortcmp(int a, int b) {

    if (a > b)
        return 1;
    else
        return 0;
}

int solution(vector<int> citations) {
    int answer = 0;


    sort(citations.begin(), citations.end(), sortcmp);

    int max = citations[0];
    int count;

    for (int i = max; i >= 0; i--) {

        count = 0;
        for (int j = 0; j < citations.size(); j++) {
            if (citations[j] >= i)
                count++;
            else
                break;
        }

        if (count >= i) {
            answer = i;
            break;
        }
    }


    return answer;
}

int main() {

    vector<int> citations = { 3,0,6,1,5 };

    int answer = solution(citations);

    printf("answer = %d\n", answer);

}