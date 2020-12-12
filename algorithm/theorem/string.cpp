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


	// string 인덱스 접근
	string e = "abcd";

	cout << "string 인덱스 접근: ";
	for (int i = 0; i < e.size(); i++) {
		printf("%c", e[i]);
	}
	printf("\n");


	// string의 strcmp
	string f = "aaaa";
	string g = "bbbb";

	printf("compare = %d\n",f.compare(g));


	// string의 strcpy
	string h = "aaaa";
	string i;

	i = h;
	cout << "strcpy 결과 = " << i << '\n';


	// string의 strcat
	string j = "aa";
	string k = "bb";

	j += k;
	cout << "strcat 결과 = " << j << '\n';


}