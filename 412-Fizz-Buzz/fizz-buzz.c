/*
 * Write a program that outputs the string representation of numbers
 * from 1 to n.
 *
 * But for multiples of three it should output "Fizz" instead of the
 * and for the multiples of five output "Buzz". For numbers which are
 * multiples of both three and five output "FizzBuzz".
 *
 * Example:
 * n = 15,
 *
 * Return:
 * [
 *      "1",
 *      "2",
 *      "Fizz",
 *      "4"，
 *      "Buzz",
 *      "Fizz",
 *      "7",
 *      "8",
 *      "Fizz",
 *      "Buzz",
 *      "11",
 *      "Fizz",
 *      "13",
 *      "14",
 *      "FizzBuzz"
 * */


/**
 *
 *  * Return an array of size *returnSize.
 *
 *   * Note: The returned array must be malloced, assume caller calls free().
 *
 *    */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#if 0
char **fizz_buzz(int n, int *returnSize)
{
    char **vec = NULL;
    char buf[50];
    int i;

    vec = (char **)malloc(n * sizeof(char *));
    if (vec == NULL)
        return NULL;

    *returnSize = n;

    for (i = 1; i <= n; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            vec[i - 1] = strdup("FizzBuzz");
        } else if (i % 3 == 0) {
            vec[i - 1] = strdup("Fizz");
        } else if (i % 5 == 0) {
            vec[i - 1] = strdup("Buzz");
        } else {
            snprintf(buf, sizeof(buf) - 1, "%d", i);
            vec[i - 1] = strdup(buf);
        }

        if (vec[i - 1] == NULL) {
            for (i -= 1; i >= 1; i--)
                free(vec[i - 1]);
            free(vec);
            return NULL;
        }
    }

    return vec;
}
#else
char** fizz_buzz(int n, int* returnSize) {
    int i;
    char **vec = NULL;
    char buf[5];

    vec = (char **)malloc(sizeof(char *) * n);

    for (i = 1; i <= n; i++) {
        if ((i % 3 != 0) && (i % 5 != 0)) {
            snprintf(buf, sizeof(buf) - 1, "%d", i);
            vec[i - 1] = strdup(buf);
        } else if (i % 3 == 0) {
            if (i % 5 == 0) {
                vec[i - 1] = strdup("FizzBuzz");
            } else {
                vec[i - 1] = strdup("Fizz");
            }
        } else {
            vec[i - 1] = strdup("Buzz");
        }
    }
    *returnSize = n;

    return vec;
}
#endif

int main(int argc, char *argv[])
{
    char **vec = NULL;
    int returnSize = 0, i;

    vec = fizz_buzz(15, &returnSize);
    if (vec) {
        for (i = 0; i < returnSize; i++) {
            printf("%s\n", vec[i]);
            free(vec[i]);
        }

        free(vec);
    }

    return 0;
}
