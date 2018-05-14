/***********************************************************************
 *
 * Defect Classification
 * ---------------------
 * Description: Defect code used to identify paths in non void function with no return value 
 *
 ***********************************************************************/

#include "HeaderFile.h"

int rand (void);

/***********************************************************************
 *
 * Defect type: No return value for non void function  
 * Complexity: No return value in case in which if statement is not executed
 *
 ***********************************************************************/
int not_return_001_func_001 (int flag)
{
	if (flag == 0)
	{
		return 0;
	}
} /* ERROR: No return value */

void not_return_001()
{
	int ret;
	
	ret = not_return_001_func_001(rand());
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: No return value for non void function  
 * Complexity: No return value in case in which nested if statement is not executed
 *
 ***********************************************************************/
int not_return_002_func_001 (int flag1, int flag2)
{
	if (flag1 == 0)
	{
		if (flag2 == 0)
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
} /* ERROR: No return value */

void not_return_002()
{
	int ret;
	
	ret = not_return_002_func_001(rand(), rand());
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: No return value for non void function  
 * Complexity: Single switch statement clause with no return statement 
 *
 ***********************************************************************/
int not_return_003_func_001 (int flag)
{
	switch (flag)
	{
		case 1:
			return 0;
		case 2:
			break;
		case 3:
			return 0;
		default:
			return -1;
	}
} /* ERROR: No return value */

void not_return_003()
{
	int ret;
	
	ret = not_return_003_func_001(rand());
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: No return value for non void function  
 * Complexity: Use of goto statement skips return statement
 *
 ***********************************************************************/
int not_return_004_func_001 (int flag)
{
	int ret = 0;
	if (flag == 0)
	{
		goto my_label;
	}
	return ret;
my_label:
	ret ++;
} /* ERROR: No return value */

void not_return_004()
{
	int ret;
	
	ret = not_return_004_func_001(rand());
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: No return value for non void function  
 * Main 
 *
 ***********************************************************************/
extern volatile int vflag;

void not_return_main()
{
	if (vflag == 1 || vflag == 888)
	{
		not_return_001();
	}

	if (vflag == 2 || vflag == 888)
	{
		not_return_002();
	}

	if (vflag == 3 || vflag == 888)
	{
		not_return_003();
	}

	if (vflag == 4 || vflag == 888)
	{
		not_return_004();
	}
}
