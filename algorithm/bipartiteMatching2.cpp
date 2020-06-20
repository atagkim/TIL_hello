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

	if (checkPerson[oldOne] == 2 || checkVisited[oldOne] == 1) return -1;

	for (int i = 0; i < jobTable[oldOne].size(); i++) {
		if (checkJob[jobTable[oldOne][i]] == 0) {
			checkJob[jobTable[oldOne][i]] = oldOne;
			checkPerson[oldOne]++;
			checkJob[targetJob] = newOne;
			checkPerson[newOne]++;

			solutionCount++;
			
			if (checkPerson[newOne] == 2 || checkPerson[oldOne] == 2) return 1;
		}
	}

	for (int i = 0; i < jobTable[oldOne].size(); i++) {
		
		if (checkPerson[jobTable[oldOne][i]] != 2 || checkVisited[jobTable[oldOne][i]] != 1) {
			if (dfsJob(jobTable[oldOne][i], checkJob[jobTable[oldOne][i]], oldOne, i) == 1) {
				checkJob[targetJob] = newOne;
				checkPerson[newOne]++;

				if (checkPerson[newOne] == 2 || checkPerson[oldOne] == 2) return 1;
			}

		}
		
	}
	
}

int main() {

	int n, m;
	scanf("%d %d", &n, &m);
	
	init(n, m);


	for (int i = 1; i <= n; i++) {		
		
		for (int j = 1; j <= n; j++) {
			checkVisited[j] = 0;
		}

		for (int j = 0; j < jobTable[i].size(); j++) {

			if (checkJob[jobTable[i][j]] == 0) {
				checkJob[jobTable[i][j]] = i;
				checkPerson[i]++;

				solutionCount++;

				if (checkPerson[i] == 2) break;
			}
			else {
				if (checkVisited[checkJob[jobTable[i][j]]] == 0 && checkPerson[checkJob[jobTable[i][j]]] != 2) {
					checkVisited[checkJob[jobTable[i][j]]] = 1;
					
					if (dfsJob(jobTable[i][j], checkJob[jobTable[i][j]], i, j) == 1) {

						if (checkPerson[i] == 2) break;
					}
					else {

					}
				}
			}
		}
	}	
	printf("%d", solutionCount);

}

