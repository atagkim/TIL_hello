#include <stdio.h>

int dpTable[20];

void dp() {

	dpTable[1] = 1;
	dpTable[2] = 2;
	dpTable[3] = 4;

	for (int i = 4; i <= 11; i++) {
		dpTable[i] = dpTable[i - 1] + dpTable[i - 2] + dpTable[i - 3];
	}
}


int main() {
	
	int t;
	scanf("%d", &t);

	dp();

	while (t--) {
		int input;
		scanf("%d", &input);

		printf("%d\n",dpTable[input]);

	}
}