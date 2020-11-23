#include <iostream>
#include <vector>
using namespace std;

int main() {

	vector<vector<int>> table;
	
	vector<int> input;

	input.push_back(2);

	for (int i = 0; i < 2; i++) {
		table.push_back(input);
	}
	table[0][0] = 3;
	for (int i = 0; i < 2; i++) {
		printf("%d\n", table[i][0]);
	}

}