#include <stdio.h>
#pragma warning(disable:4996)

int table[100010];

void init(int n) {

	table[n] = 0;
	for (int i = n + 1; i <= 100000; i++) {
		table[i] = i - n;
	}
	for (int i = n - 1; i >= 0; i--) {
		table[i] = n - i;
	}
}

int dfs(int current, int target, int length) {


	if (current < 0 || current > 100000) return -1;

	if (table[current] <= length) return -1;
	table[current] = length;

	if (current == target) return 1;

	if (table[target] <= length) {
		printf("fewfwef');\n");
		return -1;
	}


	if (current > target) {
		if (current - 1 >= 0 && table[current - 1] > length + 1) dfs(current - 1, target, length + 1);
	}
	else {
		if (current + 1 <= 100000 && table[current + 1] > length + 1) dfs(current + 1, target, length + 1);
		if (current - 1 >= 0 && table[current - 1] > length + 1) dfs(current - 1, target, length + 1);
		if (current * 2 <= 100000 && table[current * 2] > length + 1) dfs(current * 2, target, length + 1);
	}
}

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	init(n);

	
	if (n + 1 <= 100000 && table[n + 1] > 1) dfs(n + 1, m, 1);
	if (n - 1 >= 0 && table[n - 1] > 1) dfs(n - 1, m, 1);
	if (n * 2 <= 100000 && table[n * 2] > 1) dfs(n * 2, m, 1);

	printf("%d", table[m]);
}