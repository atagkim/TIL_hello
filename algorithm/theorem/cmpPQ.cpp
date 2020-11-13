#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct unit {
	int node;
	int value;
};

struct cmp {
	bool operator()(unit a, unit b) {
		if (a.value > b.value)
			return 1;
		else
			return 0;
	}
};

priority_queue<unit, vector<unit>, cmp> pq;

int main() {

	unit input;
	input.node = 1;
	input.value = 10;
	pq.push(input);

	input.node = 2;
	input.value = 20;
	pq.push(input);

	printf("%d", pq.top().node);

}


