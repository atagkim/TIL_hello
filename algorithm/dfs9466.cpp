#include <stdio.h>
#include <stack>
using namespace std;

int inputTable[100100];
int visitTable[100100];
int checkFlag, grouped;

stack<int> stt;

void init(int n) {
	for (int i = 1; i <= n; i++) {
		scanf("%d", &inputTable[i]);
	}
}

void initVisit(int n) {
	for (int i = 1; i <= n; i++) {
		visitTable[i] = 0;
	}
}

void dfs(int goal, int current, int n) {


	while (1) {

		visitTable[current] = 1;
		stt.push(current);

		if (goal == inputTable[current]) {
			grouped = grouped + stt.size();

			break;
		}

		if (visitTable[inputTable[current]] == 0) {
			current = inputTable[current];
		}
		else {
			
			int sttCurrent;
			while (!stt.empty()) {
				sttCurrent = stt.top();
				stt.pop();

				visitTable[sttCurrent] = 0;
			}

			break;
		}

	}

}

void initStt() {
	while (!stt.empty()) {
		stt.pop();
	}
}

int main() {

	int t;
	scanf("%d", &t);
	while (t--) {

		int n;
		scanf("%d", &n);
		
		init(n);
		initVisit(n);
		grouped = 0;
		
		for (int i = 1; i <= n; i++) {	
			checkFlag = 0;
			initStt();

			dfs(i, i, n);
		}
		printf("%d\n", n - grouped);
	}
}