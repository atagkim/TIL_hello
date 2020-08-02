#include <stdio.h>
#include <queue>
#pragma warning(disable:4996)

using namespace std;

struct unit {
	int start;
	int end;
	int cost;
	int value;
};

struct pqUnit {
	int start;
	int cost;
	int value;
};

struct cmp {
	bool operator()(pqUnit A, pqUnit B) {
		if (A.value == B.value) {
			return A.cost > B.cost;
		}
		else return A.value > B.value;
	}
};


priority_queue<pqUnit, vector<pqUnit>, cmp> pq;

vector<vector<unit>> edgeTable;

int distTable[110];
bool checkList[110];

void init(int vertex, int totalCost, int edge) {

	vector<unit> basis;
	for (int i = 0; i <= vertex; i++) {
		edgeTable.push_back(basis);
	}

	int start, end, cost, value;
	for (int i = 1; i <= edge; i++) {
		scanf("%d %d %d %d", &start, &end, &cost, &value);
		
		unit input;
		input.start = start;
		input.end = end;
		input.cost = cost;
		input.value = value;

		edgeTable[start].push_back(input);
	}

	distTable[1] = 0;
	for (int i = 2; i <= vertex; i++) {
		distTable[i] = 987654321;
	}

}

void findPath(int vertex, int totalCost, int edge) {

	pqUnit start;
	start.start = 1;
	start.value = 0;
	start.cost = 0;

	pq.push(start);

	while (!pq.empty()) {

		pqUnit current = pq.top();
		pq.pop();

		if (checkList[current.start] == 1) continue;
		checkList[current.start] = 0;



	}

}


int main() {

	int t;
	scanf("%d", &t);

	while (t--) {
		
		int vertex, totalCost, edge;
		scanf("%d %d %d", &vertex, &totalCost, &edge);

		init(vertex, totalCost, edge);

		findPath(vertex, totalCost, edge);

	}

}