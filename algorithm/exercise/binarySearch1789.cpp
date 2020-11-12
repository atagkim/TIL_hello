#include <stdio.h>

int main() {

	long long s;
	scanf("%lld", &s);

	long long count = 1;
	long long sum = 0;

	while (1) {
		sum += count;
		if (sum > s) {
			count--;
			break;
		}
		count++;
	}

	printf("%lld", count);
}