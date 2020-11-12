#include <stdio.h>
#include <stdlib.h>

struct unit {
	int value;
	struct unit* next;
};

struct unit** edgeTable;
int indegree[10010];

int timeTable[10010];

int queue[10010];
int front, real;

int solution[10010];

int qquFront() {
	return queue[front];
}

void qquPop() {
	front++;
}

void qquPush(int input) {
	queue[real++] = input;
}

void init(int n) {
	
	int size = n + 1;
	edgeTable = (struct unit**)malloc(sizeof(struct unit*) * size);
	
	for (int i = 0; i <= n; i++) {
		edgeTable[i] = NULL;
	}
}

void linkPush(int node, int input) {

	struct unit* temp = (struct unit*)malloc(sizeof(struct unit));
	temp->value = input;

	temp->next = edgeTable[node];
	edgeTable[node] = temp;
}

void scan(int n) {

	int input;
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &timeTable[i], &indegree[i]);
		
		for (int j = 0; j < indegree[i]; j++) {
			scanf("%d", &input);
			linkPush(input, i);
		}
	}
}

int checkZero(int n) {

	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			indegree[i] = -1;
			return i;
		}
	}
	return -1;
}

void topoSort(int n) {

	while (1) {
		int current = checkZero(n);
		if (current == -1)
			break;

		solution[current] += timeTable[current];

		struct unit* next = edgeTable[current];
		while (next != NULL) {

			indegree[next->value]--;
			if (solution[next->value] == 0)
				solution[next->value] = solution[current];
			else {
				solution[next->value] = solution[current] > solution[next->value] ? solution[current] : solution[next->value];
			}

			next = next->next;
		}
		
	}
	

}

int main() {

	int n;
	scanf("%d", &n);

	init(n);

	scan(n);

	topoSort(n);

	int max = 0;
	for (int i = 1; i <= n; i++) {
		if (max < solution[i])
			max = solution[i];
	}
	printf("%d\n", max);
}