#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct unit {
	int value;
};

bool cmp(unit a, unit b) {
	return a.value <  b.value;
}

vector<unit> table;

int main() {

	unit temp;

	temp.value = 5;
	table.push_back(temp);
	temp.value = 2;
	table.push_back(temp);
	temp.value = 7;
	table.push_back(temp);
	temp.value = 4;
	table.push_back(temp);

	sort(table.begin(), table.end(), cmp);
	printf("%d", table[0]);

}