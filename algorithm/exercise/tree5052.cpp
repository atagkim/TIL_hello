#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

char input[10010][15];
string input2[10010];

bool compare(string a, string b) {
	return a < b;
}

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int n;
		scanf("%d", &n);
		
		for(int i=0;i<n;i++){
			
			scanf("%s", input[i]);
			input2[i] = input[i];
		}
		sort(input2, input2 + n, compare);

		int flag = 1;
		for (int i = 0; i < n - 1; i++) {
			if (input2[i + 1].find(input2[i]) == 0) {
				flag = 0;
				strcmp(input2[i].c_str(), input2[i + 1].c_str());
				break;
			}
		}

		if (flag == 0)
			printf("NO\n");
		else
			printf("YES\n");

	}
}