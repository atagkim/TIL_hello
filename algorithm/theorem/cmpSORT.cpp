#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;


// sort function in algorithm should be in strict weak ordering
// don't make = and > on true together
// if make = on true, > and < should be false!!

bool compare(vector<int> a, vector<int> b) {

	// if(a[0] >= b[0]) return 1;  =>  error!!!!!
	if (a[0] > b[0])
		return 1;
	
	else
		return 0;
}

struct unit {
	int value;
};

bool compare2(unit a, unit b) {
	if (a.value < b.value)
		return 1;
	else
		return 0;
}


int main() {

	vector<vector<int>> test;

	vector<int> input;
	input.push_back(1);

	vector<int> input2;
	input2.push_back(2);

	test.push_back(input);
	test.push_back(input2);

	sort(test.begin(), test.end(), compare);

	printf("2 = %d\n", test[0][0]);


	unit test2[10];
	test2[0].value = 1;
	test2[1].value = 2;

	sort(test2, test2+2, compare2);
	printf("2 = %d", test2[1].value);

}