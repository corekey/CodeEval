/***********************************************************************
 *
 * Defect Classification
 * ---------------------
 * Description: Defect code used to identify freeing of non dynamically allocated memory
 *
 ***********************************************************************/

#include "HeaderFile.h"

/***********************************************************************
 *
 * Defect type: Free non-dynamically allocated memory 
 * Complexity: Free non-dynamically allocated string in constant if statement 
 *
 ***********************************************************************/
void free_nondynamic_allocated_memory_001()
{
	char* ptr="a";
	
	if(1)
	{
		free(ptr); /* ERROR: Free non-dynamically allocated memory */
	}
}

/***********************************************************************
 *
 * Defect type: Free non-dynamically allocated memory 
 * Complexity: Free non-dynamically allocated string in if statement 
 *
 ***********************************************************************/
void free_nondynamic_allocated_memory_002()
{
	char* ptr="a";
	int flag=1;
	
	if(flag>0)
	{
		free(ptr); /* ERROR: Free non-dynamically allocated memory */
	}
}

/***********************************************************************
 *
 * Defect type: Free non-dynamically allocated memory 
 * Complexity: Free non-dynamically allocated global pointer  
 *
 ***********************************************************************/
char *gbl_ptr_003;

void free_nondynamic_allocated_memory_003()
{
	gbl_ptr_003 = "STRING"; /* ERROR: Free non-dynamically allocated memory */
	free(gbl_ptr_003);
}

/***********************************************************************
 *
 * Defect type: Free non-dynamically allocated memory 
 * Complexity: Free non-dynamically allocated pointer using pointer alias 
 *
 ***********************************************************************/
void free_nondynamic_allocated_memory_004()
{
	char **ptr;
	char *ptr1 = "STRING";
	
	ptr = &ptr1;
	free(ptr); /* ERROR: Free non-dynamically allocated memory */
}

/***********************************************************************
 *
 * Defect type: Free non-dynamically allocated memory 
 * Complexity: Free non-dynamically allocated spine of 2D character array
 *
 ***********************************************************************/
void free_nondynamic_allocated_memory_005()
{
	char *buf1=(char*)calloc(5,sizeof(char));
	char *buf2=(char*)calloc(5,sizeof(char));
	char **pbuf[2] = {&buf1, &buf2};
	int i,j=1;
	
	if(buf2 != NULL)
	{
		buf2[0] = 10.0;
	}
	for(i=0;i<2;i++)
	{
		*((*pbuf[i])+j)=5.0;
	}
	free(buf1);
	free(buf2);
	free(pbuf); /* ERROR: Free non-dynamically allocated memory */
}

/***********************************************************************
 *
 * Defect type: Free non-dynamically allocated memory 
 * Complexity: Free non-dynamically allocated pointer of various data types
 *
 ***********************************************************************/
void free_nondynamic_allocated_memory_006(int flag)
{
	short	a = 1;
	int 	b = 2;
	long 	c = 3;
	float 	d = 4.0;
	double 	e = 5.0;

	char	*cptr ="a";
	short 	*sptr = &a;
	int	*iptr = &b;
	long 	*lptr = &c;
	float   *fptr = &d;
	double  *dptr = &e;

	switch(flag)
	{
		case 1: free(cptr); /* ERROR: Free non-dynamically allocated memory */
			break;
		case 2: free(sptr); /* ERROR: Free non-dynamically allocated memory */
			break;
		case 3: free(iptr); /* ERROR: Free non-dynamically allocated memory */
			break;
		case 4: free(lptr); /* ERROR: Free non-dynamically allocated memory */
			break;
		case 5: free(fptr); /* ERROR: Free non-dynamically allocated memory */
			break;
		case 6: free(dptr); /* ERROR: Free non-dynamically allocated memory */
			break;
		default:
			break;
	}
}

/***********************************************************************
 *
 * Defect type: Free non-dynamically allocated memory 
 * Complexity: Free non-dynamically allocated string in constant while loop
 *
 ***********************************************************************/
void free_nondynamic_allocated_memory_007()
{
	char* ptr="a";

	while(1)
	{
		free(ptr); /* ERROR: Free non-dynamically allocated memory */
	}
}

/***********************************************************************
 *
 * Defect type: Free non-dynamically allocated memory 
 * Complexity: Free non-dynamically allocated string in while loop
 *
 ***********************************************************************/
void free_nondynamic_allocated_memory_008()
{
	char* ptr="a";
	int a=2,b=0;
	
	while(a>b)
	{
		free(ptr); /* ERROR: Free non-dynamically allocated memory */
	}
}

/***********************************************************************
 *
 * Defect type: Free non-dynamically allocated memory 
 * Complexity: Free non-dynamically allocated string in for loop
 *
 ***********************************************************************/
void free_nondynamic_allocated_memory_009()
{
	int i;
	
	for(i=0;i<5;i++)
	{
		char* ptr="k";
		free(ptr); /* ERROR: Free non-dynamically allocated memory */
	}
}

