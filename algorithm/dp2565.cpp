#include <stdio.h>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

typedef struct line {
	int start;
	int end;
	int crossPointNum;
};

int solutionMax;
int dpTable[510];
line inputTable[510];

bool cmp(const line &left, const line &right) {
	if (left.start < right.start) return true;
	else return false;
}

void init(int n) {

	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &inputTable[i].start, &inputTable[i].end);
	}
	sort(inputTable + 1, inputTable + n + 1, cmp);

	for (int i = 1; i <= n; i++) {
		dpTable[i] = 1;
	}

}

void dp(int n) {

	for (int current = 1; current <= n; current++) {
		for (int before = 1; before < current; before++) {
			if (inputTable[current].end > inputTable[before].end && dpTable[before] + 1 > dpTable[current]) {
				dpTable[current] = dpTable[before] + 1;
				
				if (dpTable[current] > solutionMax) {
					solutionMax = dpTable[current];
				}
			}
		}
	}
}


int main() {

	int n;
	scanf("%d", &n);

	init(n);

	dp(n);

	printf("%d", n - solutionMax);
}