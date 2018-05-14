/***********************************************************************
 *
 * Defect Classification
 * ---------------------
 * Description: Defect code used to overwrite of overlapping memory 
 *
 ***********************************************************************/

#include "HeaderFile.h"

/***********************************************************************
 *
 * Defect type: Copy of overlapping memory 
 * Complexity: Write to array element using element in the same array
 *
 ***********************************************************************/
void ow_memcpy_001 ()
{
	int buf[5] = {1, 2, 3, 4, 5};
	int i;

	for (i = 0; i < 3; i ++)
	{
		buf[i] = buf[i+2]; /* ERROR: Copy of overlapping memory */
	}
}

/***********************************************************************
 *
 * Defect type: Copy of overlapping memory 
 * Complexity: Using function to copy memory 
 *
 ***********************************************************************/
void ow_memcpy_002_func_001 (void *dst, const void *src, int size)
{
	unsigned char *p;
	unsigned char *q;
	int i;
	
	p = (unsigned char *)src;
	q = (unsigned char *)dst;
	for (i = 0; i < size; i ++)
	{
		*q = *p; /* ERROR: Copy of overlapping memory */
		p ++;
		q ++;
	}
}

void ow_memcpy_002 ()
{
	int buf[5] = {1, 2, 3, 4, 5};
	
	ow_memcpy_002_func_001(&buf[2], &buf[0], (3 * sizeof(int)));
}

/***********************************************************************
 *
 * Defect type: Copy of overlapping memory 
 * Complexity: Copying of overlapping union members 
 *
 ***********************************************************************/
void ow_memcpy_003 ()
{
	int a = 2;
	int b = 4;
	int c;
    	union {
        	int a;
        	char b;
    	} u = {10};

    	if (c == 0)
    	{
        	u.a = a+b;
    	}
    	else
    	{
        	u.b = u.a; /* ERROR: Assignment using self */
    	}
}

/***********************************************************************
 *
 * Defect type: Copy of overlapping memory 
 * Complexity: Using memcpy function 
 *
 ***********************************************************************/
void ow_memcpy_004 ()
{
    char buf[6] = "HELLO";

    memcpy(&buf[1], &buf[3], 3); /* ERROR: Copy of overlapping memory */
}

/***********************************************************************
 *
 * Defect type: Copy of overlapping memory 
 * Main 
 *
 ***********************************************************************/
extern volatile int vflag;

void ow_memcpy_main ()
{
	if (vflag == 1 || vflag == 888)
	{
		ow_memcpy_001();
	}

	if (vflag == 2 || vflag == 888)
	{
		ow_memcpy_002();
	}
	
	if (vflag == 3 || vflag == 888)
	{
		ow_memcpy_003();
	}
	
	if (vflag == 4 || vflag == 888)
	{
		ow_memcpy_004();
	}
}
