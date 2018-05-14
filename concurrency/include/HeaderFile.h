/*
 * HeaderFile.h
 *
 */

#ifndef HEADERFILE_H_
#define HEADERFILE_H_
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
//#include <unistd.h>
#include <limits.h>

extern int idx, sink;
extern double dsink;
extern void *psink;

void dead_lock_main (void);
void double_lock_main (void);
void double_release_main (void);
void livelock_main (void);
void lock_never_unlock_main  (void);
void race_condition_main (void);
void unlock_without_lock_main (void);


/*
# define PRINT_DEBUG 0
*/
typedef int intptr_t;
#endif /* HEADERFILE_H_ */
