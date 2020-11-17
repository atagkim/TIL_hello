#include <iostream>
using namespace std;

#define HEIGHT 5

int inputTable[50][50] = { {7},{3,8},{8,1,0},{2,7,4,4},{4,5,2,6,5} };
//           7
//         3   8
//      8    1    0
//   2    7    4    4
// 4    5    2    6    5

int dpTable[50][50];

int main() {

	int max = 0;
	int leftparent, rightparent, current, parentwidth;

	dpTable[0][0] = inputTable[0][0];

	for (int i = 1; i < HEIGHT; i++) {

		parentwidth = i - 1 + 1;
		for (int j = 0; j <= i; j++) {
			
			leftparent = j - 1;
			rightparent = j;
			current = inputTable[i][j];

			if (leftparent >= 0 && leftparent < parentwidth) {
				if (dpTable[i][j] < current + dpTable[i - 1][leftparent])
					dpTable[i][j] = current + dpTable[i - 1][leftparent];
			}
			if (rightparent >= 0 && rightparent < parentwidth) {
				if (dpTable[i][j] < current + dpTable[i - 1][rightparent])
					dpTable[i][j] = current + dpTable[i - 1][rightparent];
			}
		}
	}
	for (int i = 0; i < HEIGHT - 1 + 1; i++) {
		if (max < dpTable[HEIGHT - 1][i])
			max = dpTable[HEIGHT - 1][i];
	}
	printf("max = %d\n", max);
	
	return 0;
}