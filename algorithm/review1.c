#include <stdio.h>
#include <stdlib.h>

int indegree[33000];
int queue[33000];
int front, real;
int solution[33000];
int top;

struct unit** head;

int funcEmpty() {
	if (front == real)
		return 1;
	else
		return 0;
}

void funcPush(int input) {

	queue[real++] = input;
}

int funcFront() {
	return queue[front];
}

void funcPop() {
	front++;
}

struct unit {
	int from;
	int to;
	struct unit* next;
};

void funcAdd(int from, int to) {

	struct unit* input = (struct unit*)malloc(sizeof(struct unit));

	input->from = from;
	input->to = to;
	input->next = NULL;

	input->next = head[from];
	head[from] = input;
}

void init(int n, int m) {

	int mallocSize = n + 1;
	head = (struct unit**)malloc(sizeof(struct unit*) * (mallocSize));
	for (int i = 0; i <= n; i++) {
		head[i] = NULL;
	}

	int from, to;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &from, &to);

		indegree[from]++;

		funcAdd(to, from);
		funcAdd(from, to);
	}
}


void check(int n, int m) {

	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			indegree[i] = -1;
			funcPush(i);
		}
	}
}

void topo(int n, int m) {


	check(n, m);


	while (!funcEmpty()) {

		int current = funcFront();
		funcPop();

		solution[top++] = current;

		struct unit* next = head[current];
		while (next != NULL) {
			indegree[next->to]--;
			if (indegree[next->to] == 0)
				funcPush(next->to);
			next = next->next;
		}
	}

	
}


int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	init(n, m);

	topo(n, m);

	for (int i = top - 1; i >= 0; i--) {
		printf("%d ", solution[i]);
	}
}