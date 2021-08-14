#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
char* p;
*p = 'a';
printf("address pointed by p: 0x%p\n", &p);
printf("char value at &p: %c\n", *p); //"a"
printf("string value pointed by p: %s\n", *p); //ILLEGAL!!!
}