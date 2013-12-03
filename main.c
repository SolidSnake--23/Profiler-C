#include <stdio.h>
#include "macro_profiler.h"

unsigned long int fibo(int n) {
	PROFILE
	unsigned long int r;
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	r = fibo(n-1)+fibo(n-2);
	return r;
}

int main(int argc, const char *argv[]) {
	PROFILE
	printf("%ld\n", fibo(10));
	return 0;
}
