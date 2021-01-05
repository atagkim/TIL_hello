#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;

    string current;
    int sum = 1;

    unordered_map<string, int> clothtable;

    for (int i = 0; i < clothes.size(); i++) {
        clothtable[clothes[i][1]]++;
    }

    for (int i = 0; i < clothes.size(); i++) {
        current = clothes[i][1];

        if (clothtable[current] != 0) {
            sum *= (clothtable[current] + 1);
            
            clothtable[current] = 0;
        }
    }

    answer = sum - 1;
    return answer;
}

int main() {

    vector<vector<string>> clothes = { {"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear" }, {"green_turban", "headgear" } };

    int answer = solution(clothes);

    printf("%d", answer);

}