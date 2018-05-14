/********Software Analysis - FY2013*************/
/*
* File Name: lock_never_unlock.c
* Defect Classification
* ---------------------
* Defect Type: Concurrency defects
* Defect Sub-type: Locked but never unlock
*
*/


/* #include <pthread.h>	Compile-time options. -lpthread You can specify */
#include "HeaderFile.h"



 /* Types of defects: Lock But Never Unlock
 * Complexity: Lock But Never Unlock in same function using one thread
 */

pthread_mutex_t lock_never_unlock_001_glb_mutex = PTHREAD_MUTEX_INITIALIZER;

int lock_never_unlock_001_glb_data = 0;

void * lock_never_unlock_001_tsk_001 (void *pram)
{
	pthread_mutex_lock(&lock_never_unlock_001_glb_mutex);
	lock_never_unlock_001_glb_data = (lock_never_unlock_001_glb_data % 100) + 1;
	/*Tool should detect this line as error*/ /* ERROR:Lock Never Unlock */
    return NULL;
}

void lock_never_unlock_001 ()
{
	pthread_t tid1;
	pthread_mutex_init(&lock_never_unlock_001_glb_mutex, NULL);
	pthread_create(&tid1, NULL, lock_never_unlock_001_tsk_001, NULL);
	pthread_join(tid1, NULL);
	pthread_mutex_destroy(&lock_never_unlock_001_glb_mutex);
}

/*
 * Types of defects: Lock But Never Unlock
 * Complexity: Lock But Never Unlock over multiple functions using 2 threads unlocked based on if condition
 */
pthread_mutex_t lock_never_unlock_002_glb_mutex_1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock_never_unlock_002_glb_mutex_2 = PTHREAD_MUTEX_INITIALIZER;
void *lock_never_unlock_002_tsk_001(void *input)
{
	long ip;
	pthread_mutex_lock( &lock_never_unlock_002_glb_mutex_1 ); /*Tool should detect this line as error*/ /* ERROR:Lock Never Unlock */
	ip = (long)input;
	ip = ip *10;

	if (ip < 0)
		pthread_mutex_unlock( &lock_never_unlock_002_glb_mutex_1 );
	return NULL;
}

void * lock_never_unlock_002_tsk_002(void *input)
{
	long ip;
    pthread_mutex_lock( &lock_never_unlock_002_glb_mutex_2 );
    ip = (long)input;
    ip = ip *20;
    pthread_mutex_unlock( &lock_never_unlock_002_glb_mutex_2 );
    return NULL;
}

void lock_never_unlock_002 ()
{
	pthread_t th1,th2;
	   long int t1 = 10;
	   long int t2 = 20;
	   pthread_create(&th1, NULL, lock_never_unlock_002_tsk_001, (void *)t1);
	   pthread_create(&th2, NULL, lock_never_unlock_002_tsk_002, (void *)t2);
	   sleep(1);
}

/*
 * Types of defects: Lock But Never Unlock
 * Complexity: Thread created in else condition , no unlock
 */
pthread_mutex_t lock_never_unlock_003_glb_mutex = PTHREAD_MUTEX_INITIALIZER;
int lock_never_unlock_003_glb_data = 0;

# define NO_THREAD 0
int thread_set = 1;

void * lock_never_unlock_003_tsk_001 (void *pram)
{
	pthread_mutex_lock(&lock_never_unlock_003_glb_mutex);
	lock_never_unlock_003_glb_data = (lock_never_unlock_003_glb_data % 100) + 5; /*Tool should detect this line as error*/ /* ERROR:Lock Never Unlock */

    return NULL;
}

void lock_never_unlock_003 ()
{
	if (thread_set == NO_THREAD)
	{
		;
	}
	else
	{
		pthread_t tid1;
	    pthread_mutex_init(&lock_never_unlock_003_glb_mutex, NULL);
	    pthread_create(&tid1, NULL, lock_never_unlock_003_tsk_001, NULL);
	    pthread_join(tid1, NULL);
	    pthread_mutex_destroy(&lock_never_unlock_003_glb_mutex);
	}
}


/*
 * Types of defects: Lock But Never Unlock
 * Complexity: Lock But Never Unlock over multiple functions using 2 threads inside while loop and if condition
 */
pthread_mutex_t lock_never_unlock_004_glb_mutex_1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock_never_unlock_004_glb_mutex_2 = PTHREAD_MUTEX_INITIALIZER;
int lock_never_unlock_004_glb_var1 = 0;
int lock_never_unlock_004_glb_var2 = 0;
void *lock_never_unlock_004_tsk_001(void *input)
{
	long ip;
	int i = 5;
	ip = (long)input;
	ip = ip *10;

	while (i>0)
	{
		   if (ip >= 0)
		   {
			   pthread_mutex_lock( &lock_never_unlock_004_glb_mutex_1 );
			   lock_never_unlock_004_glb_var1 += 10;
			   pthread_mutex_unlock( &lock_never_unlock_004_glb_mutex_1 );
		   }
		   i--;
	}
    return NULL;
}

