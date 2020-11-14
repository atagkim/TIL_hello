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

}