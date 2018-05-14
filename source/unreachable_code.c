/***********************************************************************
 *
 * Defect Classification
 * ---------------------
 * Description: Defect code used to identify unreachable code
 *
 ***********************************************************************/

#include "HeaderFile.h"

/***********************************************************************
 *
 * Defect type: Unreachable code
 * Complexity: Unreachable if statement block due to constant if statement control expression
 *
 ***********************************************************************/
void unreachable_code_001 ()
{
	int a = 0, ret;

	if (0)
	{
		a ++; /* ERROR: Unreachable code */
	}
	ret = a;
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Unreachable code
 * Complexity: Unreachable if statement block due to constant variable 
 *
 ***********************************************************************/
void unreachable_code_002 ()
{
	int a = 0, condition = 0, ret;

	if (condition)
	{
		a ++; /* ERROR: Unreachable code */
	}
	ret = a;
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Unreachable code
 * Complexity: Unreachable if statement block due to constant return value of function call 
 *
 ***********************************************************************/
int unreachable_code_return ()
{
	return 0;
}

void unreachable_code_003 ()
{
	int a = 0, ret;
	
	if (unreachable_code_return ())
	{
		a ++; /* ERROR: Unreachable code */
	}
	ret = a;
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Unreachable code
 * Complexity: Unreachable if statement block due to constant function argument  
 *
 ***********************************************************************/
void unreachable_code_004 (int flag)
{
	int a = 0, ret;
	
	if (flag)
	{
		a ++; /* ERROR: Unreachable code */
	}
	ret = a; 
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Unreachable code
 * Complexity: Unreachable if statement block due to logical condition always evaluating as true 
 *
 ***********************************************************************/
void unreachable_code_005 ()
{
	int flag = 0, a = 0, ret;
	
	if (flag > 0)
	{
		a ++; /*  ERROR: Unreachable code */
	}
	ret = a;
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Unreachable code
 * Complexity: Unreachable for loop block due to loop control expression always evaluating as false 
 *
 ***********************************************************************/
void unreachable_code_006 ()
{
	int a = 0, i, ret;
	
	for (i = 0; i > 1; i ++)
	{
		a ++; /* ERROR: Unreachable code */
		break;
	}
	ret = a;
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Unreachable code
 * Complexity: Unreachable while loop block due to constant in loop control expression
 *
 ***********************************************************************/
void unreachable_code_007 ()
{
	int a = 0, ret;
	
	while (0)
	{
		a ++; /* ERROR: Unreachable code */
		break;
	}
	ret = a;
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Unreachable code
 * Complexity: Unreachable while loop block due to constant variable in loop control expression
 *
 ***********************************************************************/
void unreachable_code_008 ()
{
	int flag = 0, a = 0, ret;

	while (flag)
	{
		a ++; /* ERROR: Unreachable code */
		break;
	}
	ret = a;
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Unreachable code
 * Complexity: Unreachable while loop block due to constant return value of function call in loop control expression 
 *
 ***********************************************************************/
void unreachable_code_009 ()
{
	int a = 0, ret;

	while (unreachable_code_return ())
	{
		a ++; /* ERROR: Unreachable code */
		break;
	}
	ret = a;
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Unreachable code
 * Complexity: Unreachable if statement block due to logical condition always evaluating as true
 *
 ***********************************************************************/
void unreachable_code_010 ()
{
	int flag = 0, a = 0, ret;
	
	if (flag > 0)
	{
		a ++; /* ERROR:Unreachable Code*/
	}
	ret = a;
        sink = ret;
}

/***********************************************************************
 *
 * Defect type: Unreachable code
 * Complexity: Unreachable while loop block due to constant function argument used in loop control expression 
 *
 ***********************************************************************/
void unreachable_code_011 (int flag)
{
	int a = 0, ret;

	while (flag)
	{
		a ++; /* ERROR: Unreachable code */
		break;
	}
	ret = a;
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Unreachable code
 * Complexity: Unreachable while loop block due to logical expression in loop control expression always evaluating as false 
 *
 ***********************************************************************/
void unreachable_code_012 ()
{
	int flag = 0, a = 0, ret;
	
	while (flag > 0) 
	{
		a ++; /* ERROR: Unreachable code */
		break;
	}
	ret = a;
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Unreachable code
 * Complexity: Unreachable code below break statement 
 *
 ***********************************************************************/
void unreachable_code_013 ()
{
	int a = 0, ret;

	while (1)
	{
		break;
		a++; /* ERROR: Unreachable code */
	}
	ret = a;
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Unreachable code
 * Complexity: Unreachable code below return statement 
 *
 ***********************************************************************/
int unreachable_code_014 ()
{
	int a = 1, b = 5, ret;

	return ret;
    	ret = a * b; /* ERROR: Unreachable code */
}

/***********************************************************************
 *
 * Types of defects: unreachable code
 * Complexity: Unreachable returni statement
 * http://www.gimpel.com/html/newbugs/bug527.htm
 *
 ***********************************************************************/
int unreachable_code_015 ()
{
	char *s;
	int sum = 0;
	
	s = "aeiou";
	for(;;)
	{
		switch( *s++ )
		{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			sum++;
			continue;
		default:
			continue;
		case '\0':
			break;
		}
	}
	return sum; /* ERROR: Unreachable code */
}

/***********************************************************************
 *
 * Defect type: Unreachable code
 * Complexity: Function never called 
 *
 ***********************************************************************/
void unreachable_code_016 () /* ERROR: Unreachable code */
{
	int flag = 0, a = 0, ret;
	
	if (!flag)
	{
		a ++;
	}
	ret = a;
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Unreachable code
 * Complexity: Unreachable code due to use of goto statement 
 *
 ***********************************************************************/
void unreachable_code_017 () 
{
	int flag = 0, a = 0;
	goto mylabel;
	a++; /* ERROR: Unreachable code */
mylabel:
	return;
}

/***********************************************************************
 *
 * Defect type: Unreachable code
 * Complexity: Unreachable clause of conditional expression due to condition always remaining true 
 *
 ***********************************************************************/
int unreachable_code_018 () 
{
	int a = 0, ret;
	
	ret = (a == 0) ? 5 : 10; /* ERROR: Unreachable code */
	return ret;
}

/***********************************************************************
 *
 * Defect type: Unreachable code
 * Complexity: Unreachable else block due to constant variable in if statement 
 *
 ***********************************************************************/
void unreachable_code_019 () 
{
	int flag = 1, a = 0, ret;

	if (flag)
	{
		a++;		
	}
	else 
	{
		a--; /* ERROR: Unreachable code */
	}
	ret = a;
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Unreachable code
 * Main 
 *
 ***********************************************************************/
extern volatile int vflag;

void unreachable_code_main ()
{
	int ret;
    
	if (vflag == 1 || vflag == 888)
	{
		unreachable_code_001 ();
	}

	if (vflag == 2 || vflag == 888)
	{
		unreachable_code_002 ();
	}

	if (vflag == 3 || vflag == 888)
	{
		unreachable_code_003 ();
	}

	if (vflag == 4 || vflag == 888)
	{
		unreachable_code_004 (1);
	}

	if (vflag == 5 || vflag == 888)
	{
		unreachable_code_005 ();
	}

	if (vflag == 6 || vflag == 888)
	{
		unreachable_code_006 ();
	}

	if (vflag == 7 || vflag == 888)
	{
		unreachable_code_007 ();
	}

	if (vflag == 8 || vflag == 888)
	{
		unreachable_code_008 ();
	}

	if (vflag == 9 || vflag == 888)
	{
		unreachable_code_009 ();
	}

	if (vflag == 10 || vflag == 888)
	{
		unreachable_code_010 ();
	}

	if (vflag == 11 || vflag == 888)
	{
		unreachable_code_011 (0);
	}

	if (vflag == 12 || vflag == 888)
	{
		unreachable_code_012 ();
	}

	if (vflag == 13 || vflag == 888)
	{
		unreachable_code_013 ();
	}
	
	if (vflag == 14 || vflag == 888)
	{
		ret = unreachable_code_014 ();
	}
	
	if (vflag == 15 || vflag == 888)
	{
		ret = unreachable_code_015 ();
	}
	
	if (vflag == 17 || vflag == 888)
	{
		unreachable_code_017 ();
	}
	
	if (vflag == 18 || vflag == 888)
	{
		ret = unreachable_code_018 ();
	}
	
	if (vflag == 19 || vflag == 888)
	{
		ret = unreachable_code_018 ();
	}
}
