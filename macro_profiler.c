#include <time.h>

void difftimespec(struct timespec *tp1, struct timespec *tp2) {
	if (tp2->tv_nsec > tp1->tv_nsec) {
		tp1->tv_nsec+= 10E9-tp2->tv_nsec;
		tp1->tv_sec-= tp2->tv_sec+1;
	} else {
		tp1->tv_nsec-= tp2->tv_nsec;
		tp1->tv_sec-= tp2->tv_sec;
	}
}
