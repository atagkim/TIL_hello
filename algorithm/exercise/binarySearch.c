#include <stdio.h>

int inputTable[10010];
int cut;
int binaryRevalue = 1000000000;

int init(int n) {
	
	int tempSum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &inputTable[i]);
		tempSum += inputTable[i];
	}

	scanf("%d", &cut);
	if (tempSum <= cut)
		return 1;

	else
		return 0;
}

int funcCheck(int middle, int n) {

	int tempSum = 0;
	for (int i = 0; i < n; i++) {
		if (inputTable[i] > middle)
			tempSum += middle;
		else
			tempSum += inputTable[i];
	}
	if (tempSum > cut)
		return 0;
	else
		return 1;
}

void binarySearch(int start, int end, int n) {

	if (start > end) {
		return;
	}

	int middle = (start + end) / 2;

	if (funcCheck(middle, n)) {
		
		binaryRevalue = middle;
		binarySearch(middle + 1, end, n);		
	} 
	else {
		binarySearch(start, middle - 1, n);
	}
	
}

int max(int n) {

	int tempMax = 0;
	for (int i = 0; i < n; i++) {
		if (inputTable[i] > tempMax)
			tempMax = inputTable[i];
	}
	return tempMax;
}

int main() {
	int n;
	scanf("%d", &n);

	int sol = 0;
	if (init(n)) {
		sol = max(n);
	}
	else {
		binarySearch(1, cut, n);

		for (int i = 0; i < n; i++) {
			if (inputTable[i] >= binaryRevalue && binaryRevalue > sol)
				sol = binaryRevalue;
			else if (inputTable[i] < binaryRevalue && inputTable[i] > sol)
				sol = inputTable[i];
		}
	}
	printf("%d", sol);


}
