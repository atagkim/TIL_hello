#include <stdio.h>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> minHeap;
priority_queue<int> maxHeap;

int main() {

	
	int n, t;
	scanf("%d", &n);
	t = n;

	int input;
	while (t--) {
		scanf("%d", &input);
		
		if (maxHeap.size() == minHeap.size()) {
			maxHeap.push(input);
		}
		else {
			minHeap.push(input);
		}

		if (maxHeap.size() != 0 && minHeap.size() != 0 && maxHeap.top() > minHeap.top()) {
			int maxtop = maxHeap.top();
			maxHeap.pop();

			int mintop = minHeap.top();
			minHeap.pop();

			maxHeap.push(mintop);
			minHeap.push(maxtop);
		}
		
		printf("%d\n", maxHeap.top());
	}

}