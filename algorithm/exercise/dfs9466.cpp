#include <stdio.h>

int inputTable[100010];
int visitTable[100010];
int cycleChecker[100010];
int solution;

void init(int n) {

    for (int i = 1; i <= n; i++) {
        scanf("%d", &inputTable[i]);
        visitTable[i] = 0;
        cycleChecker[i] = 0;
    }

    solution = n;
}

int dfs(int current) {

    if (visitTable[current] == 1) {
        return 0;
    }
    else if (cycleChecker[current] == 1) {
        visitTable[current] = 1;
        cycleChecker[current] = 0;
        
        solution--;
        return current;
    }

    cycleChecker[current] = 1;
    int next = inputTable[current];

    int revalue = dfs(next);
    cycleChecker[current] = 0;
    
    if (revalue != 0) {
        if (revalue == current) {
            return 0;
        }
        else {
            visitTable[current] = 1;
            solution--;

            return revalue;
        }
    }
    else {
        visitTable[current] = 1;
        return 0;
    }
}

int main() {

    int t;
    scanf("%d", &t);

    while (t--) {

        int n;
        scanf("%d", &n);

        init(n);

        for (int i = 1; i <= n; i++) {
            if (visitTable[i] == 0) {
                dfs(i);
            }
        }

        printf("%d\n", solution);

    }

}