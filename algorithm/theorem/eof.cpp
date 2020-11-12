#include <stdio.h>

int main() {

	char input;

	while (1) {
		
		int revalue = scanf("%c", &input);

		if (revalue == -1) {
			printf("print: end\n");
			break;
		}
		else
			printf("print: %c\n", input);
	}

}