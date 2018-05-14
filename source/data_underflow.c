/***********************************************************************
 *
 * Defect Classification
 * ---------------------
 * Description: Defect code used to identify data underflow 
 *
 ***********************************************************************/

#include "HeaderFile.h"

/***********************************************************************
 *
 * NOTE: This behavior is implementation defined since it depends on the 
 *       size of built in data types. Hence I have defined several macro
 *       constants to improve reusability.
 *
 ***********************************************************************/
#define MIN_INT  -2147483648
#define MIN_CHAR -128

/***********************************************************************
 *
 * Defect type: Data underflow 
 * Complexity: Below bounds of smallest integer 
 *
 ***********************************************************************/
void data_underflow_001  ()
{
	int min = MIN_INT;	/* 0x80000001 */
	int ret;
	
	ret = min - 2; /* ERROR: Data underflow */
}

/***********************************************************************
 *
 * Defect type: Data underflow 
 * Complexity: Below bounds of smallest unsigned integer
 *
 ***********************************************************************/
void data_underflow_002  ()
{
	unsigned int min = 0;
	unsigned int ret;
	
	ret = min - 1; /* ERROR: Data underflow */
}

/***********************************************************************
 *
 * Defect type: Data underflow 
 * Complexity: Below bounds of integer size using decrement operator 
 *
 ***********************************************************************/
void data_underflow_003  ()
{
	int min = MIN_INT;	/* 0x80000001 */
	int ret;
	
	min --;
	min --;
	ret = min; /* ERROR: Data underflow */
}

/***********************************************************************
 *
 * Defect type: Data underflow 
 * Complexity: Below bounds of integer size size using constant 
 *
 ***********************************************************************/
void data_underflow_004  ()
{
	int min = MIN_INT + 126;
	int ret;
	
	ret = min - 128; /* ERROR: Data underflow */
}

/***********************************************************************
 *
 * Defect type: Data underflow 
 * Complexity: Below bounds of integer size using multiplication 
 *
 ***********************************************************************/
void data_underflow_005  ()
{
	int min = MIN_INT/2 - 3;	/* 0xbfffffff */
	int ret;

	ret = min * 2; /* ERROR: Data underflow */
}

/***********************************************************************
 *
 * Defect type: Data underflow 
 * Complexity: Below bounds of integer size using constant operands 
 *
 ***********************************************************************/
void data_underflow_006  ()
{
	int ret;
	
	ret = (MIN_INT) - 2; /* ERROR: Data underflow */
}

/***********************************************************************
 *
 * Defect type: Data underflow 
 * Complexity: Below bounds of float size using division 
 *
 ***********************************************************************/
void data_underflow_007  ()
{
	float ret;
	
	/* 0 00000000 00000000000000000000001 */
	float min = 1.40129846e-45F;	

	ret = min / 2.0F; /* ERROR: Data underflow */
}

/***********************************************************************
 *
 * Defect type: Data underflow 
 * Complexity: Below bounds of double size using division 
 *
 ***********************************************************************/
void data_underflow_008  ()
{
	double ret;

	/* 0 00000000000 0000000000000000000000000000000000000000000000000001 */
	double min = 4.9406564584124654e-324;

	ret = min / 2.0; /* ERROR: Data underflow */
}

/***********************************************************************
 *
 * Defect type: Data underflow 
 * Complexity: Below bounds of character size using constant subtrahend 
 *
 ***********************************************************************/
void data_underflow_009  ()
{
	char min = MIN_CHAR;	/* 0x80000002 */
	char ret;

	ret = min - 2; /* ERROR: Data underflow */
}

/***********************************************************************
 *
 * Defect type: Data underflow 
 * Complexity: Below bounds of integer size using function return value as subtrahend 
 *
 ***********************************************************************/
int data_underflow_010_func_001  ()
{
	return 2;
}

void data_underflow_010  ()
{
	int min = -2147483647;
	int ret;
	
	ret = min - data_underflow_010_func_001 (); /* ERROR: Data underflow */
}

/***********************************************************************
 *
 * Defect type: Data underflow 
 * Complexity: Below bounds of integer size using function argument as subtrahend 
 *
 ***********************************************************************/
void data_underflow_011 (int d)
{
	int min = MIN_INT;
	int ret;

	ret = min - d; /* ERROR: Data underflow */
}

/***********************************************************************
 *
 * Defect type: Data underflow 
 * Complexity: Below bounds of integer size using array element as subtrahend 
 *
 ***********************************************************************/
void data_underflow_012  ()
{
	int min = MIN_INT;
	int dlist[4] = {0, 1, -2, -1};
	int ret;

	ret = min - dlist[2]; /* ERROR: Data underflow */
}

/***********************************************************************
 *
 * Defect type: Data underflow 
 * Main 
 *
 ***********************************************************************/
extern volatile int vflag;

void data_underflow_main  ()
{
	if (vflag == 1 || vflag == 888)
	{
		data_underflow_001 ();
	}

	if (vflag == 2 || vflag == 888)
	{
		data_underflow_002 ();
	}

	if (vflag == 3 || vflag == 888)
	{
		data_underflow_003 ();
	}

	if (vflag == 4 || vflag == 888)
	{
		data_underflow_004 ();
	}

	if (vflag == 5 || vflag == 888)
	{
		data_underflow_005 ();
	}

	if (vflag == 6 || vflag == 888)
	{
		data_underflow_006 ();
	}

	if (vflag == 7 || vflag == 888)
	{
		data_underflow_007 ();
	}

	if (vflag == 8 || vflag == 888)
	{
		data_underflow_008 ();
	}

	if (vflag == 9 || vflag == 888)
	{
		data_underflow_009 ();
	}

	if (vflag == 10 || vflag == 888)
	{
		data_underflow_010 ();
	}

	if (vflag == 11 || vflag == 888)
	{
		data_underflow_011 (2);
	}

	if (vflag == 12 || vflag == 888)
	{
		data_underflow_012 ();
	}
}