void * lock_never_unlock_004_tsk_002(void *input)
{
	long ip;
    int i=5;
    ip = (long)input;
    ip = ip *20;
	while (i>0)
	{
		   if (ip >= 0)
		   {
			   pthread_mutex_lock( &lock_never_unlock_004_glb_mutex_2 );

			   if(i!=5)
			   {
				   lock_never_unlock_004_glb_var2 += 20;
				   pthread_mutex_unlock( &lock_never_unlock_004_glb_mutex_2 );/*Tool should detect this line as error*/ /* ERROR:Lock Never Unlock */
			   }
		   }
		   i--;
	}
    return NULL;
}

void lock_never_unlock_004 ()
{
    pthread_t th1,th2;
	long int t1 = 10;
	long int t2 = 20;
	pthread_create(&th1, NULL, lock_never_unlock_004_tsk_001, (void *)t1);
	pthread_create(&th2, NULL, lock_never_unlock_004_tsk_002, (void *)t2);
	pthread_join(th1, NULL);
	pthread_join(th2, NULL);
}

/*
 * Types of defects: Lock But Never Unlock
 * Complexity: Lock But Never Unlock over multiple functions using 2 threads created in else condition
*/
pthread_mutex_t lock_never_unlock_005_glb_mutex_1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock_never_unlock_005_glb_mutex_2 = PTHREAD_MUTEX_INITIALIZER;
# define CREATE_THREAD 1
typedef struct {
	int a;
	int b;
} lock_never_unlock_005_s_001;
lock_never_unlock_005_s_001 lock_never_unlock_005_glb_sptr ={0};
void * lock_never_unlock_005_tsk_001(void *input)
{
	long ip;
	int i;
	ip = (long)input;
	ip = ip *10;
	for (i=0;i<=4;i++)
	{
		if (ip >= 0)
		{
			pthread_mutex_lock( &lock_never_unlock_005_glb_mutex_1 );
			lock_never_unlock_005_glb_sptr.a += 10;
			if(i!=4)
			   pthread_mutex_unlock( &lock_never_unlock_005_glb_mutex_1 );/*Tool should detect this line as error*/ /* ERROR:Lock Never Unlock */
		}
	}
    return NULL;
}

void * lock_never_unlock_005_tsk_002(void *input)
{
	long ip;
	int i;
	ip = (long)input;
	ip = ip *20;
	for (i=0;i<=4;i++)
	{
		if (ip >= 0)
		{
			pthread_mutex_lock( &lock_never_unlock_005_glb_mutex_2 );
			lock_never_unlock_005_glb_sptr.a += 20;
			pthread_mutex_unlock( &lock_never_unlock_005_glb_mutex_2 );
		}
	}
    return NULL;
}

void lock_never_unlock_005 ()
{
	int thread_set = 0;
	pthread_t th1,th2;
	long int t1 = 10;
	long int t2 = 20;
	if ( thread_set == CREATE_THREAD)
	{
		;
	}
	else
	{
		pthread_create(&th1, NULL, lock_never_unlock_005_tsk_001, (void *)t1);
		pthread_create(&th2, NULL, lock_never_unlock_005_tsk_002, (void *)t2);
		sleep(1);
	}
}

/*
 * Types of defects: Lock But Never Unlock
 * Complexity: Lock But Never Unlock over multiple functions using 2 threads inside do-while loop and if condition
 */
pthread_mutex_t lock_never_unlock_006_glb_mutex_1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock_never_unlock_006_glb_mutex_2 = PTHREAD_MUTEX_INITIALIZER;
int lock_never_unlock_006_glb_var = 0;
void *lock_never_unlock_006_tsk_001(void *input)
{
	long ip;
	int i = 5;
	ip = (long)input;
	ip = ip *10;
	do
	{
		   if (ip >= 0)
		   {
			   pthread_mutex_lock( &lock_never_unlock_006_glb_mutex_1 );
			   lock_never_unlock_006_glb_var += 10;
			   pthread_mutex_unlock( &lock_never_unlock_006_glb_mutex_1 );
		   }
		   i--;
	}while (i>0);
	return NULL;
}

void * lock_never_unlock_006_tsk_002(void *input)
{
	long ip;
    int i=5;
    ip = (long)input;
    ip = ip *20;
    do
	{
		   if (ip >= 0)
		   {
			   pthread_mutex_lock( &lock_never_unlock_006_glb_mutex_2 );

			   if(i!=5)
			   {
				   lock_never_unlock_006_glb_var += 20;
				   pthread_mutex_unlock( &lock_never_unlock_006_glb_mutex_2 );/*Tool should detect this line as error*/ /* ERROR:Lock Never Unlock */
			   }
		   }
		   i--;
	}	while (i>0);
    return NULL;
}

void lock_never_unlock_006 ()
{
	pthread_t th1,th2;
	long int t1 = 10;
	long int t2 = 20;
	pthread_create(&th1, NULL, lock_never_unlock_006_tsk_001, (void *)t1);
	pthread_create(&th2, NULL, lock_never_unlock_006_tsk_002, (void *)t2);
	pthread_join(th1, NULL);
	pthread_join(th2, NULL);
}


