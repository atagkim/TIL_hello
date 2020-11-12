#include <stdio.h>

long long table[100][3];

int main() {

	int n; 
	scanf("%d", &n);

	//0: �Ѱ���, 1: 0���� ������ ����

	table[1][0] = 1;
	table[1][1] = 0;

	for (int i = 2; i <= 90; i++) {
		table[i][0] = table[i - 1][0] + table[i - 1][1];
		table[i][1] = table[i - 1][0];
	}

	printf("%lld", table[n][0]);

}