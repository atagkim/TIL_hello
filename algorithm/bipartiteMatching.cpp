#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	vector< vector<int> > jobTable;
	int n, m, jobNum, inputBuf, solutionCount = 0;
	int jobCheckList[1010] = { 0, };

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {

		vector<int> jobBuf;
	
		scanf("%d", &jobNum);
		jobBuf.push_back(jobNum);
		
		for (int j = 0; j < jobNum; j++) {
			scanf("%d", &inputBuf);
			jobBuf.push_back(inputBuf);
		}
		
		jobTable.push_back(jobBuf);

	}

	sort(jobTable.begin(), jobTable.end());

	for (int i = 0; i < n; i++) {
		for (int j = 1; j < jobTable[i].size(); j++) {

			if (jobCheckList[jobTable[i][j]] == 0) {
				jobCheckList[jobTable[i][j]] = 1;
				solutionCount++;
				break;
			}
		}
	}

	printf("%d", solutionCount);


}