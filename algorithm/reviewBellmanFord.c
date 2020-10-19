#include <stdio.h>
#include <stdlib.h>

long long distTable[510];
int inf = 987654321;

struct unit {
	int to;
	int weight;
	struct unit* link;
};

struct unit** table;

void vectorPush(int start, int end, int weight) {

	struct unit* input = (struct unit*)malloc(sizeof(struct unit));

	input->to = end;
	input->weight = weight;
	
	input->link = table[start];
	table[start] = input;

}

void init(int n, int m) {

	int malsize = n + 1;
	table = (struct unit**)malloc(sizeof(struct unit*) * malsize);

	for (int i = 0; i <= n; i++) {
		table[i] = NULL;
	}

	int start, end, weight;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &start, &end, &weight);

		vectorPush(start, end, weight);
	}
	
}

void clear(int n, int m, int w) {

	for (int i = 0; i <= n; i++) {
		struct unit* next = table[i];
		struct unit* temp;
		while (next != NULL) {
			temp = next->link;
			free(next);
			next = temp;
		}
	}
	free(table);

}

int bellman(int n, int m) {

	for (int i = 2; i <= n; i++) {
		distTable[i] = inf;
	}
	distTable[1] = 0;


	int flag = 0;
	for (int i = 1; i <= n; i++) {
		
		for (int j = 1; j <= n; j++) {
			
			struct unit* current = table[j];
			while (current != NULL) {
				int currentto = current->to;
				int currentweight = current->weight;

				if (distTable[j] != inf && distTable[currentto] > distTable[j] + currentweight) {
					distTable[currentto] = distTable[j] + currentweight;
					
					if (i == n)
						flag = 1;
				}

				current = current->link;
			}

		}
	}

	return flag;
}

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	init(n, m);

	if (bellman(n, m) == 1) {

		printf("-1\n");
	}
	else {
		for (int i = 2; i <= n; i++) {
			if (distTable[i] == inf)
				printf("-1\n");
			else 
				printf("%lld\n", distTable[i]);
		}
	}

}