/********Software Analysis - FY2013*************/
/*
* File Name: unlock_without_lock.c
* Defect Classification
* ---------------------
* Defect Type: Concurrency defects
* Defect Sub-type: Unlock without lock
* Description: Defect Code to identify if a shared resource is unlocked without preceeding lock
*/


/* #include <pthread.h>	Compile-time options. -lpthread You can specify */
#include "HeaderFile.h"


/*
 * Types of defects: Unlock without Lock
 * Complexity: Unlock without Lock in same function using two thread
 */

pthread_mutex_t unlock_without_lock_001_glb_mutex = PTHREAD_MUTEX_INITIALIZER;

int unlock_without_lock_001_glb_data = 0;

void * unlock_without_lock_001_tsk_001 (void *pram)
{
	char * th = (char *)pram;
	unlock_without_lock_001_glb_data = (unlock_without_lock_001_glb_data % 100) + 1;
	pthread_mutex_unlock(&unlock_without_lock_001_glb_mutex);	/*Tool should detect this line as error*/ /* ERROR:UnLock without lock */

    return NULL;
}

void unlock_without_lock_001 ()
{
	pthread_t tid1,tid2;
	const char *t1 = "THREAD1";
	const char *t2 = "THREAD2";
	pthread_mutex_init(&unlock_without_lock_001_glb_mutex, NULL);
	pthread_create(&tid1, NULL, unlock_without_lock_001_tsk_001, (void *)t1);
	pthread_create(&tid2, NULL, unlock_without_lock_001_tsk_001, (void *)t2);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_mutex_destroy(&unlock_without_lock_001_glb_mutex);
}

/*
 * Types of defects: Unlock without Lock
 * Complexity: unLock without lock in same function using two thread inside a if condition
 */
pthread_mutex_t unlock_without_lock_002_glb_mutex = PTHREAD_MUTEX_INITIALIZER;


unsigned long unlock_without_lock_002_glb_data = 0;
int const unlock_without_lock_002_var = 10;
void * unlock_without_lock_002_tsk_001 (void * pram)
{
	if(unlock_without_lock_002_var == (intptr_t)pram)
	{

	    unlock_without_lock_002_glb_data = (unlock_without_lock_002_glb_data % 100) + 1;
        pthread_mutex_unlock(&unlock_without_lock_002_glb_mutex); /*Tool should detect this line as error*/ /* ERROR:UnLock without lock */
	}
	return NULL;
}

void unlock_without_lock_002 ()
{
	pthread_t tid1,tid2;
	intptr_t const unlock_without_lock_002_t1 = 10;
	intptr_t const unlock_without_lock_002_t2 = 20;
	pthread_mutex_init(&unlock_without_lock_002_glb_mutex, NULL);
	pthread_create(&tid1, NULL, unlock_without_lock_002_tsk_001, (void *)unlock_without_lock_002_t1);
	pthread_create(&tid2, NULL, unlock_without_lock_002_tsk_001, (void *)unlock_without_lock_002_t2);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
}

/*
 * Types of defects: Unlock without Lock
 * Complexity: Unlock without Lock over multiple functions , 2 threads,based on return value of function
 */
pthread_mutex_t unlock_without_lock_003_glb_mutex = PTHREAD_MUTEX_INITIALIZER;


float unlock_without_lock_003_glb_data = 1000.0;

int unlock_without_lock_003_func_002 (int a );

void unlock_without_lock_003_func_001 (void *pram)
{
	if(unlock_without_lock_003_func_002(0) >1)
    {
      pthread_mutex_lock (&unlock_without_lock_003_glb_mutex);/*Tool should detect this line as error*/ /* ERROR:UnLock without lock */
    }

	unlock_without_lock_003_glb_data = (unlock_without_lock_003_glb_data) + 1.2;
	unlock_without_lock_003_func_002(10);

	if(unlock_without_lock_003_func_002(10) >1)
    {
      pthread_mutex_unlock (&unlock_without_lock_003_glb_mutex);
    }
}

int unlock_without_lock_003_func_002 (int a )
{
	int ret = 0;
	if (a > 1)
	{
		ret = a++;
	}
	else
	{
		ret = 0;
	}
	return ret;
}

