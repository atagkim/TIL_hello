#include <iostream>
#include <vector>
using namespace std;

#define WHAT 10
#define TABLESIZE 7

int table[100100] = { 1,2,4,5,10,100,120 };


void binarySearch(int what, int start, int end) {

	int middle = (start + end) / 2;

	if (start >= end) {
		if (table[middle] == what) {
			printf("table[%d] = %d\n", middle, what);
		}
		else {
			printf("%d is not in the table\n", what);
		}
		return;
	}

	if (table[middle] > what) {
		binarySearch(what, start, middle - 1);
	}
	else if(table[middle] < what) {
		binarySearch(what, middle + 1, end);
	}
	else {
		printf("table[%d] = %d\n", middle, what);
	}

	return;
}

int main() {

	binarySearch(WHAT ,0, TABLESIZE - 1);

}