#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

char input[60];
int sum;

void parsing() {

	int inputLength = strlen(input);
	char numBuf[60];
	int numBufIndex = 0, current = 0;
	bool swich = 0;

	for (int i = 0; i < inputLength; i++) {

		if (input[i] != '-' && input[i] != '+') {			
			numBuf[numBufIndex++] = input[i];
		}
		else {
			numBuf[numBufIndex] = 0;			
			numBufIndex = 0;

			current = atoi(numBuf);

			if (swich == 0) {
				sum += current;
			}
			else {
				sum -= current;
			}
		}
		
		if (input[i] == '-') swich = 1;
	}

	numBuf[numBufIndex] = 0;

	current = atoi(numBuf);

	if (swich == 0) {
		sum += current;
	}
	else {
		sum -= current;
	}

}


int main() {

	scanf("%s", input);

	parsing();

	printf("%d",sum);
}