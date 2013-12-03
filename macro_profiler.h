#ifndef __MACRO__PROFILAGE__
#define __MACRO__PROFILAGE__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <sys/time.h>

/* Between 1 and 9. */
#define PRECISION 9

#define CLK_ID CLOCK_REALTIME

#define FORMAT_START  "%%s -- time : %%ld.%%.%dlds\n"
#define FORMAT_END    "END -- time : %%ld.%%.%dlds\n"

long int precision;
struct timespec initial_time_profiler;
static FILE *file_profiler;
static char *formats_profiler[2];

#ifdef PROFILE_MODE
#define PROFILE \
struct timespec tp_profiler;\
if (strcmp(__FUNCTION__, "main") == 0) {\
	formats_profiler[0] = (char*)malloc(sizeof(char)*strlen(FORMAT_START));\
  assert(formats_profiler[0] != NULL);\
	formats_profiler[1] = (char*)malloc(sizeof(char)*strlen(FORMAT_START));\
  assert(formats_profiler[1] != NULL);\
	sprintf(formats_profiler[0], FORMAT_START, PRECISION);\
	sprintf(formats_profiler[1], FORMAT_END, PRECISION);\
	precision = pow(10, 9-PRECISION);\
	if ((file_profiler=fopen("profile.log", "w")) == NULL)\
		exit(EXIT_FAILURE);\
	clock_gettime(CLK_ID, &initial_time_profiler);\
}\
if (clock_gettime(CLK_ID, &tp_profiler) != 0)\
	fprintf(stderr, "erreur: clock_gettime.\n");\
difftimespec(&tp_profiler, &initial_time_profiler);\
fprintf(file_profiler, formats_profiler[0], __FUNCTION__, tp_profiler.tv_sec, tp_profiler.tv_nsec/precision);

#define return \
if (strcmp(__FUNCTION__, "main") == 0) {\
	free(formats_profiler[0]);\
	free(formats_profiler[1]);\
}\
if (clock_gettime(CLK_ID, &tp_profiler) != 0)\
	fprintf(stderr, "erreur: clock_gettime.\n");\
difftimespec(&tp_profiler, &initial_time_profiler);\
fprintf(file_profiler, formats_profiler[1], tp_profiler.tv_sec, tp_profiler.tv_nsec/precision);\
return
#else
#define PROFILE
#endif

void difftimespec(struct timespec*, struct timespec*);

#endif
