#ifndef _SEARCH_ALGOS_H_
#define _SEARCH_ALGOS_H_

#include <stdio.h>
#include <stdlib.h>

int advanced_binary(int *array, size_t size, int value);
int recursive_advanced_binary(int *array, int left, int right, int value);
void print_array(int *array, int left, int right);

#endif