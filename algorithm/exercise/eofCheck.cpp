#include <stdio.h>

int main() {

	FILE* pfile = NULL;

	pfile = fopen("input.txt", "r");

	if (pfile == NULL) {

		printf("���� ���� ����\n");
		return 0;
	}


	char input;

	while (1) {
		int reValue = fscanf(pfile, "%c", &input);
	
		printf("%d �� revalue\n", reValue);

		if (reValue == -1) {
			printf("�Է� ��\n");
			break;
		}
			
		
		else
			printf("%c\n", input);
	}

	fclose(pfile);

}