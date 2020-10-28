#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	printf("argc: %d\n",argc);
	for (size_t i = 0; i < argc; i++) {
		printf("argv[%d]: %s\n",i,argv[i]);
	}
	return 0;
}