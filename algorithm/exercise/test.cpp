#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct compare {
	bool operator()(int a, int b) {
		if (a > b)
			return 1;
		else
			return 0;
	}
};

priority_queue<int, vector<int>, compare> pq;

int main() {


	pq.push(0);
	pq.push(0);
	pq.push(0);

	printf("%d", pq.top());


}