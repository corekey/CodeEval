/***********************************************************************
 *
 * Defect Classification
 * ---------------------
 * Description: Defect code used to identify assertion violation 
 * 
 ***********************************************************************/

#include "HeaderFile.h"

/***********************************************************************
 *
 * Defect type: Assertion violation
 * Complexity: Assertion on unsigned integer
 *
 ***********************************************************************/
void assertion_violation_001 (unsigned int theta)
{
	 theta =+ 5;
	 assert(theta < 0); /* ERROR: Assertion violation */
}

/***********************************************************************
 *
 * Defect type: Assertion violation
 * Complexity: Asserting zero
 *
 ***********************************************************************/
void assertion_violation_002 ()
{
	int i_test_z = 0;
	float f_test_z = (float)i_test_z;
	
	assert(f_test_z); /* ERROR: Assertion violation */
}

/***********************************************************************
 *
 * Defect type: Assertion violation
 * Complexity: Assertion on memory allocation
 *
 ***********************************************************************/
void assertion_violation_003 ()
{
	int *ptr = malloc(sizeof(int) * 10);

	if (ptr == NULL) { return; }
	assert(ptr); /* ERROR: Assertion violation */
	ptr++;
	free(ptr);
}

/***********************************************************************
 *
 * Defect type: Assertion violation
 * Main
 *
 ***********************************************************************/
extern volatile int vflag;

void assertion_violation_main ()
{
	if (vflag == 1 || vflag == 888)
	{
		assertion_violation_001(0);
	}

	if (vflag == 2 || vflag == 888)
	{
		assertion_violation_002 ();
	}

	if (vflag == 3 || vflag == 888)
	{
		assertion_violation_003 ();
	}
}