/*
 * Types of defects: Lock But Never Unlock -- double lock
 * Complexity: double-lock in same function using one thread
 */
pthread_mutex_t lock_never_unlock_007_glb_mutex = PTHREAD_MUTEX_INITIALIZER;

int lock_never_unlock_007_glb_data = 0;

void* lock_never_unlock_007_tsk_001 (void *pram)
{
	int ip = (int)pthread_self();
	pthread_mutex_lock(&lock_never_unlock_007_glb_mutex);
	lock_never_unlock_007_glb_data = (lock_never_unlock_007_glb_data % 100) + 1;
	pthread_mutex_lock(&lock_never_unlock_007_glb_mutex); 	/*Tool should detect this line as error*/ /*ERROR:Double Lock*/
	lock_never_unlock_007_glb_data = (lock_never_unlock_007_glb_data % 100) + 1;

    printf("Task1! It's me, thread #%d!\n",ip);

    return NULL;
}

void lock_never_unlock_007 ()
{
	pthread_t tid1;
	pthread_mutex_init(&lock_never_unlock_007_glb_mutex, NULL);
	pthread_create(&tid1, NULL, lock_never_unlock_007_tsk_001, NULL);
	pthread_join(tid1, NULL);
	pthread_mutex_destroy(&lock_never_unlock_007_glb_mutex);
}

/*
 * Types of defects: Lock But Never Unlock -- double lock
 * Complexity: Locking twice and unlocking only once in same function using one thread
 */
pthread_mutex_t lock_never_unlock_008_glb_mutex = PTHREAD_MUTEX_INITIALIZER;

int lock_never_unlock_008_glb_data = 0;

void * lock_never_unlock_008_tsk_001 (void * pram)
{
	pthread_mutex_lock (&lock_never_unlock_008_glb_mutex);
	lock_never_unlock_008_glb_data = (lock_never_unlock_008_glb_data% 100) + 1;

    pthread_mutex_lock (&lock_never_unlock_008_glb_mutex);  /*Tool should detect this line as error*/ /*ERROR:Double Lock*/
    lock_never_unlock_008_glb_data = (lock_never_unlock_008_glb_data% 100) + 1;
	pthread_mutex_unlock(&lock_never_unlock_008_glb_mutex);
    return NULL;
}

void lock_never_unlock_008 ()
{
	pthread_t tid1;
	pthread_mutex_init (&lock_never_unlock_008_glb_mutex, NULL);
	pthread_create (&tid1, NULL, lock_never_unlock_008_tsk_001, NULL);
	pthread_join (tid1, NULL);
	pthread_mutex_destroy (&lock_never_unlock_008_glb_mutex);
}


/*
 * Types of defects: Lock But Never Unlock -- double lock
 * Complexity: double-lock over multiple functions
 */
pthread_mutex_t lock_never_unlock_009_glb_mutex = PTHREAD_MUTEX_INITIALIZER;

int lock_never_unlock_009_glb_data = 0;

void lock_never_unlock_009_func_001 ()
{
	pthread_mutex_lock (&lock_never_unlock_009_glb_mutex); /*Tool should detect this line as error*/ /*ERROR:Double Lock*/
	lock_never_unlock_009_glb_data = (lock_never_unlock_009_glb_data% 100) + 1;
}

void * lock_never_unlock_009_tsk_001 (void * pram)
{
	pthread_mutex_lock (&lock_never_unlock_009_glb_mutex);
	lock_never_unlock_009_glb_data = (lock_never_unlock_009_glb_data% 100) + 1;
	lock_never_unlock_009_func_001 ();

    return NULL;
}

void lock_never_unlock_009 ()
{
	pthread_t tid1;
    pthread_mutex_init (&lock_never_unlock_009_glb_mutex, NULL);
    pthread_create (&tid1, NULL, lock_never_unlock_009_tsk_001, NULL);
    pthread_join (tid1, NULL);
    pthread_mutex_destroy (&lock_never_unlock_009_glb_mutex);
}


/*
 * Types of defects: Lock But Never Unlock
 * Lock But Never Unlock main function
 */
extern volatile int vflag;
void lock_never_unlock_main ()
{
	if (vflag == 1 || vflag ==888)
	{
		lock_never_unlock_001();
	}

	if (vflag == 2 || vflag ==888)
	{
		lock_never_unlock_002();
	}

	if (vflag == 3 || vflag ==888)
	{
		lock_never_unlock_003();
	}

	if (vflag == 4 || vflag ==888)
	{
		lock_never_unlock_004();
	}

	if (vflag == 5 || vflag ==888)
	{
		lock_never_unlock_005();
	}

	if (vflag == 6 || vflag ==888)
	{
		lock_never_unlock_006();
	}

	if (vflag == 7 || vflag ==888)
	{
		lock_never_unlock_007();
	}

	if (vflag == 8 || vflag ==888)
	{
		lock_never_unlock_008();
	}

	if (vflag == 9 || vflag ==888)
	{
		lock_never_unlock_009();
	}
}