void* unlock_without_lock_003_tsk_001 (void *pram)
{
    if(unlock_without_lock_003_func_002(10) >1)
    {
    	pthread_mutex_lock (&unlock_without_lock_003_glb_mutex);
    }

	unlock_without_lock_003_glb_data = (unlock_without_lock_003_glb_data) + 3.5;
	unlock_without_lock_003_func_001(pram);

	if(unlock_without_lock_003_func_002(10) > 1)
    {
    	pthread_mutex_unlock(&unlock_without_lock_003_glb_mutex);
    }
	return NULL;
}

void unlock_without_lock_003 ()
{
	pthread_t tid1,tid2;
	intptr_t t1 = 10, t2 = 20;
	pthread_mutex_init(&unlock_without_lock_003_glb_mutex, NULL);
	pthread_create(&tid1, NULL, unlock_without_lock_003_tsk_001, (void *)t1);
	pthread_create(&tid2, NULL, unlock_without_lock_003_tsk_001, (void *)t2);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_mutex_destroy(&unlock_without_lock_003_glb_mutex);
}

/*
 * Types of defects: Unlock without Lock
 * Complexity: Unlock without Lock over multiple functions using 2 threads inside while loop and if condition
 */
pthread_mutex_t unlock_without_lock_004_glb_mutex_1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t unlock_without_lock_004_glb_mutex_2 = PTHREAD_MUTEX_INITIALIZER;
int lock_never_unlock_004_glb_var = 0;
void *unlock_without_lock_004_tsk_001(void *input)
{
	long ip;
	int i = 5;
	ip = (long)input;
	ip = ip *10;
	while (i>0)
	{
		   if (ip >= 0)
		   {
			   pthread_mutex_lock( &unlock_without_lock_004_glb_mutex_1 );
               lock_never_unlock_004_glb_var += 20;
               pthread_mutex_unlock( &unlock_without_lock_004_glb_mutex_1 );
		   }
		   i--;
	}
	return NULL;
}

void * unlock_without_lock_004_tsk_002(void *input)
{
	long ip;
    int i=5;
    ip = (long)input;
    ip = ip *20;
	while (i>0)
	{
		   if (ip >= 0)
		   {
			   if (i != 1)
			   pthread_mutex_lock( &unlock_without_lock_004_glb_mutex_2 ); /*Tool should detect this line as error*/ /* ERROR:UnLock without lock */
               lock_never_unlock_004_glb_var += 5;
			   pthread_mutex_unlock( &unlock_without_lock_004_glb_mutex_2 );
		   }
		   i--;
	}
	return NULL;
}

void unlock_without_lock_004 ()
{
	pthread_t th1,th2;
	intptr_t t1 = 10;
	intptr_t t2 = 20;
    pthread_create(&th1, NULL, unlock_without_lock_004_tsk_001, (void *)t1);
    pthread_create(&th2, NULL, unlock_without_lock_004_tsk_002, (void *)t2);
	sleep(1);
}

/*
 * Types of defects: Unlock without Lock
 * Complexity: Thread created in else condition , no lock but there is a unlock
 */
pthread_mutex_t unlock_without_lock_005_glb_mutex = PTHREAD_MUTEX_INITIALIZER;
int unlock_without_lock_005_glb_data = 0;

# define NO_THREAD 0
int unlock_without_lock_005_thread_set = 1;

void * unlock_without_lock_005_tsk_001 (void *pram)
{
	if (unlock_without_lock_005_thread_set == NO_THREAD)
	{
		;
	}
	else
	{
	    unlock_without_lock_005_glb_data = (unlock_without_lock_005_glb_data % 100) + 5;
	    pthread_mutex_unlock(&unlock_without_lock_005_glb_mutex);/*Tool should detect this line as error*/ /* ERROR:UnLock without lock */
	}
    return NULL;
}

