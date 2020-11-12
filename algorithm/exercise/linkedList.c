#include <stdio.h>
#include <stdlib.h>

struct unit {
	int end;
	int value;
	struct unit* link;
};

struct unit* inputTable[100];

void add(struct unit** whatTable, int start, int end, int value) {

	struct unit* current = (struct unit*)malloc(sizeof(struct unit));

	current->value = value;
	current->end = end;
	current->link = NULL;

	current->link = whatTable[start];
	whatTable[start] = current;
}

void init(int n, int m) {
	
	int start, end, value;
	for (int i = 1; i <= m; i++) {
		
		scanf("%d %d %d", &start, &end, &value);

		add(inputTable, start, end, value);

	}
}

void print(int n, int m) {

	for (int i = 1; i <= n; i++) {

		struct unit* current = inputTable[i];
		while (current != NULL) {
			printf("%d %d %d\n", i, current->end, current->value);
			current = current->link;
		}

	}

}

void removeList(int n, int m) {

	for (int i = 1; i <= n; i++) {
		struct unit* current = inputTable[i];
		struct unit* temp;
		while (current != NULL) {
			temp = current->link;
			free(current);
			
			current = temp;
		}
		inputTable[i] = NULL;
	}
}

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	init(n, m);

	print(n, m);

	removeList(n, m);

}

