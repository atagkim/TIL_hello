#include <stdio.h>

int queueTable[100];
int front, real;

void push(int* table, int* real, int data) {

	table[(*real)++] = data;
	return;
}

int frontFunc(int* table, int* front) {

	int revalue = table[*front];

	return revalue;
}

void pop(int* table, int* front) {
	
	(*front)++;
	return;
}

int empty(int* table, int* front, int* real) {
	if (*front >= *real)
		return 1;

	return 0;
}

int main() {

	push(queueTable, &real, 5);
	push(queueTable, &real, 3);
	push(queueTable, &real, 2);
	push(queueTable, &real, 4);
	
	while (!empty(queueTable, &front, &real)) {
		
		int current = frontFunc(queueTable, &front);
		pop(queueTable, &front);

		printf("%d\n", current);
	}
	printf("end\n");
}