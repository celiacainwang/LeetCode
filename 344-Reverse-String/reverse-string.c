/*
 * Write a function that takes a string as input and returns the string reversed.
 *
 * Example:
 * Given s = "hello", return "olleh". 
 */

#include <stdio.h>
#include <string.h>

char* reverseString(char* s) {
	char temp;
    int reverse_times = strlen(s) / 2;
    int reverse_superscript = strlen(s) - 1;
	int i;

	for (i = 0; i < reverse_times; i++) {
		temp = s[i];
		s[i] = s[reverse_superscript - i];
		s[reverse_superscript - i] = temp;
	}

	return s;
}

int main(int argc, char *argv[]) {
	char str[] = "hello";

	printf("%s\n", reverseString(str));
	return 0;
}
