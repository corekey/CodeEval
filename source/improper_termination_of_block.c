/***********************************************************************
 *
 * Defect Classification
 * ---------------------
 * Description: Defect code used to identify improper termination of a block
 *
 ***********************************************************************/

#include "HeaderFile.h"

/***********************************************************************
 *
 * Defect type: Improper termination of block 
 * Complexity: Missing braces if statement 
 *
 ***********************************************************************/
void improper_termination_of_block_001()
{
	int condition=0,x=0,y=0;
	
	if (condition==0) /* ERROR: Improper termination of block */
	printf("%d",x);
	printf("%d",y);
}

/***********************************************************************
 *
 * Defect type: Improper termination of block 
 * Complexity: Missing braces if statement 
 *
 ***********************************************************************/
void improper_termination_of_block_002()
{
	int condition=0,x=0,y=0;
	
	if (condition==0);	printf("%d",x); /* ERROR: Improper termination of block */
	printf("%d",y);
}

/***********************************************************************
 *
 * Defect type: Improper termination of block 
 * Complexity: Missing braces for loop 
 *
 ***********************************************************************/
void improper_termination_of_block_003()
{
	int x,y=0;
	
	for(x=0;x<10;x++); /* ERROR: Improper termination of block */
	printf("%d",x);
	printf("%d",y);
}

/***********************************************************************
 *
 * Defect type: Improper termination of block 
 * Complexity: Missing braces while loop 
 *
 ***********************************************************************/
void improper_termination_of_block_004()
{
	int x=0,y=0;
	
	while(x<10); /* ERROR: Improper termination of block */
	x++;
	printf("%d",x);
	printf("%d",y);
}

/***********************************************************************
 *
 * Defect type: Improper termination of block 
 * Complexity: Missing default case switch statement 
 *
 ***********************************************************************/
enum WidgetEnum { WE_W, WE_X, WE_Y, WE_Z } widget_type;

extern void demo_do_something_for_WE_W(void);

extern void demo_do_something_for_WE_X(void);

void improper_termination_of_block_005()
{
	enum WidgetEnum wt;
    	switch (wt)
    	{
      		case WE_W:
        		demo_do_something_for_WE_W();
        		break;
      		case WE_X:
        		demo_do_something_for_WE_X();
        		break;
    } /* ERROR: Improper termination of block */
}

/***********************************************************************
 *
 * Defect type: Improper termination of block 
 * Main 
 *
 ***********************************************************************/
extern volatile int vflag;

void improper_termination_of_block_main ()
{
	if (vflag == 1 || vflag == 888)
	{
		improper_termination_of_block_001 ();
	}

	if (vflag == 2 || vflag == 888)
	{
		improper_termination_of_block_002 ();
	}

	if (vflag == 3 || vflag == 888)
	{
		improper_termination_of_block_003 ();
	}

	if (vflag == 4 || vflag == 888)
	{
		improper_termination_of_block_004 ();
	}
	
	if (vflag == 5 || vflag == 888)
	{
		improper_termination_of_block_005 ();
	}
}