void unlock_without_lock_005 ()
{
	if (unlock_without_lock_005_thread_set == NO_THREAD)
	{
		;
	}
	else
	{
		pthread_t tid1;
	    pthread_mutex_init(&unlock_without_lock_005_glb_mutex, NULL);
	    pthread_create(&tid1, NULL, unlock_without_lock_005_tsk_001, NULL);
	    pthread_join(tid1, NULL);
	    pthread_mutex_destroy(&unlock_without_lock_005_glb_mutex);
	}
}

/*
 * Types of defects: Unlock without Lock
 * Complexity: Unlock without Lock over multiple functions using 2 threads created in else condition
*/
pthread_mutex_t unlock_without_lock_006_glb_mutex_1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t unlock_without_lock_006_glb_mutex_2 = PTHREAD_MUTEX_INITIALIZER;
# define CREATE_THREAD 1
char unlock_without_lock_006_glb_buf[5]="BBBBB";
void * unlock_without_lock_006_tsk_001(void *input)
{
	long ip;
	int i;
	ip = (long)input;
	ip = ip *10;
	for (i=0;i<5;i++)
	{
		if (ip >= 0)
		{
			if(i !=3)
				pthread_mutex_lock( &unlock_without_lock_006_glb_mutex_1 );/*Tool should detect this line as error*/ /* ERROR:UnLock without lock */
			unlock_without_lock_006_glb_buf[i] = 'a';
			pthread_mutex_unlock( &unlock_without_lock_006_glb_mutex_1 );
		}
	}
	return NULL;
}

void * unlock_without_lock_006_tsk_002(void *input)
{
	long ip;
	ip = (long)input;
	ip = ip *20;
	if (ip >= 0)
	{
		pthread_mutex_lock( &unlock_without_lock_006_glb_mutex_2 );
        strcpy(unlock_without_lock_006_glb_buf,"STRI");
		pthread_mutex_unlock( &unlock_without_lock_006_glb_mutex_2 );
	}
	return NULL;
}

void unlock_without_lock_006 ()
{
	int thread_set = 0;
	pthread_t th1,th2;
        intptr_t t1 = 10;
	intptr_t t2 = 20;
	if ( thread_set == CREATE_THREAD)
	{
	   ;
	}
	else
	{
		pthread_create(&th1, NULL, unlock_without_lock_006_tsk_001, (void *)t1);
		pthread_create(&th2, NULL, unlock_without_lock_006_tsk_002, (void *)t2);
		sleep(1);
	}
}

/*
 * Types of defects: Unlock without Lock
 * Complexity: Unlock without Lock over multiple functions using 2 threads inside while loop and if condition
 */
pthread_mutex_t unlock_without_lock_007_glb_mutex_1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t unlock_without_lock_007_glb_mutex_2 = PTHREAD_MUTEX_INITIALIZER;
int unlock_without_lock_007_glb_var = 0;
void *unlock_without_lock_007_tsk_001(void *input)
{
	long ip;
	int i = 5;
	ip = (long)input;
	ip = ip *10;
	while (i>0)
	{
		   if (ip >= 0)
		   {
			   pthread_mutex_lock( &unlock_without_lock_007_glb_mutex_1 );
			   unlock_without_lock_007_glb_var += 10;
			   pthread_mutex_unlock( &unlock_without_lock_007_glb_mutex_1 );
		   }
		   i--;
	}
	return NULL;
}

void * unlock_without_lock_007_tsk_002(void *input)
{
	long ip;
    int i=5;
    ip = (long)input;
    ip = ip *20;
	while (i>0)
	{
		   if (ip >= 0)
		   {
               if(i!=5)
			   {
				   pthread_mutex_lock( &unlock_without_lock_007_glb_mutex_2 );
				   unlock_without_lock_007_glb_var += 20;
			   }
			   pthread_mutex_unlock( &unlock_without_lock_007_glb_mutex_2 );/*Tool should detect this line as error*/ /* ERROR:UnLock without lock */
		   }
		   i--;
	}
	return NULL;
}

void unlock_without_lock_007 ()
{
	pthread_t th1,th2;
	intptr_t t1 = 10;
	intptr_t t2 = 20;
	pthread_create(&th1, NULL, unlock_without_lock_007_tsk_001, (void *)t1);
	pthread_create(&th2, NULL, unlock_without_lock_007_tsk_002, (void *)t2);
	pthread_join(th1, NULL);
	pthread_join(th2, NULL);
}

