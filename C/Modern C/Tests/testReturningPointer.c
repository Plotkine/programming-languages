#include <stdlib.h>
#include <stdio.h>

int* mergeSort(int* array) {
	printf("%p",&array);
}

int main(int argc, char* argv[]) {
	int* argument;
	int* variable = mergeSort(argument);
	return 0;
}