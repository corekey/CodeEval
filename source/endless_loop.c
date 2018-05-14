/***********************************************************************
 *
 * Defect Classification
 * ---------------------
 * Description: Defect code used to identify unintentional endless loop
 *
 ***********************************************************************/

#include "HeaderFile.h"

/***********************************************************************
 *
 * Defect type: Endless loop 
 * Complexity: Endless for loop due to missing loop control expression clause 
 *
 ***********************************************************************/
void endless_loop_001 ()
{
	int a = 0, i, ret;

	for (i = 0; ; i ++) /* ERROR: Endless loop */
	{
		a ++; 
	}
	ret = a;
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Endless loop 
 * Complexity: Endless for loop due to missing loop control variable update expression clause 
 *
 ***********************************************************************/
void endless_loop_002 ()
{
	int a = 0, i, ret;

	for (i = 0; i < 10; ) /* ERROR: Endless loop */
	{
		a ++; 
	}
	ret = a;
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Endless loop 
 * Complexity: Endless for loop due to empty clauses 
 *
 ***********************************************************************/
void endless_loop_003 ()
{
	int a = 0, i, ret;

	for (;;) /* ERROR: Endless loop */
	{
		a ++;
	}
	ret = a;
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Endless loop 
 * Complexity: Endless for loop due to break condition not being met
 *
 ***********************************************************************/
void endless_loop_004 ()
{
	int a = 0, control = 0, i, ret;

	for (;;) /* ERROR: Endless loop */
	{
		if (control) { break; }
		a ++;
	}
	ret = a;
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Endless loop 
 * Complexity: Endless while loop due to constant expression in loop control condition 
 *
 ***********************************************************************/
void endless_loop_005 ()
{
	int a = 0, ret;

	while (1) /* ERROR: Endless loop */
	{
		a ++; 
	}
	ret = a;
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Endless loop 
 * Complexity: Endless while loop due to constant loop loop control variable 
 *
 ***********************************************************************/
void endless_loop_006 ()
{
	int a = 0, control = 1, ret;

	while (control) /* ERROR: Endless loop */
	{
		a ++; 
	}
	ret = a;
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Endless loop 
 * Complexity: Endless while loop due to use of constant function argument as loop control variable 
 *
 ***********************************************************************/
void endless_loop_007 (int flag)
{
	int a = 0, ret;
	
	while (flag) /* ERROR: Endless loop */
	{
		a ++;
	}
	ret = a;
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Endless loop 
 * Complexity: Endless while loop due to use of constant function return value as loop control variable 
 *
 ***********************************************************************/
int endless_loop_return ()
{
	return 1;
}

void endless_loop_008 ()
{
	int a = 0, ret;

	while (endless_loop_return()) /* ERROR: Endless loop */
	{
		a ++; 
	}
	ret = a;
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Endless loop 
 * Complexity: Endless while loop due to logical expression always evaluating as true 
 *
 ***********************************************************************/
void endless_loop_009 ()
{
	int a = 0, control = 1, ret;

	while (control == 1) /* ERROR: Endless loop */
	{
		a ++; 
	}
	ret = a;
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Endless loop 
 * Complexity: Endless while loop due to conditional expression always being positive 
 *
 ***********************************************************************/
void endless_loop_010 ()
{
	int a = 0, ret;

	while((a==0) ? 1: 3) /* ERROR: Endless loop */
	{
		a ++; 
	}
	ret = a;
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Endless loop 
 * Complexity: Endless while loop due break condition not being met 
 *
 ***********************************************************************/
void endless_loop_011 ()
{
	int a = 0, control = 0, ret;

	while(1) /* ERROR: Endless loop */
	{
		if (control) { break; }
		a ++; 
	}
	ret = a;
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Endless loop 
 * Complexity: Endless do-while loop due to constant expression in loop control condition 
 *
 ***********************************************************************/
void endless_loop_012 ()
{
	int a = 0, ret;

	do 
	{
		a ++; 
	}
	while (1); /* ERROR: Endless loop */
	
	ret = a;
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Endless loop 
 * Complexity: Endless do-while loop due to constant loop loop control variable 
 *
 ***********************************************************************/
void endless_loop_013 ()
{
	int a = 0, control = 1, ret;

	do 
	{
		a ++; 
	}
	while (control); /* ERROR: Endless loop */
	
	ret = a;
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Endless loop 
 * Complexity: Endless do-while loop due to use of constant function argument as loop control variable 
 *
 ***********************************************************************/
void endless_loop_014 (int flag)
{
	int a = 0, ret;
	
	do 
	{
		a ++;
	}
	while (flag); /* ERROR: Endless loop */
	
	ret = a;
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Endless loop 
 * Complexity: Endless do-while loop due to use of constant function return value as loop control variable 
 *
 ***********************************************************************/
void endless_loop_015 ()
{
	int a = 0, ret;

	do
	{
		a ++; 
	} 
	while (endless_loop_return()); /* ERROR: Endless loop */
	
	ret = a;
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Endless loop 
 * Complexity: Endless do-while loop due to logical expression always evaluating as true 
 *
 ***********************************************************************/
void endless_loop_016 ()
{
	int a = 0, control = 1, ret;

	do 
	{
		a ++; 
	}
	while (control == 1); /* ERROR: Endless loop */
	
	ret = a;
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Endless loop 
 * Complexity: Endless do-while loop due to conditional expression always being positive 
 *
 ***********************************************************************/
void endless_loop_017 ()
{
	int a = 0, ret;

	do
	{
		a ++; 
	} 
	while((a==0) ? 1: 3); /* ERROR: Endless loop */
	
	ret = a;
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Endless loop 
 * Complexity: Endless do-while loop due break condition not being met 
 *
 ***********************************************************************/
void endless_loop_018 ()
{
	int a = 0, control = 0, ret;

	do
	{
		if (control) { break; }
		a ++; 
	}
	while(1); /* ERROR: Endless loop */
	
	ret = a;
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Endless loop 
 * Main 
 *
 ***********************************************************************/
extern volatile int vflag;

void endless_loop_main  ()
{
	if (vflag == 1 || vflag == 888)
	{
		endless_loop_001 ();
	}

	if (vflag == 2 || vflag == 888)
	{
		endless_loop_002 ();
	}

	if (vflag == 3 || vflag == 888)
	{
		endless_loop_003 ();
	}
	
	if (vflag == 4 || vflag == 888)
	{
		endless_loop_004 ();
	}

	if (vflag == 5 || vflag == 888)
	{
		endless_loop_005 ();
	}

	if (vflag == 6 || vflag == 888)
	{
		endless_loop_006 ();
	}
	
	if (vflag == 7 || vflag == 888)
	{
		endless_loop_007 (1);
	}

	if (vflag == 8 || vflag == 888)
	{
		endless_loop_008 ();
	}

	if (vflag == 9 || vflag == 888)
	{
		endless_loop_009 ();
	}
	
	if (vflag == 10 || vflag == 888)
	{
		endless_loop_010 ();
	}

	if (vflag == 11 || vflag == 888)
	{
		endless_loop_011 ();
	}

	if (vflag == 12 || vflag == 888)
	{
		endless_loop_012 ();
	}
	
	if (vflag == 13 || vflag == 888)
	{
		endless_loop_013 ();
	}

	if (vflag == 14 || vflag == 888)
	{
		endless_loop_014 (1);
	}

	if (vflag == 15 || vflag == 888)
	{
		endless_loop_015 ();
	}
	
	if (vflag == 16 || vflag == 888)
	{
		endless_loop_016 ();
	}

	if (vflag == 17 || vflag == 888)
	{
		endless_loop_017 ();
	}

	if (vflag == 18 || vflag == 888)
	{
		endless_loop_018 ();
	}
}
