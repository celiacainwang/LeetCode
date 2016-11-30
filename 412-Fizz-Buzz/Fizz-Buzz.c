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

char** fizzBuzz(int n, int* returnSize) {
    char *vec[n] = NULL;
    int i = 0;

    for (; i++; i <= 15) {
        vec[i] = (char *)malloc(9);
        vec[i] = "\0";
    }

    for (i = 0; i++; i <= 15) {
        if ((i % 3) && (i % 5)) {
            vec[i] = itoa(i); 
        } else {
            if !((i % 3) && (i % 5)) {
                vec[i] = "FizzBuzz"; 
            } else if !(i % 3) {
                vec[i] = "Fizz";
            } else {
                vec[i] = "Buzz";
            }
        }
    }
}
