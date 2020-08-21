#include <stdio.h>
#include <vector>
using namespace std;

vector<vector<int>> jobTable;
int jobCheckTable[1010];
int nodeCheckTable[1010];
int solutionCount;

int jobDFS(int oldOne, int newOne, int jobTarget) {

	nodeCheckTable[oldOne] = 1;

	for (int i = 0; i < jobTable[oldOne].size(); i++) {
		
		if (jobCheckTable[jobTable[oldOne][i]] == 0) {
			jobCheckTable[jobTable[oldOne][i]] = oldOne;
			jobCheckTable[jobTarget] = newOne;
			solutionCount++;

			return 1;
		}
	}

	for (int i = 0; i < jobTable[oldOne].size(); i++) {

		int dfsTarget = jobCheckTable[jobTable[oldOne][i]];
		if (nodeCheckTable[dfsTarget] == 0) {
			if (jobDFS(dfsTarget, oldOne, jobTable[oldOne][i]) == 1) {
				jobCheckTable[jobTable[oldOne][i]] = newOne;
				
				return 1;
			}
		}

	}
	return -1;
	

}


int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	vector<int> deleteZero;
	jobTable.push_back(deleteZero);

	int eachJobNum, inputBuf;
	for (int i = 0; i < n; i++) {

		vector<int> person;
		
		scanf("%d", &eachJobNum);
		for (int j = 0; j < eachJobNum; j++) {
			scanf("%d", &inputBuf);

			person.push_back(inputBuf);
		}
		jobTable.push_back(person);
	}

	
	int currentJob, nodeFlag = 0;
	for (int i = 1; i <= n; i++) {
		
		for (int j = 0; j < jobTable[i].size(); j++) {

			if (jobCheckTable[jobTable[i][j]] == 0) {
				jobCheckTable[jobTable[i][j]] = i;
				solutionCount++;
				nodeFlag = 1;
				break;
			}
		}
		if (nodeFlag == 1) {
			nodeFlag = 0;
			continue;
		}


		for (int j = 1; j <= n; j++) {
			nodeCheckTable[j] = 0;
		}

		for (int j = 0; j < jobTable[i].size(); j++) {

			int dfsTarget = jobCheckTable[jobTable[i][j]];
			if (nodeCheckTable[dfsTarget] == 0) {
				if (jobDFS(dfsTarget, i, jobTable[i][j]) == 1) break;
			}
		}

	}

	printf("%d", solutionCount);
}