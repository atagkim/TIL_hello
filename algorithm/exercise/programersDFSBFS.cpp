#include <string>
#include <vector>

using namespace std;

int currentSolution;
int currentSum;

void dfs(vector<int> numbers, int target, int current) {

    int numbersSize = numbers.size();

    if (current >= numbersSize) {

        if (currentSum == target)
            currentSolution++;
        return;
    }

    for (int i = 0; i < 2; i++) {
        if (i == 0) {
            currentSum += numbers[current];
        }
        else {
            currentSum -= numbers[current];
        }

        dfs(numbers, target, current + 1);
        
        if (i == 0) {
            currentSum -= numbers[current];
        }
        else {
            currentSum += numbers[current];
        }
    }

    return;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    dfs(numbers, target, 0);

    answer = currentSolution;
    return answer;
}

int main() {

    vector<int> numbers = { 1,1,1,1,1 };
    int target = 3;

    int revalue = solution(numbers, target);
    printf("%d", revalue);
}