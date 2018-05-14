/********Software Analysis - FY2013*************/
/*
* File Name: dead_lock.c
* Defect Classification
* ---------------------
* Defect Type: Concurrency defects
* Defect Sub-type: Dead lock
*
*/

#include "HeaderFile.h"

/*
 * Types of defects: deadlock
 * Complexity: exclusive control of two resources task 1: A -> B, task 2: B -> A
 */
pthread_mutex_t dead_lock_001_glb_mutexA = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t dead_lock_001_glb_mutexB = PTHREAD_MUTEX_INITIALIZER;

int dead_lock_001_glb_dataA = 10;
int dead_lock_001_glb_dataB = 10;

void* dead_lock_001_tsk_001 (void *pram)
{
	/* lock A */
	pthread_mutex_lock(&dead_lock_001_glb_mutexA);
	dead_lock_001_glb_dataA = (dead_lock_001_glb_dataA % 100) + 10;
    printf("Task1! dead_lock= %d \n",dead_lock_001_glb_dataA);

	/* lock B */
	pthread_mutex_lock(&dead_lock_001_glb_mutexB);
	dead_lock_001_glb_dataB = (dead_lock_001_glb_dataB % 100) + 20;
	pthread_mutex_unlock(&dead_lock_001_glb_mutexB);

	pthread_mutex_unlock(&dead_lock_001_glb_mutexA);

	return NULL;
}

void* dead_lock_001_tsk_002 (void *pram)
{
	/* lock B */
	pthread_mutex_lock(&dead_lock_001_glb_mutexB);  /*Tool should detect this line as error*/ /*ERROR:Dead Lock*/
	dead_lock_001_glb_dataB = (dead_lock_001_glb_dataB % 100) + 1;

	/* lock A */
	pthread_mutex_lock(&dead_lock_001_glb_mutexA);

	dead_lock_001_glb_dataA = (dead_lock_001_glb_dataA % 100) + 1;
	pthread_mutex_unlock(&dead_lock_001_glb_mutexA);

	pthread_mutex_unlock(&dead_lock_001_glb_mutexB);
	return NULL;
}

