#include <iostream>
#include <string.h>
using namespace std;

int main() {

	// string => char
	string a = "stringtype";
	
	char b[30];
	strcpy(b, a.c_str());

	printf("%s\n", b);


	// char => string
	char c[30];
	strcpy(c, "chartype");

	string d;
	d = c;

	cout << d << '\n';


	// string �ε��� ����
	string e = "abcd";

	cout << "string �ε��� ����: ";
	for (int i = 0; i < e.size(); i++) {
		printf("%c", e[i]);
	}
	printf("\n");


	// string�� strcmp
	string f = "aaaa";
	string g = "bbbb";

	printf("compare = %d\n",f.compare(g));


	// string�� strcpy
	string h = "aaaa";
	string i;

	i = h;
	cout << "strcpy ��� = " << i << '\n';


	// string�� strcat
	string j = "aa";
	string k = "bb";

	j += k;
	cout << "strcat ��� = " << j << '\n';


}