/*
 * Types of defects: Unlock without Lock
 * Complexity: Unlock without Lock over multiple functions using 2 threads inside do-while loop and if condition
 */
pthread_mutex_t unlock_without_lock_008_glb_mutex_1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t unlock_without_lock_008_glb_mutex_2 = PTHREAD_MUTEX_INITIALIZER;
int unlock_without_lock_008_glb_var = 0;
void *unlock_without_lock_008_tsk_001(void *input)
{
	long ip;
	int i = 5;
	ip = (long)input;
	ip = ip *10;
	do
	{
		   if (ip >= 0)
		   {
			   pthread_mutex_lock( &unlock_without_lock_008_glb_mutex_1 );
			   unlock_without_lock_008_glb_var += 10;
			   pthread_mutex_unlock( &unlock_without_lock_008_glb_mutex_1 );
		   }
		   i--;
	}while (i>0);
	return NULL;
}

void * unlock_without_lock_008_tsk_002(void *input)
{
	long ip;
    int i=5;
    ip = (long)input;
    ip = ip *20;
     do
	{
		   if (ip >= 0)
		   {
			   if(i!=5)
			   {
				   pthread_mutex_lock( &unlock_without_lock_008_glb_mutex_2 );
				   unlock_without_lock_008_glb_var += 20;
				   pthread_mutex_unlock( &unlock_without_lock_008_glb_mutex_2 );
			   }
			   pthread_mutex_unlock( &unlock_without_lock_008_glb_mutex_2 );/*Tool should detect this line as error*/ /* ERROR:Unlock without Lock */
		   }
		   i--;
	}	while (i>0);
     return NULL;
}

void unlock_without_lock_008 ()
{
	pthread_t th1,th2;
	intptr_t t1 = 10;
	intptr_t t2 = 20;
	pthread_create(&th1, NULL, unlock_without_lock_008_tsk_001, (void *)t1);
	pthread_create(&th2, NULL, unlock_without_lock_008_tsk_002, (void *)t2);
	pthread_join(th1, NULL);
	pthread_join(th2, NULL);
}

/*
* Types of defects: unlock_without_lock
* Complexity: double release in same function
*/
pthread_mutex_t unlock_without_lock_009_glb_mutex;

int unlock_without_lock_009_glb_data = 0;

void * unlock_without_lock_009_tsk_001 (void * pram)
{
	pthread_mutex_lock (&unlock_without_lock_009_glb_mutex);
	unlock_without_lock_009_glb_data = (unlock_without_lock_009_glb_data% 100) + 1;
    pthread_mutex_unlock (&unlock_without_lock_009_glb_mutex);
    pthread_mutex_unlock (&unlock_without_lock_009_glb_mutex); /*Tool should detect this line as error*/ /*ERROR:Double UnLock*/
    return NULL;
}

void unlock_without_lock_009 ()
{
	printf("Double release");
	pthread_t tid1;
    pthread_mutex_init (&unlock_without_lock_009_glb_mutex, NULL);
    pthread_create (&tid1, NULL, unlock_without_lock_009_tsk_001, NULL);
    pthread_join (tid1, NULL);
    pthread_mutex_destroy (&unlock_without_lock_009_glb_mutex);
}

/*
* Types of defects: unlock_without_lock
* Complexity: double release across function
*/
pthread_mutex_t unlock_without_lock_010_glb_mutex;

int unlock_without_lock_010_glb_data = 0;

void unlock_without_lock_010_func_001 ()
{
	pthread_mutex_unlock (&unlock_without_lock_010_glb_mutex);
}

void * unlock_without_lock_010_tsk_001 (void * pram)
{
	pthread_mutex_lock (&unlock_without_lock_010_glb_mutex);
	unlock_without_lock_010_glb_data = (unlock_without_lock_010_glb_data% 100) + 1;
	unlock_without_lock_010_func_001 ();
	pthread_mutex_unlock (&unlock_without_lock_010_glb_mutex); /*Tool should detect this line as error*/ /*ERROR:Double UnLock*/
	return NULL;
}

