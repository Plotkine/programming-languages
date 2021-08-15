#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
for (size_t i = 10; i; i--) { //prints numbers from 10 to 1
    printf("%zu\n", i);        //since "i" is true iff i != 0

};
}