void dead_lock_001 ()
{
	pthread_t tid1;
	pthread_t tid2;

	pthread_mutex_init(&dead_lock_001_glb_mutexA, NULL);
	pthread_mutex_init(&dead_lock_001_glb_mutexB, NULL);

	pthread_create(&tid1, NULL, dead_lock_001_tsk_001, NULL);
	pthread_create(&tid2, NULL, dead_lock_001_tsk_002, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	pthread_mutex_destroy(&dead_lock_001_glb_mutexA);
	pthread_mutex_destroy(&dead_lock_001_glb_mutexB);
}


/*
 * Types of defects: deadlock
 * Complexity: exclusive control three resources task 1: A -> B, task 2: B -> C and task 3: C -> A
 */

pthread_mutex_t dead_lock_002_glb_mutexA = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t dead_lock_002_glb_mutexB = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t dead_lock_002_glb_mutexC = PTHREAD_MUTEX_INITIALIZER;

int dead_lock_002_glb_dataA = 0;
int dead_lock_002_glb_dataB = 0;
int dead_lock_002_glb_dataC = 0;

void* dead_lock_002_tsk_001 (void *pram)
{
	/* lock A */
	pthread_mutex_lock(&dead_lock_002_glb_mutexA);
	dead_lock_002_glb_dataA = (dead_lock_002_glb_dataA % 100) + 1;

	/* lock B */
	pthread_mutex_lock(&dead_lock_002_glb_mutexB);
	dead_lock_002_glb_dataB = (dead_lock_002_glb_dataB % 100) + 1;
	pthread_mutex_unlock(&dead_lock_002_glb_mutexB);

	pthread_mutex_unlock(&dead_lock_002_glb_mutexA);

	return NULL;
}

void* dead_lock_002_tsk_002 (void *pram)
{
	/* lock B */
	pthread_mutex_lock(&dead_lock_002_glb_mutexB);
	dead_lock_002_glb_dataB = (dead_lock_002_glb_dataB % 100) + 1;

	/* lock C */
	pthread_mutex_lock(&dead_lock_002_glb_mutexC);
	dead_lock_002_glb_dataC = (dead_lock_002_glb_dataC % 100) + 1;
	pthread_mutex_unlock(&dead_lock_002_glb_mutexC);

	pthread_mutex_unlock(&dead_lock_002_glb_mutexB);

	return NULL;
}

void* dead_lock_002_tsk_003 (void *pram)
{
	/* lock C */

	pthread_mutex_lock(&dead_lock_002_glb_mutexC); /*Tool should detect this line as error*/ /*ERROR:Dead Lock*/
	dead_lock_002_glb_dataC = (dead_lock_002_glb_dataC % 100) + 1;

	/* lock A */

	pthread_mutex_lock(&dead_lock_002_glb_mutexA);
	dead_lock_002_glb_dataA = (dead_lock_002_glb_dataA % 100) + 1;
	pthread_mutex_unlock(&dead_lock_002_glb_mutexA);

	pthread_mutex_unlock(&dead_lock_002_glb_mutexC);

	return NULL;
}

void dead_lock_002 ()
{
	pthread_t tid1;
	pthread_t tid2;
	pthread_t tid3;

	pthread_mutex_init(&dead_lock_002_glb_mutexA, NULL);
	pthread_mutex_init(&dead_lock_002_glb_mutexB, NULL);
	pthread_mutex_init(&dead_lock_002_glb_mutexC, NULL);

	pthread_create(&tid1, NULL, dead_lock_002_tsk_001, NULL);
	pthread_create(&tid2, NULL, dead_lock_002_tsk_002, NULL);
	pthread_create(&tid3, NULL, dead_lock_002_tsk_003, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_join(tid3, NULL);

	pthread_mutex_destroy(&dead_lock_002_glb_mutexA);
	pthread_mutex_destroy(&dead_lock_002_glb_mutexB);
	pthread_mutex_destroy(&dead_lock_002_glb_mutexC);
}

/*
 * Types of defects: deadlock
 * Complexity: exclusive control three resources task 1: A -> B -> C, task 2: B -> A -> C
 */
pthread_mutex_t dead_lock_003_glb_mutexA = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t dead_lock_003_glb_mutexB = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t dead_lock_003_glb_mutexC = PTHREAD_MUTEX_INITIALIZER;

int dead_lock_003_glb_dataA = 0;
int dead_lock_003_glb_dataB = 0;
int dead_lock_003_glb_dataC = 0;

void* dead_lock_003_tsk_001 (void *pram)
{
	/* lock A */
	pthread_mutex_lock(&dead_lock_003_glb_mutexA);
	dead_lock_003_glb_dataA = (dead_lock_003_glb_dataA % 100) + 1;

	/* lock B */
	pthread_mutex_lock(&dead_lock_003_glb_mutexB);
	dead_lock_003_glb_dataB = (dead_lock_003_glb_dataB % 100) + 1;

	/* lock C */
	pthread_mutex_lock(&dead_lock_003_glb_mutexC);
	dead_lock_003_glb_dataC = (dead_lock_003_glb_dataC % 100) + 1;
	pthread_mutex_unlock(&dead_lock_003_glb_mutexC);

	pthread_mutex_unlock(&dead_lock_003_glb_mutexB);

	pthread_mutex_unlock(&dead_lock_003_glb_mutexA);

	return NULL;
}

void* dead_lock_003_tsk_002 (void *pram)
{
	/* lock B */

	pthread_mutex_lock(&dead_lock_003_glb_mutexB);/*Tool should detect this line as error*/ /*ERROR:Dead Lock*/
	dead_lock_003_glb_dataB = (dead_lock_003_glb_dataB % 100) + 1;

	/* lock A */
	pthread_mutex_lock(&dead_lock_003_glb_mutexA);
	dead_lock_003_glb_dataA = (dead_lock_003_glb_dataA % 100) + 1;

	/* lock C */
	pthread_mutex_lock(&dead_lock_003_glb_mutexC);
	dead_lock_003_glb_dataC = (dead_lock_003_glb_dataC % 100) + 1;
	pthread_mutex_unlock(&dead_lock_003_glb_mutexC);

	pthread_mutex_unlock(&dead_lock_003_glb_mutexA);

	pthread_mutex_unlock(&dead_lock_003_glb_mutexB);

	return NULL;
}

void dead_lock_003 ()
{
	pthread_t tid1;
	pthread_t tid2;

	pthread_mutex_init(&dead_lock_003_glb_mutexA, NULL);
	pthread_mutex_init(&dead_lock_003_glb_mutexB, NULL);
	pthread_mutex_init(&dead_lock_003_glb_mutexC, NULL);

	pthread_create(&tid1, NULL, dead_lock_003_tsk_001, NULL);
	pthread_create(&tid2, NULL, dead_lock_003_tsk_002, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	pthread_mutex_destroy(&dead_lock_003_glb_mutexA);
	pthread_mutex_destroy(&dead_lock_003_glb_mutexB);
	pthread_mutex_destroy(&dead_lock_003_glb_mutexC);
}

/*
 * Types of defects: deadlock
 * Complexity: exclusive control three resources task 1: A -> B -> C, task 2: B -> C -> A
 */
/*pthread_mutex_t dead_lock_004_glb_mutexA_;
pthread_mutex_t dead_lock_004_glb_mutexB_;
pthread_mutex_t dead_lock_004_glb_mutexC_;
pthread_mutex_t *dead_lock_004_glb_mutexA = &dead_lock_004_glb_mutexA_;
pthread_mutex_t *dead_lock_004_glb_mutexB = &dead_lock_004_glb_mutexB_;
pthread_mutex_t *dead_lock_004_glb_mutexC = &dead_lock_004_glb_mutexC_;
*/
pthread_mutex_t dead_lock_004_glb_mutexA = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t dead_lock_004_glb_mutexB = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t dead_lock_004_glb_mutexC = PTHREAD_MUTEX_INITIALIZER;

int dead_lock_004_glb_dataA = 0;
int dead_lock_004_glb_dataB = 0;
int dead_lock_004_glb_dataC = 0;

void* dead_lock_004_tsk_001 (void *pram)
{
	/* lock A */
	pthread_mutex_lock(&dead_lock_004_glb_mutexA);
	dead_lock_004_glb_dataA = (dead_lock_004_glb_dataA % 100) + 1;

	/* lock B */
	pthread_mutex_lock(&dead_lock_004_glb_mutexB);
	dead_lock_004_glb_dataB = (dead_lock_004_glb_dataB % 100) + 1;

	/* lock C */
	pthread_mutex_lock(&dead_lock_004_glb_mutexC);
	dead_lock_004_glb_dataC = (dead_lock_004_glb_dataC % 100) + 1;
	pthread_mutex_unlock(&dead_lock_004_glb_mutexC);

	pthread_mutex_unlock(&dead_lock_004_glb_mutexB);

	pthread_mutex_unlock(&dead_lock_004_glb_mutexA);

	return NULL;
}

void* dead_lock_004_tsk_002 (void *pram)
{
	/* lock B */
	pthread_mutex_lock(&dead_lock_004_glb_mutexB); /*Tool should detect this line as error*/ /*ERROR:Dead Lock*/
	dead_lock_004_glb_dataB = (dead_lock_004_glb_dataB % 100) + 1;

	/* lock C */
	pthread_mutex_lock(&dead_lock_004_glb_mutexC);
	dead_lock_004_glb_dataC = (dead_lock_004_glb_dataC % 100) + 1;

	/* lock A */
	pthread_mutex_lock(&dead_lock_004_glb_mutexA);
	dead_lock_004_glb_dataA = (dead_lock_004_glb_dataA % 100) + 1;
	pthread_mutex_unlock(&dead_lock_004_glb_mutexA);

	pthread_mutex_unlock(&dead_lock_004_glb_mutexC);

	pthread_mutex_unlock(&dead_lock_004_glb_mutexB);

	return NULL;
}

void dead_lock_004 ()
{
	pthread_t tid1;
	pthread_t tid2;

	pthread_mutex_init(&dead_lock_004_glb_mutexA, NULL);
	pthread_mutex_init(&dead_lock_004_glb_mutexB, NULL);
	pthread_mutex_init(&dead_lock_004_glb_mutexC, NULL);

	pthread_create(&tid1, NULL, dead_lock_004_tsk_001, NULL);
	pthread_create(&tid2, NULL, dead_lock_004_tsk_002, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	pthread_mutex_destroy(&dead_lock_004_glb_mutexA);
	pthread_mutex_destroy(&dead_lock_004_glb_mutexB);
	pthread_mutex_destroy(&dead_lock_004_glb_mutexC);
}

/*
 * Types of defects: deadlock
 * Complexity: exclusive control over resources, across functions
 */
/*
pthread_mutex_t dead_lock_005_glb_mutexA_;
pthread_mutex_t dead_lock_005_glb_mutexB_;
pthread_mutex_t *dead_lock_005_glb_mutexA = &dead_lock_005_glb_mutexA_;
pthread_mutex_t *dead_lock_005_glb_mutexB = &dead_lock_005_glb_mutexB_;
*/
pthread_mutex_t dead_lock_005_glb_mutexA = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t dead_lock_005_glb_mutexB = PTHREAD_MUTEX_INITIALIZER;

int dead_lock_005_glb_dataA = 0;
int dead_lock_005_glb_dataB = 0;

void dead_lock_005_func_001 ()
{
	/* lock B */
	pthread_mutex_lock(&dead_lock_005_glb_mutexB);
	dead_lock_005_glb_dataB = (dead_lock_005_glb_dataB % 100) + 1;
	pthread_mutex_unlock(&dead_lock_005_glb_mutexB);
}

void dead_lock_005_func_002 ()
{
	/* lock A */
	pthread_mutex_lock(&dead_lock_005_glb_mutexA);/*Tool should detect this line as error*/ /*ERROR:Dead Lock*/
	dead_lock_005_glb_dataA = (dead_lock_005_glb_dataA % 100) + 1;
	pthread_mutex_unlock(&dead_lock_005_glb_mutexA);
}

void* dead_lock_005_tsk_001 (void *pram)
{
	/* lock A */
	pthread_mutex_lock(&dead_lock_005_glb_mutexA);
	dead_lock_005_glb_dataA = (dead_lock_005_glb_dataA % 100) + 1;

	/* lock B */
	dead_lock_005_func_001();
	pthread_mutex_unlock(&dead_lock_005_glb_mutexA);

	return NULL;
}

void* dead_lock_005_tsk_002 (void *pram)
{
	/* lock B */
	pthread_mutex_lock(&dead_lock_005_glb_mutexB);
	dead_lock_005_glb_dataB = (dead_lock_005_glb_dataB % 100) + 1;

	/* lock A */
	dead_lock_005_func_002();
	pthread_mutex_unlock(&dead_lock_005_glb_mutexB);

	return NULL;
}

void dead_lock_005 ()
{
	printf("dead lock");
	pthread_t tid1;
	pthread_t tid2;

	pthread_mutex_init(&dead_lock_005_glb_mutexA, NULL);
	pthread_mutex_init(&dead_lock_005_glb_mutexB, NULL);

	pthread_create(&tid1, NULL, dead_lock_005_tsk_001, NULL);
	pthread_create(&tid2, NULL, dead_lock_005_tsk_002, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	pthread_mutex_destroy(&dead_lock_005_glb_mutexA);
	pthread_mutex_destroy(&dead_lock_005_glb_mutexB);
}

/*
 * Types of defects: deadlock
 * Deadlock main function
 */
extern volatile int vflag;
void dead_lock_main ()
{
	if (vflag == 1 || vflag ==888)
	{
		dead_lock_001();
	}

	if (vflag == 2 || vflag ==888)
	{
		dead_lock_002();
	}

	if (vflag == 3 || vflag ==888)
	{
		dead_lock_003();
	}

	if (vflag == 4 || vflag ==888)
	{
		dead_lock_004();
	}

	if (vflag == 5 || vflag ==888)
	{
		dead_lock_005();
	}
}
