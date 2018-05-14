/***********************************************************************
 *
 * Defect Classification
 * ---------------------
 * Description: Defect code used to identify conflicting conditions 
 * 
 ***********************************************************************/

#include "HeaderFile.h"

int rand (void);

/***********************************************************************
 *
 * Defect type: Conflicting conditions 
 * Complexity: Conflicting test for equality in if statement
 *
 ***********************************************************************/
void conflicting_cond_001 ()
{
	int a, b = 0, ret;

	a = rand();
	if ((a == 0) && (a == 1)) /* ERROR: Conflicting conditions */
	{
		b += a;
	}
	ret = b;
        sink = ret;
}

/***********************************************************************
 *
 * Defect type: Conflicting conditions 
 * Complexity: Conflicting arithmetic comparison in if statement
 *
 ***********************************************************************/
void conflicting_cond_002 ()
{
	int a, b = 0, ret;

	a = rand();
	if ((a < 5) && (10 < a)) /* ERROR: Conflicting conditions */
	{
		b += a;
	}
	ret = b;
        sink = ret;
}

/***********************************************************************
 *
 * Defect type: Conflicting conditions 
 * Complexity: Conflicting arithmetic comparison in if statement
 *
 ***********************************************************************/
void conflicting_cond_003 ()
{
	int a, b = 0, ret;

	a = rand();
	if (((0 < a) && (a < 2)) && ((8 < a) && (a < 10))) /* ERROR: Conflicting conditions */
	{
		b += a;
	}
	ret = b;
        sink = ret;
}

/***********************************************************************
 *
 * Defect type: Conflicting conditions 
 * Complexity: Conflicting arithmetic comparison in nested if statement
 *
 ***********************************************************************/
void conflicting_cond_004 ()
{
	int a, b = 0, ret;

	a = rand();
	if (a < 5)
	{
		if (10 < a) /* ERROR: Conflicting conditions */
		{
			b += a;
		}
	}
	ret = b;
        sink = ret;
}

/***********************************************************************
 *
 * Defect type: Conflicting conditions 
 * Complexity: Conflicting test for equality in conditional statement 
 *
 ***********************************************************************/
void conflicting_cond_005 ()
{
	int a, b, ret;

	a = rand();
	b = ((a == 0) && (a == 1)) ? 0 : 1; /* ERROR: Conflicting conditions */
	ret = b;
        sink = ret;
}

/***********************************************************************
 *
 * Defect type: Conflicting conditions 
 * Complexity: Conflicting test for equality in for loop control expression 
 *
 ***********************************************************************/
void conflicting_cond_006 ()
{
	int a, b = 0, ret;

	for (a = 0; (a == 0) && (a == 1); a ++) /* ERROR: Conflicting conditions */
	{
		b += a;
	}
	ret = b;
        sink = ret;
}

/***********************************************************************
 *
 * Defect type: Conflicting conditions 
 * Complexity: Conflicting test for equality in while loop control expression 
 *
 ***********************************************************************/
void conflicting_cond_007 ()
{
	int a, b = 0, ret;

	a = rand();
	while ((a == 0) && (a == 1)) /* ERROR: Conflicting conditions */
	{
		b += a;
		a ++;
	}
	ret = b;
        sink = ret;
}

/***********************************************************************
 *
 * Defect type: Conflicting conditions 
 * Complexity: Conflicting arithmetic comparison in while loop control expression 
 *
 ***********************************************************************/
void conflicting_cond_008 ()
{
	int a, b = 0, ret;

	a = rand();
	while ((a < 5) && (10 < a)) /* ERROR: Conflicting conditions */
	{
		b += a;
		a ++;
	}
	ret = b;
        sink = ret;
}

/***********************************************************************
 *
 * Defect type: Conflicting conditions 
 * Complexity: Conflicting arithmetic comparison in while loop control expression 
 *
 ***********************************************************************/
void conflicting_cond_009 ()
{
	int a, b = 0, ret;
	
	a = rand();
	while (((0 < a) && (a < 2)) && ((8 < a) && (a < 10))) /* ERROR: Conflicting conditions */
	{
		b += a;
		a ++;
	}
	ret = b;
        sink = ret;
}

/***********************************************************************
 *
 * Defect type: Conflicting conditions 
 * Complexity: Conflicting test for equality in do-while loop control expression 
 *
 ***********************************************************************/
void conflicting_cond_010 ()
{
	int a, ret;

	do
	{
		a = rand();
	}
	while ((a == 0) && (a == 1)); /* ERROR: Conflicting conditions */
	ret = a;
        sink = ret;
}

/***********************************************************************
 *
 * Defect type: Conflicting conditions 
 * Complexity: Conflicting arithmetic comparison in do-while loop control expression 
 *
 ***********************************************************************/
void conflicting_cond_011 ()
{
	int a, ret;

	do
	{
		a = rand();
	}
	while ((a > 10) && (a < 5)); /* ERROR: Conflicting conditions */
	ret = a;
        sink = ret;
}

/***********************************************************************
 *
 * Defect type: Conflicting conditions 
 * Main 
 *
 ***********************************************************************/
extern volatile int vflag;

void conflicting_cond_main ()
{
	if (vflag == 1 || vflag == 888)
	{
		conflicting_cond_001();
	}

	if (vflag == 2 || vflag == 888)
	{
		conflicting_cond_002();
	}

	if (vflag == 3 || vflag == 888)
	{
		conflicting_cond_003();
	}

	if (vflag == 4 || vflag == 888)
	{
		conflicting_cond_004();
	}

	if (vflag == 5 || vflag == 888)
	{
		conflicting_cond_005();
	}

	if (vflag == 6 || vflag == 888)
	{
		conflicting_cond_006();
	}

	if (vflag == 7 || vflag == 888)
	{
		conflicting_cond_007();
	}

	if (vflag == 8 || vflag == 888)
	{
		conflicting_cond_008();
	}

	if (vflag == 9 || vflag == 888)
	{
		conflicting_cond_009();
	}

	if (vflag == 10 || vflag == 888)
	{
		conflicting_cond_010();
	}
	
	if (vflag == 11 || vflag == 888)
	{
		conflicting_cond_011();
	}
}
