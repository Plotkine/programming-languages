#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	printf("++i\n");
	for (size_t i = 0; i < 5; ++i) { //note that ++i is equivalent in i++ in this case
    printf("%d\n",i);
	}
	
	printf("i++\n");
	for (size_t i = 0; i < 5; i++) { //note that ++i is equivalent in i++ in this case
    printf("%d\n",i);
	}
}