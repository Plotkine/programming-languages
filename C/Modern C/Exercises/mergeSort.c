/*
gcc mergeSort.c -o mergeSort

LESSONS LEARNED
Beware of loops going backward since if a size_t is 0 and we decrement it by 1, it becomes the max possible size_t
(see end of "mergeSort" function)

OPTIMIZATION
See if we should use arrays instead of pointers
*/

#include <stdlib.h>
#include <stdio.h>

void draw(size_t startX, size_t endX, size_t startO, size_t endO, size_t len) {
	size_t i;
	for (i = 0; i < len; i++) {
		if ((i >= startX) && (i <= endX)) {
			printf("X");
		}
		else if ((i >= startO) && (i <= endO)) {
			printf("O");
		}
		else {
			printf("-");
		}
	}
	printf("\n");
}

void mergeSort(size_t* array, size_t low, size_t high, size_t totalSize) { //total_size is just for drawing
	size_t len = high - low + 1;
	size_t mid = (high + low)/2;
	if (len >= 2) {
		//dividing
		mergeSort(array, low, mid, totalSize);
		mergeSort(array, mid + 1, high, totalSize);
	
		//merging: we insert the elements of the second block inside the first one
		//(length of first block is always >=)
		printf("merging: ");
		draw(low, mid, mid + 1, high, totalSize);
		size_t secondBlockLength = high - (mid + 1) + 1; //high index - low index + 1
		size_t i;
		for (i = 0; i < secondBlockLength; i++) { //iterating over second block
			size_t elemIndex = (mid + 1) + i; //index of the element to be inserted in the array
			size_t insertIndex = low;
			while (*(array + elemIndex) > *(array + insertIndex)) { //iterating over first block to know where to insert
				insertIndex++;
			}
			//inserting i^th element of second block at insertIndex
			size_t temp = *(array + elemIndex);
			size_t k;
			for (k = elemIndex - 1; (k >= insertIndex) && (k <= elemIndex - 1); k--)  { //offsetting the whole portion [insert index, index of element to move - 1] by +1
			//WARNING: if insertIndex = 0, since k is a size_t, we're screwed since k-1 = infinite when k = 0.
			//If we declare k as an int it apparently doesn't work neither
			//So that's why we verify that (k <= elemIndex - 1) in the stop condition of the for loop
				*(array + k + 1) = *(array + k);
			}
			*(array + insertIndex) = temp; //we insert our element
		}
	}
}

int main(int argc, char* argv[]) {
	size_t len = argc - 1;
	size_t array[len];
	size_t i;
	for (i = 0; i < len; i++) {
		array[i] = strtol(argv[i + 1], NULL, 10);
		/* we could error check here like explained here: https://stackoverflow.com/questions/9748393/how-can-i-get-argv-as-int/38669018*/
	}
	printf("\n");
	mergeSort(array, 0, len - 1, len);
	printf("\n");
	printf("RESULT: ");
	for (i = 0; i < len; i++) {
		printf("%zu ",*(array + i)); //%zu is for size_t variables
	}
	printf("\n");
	return 0;
}