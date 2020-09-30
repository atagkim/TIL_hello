#include <stdio.h>
#include <stdlib.h>


int indegree[33000];

struct unit {
	int value;
	struct unit* next;
};

struct unit** edgeTable;

void add(int node, int value) {

	struct unit* input = (struct unit*)malloc(sizeof(struct unit));
	input->value = value;

	if (edgeTable[node] == NULL) {
		edgeTable[node] = input; 
		input->next = NULL;
	}
	else {
		input->next = edgeTable[node];
		edgeTable[node] = input;
	}
}


void scan(int n, int m) {
	int pre, post;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &pre, &post);

		add(pre, post);

		indegree[post]++;
	}

}

void init(int n, int m) {

	int size = n + 1;
	edgeTable = (struct unit**)malloc(sizeof(struct unit*) * (size));
	for (int i = 0; i <= n; i++) {
		edgeTable[i] = NULL;
	}
}

int checkZero(int n, int m) {

	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			indegree[i] = -1;
			return i;
		}
	}
	return -1;
}

void find(int n, int m) {

	while (1) {
		
		int current = checkZero(n, m);
		if (current == -1)
			break;

		printf("%d ", current);

		struct unit* next = edgeTable[current];
		while (next != NULL) {
			indegree[next->value]--;

			next = next->next;
		}

	}

}

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	init(n, m);

	scan(n, m);

	find(n, m);
}

