#include <iostream>
#include <vector>
using namespace std;

#define INPUTSIZE 4
#define KSIZE 3

//1,2,3,4로 만들 수 있는 k자리 수열의 경우의 수. (비복원추출)
int input[INPUTSIZE] = { 1,2,3,4 };
bool visitTable[INPUTSIZE + 1]; // 0 base, 1 base 늘 체크

int buf[KSIZE];

void dfs(int idx) {

	int current;

	if (idx >= KSIZE) {
		for (int i = 0; i < KSIZE; i++) {
			printf("%d", buf[i]);
		}
		printf("\n");
		
		return;
	}

	for (int i = 0; i < INPUTSIZE; i++) {
		current = input[i];

		if (visitTable[current] == 0) {

			buf[idx] = current;
			visitTable[current] = 1;

			dfs(idx + 1);
			visitTable[current] = 0;
		}
	}
	
	return;
}

int main() {

	dfs(0);
}