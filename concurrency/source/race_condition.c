/********Software Analysis - FY2013*************/
/*
* File Name: race_condition.c
* Defect Classification
* ---------------------
* Defect Type: Concurrency defects
* Defect Sub-type: Race condition
*
*/


/* Race condition
 * Complexity: Thread 1 and thread 2 try to access and change the 
 * same resource at the same time.This leads to erroneous results.
*/

#include "HeaderFile.h"

int race_condition_001_glb_data=5;

void* race_condition_001_1(void *pram)
{
	race_condition_001_glb_data= 2 * race_condition_001_glb_data; /*Tool should detect this line as error*/ /*ERROR:Race condition*/
	return NULL;
}

void* race_condition_001_2(void *pram)
{
	race_condition_001_glb_data= 2 + race_condition_001_glb_data;
	return NULL;
}

void race_condition_001()
{
	pthread_t pthread1,pthread2,pthread3,pthread4;
	pthread_create(&pthread1,NULL,race_condition_001_1,NULL);
	pthread_create(&pthread2,NULL,race_condition_001_1,NULL);
	pthread_create(&pthread3,NULL,race_condition_001_2,NULL);
	pthread_create(&pthread4,NULL,race_condition_001_2,NULL);
}

/* Race condition
 * Complexity: Thread 1 and thread 2 try to access the 
 * same function at the same time.This leads to erroneous results.
*/

int race_condition_002_glb_data=0;

void* race_condition_002_1(void *pram)
{
	while(1)
	{

	
		if(race_condition_002_glb_data<100)
		{
			race_condition_002_glb_data++; /*Tool should detect this line as error*/ /*ERROR:Race condition*/
		}


	    break;
	}
	return NULL;
}

void race_condition_002()
{
	while(1)
	{
		pthread_t pthread1,pthread2;
		pthread_create(&pthread1,NULL,race_condition_002_1,NULL);
        pthread_create(&pthread2,NULL,race_condition_002_1,NULL);
	}
}

/* Race condition
 * Complexity: Thread 1,2,3 try to access the 
 * same function at the same time.This leads to erroneous results.
*/

int race_condition_003_glb_data=0;

void* race_condition_003_1(void *pram)
{
	if(race_condition_003_glb_data==0)
	{
		int* ptr=(int*) malloc(10*sizeof(int));
	    memcpy(ptr,"This is test", 0);
        free(ptr);
        race_condition_003_glb_data++ ;/*Tool should detect this line as error*/ /*ERROR:Race condition*/
	}
	return NULL;
}


void race_condition_003()
{
	while(1)
	{
		pthread_t pthread1,pthread2,pthread3;
		pthread_create(&pthread1,NULL,race_condition_003_1,NULL);
		pthread_create(&pthread2,NULL,race_condition_003_1,NULL);
		pthread_create(&pthread2,NULL,race_condition_003_1,NULL);
	}
}

/* Race condition
 * Complexity: 10 threads try to access the 
 * same variable.This leads to erroneous results if mutexes are not used.
*/
/* Prototype for thread function */
void* mythread(void * data);


/* Global variable which will be shared */
int race_condition_004_glb_data = 0;

void race_condition_004()
{
	int i;
	pthread_t pth[10];	

	for(i = 0; i < 10; i++)
	pthread_create(&pth[i],NULL,mythread,NULL);

	for(i = 0; i < 10; i++)
	pthread_join(pth[i],NULL);		

}

void* mythread(void* data)
{
	while(race_condition_004_glb_data < 100)
	{
		
		race_condition_004_glb_data++; /*Tool should detect this line as error*/ /*ERROR:Race condition*/
	}
	return(NULL);
}

/*
 * Types of defects: Data Race Condition
 * Complexity: Data Race Condition over multiple functions , 2 threads
 */

float race_condition_005_glb_data = 1000.0;

void race_condition_005_func_001 (void *pram)
{
    race_condition_005_glb_data = (race_condition_005_glb_data) + 1.2; /*Tool should detect this line as error*/ /*ERROR:Race condition*/
}

void* race_condition_005_tsk_001 (void *pram)
{
	race_condition_005_glb_data = (race_condition_005_glb_data) + 3.5;
	race_condition_005_func_001(pram);

	return NULL;
}

void race_condition_005 ()
{
	pthread_t tid1,tid2;
	intptr_t t1 = 10, t2 = 20;
	pthread_create(&tid1, NULL, race_condition_005_tsk_001, (void *)t1);
	pthread_create(&tid2, NULL, race_condition_005_tsk_001, (void *)t2);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
}



extern volatile int vflag;
void race_condition_main ()
{
	if (vflag == 1 || vflag ==888)
	{
		race_condition_001();
	}

	if (vflag == 2 || vflag ==888)
	{
		race_condition_002();
	}

	if (vflag == 3 || vflag ==888)
	{
		race_condition_003();
	}

	if (vflag == 4 || vflag ==888)
	{
		race_condition_004();
	}

	if (vflag == 5 || vflag ==888)
	{
		race_condition_005();
	}

}
