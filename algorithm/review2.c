#include <stdio.h>
#include <stdlib.h>

struct unit {
	int to;
	int weight;
	struct unit* link;
};

struct unit** head;

int distTable[20010];
int visitTable[20010];
int inf = 987654321;
int top = 1;

struct heapunit {
	int dist;
	int node;
};
struct heapunit heap[300010];

int heapEmpty() {
	if (top == 1)
		return 1;
	return 0;
}

void heapPush(struct heapunit input) {
		
	heap[top++] = input;

	int current = top - 1, parent = current / 2;
	while (parent >= 1) {

		if (heap[current].dist < heap[parent].dist) {
			struct heapunit temp = heap[current];
			heap[current] = heap[parent];
			heap[parent] = temp;

			current = parent;
			parent = current / 2;
		}
		else
			break;
	}
}

struct heapunit heapFront() {

	return heap[1];
}

void heapPop() {

	heap[1] = heap[top - 1];
	top--;

	int current = 1;
	while (1) {

		if (current * 2 >= top)
			break;

		int next;
		if (current * 2 + 1 < top) {

			if (heap[current * 2 + 1].dist < heap[current * 2].dist) {
				next = current * 2 + 1;
			}
			else
				next = current * 2;
		}
		else
			next = current * 2;

		if (heap[next].dist < heap[current].dist) {

			struct heapunit temp = heap[current];
			heap[current] = heap[next];
			heap[next] = temp;

			current = next;
		}
		else
			break;
	}
}

void vectorAdd(int start, int end, int weight) {

	struct unit* input = (struct unit*)malloc(sizeof(struct unit));
	input->to = end;
	input->weight = weight;

	input->link = head[start];
	head[start] = input;
}

void init(int v, int e, int k) {

	int malsize = v + 1;
	head = (struct unit**)malloc(sizeof(struct unit*) * (malsize));
	for (int i = 0; i <= v; i++){
		head[i] = NULL;
	}

	int start, end, weight;
	for (int i = 0; i < e; i++) {

		scanf("%d %d %d", &start, &end, &weight);

		vectorAdd(start, end, weight);
	}
}

void dijk(int v, int e, int k) {

	for (int i = 1; i <= v; i++) {
		distTable[i] = inf;
	}
	distTable[k] = 0;

	struct heapunit fire;
	fire.dist = 0;
	fire.node = k;

	heapPush(fire);

	while (!heapEmpty()) {

		struct heapunit current = heapFront();
		heapPop();

		if (visitTable[current.node] == 1)
			continue;
		visitTable[current.node] = 1;

		struct unit* next = head[current.node];

		while (next != NULL) {

			int nextnode = next->to;
			int nextweight = next->weight;

			if (visitTable[nextnode] == 0 && distTable[nextnode] > distTable[current.node] + nextweight) {
				distTable[nextnode] = distTable[current.node] + nextweight;
				
				struct heapunit heapnext;
				heapnext.dist = distTable[nextnode];
				heapnext.node = nextnode;

				heapPush(heapnext);
			}

			next = next->link;
		}

	}

}

int main() {


	int v, e, k;
	scanf("%d %d %d", &v, &e, &k);

	init(v, e, k);

	dijk(v,e,k);

	for (int i = 1; i <= v; i++) {
		if (distTable[i] == inf)
			printf("INF\n");
		else
			printf("%d\n", distTable[i]);
	}


}
