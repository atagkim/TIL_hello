#include <stdio.h>

// n(5)개 숫자 중 k(3)개 숫자로 조합 만들기

int numtable[10] = { 1,3,5,6,9 };
int numbuf[10];

void dfs(int bufidx, int tableidx, int n, int k) {

	int current;

	if (bufidx >= k) {

		for (int i = 0; i < k; i++) 
			printf("%d", numbuf[i]);
		printf("\n");

		return;
	}

	for (int i = tableidx + 1; i < n; i++) {

		current = numtable[i];
		
		numbuf[bufidx] = current;
		dfs(bufidx + 1, i, n, k);

	}

}

int main() {

	dfs(0, -1 ,5, 3);
}