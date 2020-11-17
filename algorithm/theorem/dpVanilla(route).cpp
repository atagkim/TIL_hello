#include <iostream>
using namespace std;

#define HEIGHT 5

int route[55];
int parentTable[50][50];

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
	int myparent, maxidx;

	dpTable[0][0] = inputTable[0][0];

	for (int i = 1; i < HEIGHT; i++) {

		parentwidth = i - 1 + 1;
		for (int j = 0; j <= i; j++) {
			
			leftparent = j - 1;
			rightparent = j;
			current = inputTable[i][j];

			if (leftparent >= 0 && leftparent < parentwidth) {
				if (dpTable[i][j] < current + dpTable[i - 1][leftparent]) {
					dpTable[i][j] = current + dpTable[i - 1][leftparent];
					
					myparent = leftparent;
				}
			}
			if (rightparent >= 0 && rightparent < parentwidth) {
				if (dpTable[i][j] < current + dpTable[i - 1][rightparent]) {
					dpTable[i][j] = current + dpTable[i - 1][rightparent];
					
					myparent = rightparent;
				}
			}

			parentTable[i][j] = myparent;
		}
	}
	for (int i = 0; i < HEIGHT - 1 + 1; i++) {
		if (max < dpTable[HEIGHT - 1][i]) {
			max = dpTable[HEIGHT - 1][i];

			maxidx = i;
		}
	}

	route[HEIGHT - 1] = maxidx;
	for (int i = HEIGHT - 2; i >= 0; i--) {
		route[i] = parentTable[i + 1][route[i + 1]] ;
	}

	printf("route is...\n");
	for (int i = 0; i < HEIGHT; i++) {
		printf("\t%d %d\n", i, route[i]);
	}
	
	printf("\nmax = %d\n", max);
	
	return 0;
}