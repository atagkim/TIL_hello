#include <stdio.h>
#include <queue>
#pragma warning(disable:4996)

using namespace std;

struct unit {
	int vertex;
	int value;
};

struct cmp {
	bool operator()(unit A, unit B) {
		return A.value > B.value;
	}
};

struct busUnit {
	int start;
	int end;
	int value;
};

priority_queue<unit, vector<unit>, cmp> pq;

vector<vector<busUnit>> busTable;
int distTable[110][110];
bool checkList[110];

void init(int n, int m) {

	vector<busUnit> forInit;
	for (int i = 0; i <= n; i++) {
		busTable.push_back(forInit);
	}

	int start, end, value;
	for (int i = 1; i <= m; i++) {

		scanf("%d %d %d", &start, &end, &value);
		busUnit input;
		input.start = start;
		input.end = end;
		input.value = value;

		busTable[start].push_back(input);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) distTable[i][j] = 0;
			else distTable[i][j] = 987654321;
		}
	}
}

void initCheckList(int n) {
	for (int i = 1; i <= n; i++) {
		checkList[i] = 0;
	}
}

void findPath(int n, int m, int startVertex) {

	unit startUnit;
	startUnit.vertex = startVertex;
	startUnit.value = 0;

	pq.push(startUnit);

	while (!pq.empty()) {

		unit current;
		current = pq.top();
		pq.pop();

		if (checkList[current.vertex] == 1) continue;
		checkList[current.vertex] = 1;

		for (int i = 0; i < busTable[current.vertex].size(); i++) {
			int start = busTable[current.vertex][i].start;
			int end = busTable[current.vertex][i].end;
			int value = busTable[current.vertex][i].value;

			if (distTable[startVertex][end] > distTable[startVertex][start] + value) {
				distTable[startVertex][end] = distTable[startVertex][start] + value;
				unit next;
				next.vertex = end;
				next.value = distTable[startVertex][end];

				if(checkList[end] == 0)	pq.push(next);
			}
		}
	}

}

int main() {

	int n, m;
	scanf("%d %d", &n, &m);
	init(n, m);

	for (int i = 1; i <= n; i++) {
		initCheckList(n);
		findPath(n, m, i);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (distTable[i][j] == 987654321) distTable[i][j] = 0;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", distTable[i][j]);
		}printf("\n");
	}
}