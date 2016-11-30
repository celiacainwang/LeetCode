/*
 * Write a function that takes a string as input and returns the string reversed.
 *
 * Example:
 * Given s = "hello", return "olleh". 
 */

#include <stdio.h>
#include <string.h>

char* reverseString(char* s) {
	int i;
	char temp;

	for (i = 0; i < (strlen(s) / 2); i++) {
		temp = s[i];
		s[i] = s[strlen(s) - 1 - i];
		s[strlen(s) - 1 - i] = temp;
	}

	return s;
}

int main(int argc, char *argv[]) {
	char str[] = "hello";

	printf("%s\n", reverseString(str));
	return 0;
}
