/***********************************************************************
 *
 * Defect Classification
 * ---------------------
 * Description: Defect code used to identify double free of memory
 *
 ***********************************************************************/

#include "HeaderFile.h"

/***********************************************************************
 *
 * Defect type: Double free
 * Complexity: free twice in succession
 *
 ***********************************************************************/
void double_free_001 ()
{
	char* ptr= (char*) malloc(sizeof(char));
	
	free(ptr);
	free(ptr); /* ERROR: Double free */
}

/***********************************************************************
 *
 * Defect type: Double free
 * Complexity: Double free inside and outside for loop 
 *
 ***********************************************************************/
void double_free_002 ()
{
	char* ptr= (char*) malloc(10*sizeof(char));
	int i;
	
	for(i=0;i<10;i++)
	{
		*(ptr + i) = 'a';	
		if(i==9)
		{
			free(ptr);
		}
	}
	free(ptr); /* ERROR: Double free */
}

/***********************************************************************
 *
 * Defect type: Double free
 * Complexity: Double free inside and outside for loop 
 *
 ***********************************************************************/
void double_free_003 ()
{
	char* ptr= (char*) malloc(10*sizeof(char));
	int i;
	
	for(i=0;i<10;i++)
	{
		ptr[i]='a';
		if(i==9)
		{
			free(ptr);
		}
	}
	free(ptr); /* ERROR: Double free */
}

/***********************************************************************
 *
 * Defect type: Double free
 * Complexity: Possible double free as a result of call to rand function
 *
 ***********************************************************************/
void double_free_004 ()
{
	char* ptr= (char*) malloc(10*sizeof(char));
	int i;

	for(i=0;i<10;i++)
	{
		*(ptr+i)='a';
	}

	if(rand () % 2 == 0)
	{
		free(ptr);
	}

	if(rand () % 3 == 0)
	{
		free(ptr); /* ERROR: Double free */
	}
}

/***********************************************************************
 *
 * Defect type: Double free
 * Complexity: Double free due to use of pointer in if statement conditon 
 *
 ***********************************************************************/
void double_free_005 ()
{
	char* ptr= (char*) malloc(sizeof(char));
	
	free(ptr);
	if(ptr)
	{
		free(ptr); /* ERROR: Double free */
	}
}

/***********************************************************************
 *
 * Defect type: Double free
 * Complexity: Double free due to excessive free in constant if statement
 *
 ***********************************************************************/
void double_free_006 ()
{
	char* ptr= (char*) malloc(sizeof(char));
	
	if(1)
	{
		free(ptr);
	}
	free(ptr); /* ERROR: Double free */
}

/***********************************************************************
 *
 * Defect type: Double free
 * Complexity: Double free due to excessive free in variable if statement
 *
 ***********************************************************************/
void double_free_007 ()
{
	char* ptr= (char*) malloc(sizeof(char));
	int flag=0;
	
	if(flag>=0)
	{
		free(ptr);
	}
	free(ptr); /* ERROR: Double free */
}

/***********************************************************************
 *
 * Defect type: Double free
 * Complexity: Double free due to excessive free in a called function
 *
 ***********************************************************************/
char *double_free_function_008_gbl_ptr;

void double_free_function_008 ()
{
	free (double_free_function_008_gbl_ptr);
}

void double_free_008 ()
{
	double_free_function_008_gbl_ptr = (char*) malloc(sizeof(char));

	double_free_function_008 ();
	free(double_free_function_008_gbl_ptr); /* ERROR: Double free */
}

/***********************************************************************
 *
 * Defect type: Double free
 * Complexity: Double free due to free in while loop with a constant loop control expression
 *
 ***********************************************************************/
void double_free_009 ()
{
	char* ptr= (char*) malloc(sizeof(char));

	while(1)
	{
		free(ptr); /* ERROR: Double free */
	}
}

/***********************************************************************
 *
 * Defect type: Double free
 * Complexity: Double free due to excessive free in a while loop with a variable loop control expression
 *
 ***********************************************************************/
void double_free_010 ()
{
	char* ptr= (char*) malloc(sizeof(char));
	int flag = 1;

	while(flag)
	{
		free(ptr);
		flag--;
	}
	free(ptr); /* ERROR: Double free */
}

/***********************************************************************
 *
 * Defect type: Double free
 * Complexity: Double free due to  free on multiple iterations of a while loop 
 *
 ***********************************************************************/
void double_free_011 ()
{
	char* ptr= (char*) malloc(sizeof(char));
	int flag = 1, a = 0, b = 2;

	while(a<b)
	{
		if(flag == 1)
		{
			free(ptr); /* ERROR: Double free */
			a++;
		}
	}
}

/***********************************************************************
 *
 * Defect type: Double free
 * Complexity: Double free due to  free on multiple iterations of a for loop 
 *
 ***********************************************************************/
void double_free_012 ()
{
	char* ptr= (char*) malloc(sizeof(char));
	int a=0;

	for(a=0;a<2;a++)
	{
		free(ptr); /* ERROR: Double free */
	}
}

/***********************************************************************
 *
 * Defect type: Double free
 * Complexity: Double free due to  free on pointer aliases 
 *
 ***********************************************************************/
void double_free_013 (void)
{
	char *a = calloc(16, sizeof(char));
	char *b = a;
	
	free(b);
	free(a); /* ERROR: Double free */
}

/***********************************************************************
 *
 * Defect type: Double free
 * Main 
 *
 ***********************************************************************/
extern volatile int vflag;

void double_free_main  ()
{
	if (vflag == 1 || vflag == 888)
	{
		double_free_001  ();
	}

    	if (vflag == 2 || vflag == 888)
    	{
    		double_free_002  ();
    	}

    	if (vflag == 3 || vflag == 888)
    	{
    		double_free_003  ();
    	}

    	if (vflag == 4 || vflag == 888)
    	{
    		double_free_004  ();
    	}

    	if (vflag == 5 || vflag == 888)
    	{
    		double_free_005  ();
    	}

    	if (vflag == 6 || vflag == 888)
    	{
    		double_free_006  ();
   	}

    	if (vflag == 7 || vflag == 888)
    	{
    		double_free_007  ();
    	}

    	if (vflag == 8 || vflag == 888)
    	{
    		double_free_008  ();
    	}

    	if (vflag == 9 || vflag == 888)
    	{
    		double_free_009  ();
    	}

    	if (vflag == 10 || vflag == 888)
    	{
    		double_free_010  ();
    	}

    	if (vflag == 11 || vflag == 888)
    	{
    		double_free_011  ();
    	}

    	if (vflag == 12 || vflag == 888)
    	{
    		double_free_012  ();
    	}
    
    	if (vflag == 13 || vflag == 888)
    	{
    		double_free_013  ();
    	}
}
