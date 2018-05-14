/***********************************************************************
 *
 * Defect Classification
 * ---------------------
 * Description: Defect code used to identify return of a local variable 
 *
 ***********************************************************************/

#include "HeaderFile.h"

/***********************************************************************
 *
 * Defect type: Return of local variable
 * Complexity: Return of pointer to local integer array 
 *
 ***********************************************************************/
int* return_local_001_func_001()
{
	int buf[5];
	return buf; /*ERROR: Return - pointer to local variable */
}

void return_local_001()
{
	int *p;
	p = return_local_001_func_001();
	p[3] = 1;
}

/***********************************************************************
 *
 * Defect type: Return of local variable
 * Complexity: Pointer value assigned to address of local variable 
 *
 ***********************************************************************/
void return_local_002_func_001 (int **pp)
{
	int buf[5];
	*pp = buf; /*ERROR: Return - pointer to local variable */
}

void return_local_002()
{
	int *p;
	return_local_002_func_001(&p);
	p[3] = 1;
}

/***********************************************************************
 *
 * Defect type: Return of local variable
 * Main 
 *
 ***********************************************************************/
extern volatile int vflag;

void return_local_main()
{
	if (vflag == 1 || vflag == 888)
	{
		return_local_001();
	}

	if (vflag == 2 || vflag == 888)
	{
		return_local_002();
	}
}
