#include <stdio.h>

int main() {

	FILE* pfile = NULL;

	pfile = fopen("input.txt", "r");

	if (pfile == NULL) {

		printf("파일 오픈 실패\n");
		return 0;
	}


	char input;

	while (1) {
		int reValue = fscanf(pfile, "%c", &input);
	
		printf("%d 가 revalue\n", reValue);

		if (reValue == -1) {
			printf("입력 끝\n");
			break;
		}
			
		
		else
			printf("%c\n", input);
	}

	fclose(pfile);

}