/***********************************************************************
 *
 * Defect type: Free non-dynamically allocated memory 
 * Complexity: Free non-dynamically allocated string in if statement nested in while loop
 *
 ***********************************************************************/
void free_nondynamic_allocated_memory_010()
{
	char* ptr="a";
	int a=0,b=2;
	while(a<b)
	{
		a++;
		if(a==1)
		{
			free(ptr); /* ERROR: Free non-dynamically allocated memory */
		}
	}
}

/***********************************************************************
 *
 * Defect type: Free non-dynamically allocated memory 
 * Complexity: Free non-dynamically allocated structure member 
 *
 ***********************************************************************/
typedef struct node
{
	int a;
	struct node * next;

} free_nondynamic_allocated_memory_structure;

void free_nondynamic_allocated_memory_011()
{
	free_nondynamic_allocated_memory_structure* new_struct = malloc(sizeof(free_nondynamic_allocated_memory_structure));
	free_nondynamic_allocated_memory_structure str;
	new_struct->next = &str;
	free(new_struct->next); /* ERROR: Free non-dynamically allocated memory */
	free(new_struct);
}

/***********************************************************************
 *
 * Defect type: Free non-dynamically allocated memory 
 * Complexity: Free non-dynamically allocated global pointer 
 *
 ***********************************************************************/
free_nondynamic_allocated_memory_structure * gbl_str_012;

void free_nondynamic_allocated_memory_012()
{
	free_nondynamic_allocated_memory_structure free_nondynamic_allocated_memory_st ;
	gbl_str_012= &free_nondynamic_allocated_memory_st;
	free(gbl_str_012); /* ERROR: Free non-dynamically allocated memory */
}

/***********************************************************************
 *
 * Defect type: Free non-dynamically allocated memory 
 * Complexity: Free non-dynamically allocated global pointer in another function
 *
 ***********************************************************************/
char *gbl_ptr_013;

void free_nondynamic_allocated_memory_013_func_001()
{
	free(gbl_ptr_013); /* ERROR: Free non-dynamically allocated memory */
}

void free_nondynamic_allocated_memory_013()
{
	gbl_ptr_013 = "STRING";
	free_nondynamic_allocated_memory_013_func_001();
}

/***********************************************************************
 *
 * Defect type: Free non-dynamically allocated memory 
 * Complexity: Global variable , variable set in another In a function
 *
 ***********************************************************************/
char *gbl_ptr_014;

char free_nondynamic_allocated_memory_014_gbl_var;

void free_nondynamic_allocated_memory_014_func_001()
{
	gbl_ptr_014 = "STRING";
}

void free_nondynamic_allocated_memory_014_func_002()
{
	if(free_nondynamic_allocated_memory_014_gbl_var =='A')
	{
	   	free(gbl_ptr_014); /*ERROR:Free memory not allocated dynamically*/
	}
}

void free_nondynamic_allocated_memory_014()
{
	free_nondynamic_allocated_memory_014_gbl_var = 'A';
	free_nondynamic_allocated_memory_014_func_001();
	free_nondynamic_allocated_memory_014_func_002();
}

/***********************************************************************
 *
 * Defect type: Free non-dynamically allocated memory 
 * Main 
 *
 ***********************************************************************/
extern volatile int vflag;

void free_nondynamic_allocated_memory_main ()
{
	if (vflag == 1 || vflag == 888)
	{
		free_nondynamic_allocated_memory_001();
	}

	if (vflag == 2 || vflag == 888)
	{
		free_nondynamic_allocated_memory_002();
	}

	if (vflag == 3 || vflag == 888)
	{
		free_nondynamic_allocated_memory_003();
	}

	if (vflag == 4 || vflag == 888)
	{
		free_nondynamic_allocated_memory_004();
	}

	if (vflag == 5 || vflag == 888)
	{
		free_nondynamic_allocated_memory_005();
	}

	if (vflag == 6 || vflag == 888)
	{
		free_nondynamic_allocated_memory_006(3);
	}

	if (vflag == 7 || vflag == 888)
	{
		free_nondynamic_allocated_memory_007();
	}

	if (vflag == 8 || vflag == 888)
	{
		free_nondynamic_allocated_memory_008();
	}

	if (vflag == 9 || vflag == 888)
	{
		free_nondynamic_allocated_memory_009();
	}

	if (vflag == 10 || vflag == 888)
	{
		free_nondynamic_allocated_memory_010();
	}

	if (vflag == 11 || vflag == 888)
	{
		free_nondynamic_allocated_memory_011();
	}

	if (vflag == 12 || vflag == 888)
	{
		free_nondynamic_allocated_memory_012();
	}

	if (vflag == 13 || vflag == 888)
	{
		free_nondynamic_allocated_memory_013();
	}

	if (vflag == 14 || vflag == 888)
	{
		free_nondynamic_allocated_memory_014();
	}
}
