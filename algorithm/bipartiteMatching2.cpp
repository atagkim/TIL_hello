#include <stdio.h>

int jobTable[1010][1010];
int checkJob[1010], checkPerson[1010];
int solutionCount;

int checkVisited[1010];

void initCheckVisited(int n) {

	for (int i = 1; i <= n; i++) {
		checkVisited[i] = 0;
	}
}

void init(int n, int m) {

	for (int i = 1; i <= n; i++) {
		scanf("%d", &jobTable[i][0]);

		for (int j = 1; j <= jobTable[i][0]; j++) {
			scanf("%d", &jobTable[i][j]);
		}
	}
}

int dfsJob(int targetJob, int oldOne, int newOne, int newOneIndex) {

	if (checkVisited[oldOne] == 1) return -1;
	checkVisited[oldOne] = 1;

	for (int j = 1; j <= jobTable[oldOne][0]; j++) {

		int currentJob = jobTable[oldOne][j];
	
		if (checkJob[currentJob] == 0) {
			checkJob[currentJob] = oldOne;
			solutionCount++;

			return 1;
		}
	}

	for (int j = 1; j <= jobTable[oldOne][0]; j++) {

		int currentJob = jobTable[oldOne][j];
		if (currentJob == targetJob) continue;

		if (dfsJob(currentJob, checkJob[currentJob], oldOne, j) == 1) {
			checkJob[currentJob] = oldOne;

			return 1;
		}
	}

}

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	init(n, m);

	for (int i = 1; i <= n; i++) {
		
		for (int j = 1; j <= jobTable[i][0]; j++) {

			initCheckVisited(n);

			int currentJob = jobTable[i][j];
			if (checkJob[currentJob] == 0) {
				checkJob[currentJob] = i;
				checkPerson[i]++;

				solutionCount++;

				if (checkPerson[i] >= 2) break;
			}

		}

		if (checkPerson[i] < 2 && jobTable[i][0] >= 2) {

			for (int j = 1; j <= jobTable[i][0]; j++) {

				int currentJob = jobTable[i][j];
				if (dfsJob(currentJob, checkJob[currentJob], i, j) == 1) {
					checkJob[currentJob] = i;
					checkPerson[i]++;

					if (checkPerson[i] >= 2) break;
				}
			}

		}
	}

	printf("%d", solutionCount);

}

//bj 11376
