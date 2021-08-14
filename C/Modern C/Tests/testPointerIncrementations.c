#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	char* p; //string
	*p = "a"; //string = "a"
	*(++p) = "b"; //string = "b"
	*(p++) = "c"; //string = "b" (and we put "c" at previous memory address)
	*(p + 2) = "c";
	p++;    // use it then move to next int position
	++p;    // move to next int and then use it
	int a = ++(*p); // increments the value by 1 then use it 
	*p++;   // use the value of p then moves to next position
	(*p)++; // use the value of p then increment the value
	*(p)++; // use the value of p then moves to next position
	*++p;   // moves to the next int location then use that value
	*(++p); // moves to next location then use that value
	return 0;
}