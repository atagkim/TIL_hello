#include <stdio.h>
#include <vector>
using namespace std;

struct unit {
	int end;
	int value;
};

vector<unit> edgeTable[550];
int distTable[550][550];

int main() {

	int tc;
	scanf("%d", &tc);

	while (tc--) {

		int n, m, w;
		scanf("%d %d %d", &n, &m, &w);

		int start, end, value;
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &start, &end, &value);
			
			unit input;
			input.end = end;
			input.value = value;

			edgeTable[start].push_back(input);

			input.end = start;
			edgeTable[end].push_back(input);
		}
		for (int i = 0; i < w; i++) {
			scanf("%d %d %d", &start, &end, &value);

			unit input;
			input.end = end;
			input.value = value;

			edgeTable[start].push_back(input);
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				
				distTable[i][j] = 987654321;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < edgeTable[i].size(); j++) {
				distTable[i][j] = edgeTable[i][j].value;
			}
		}
		
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 0; j < edgeTable[i].size(); j++) {

					unit current = edgeTable[i][j];

					if(distTable[])

				}
			}
		}


	}

}