#include <stdio.h>
#include <algorithm>
using namespace std;

struct unit {
    int aScore;
    int bScore;
};

struct unit score[100010];
int solution;

void init(int n) {
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &score[i].aScore, &score[i].bScore);
    }
}

bool compare(struct unit A, struct unit B) {
    return A.aScore < B.aScore;
}

void funcSolution(int n) {

    sort(score + 1, score + 1 + n, compare);

    int temp = score[1].bScore;
    solution++;
    for (int i = 2; i <= n; i++) {
        if (score[i].bScore < temp) {
            temp = score[i].bScore;
            solution++;
        }
    }

}

int main() {

    int t;
    scanf("%d", &t);

    while (t--) {

        int n;
        scanf("%d", &n);

        init(n);

        solution = 0;
        funcSolution(n);

        printf("%d\n", solution);
    }

}