#include <stdio.h>
#include <queue>
#pragma warning(disable:4996)

using namespace std;


typedef struct stt {
	int location;
	int length;
};

int table[100010];
queue<stt> qqu;

void bfs(int target) {

	while (!qqu.empty()) {

		stt current = qqu.front();
		qqu.pop();

		if (current.location < 0 || current.location > 100000) continue;

		if (table[current.location] != 0) continue;
		table[current.location] = 1;

		if (current.location == target) {
			printf("%d", current.length);
			break;
		}

		if (current.location * 2 <= 100000 && table[current.location * 2] == 0) {
			stt next;
			next.location = current.location * 2;
			next.length = current.length + 1;
			
			qqu.push(next);
		}

		if (current.location - 1 >= 0 && table[current.location - 1] == 0) {
			stt next;
			next.location = current.location - 1;
			next.length = current.length + 1;

			qqu.push(next);
		}

		if (current.location + 1 <= 100000 && table[current.location + 1] == 0) {
			stt next;
			next.location = current.location + 1;
			next.length = current.length + 1;

			qqu.push(next);
		}
	}
}

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	stt start;
	start.length = 0;
	start.location = n;

	qqu.push(start);
	
	bfs(m);
}