void unlock_without_lock_010 ()
{
	pthread_t tid1;
	pthread_mutex_init (&unlock_without_lock_010_glb_mutex, NULL);
	pthread_create (& tid1, NULL, unlock_without_lock_010_tsk_001, NULL);
	pthread_join (tid1, NULL);
	pthread_mutex_destroy (&unlock_without_lock_010_glb_mutex);
}

/*
* Types of defects: unlock_without_lock
* Complexity: double release inside and outside a loop
*/
pthread_mutex_t unlock_without_lock_011_glb_mutex;

int unlock_without_lock_011_glb_data = 0;

void * unlock_without_lock_011_tsk_001 (void * pram)
{
	int i;
	for(i = 0; i < 2; i++)
	{
		pthread_mutex_lock (&unlock_without_lock_011_glb_mutex);
		unlock_without_lock_011_glb_data = (unlock_without_lock_011_glb_data% 100) + 1;
		pthread_mutex_unlock (&unlock_without_lock_011_glb_mutex);
	}
	pthread_mutex_unlock (&unlock_without_lock_011_glb_mutex);/*Tool should detect this line as error*/ /*ERROR:Double UnLock*/
    return NULL;
}

void unlock_without_lock_011 ()
{
	pthread_t tid1;
    pthread_mutex_init (&unlock_without_lock_011_glb_mutex, NULL);
    pthread_create (& tid1, NULL, unlock_without_lock_011_tsk_001, NULL);
    pthread_join (tid1, NULL);
    pthread_mutex_destroy (&unlock_without_lock_011_glb_mutex);
}


/*
* Types of defects: unlock_without_lock
* Complexity: double release inside a loop
*/
pthread_mutex_t unlock_without_lock_012_glb_mutex;

int unlock_without_lock_012_glb_data = 0;

void * unlock_without_lock_012_tsk_001 (void * pram)
{
	int i;
	pthread_mutex_lock (&unlock_without_lock_012_glb_mutex);
	unlock_without_lock_012_glb_data = (unlock_without_lock_012_glb_data% 100) + 1;
	for(i=0;i<2;i++)
	{
		pthread_mutex_unlock (&unlock_without_lock_012_glb_mutex); /*Tool should detect this line as error*/ /*ERROR:Double UnLock*/
	}
	return NULL;
}

void unlock_without_lock_012 ()
{
	pthread_t tid1;
    pthread_mutex_init (&unlock_without_lock_012_glb_mutex, NULL);
    pthread_create (&tid1, NULL, unlock_without_lock_012_tsk_001, NULL);
    pthread_join (tid1, NULL);
    pthread_mutex_destroy (&unlock_without_lock_012_glb_mutex);
}

/*
 * Types of defects: Unlock without Lock
 * Unlock without Lock main function
 */
extern volatile int vflag;
void unlock_without_lock_main ()
{
	if (vflag == 1 || vflag ==888)
	{
		unlock_without_lock_001();
	}

	if (vflag == 2 || vflag ==888)
	{
		unlock_without_lock_002();
	}

	if (vflag == 3 || vflag ==888)
	{
		unlock_without_lock_003();
	}

	if (vflag == 4 || vflag ==888)
	{
		unlock_without_lock_004();
	}

	if (vflag == 5 || vflag ==888)
	{
		unlock_without_lock_005();
	}

	if (vflag == 6 || vflag ==888)
	{
		unlock_without_lock_006();
	}

	if (vflag == 7 || vflag ==888)
	{
		unlock_without_lock_007();
	}

	if (vflag == 8 || vflag ==888)
	{
		unlock_without_lock_008();
	}
	if (vflag == 9 || vflag ==888)
	{
		unlock_without_lock_009();
	}
	if (vflag == 10 || vflag ==888)
	{
		unlock_without_lock_010();
	}
	if (vflag == 11 || vflag ==888)
	{
		unlock_without_lock_011();
	}
	if (vflag == 12 || vflag ==888)
	{
		unlock_without_lock_012();
	}
}
