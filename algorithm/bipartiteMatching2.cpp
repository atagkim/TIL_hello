#include <stdio.h>
#include <vector>
using namespace std;

vector <vector <int>> jobTable;
int checkPerson[1010];
int checkJob[1010];
int checkVisited[1010];
int solutionCount;

void init(int n, int m) {

	vector<int> deleteZero;
	jobTable.push_back(deleteZero);

	int jobNum;
	for (int i = 1; i <= n; i++) {
		
		scanf("%d", &jobNum);

		int jobInput;
		vector<int> rowInput;
		for (int j = 0; j < jobNum; j++) {
			scanf("%d", &jobInput);
			rowInput.push_back(jobInput);
		}
		jobTable.push_back(rowInput);
	}

}

int dfsJob(int targetJob, int oldOne, int newOne, int newOneIndex) {

	if (checkVisited[oldOne] == 1) return -1;
	checkVisited[oldOne] = 1;

	for (int i = 0; i < jobTable[oldOne].size(); i++) {
		if (checkJob[jobTable[oldOne][i]] == 0) {
			checkJob[jobTable[oldOne][i]] = oldOne;
			if(checkPerson[oldOne] <= 1) checkPerson[oldOne]++;

			checkJob[targetJob] = newOne;
			if (checkPerson[newOne] <= 1) checkPerson[newOne]++;

			solutionCount++;

			return 1;
		}
	}

	for (int i = 0; i < jobTable[oldOne].size(); i++) {
		
		if (dfsJob(jobTable[oldOne][i], checkJob[jobTable[oldOne][i]], oldOne, i) == 1) {
			checkJob[targetJob] = newOne;
			if (checkPerson[newOne] <= 1) checkPerson[newOne]++;

			return 1;
		}
	}
	
}

void initVisited(int n) {

	for (int k = 1; k <= n; k++) {
		checkVisited[k] = 0;
	}
}

int main() {

	int n, m;
	scanf("%d %d", &n, &m);
	
	init(n, m);


	for (int i = 1; i <= n; i++) {		
		
		for (int j = 0; j < jobTable[i].size(); j++) {

			initVisited(n);

			if (checkJob[jobTable[i][j]] == 0) {
				checkJob[jobTable[i][j]] = i;
				checkPerson[i]++;

				solutionCount++;

				if (checkPerson[i] == 2) break;
			}
			else {
					
				if (dfsJob(jobTable[i][j], checkJob[jobTable[i][j]], i, j) == 1) {

					if (checkPerson[i] >= 2) break;
				}

			}
		}
	}	
	printf("%d", solutionCount);

}

