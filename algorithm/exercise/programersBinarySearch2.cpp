#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define START 0
#define END 1000000000

int currentSolution;

int checkPossible(int middle, int dist, vector<int> rocks, int n) {

    int count = 0, left = 0, right, rocksSize = rocks.size();
    for (int i = 0; i < rocks.size(); i++) {
        right = rocks[i];

        if (right - left < middle && count < n) {
            count++;
        }
        else if (right - left < middle && count >= n) {
            return 0;
        }
        else {
            left = right;
        }
    }
    right = dist;
    if (right - left < middle && count >= n) {
        return 0;
    }    

    return 1;
}

void binarySearch(int start, int end, int dist, vector<int> rocks, int n) {

    int middle = (start + end) / 2;

    if (start >= end) {
        if (checkPossible(middle, dist, rocks, n)) {
            currentSolution = middle;
        }
        return;
    }
    else {
        if (checkPossible(middle, dist, rocks, n)) {
            currentSolution = middle;
            binarySearch(middle + 1, end, dist, rocks, n);
        }
        else {
            binarySearch(start, middle - 1, dist, rocks, n);
        }
    }
    return;
}


int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;

    sort(rocks.begin(), rocks.end());

    binarySearch(START, END, distance, rocks, n);

    answer = currentSolution;

    return answer;
}


int main() {

    int dist = 25;
    vector<int> rocks = { 2,14,11,21,17 };
    int n = 2;

    printf("answer: %d\n", solution(dist, rocks, n));

}