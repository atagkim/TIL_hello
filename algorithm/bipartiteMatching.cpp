#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector< vector<int> > jobTable;
int jobCheckTable[1010];
int solutionCount;


void dfsMatching(int peopleNum, int totalJob, int currentPeople, int currentJob) {

	if (currentPeople >= peopleNum) {
		if (solutionCount < currentJob) {
			solutionCount = currentJob;
		}
		return;
	}

	for (int i = 1; i < jobTable[currentPeople].size(); i++) {
		
		if (jobCheckTable[jobTable[currentPeople][i]] == 0) {
			jobCheckTable[jobTable[currentPeople][i]] = 1;
			dfsMatching(peopleNum, totalJob, currentPeople + 1, currentJob + 1);
			jobCheckTable[jobTable[currentPeople][i]] = 0;
		}

	}

	dfsMatching(peopleNum, totalJob, currentPeople + 1, currentJob);

}


int main() {

	int n, m, inputBuf, inputBuf2;
	int jobCheckList[1010] = { 0, };

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {

		vector<int> jobBuf;
	
		scanf("%d", &inputBuf);
		jobBuf.push_back(inputBuf);

		for (int j = 0; j < inputBuf; j++) {
			scanf("%d", &inputBuf2);
			jobBuf.push_back(inputBuf2);
		}
		
		jobTable.push_back(jobBuf);

	}

	sort(jobTable.begin(), jobTable.end());


	dfsMatching(n, m, 0, 0);

	printf("%d", solutionCount);


}