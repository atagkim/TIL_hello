#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;


struct inputUnit {
	int end;
	int cost;
	int time;
};

struct pqUnit {
	int start;
	int cost;
	int time;
};
vector<inputUnit> inputTable[110];

struct cmp {
	bool operator()(pqUnit a, pqUnit b) {
		return a.cost > b.cost;
	}
};
priority_queue<pqUnit, vector<pqUnit>, cmp> pq;

int timeTable[110][10010];


void init(int n, int m, int k) {

	for (int i = 1; i <= k; i++) {
		
		int start;
		inputUnit input;
		scanf("%d %d %d %d",&start, &input.end, &input.cost, &input.time );

		inputTable[start].push_back(input);
	}

	for (int j = 0; j <= 10000; j++) {
		timeTable[1][j] = 0;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 10000; j++) {
			timeTable[i][j] = 987654321;
		}
	}

}

void free(int n, int m, int k) {

	for (int i = 1; i <= n; i++) {
		inputTable[i].clear();
	}
}

void dijk(int n, int m, int k) {

	pqUnit fire;
	fire.cost = 0;
	fire.start = 1;
	fire.time = 0;

	pq.push(fire);

	while (!pq.empty()) {

		pqUnit current = pq.top();
		int start = current.start;
		int cost = current.cost;
		int time = current.time;
		pq.pop();

		if (timeTable[start][cost] < time) {
			continue;
		}

		for (int i = 0; i < inputTable[start].size(); i++) {
			int end = inputTable[start][i].end;
			int costAdded = inputTable[start][i].cost;
			int timeAdded = inputTable[start][i].time;

			if (cost + costAdded > m) 
				continue;
			if (time + timeAdded < timeTable[end][cost + costAdded]) {
			
				for (int i = cost + costAdded; i <= m; i++) {
					if (timeTable[end][i] > time + timeAdded) {
						timeTable[end][i] = time + timeAdded;
					}
				}
		
				pqUnit next;
				next.start = end;
				next.cost = cost + costAdded;
				next.time = time + timeAdded;

				pq.push(next);
			}

		}
	}

}


int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);

		init(n, m, k);

		dijk(n, m, k);



		int solution = 987654321;
		for (int i = 1; i <= m; i++) {
			if (timeTable[n][i] < solution)
				solution = timeTable[n][i];
		}
		if (solution == 987654321) 
			printf("Poor KCM\n");
		else
			printf("%d\n", solution);

		free(n, m, k);

	}

}

