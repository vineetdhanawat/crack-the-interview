/*
	Write a C program to round a floating point number.
*/

#include <stdio.h>

int main() {
    float num = 4.45;
    int n = (int)(num < 0 ? (num - 0.5) : (num + 0.5));
    printf("%d\n", n);
}