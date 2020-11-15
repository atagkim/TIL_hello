#include <iostream>
#include <vector>
using namespace std;

#define TESTSIZE 5

int parentTable[50] = { 0,1,1,2,3,5 }; 
// ��� Ʈ��
// [1,2,3,4]    [5] �� ��Ȳ

// => ���Ʈ���� �׷캰�� �����ɰ���.

int find(int current) {

	if (parentTable[current] == current) {
		return current;
	}

	int revalue = find(parentTable[current]);
	parentTable[current] = revalue;

	return revalue;
}

void merge(int a, int b) {

	int parentA = find(a);
	int parentB = find(b);

	if (parentA == parentB)
		return;
	
	parentTable[parentB] = parentA;
	return;
}


int main() {

	printf("before");
	for (int i = 1; i <= TESTSIZE; i++) {
		printf("[%d]: %d ", i, parentTable[i]);
	}
	printf("\n");

	for (int i = 1; i <= TESTSIZE; i++)
		find(i);

	printf("after");
	for (int i = 1; i <= TESTSIZE; i++) {
		printf("[%d]: %d ", i, parentTable[i]);
	}
	printf("\n");

}