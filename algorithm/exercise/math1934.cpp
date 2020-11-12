#include <stdio.h>

int findLV(int a, int b) {

	int small, large;
	if (a < b) {
		small = a;
		large = b;
	}
	else {
		small = b;
		large = a;
	}
	
	int returnValue = 1;
	int idx = 2;
	while (idx  <= small) {
		
		if (small % idx == 0 && large % idx == 0) {
			returnValue *= idx;
			small /= idx;
			large /= idx;
		}
		else
			idx++;
	}

	return returnValue;
}

int main() {

	int t;
	scanf("%d", &t);

	int a, b;
	while (t--) {
		scanf("%d %d", &a, &b);

		int lv = findLV(a, b);

		int lm = a * b / lv;

		printf("%d\n", lm);

	}
}