#include <iostream>
#include <vector>

using namespace std;

int planeTable[100100];
int gateTable[100100];
int findFlag, solution;

int findGate(int gate) {

	if (gateTable[gate] == -1) {
		return gate;
	}

	int parentGate = findGate(gateTable[gate]);
	gateTable[gate] = parentGate;

	return parentGate;
}

void merge(int a, int b) {

	int parentA = findGate(a);
	int parentB = findGate(b);
	
	if(parentA != parentB)
		gateTable[parentB] = parentA;

	return;
}

int main() {

	int g, p, plane, parentGate;
	scanf("%d %d", &g, &p);

	for (int i = 0; i <= g; i++) {
		gateTable[i] = -1;
	}

	for (int i = 0; i < p; i++) {
		scanf("%d", &planeTable[i]);
	}

	for (int i = 0; i < p; i++) {

		parentGate = findGate(planeTable[i]);

		if (parentGate == 0) 
			break;

		solution++;
		
		merge(parentGate - 1, parentGate);
	}

	printf("%d", solution);

}