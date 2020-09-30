#include <stdio.h>
#include <stdlib.h>

int queue[1010];
int front, real;

int indegree[1010];
int board[1010][1010];
int flag;

struct unit {
	int value;
	struct unit* next;
};

struct unit** edgeTable;

void add(int node, int input) {

	board[node][input] = 1;
	if (board[input][node] == 1)
		flag = 1;

	indegree[input]++;

	struct unit* temp = (struct unit*)malloc(sizeof(struct unit));
	temp->value = input;

	temp->next = edgeTable[node];
	edgeTable[node] = temp;
	
}

void scan(int n, int m) {

	int num, input = 0, before;
	for (int i = 0; i < m; i++) {
		scanf("%d", &num);

		for (int j = 0; j < num; j++) {
			before = input;
			scanf("%d", &input);
			
			if (j != 0) {
				add(before, input);
			}
		}
	}
}

void init(int n, int m) {

	int size = n + 1;
	edgeTable = (struct unit**)malloc(sizeof(struct unit*) * size);

	for (int i = 0; i <= n; i++) {
		edgeTable[i] = NULL;
	}
}

void print(int n, int m) {

	for (int i = 1; i <= n; i++) {
		struct unit* next = edgeTable[i];
		printf("%d: ", i);
		while (next != NULL) {

			printf("%d ", next->value);
			next = next->next;
		}
		printf("\n");
	}
}

void qquPush(int input) {

	queue[real++] = input;
}

void qquPop() {
	front++;
}

int qquFront() {

	return queue[front];
}

int qquEmpty() {
	return front == real;
}

int checkZero(int n, int m) {

	int revalue = -1;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			revalue = 1;
			
			indegree[i] = -1;
			qquPush(i);
		}
	}
	return revalue;
}

void findSolution(int n, int m) {

	while (1) {
		int current = checkZero(n, m);
		if (current == -1)
			break;

		while (!qquEmpty()) {

			current = qquFront();
			qquPop();

			printf("%d ", current);

			struct unit* next = edgeTable[current];
			while (next != NULL) {
				indegree[next->value]--;

				next = next->next;
			}
		}

	}

}

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	init(n, m);

	scan(n, m);

	if (flag == 1)
		printf("0");
	else
		findSolution(n, m);
}

