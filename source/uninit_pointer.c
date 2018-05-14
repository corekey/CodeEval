/***********************************************************************
 *
 * Defect Classification
 * ---------------------
 * Description: Defect code used to identify uninitialized pointer use
 *
 ***********************************************************************/

#include "HeaderFile.h"

/***********************************************************************
 *
 * Defect type: Uninitialized pointer
 * Complexity: Read of uninitialized pointer
 *
 ***********************************************************************/
void uninit_pointer_001 (int flag)
{
	char 	 cret, *cptr, a = 1; 
	short 	 sret, *sptr, b = 1; 
	int 	 iret, *iptr, c = 1; 
	unsigned uret, *uptr, d = 1; 
	long 	 lret, *lptr, e = 1; 
	float 	 fret, *fptr, f = 1; 
	double 	 dret, *dptr, g = 1; 

	switch (flag)
	{
		case 1: cret = *cptr; /* ERROR: Uninitialized pointer */
			break;
		case 2: sret = *sptr; /* ERROR: Uninitialized pointer */
			break;
		case 3: iret = *iptr; /* ERROR: Uninitialized pointer */
			break;
		case 4: uret = *uptr; /* ERROR: Uninitialized pointer */
			break;
		case 5: lret = *lptr; /* ERROR: Uninitialized pointer */
			break;
		case 6: fret = *fptr; /* ERROR: Uninitialized pointer */
			break;
		case 7: dret = *dptr; /* ERROR: Uninitialized pointer */
			break;
		default:
			break;
	}
}

/***********************************************************************
 *
 * Defect type: Uninitialized pointer
 * Complexity: Write to uninitialized pointer
 *
 ***********************************************************************/
void uninit_pointer_002 (int flag)
{
	char 	 *cptr, a = 1; 
	short 	 *sptr, b = 1; 
	int 	 *iptr, c = 1; 
	unsigned *uptr, d = 1; 
	long 	 *lptr, e = 1; 
	float 	 *fptr, f = 1; 
	double 	 *dptr, g = 1; 

	switch (flag)
	{
		case 1: *cptr = 1; /* ERROR: Uninitialized pointer */
			break;
		case 2: *sptr = 1; /* ERROR: Uninitialized pointer */
			break;
		case 3: *iptr = 1; /* ERROR: Uninitialized pointer */
			break;
		case 4: *uptr = 1; /* ERROR: Uninitialized pointer */
			break;
		case 5: *lptr = 1; /* ERROR: Uninitialized pointer */
			break;
		case 6: *fptr = 1; /* ERROR: Uninitialized pointer */
			break;
		case 7: *dptr = 1; /* ERROR: Uninitialized pointer */
			break;
		default:
			break;
	}
}

/***********************************************************************
 *
 * Defect type: Uninitialized pointer
 * Complexity: Read of uninitialized pointer using double pointer dereference
 *
 ***********************************************************************/
void uninit_pointer_003 ()
{
	int **pp;
	int *p;
	int a = 0;
	int ret;
	
	pp = &p;
	ret = **pp; /* ERROR: Uninitialized pointer */
}

/***********************************************************************
 *
 * Defect type: Uninitialized pointer
 * Complexity: Read of uninitialized pointer function argument
 *
 ***********************************************************************/
void uninit_pointer_004_func_001 (int *p)
{
	int ret;
	ret = *p; /* ERROR: Uninitialized pointer */
}
void uninit_pointer_004 ()
{
	int a = 0;
	int *p;
	uninit_pointer_004_func_001(p); 
}

/***********************************************************************
 *
 * Defect type: Uninitialized pointer
 * Complexity: Read of partially ininitialized 2D array 
 *
 ***********************************************************************/
void uninit_pointer_005_func_001 (int *pbuf[])
{
	int buf1[6] = {1, 2, 3, 4, 5, 6};
	int buf2[6] = {1, 2, 3, 4, 5, 6};
	int buf3[6] = {1, 2, 3, 4, 5, 6};
	int buf4[6] = {1, 2, 3, 4, 5, 6};
	int buf5[6] = {1, 2, 3, 4, 5, 6};
	int ret;
	
	pbuf[0] = buf1;
	pbuf[2] = buf3;
	pbuf[3] = buf4;
	pbuf[4] = buf5;
	ret = *((pbuf[1]) + 1); /* ERROR: Uninitialized pointer */
}
void uninit_pointer_005 ()
{
	int *pbuf[5];
	
	uninit_pointer_005_func_001(pbuf);
}

/***********************************************************************
 *
 * Defect type: Uninitialized pointer
 * Complexity: Write to uninitialized pointer argument 
 *
 ***********************************************************************/
void uninit_pointer_006_func_001 (int **pp)
{
	**pp = 1; /* ERROR: Uninitialized pointer */
}

void uninit_pointer_006 ()
{
	int a;
	int *p;
	uninit_pointer_006_func_001(&p);
}

/***********************************************************************
 *
 * Defect type: Uninitialized pointer
 * Complexity: Write to 2D array with partially initialized spine 
 *
 ***********************************************************************/
void uninit_pointer_007 ()
{
        char *buf1=strdup("String1");
	char *buf2;
	char *buf3=strdup("String3");
	char *buf4=strdup("String4");
	char *buf5=strdup("String5");
        
	if (!buf1 || !buf3 || !buf4 || !buf5) { return;}
	
	char **pbuf[5] = {&buf2, &buf3, &buf4, &buf5};
	int i,j=4;

	for(i=0;i<5;i++)
	{
		*((*pbuf[i])+j)='a'; /* ERROR: Uninitialized pointer */
	}
        free(buf1);
        free(buf3);
        free(buf4);
        free(buf5);
}

/***********************************************************************
 *
 * Defect type: Uninitialized pointer
 * Complexity: Passing of structure with uninitialized member to function 
 *
 ***********************************************************************/
typedef struct {
	int a;
	int b;
	int uninit;
} uninit_pointer_structure;

void uninit_pointer_008_func_001 (uninit_pointer_structure *p)
{
	int ret;
	p->uninit=ret;
}
void uninit_pointer_008 ()
{
	uninit_pointer_structure s;
	s.a = 1;
	s.b = 1;
	uninit_pointer_008_func_001(&s); /* ERROR: Uninitialized pointer */
}

/***********************************************************************
 *
 * Defect type: Uninitialized pointer
 * Complexity: Use of memcpy with uninitialized arguments 
 *
 ***********************************************************************/
void uninit_pointer_009()
{
	char *buf,buf1[25];
	int flag=10;

	if(flag ==0)
	{
		buf = "This is a string";
	}
    	
	if(flag > 0)
    	{
    		strcpy(buf1,buf); /* ERROR: Uninitialized pointer */
    	}
}

/***********************************************************************
 *
 * Defect type: Uninitialized pointer
 * Complexity: Equating pointer to uninitialized pointer using cast 
 *
 ***********************************************************************/
void uninit_pointer_010_func_001 (void * vptr)
{
    	/* cast void pointer to a pointer of the appropriate type */
    	char * * cptr = (char * *)vptr;
    	char * buf;
    	buf = (*cptr); /* ERROR: Uninitialized pointer */
}

void uninit_pointer_010 ()
{
    	void *buf1;
    	uninit_pointer_010_func_001(&buf1);
}

/***********************************************************************
 *
 * Defect type: Uninitialized pointer
 * Complexity: Read of array, partially initialized in for loop 
 *
 ***********************************************************************/
void uninit_pointer_011 ()
{
    	unsigned int * ptr,a=0;
    	ptr = (unsigned int *)malloc(10*sizeof(unsigned int *));
    	int i;
	
	if (ptr!=NULL)
	{
           	for(i=0;i<10/2;i++)
           	{
            		ptr[i] = i;
           	}
         	
		for(i=0;i<10;i++)
          	{
          		a += ptr[i]; /* ERROR: Uninitialized pointer */
        	}
	}
}

/***********************************************************************
 *
 * Defect type: Uninitialized pointer
 * Complexity: Read of array, partially initialized in declaration 
 *
 ***********************************************************************/
void uninit_pointer_012 ()
{
	int **ptr = (int**) malloc(5*sizeof(int*));
	int i,j;

	for(i=0;i<5;i++)
	{
		ptr[i]=(int*) malloc(5*sizeof(int));
	}
	
	int arr[3][3] = {{1,2,3},
		         {11,12,13},
	                 {21,22,23}};

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			*(*(ptr+i)+j)= arr[i][j]; /* ERROR: Uninitialized pointer */
		}
	    	free(ptr[i]);
	    	ptr[i] = NULL;
	}
	free(ptr);
	ptr = NULL;
}

/***********************************************************************
 *
 * Defect type: Uninitialized pointer
 * Complexity: Assignment of partially initialized structure to another structure 
 *
 ***********************************************************************/
uninit_pointer_structure *s;

void uninit_pointer_013_func_001 (int flag)
{
	switch (flag)
	{
		case 1:
		{
			s = (uninit_pointer_structure *)calloc(1,sizeof(uninit_pointer_structure));
			if(s!=NULL)
			{
				s->a = 10;
			    	s->b = 10;
			}
			break;
		}
		case 2:
		{
			s = (uninit_pointer_structure *)calloc(1,sizeof(uninit_pointer_structure));
			if(s!=NULL)
			{
				s->a = 20;
			    	s->b = 20;
			}
			break;
		}
		default:
		{
			break;
		}

	}
}

void uninit_pointer_013 ()
{
	uninit_pointer_structure r;
	
	uninit_pointer_013_func_001 (1);
	if(s!=NULL)
	{
		r = *s; /* ERROR: Uninitialized pointer */
	    	free(s);
	}
}

/***********************************************************************
 *
 * Defect type: Uninitialized pointer
 * Complexity: Assignment of partially initialized array of floats 
 *
 ***********************************************************************/
void uninit_pointer_014 ()
{
	float * fptr;
	float arr[10];
	int i;
	
	fptr = arr;
	for(i=0; i<10/2; i++)
	{
		fptr[i] = (float)i;
	}

	for(i=0; i<10; i++)
	{
		arr[i] = ++fptr[i]; /* ERROR: Uninitialized pointer */
	}
}

/***********************************************************************
 *
 * Defect type: Uninitialized pointer
 * Complexity: Enumeration used to initialize value of empty pointer 
 *
 ***********************************************************************/
typedef enum
{
	ZERO,
	ONE,
	TWO 
} values;

void uninit_pointer_015_func_001 (int *ptr )
{
	values val = ONE;
	*ptr = val; /* ERROR: Uninitialized pointer */
}

void uninit_pointer_015 ()
{
    	int  *ptr;
    	uninit_pointer_015_func_001(ptr);
}

/***********************************************************************
 *
 * Defect type: Uninitialized pointer
 * Complexity: Global pointer partially initialized and copied using strcpy  
 *
 ***********************************************************************/
char ** uninit_pointer_016_gbl_doubleptr;

void uninit_pointer_016_func_001()
{
	int i, flag = 0;
	
	if(flag == 0)
	{
		uninit_pointer_016_gbl_doubleptr = (char**) malloc(10*sizeof(char*));
    		for(i=0;i<10;i++)
	    	{
    			uninit_pointer_016_gbl_doubleptr[i]=(char*) malloc(10*sizeof(char));
			if(i<5)
    		   	{
				strcpy(uninit_pointer_016_gbl_doubleptr[i],"STRING00");
	   		}
		}
	}
}

void uninit_pointer_016()
{
	int flag = 0, i;
	char *s=(char*) malloc(10*sizeof(char));
	
	if(flag == 0)
	{
		uninit_pointer_016_func_001();
	}

	if(uninit_pointer_016_gbl_doubleptr!=NULL)
	{
		for(i=0;i<10;i++)
		{
			if(uninit_pointer_016_gbl_doubleptr[i] !=NULL)
			{
				if(i==7)
				{    
					strcpy(s,uninit_pointer_016_gbl_doubleptr[i]); /* ERROR: Uninitialized pointer */
				}
				free (uninit_pointer_016_gbl_doubleptr[i]);
			}
	    	}
	    	free(uninit_pointer_016_gbl_doubleptr);
	    	free(s);
	}
}

/***********************************************************************
 *
 * Types of defects: Uninitialized pointer
 * Complexity: char variable initialized with function return value using enumeration
 * http://www.gimpel.com/html/newbugs/bug530.htm
 *
 ***********************************************************************/
void uninit_pointer_017_func_001( char *x )
{
	enum { N = 5 };
	const char * const names[N] = { "Red Sox", "Yankees", "Giants", "Rangers", "Phillies" /* etc. */ };

	x = (char *)malloc(100);
	if( x )
	{
		strcpy( x, names[ N-1 ] );
	}
}

void uninit_pointer_017 (void)
{
	char *x;

	uninit_pointer_017_func_001(x); /* ERROR: Uninitialized pointer */
}

/***********************************************************************
 *
 * Defect type: Uninitialized pointer
 * Main 
 *
 ***********************************************************************/
extern volatile int vflag;

void uninit_pointer_main ()
{
	if (vflag == 1 || vflag == 888)
	{
		uninit_pointer_001(3);
	}

	if (vflag == 2 || vflag == 888)
	{
		uninit_pointer_002(3);
	}

	if (vflag == 3 || vflag == 888)
	{
		uninit_pointer_003();
	}

	if (vflag == 4 || vflag == 888)
	{
		uninit_pointer_004();
	}

	if (vflag == 5 || vflag == 888)
	{
		uninit_pointer_005();
	}

	if (vflag == 6 || vflag == 888)
	{
		uninit_pointer_006();
	}

	if (vflag == 7 || vflag == 888)
	{
		uninit_pointer_007();
	}

	if (vflag == 8 || vflag == 888)
	{
		uninit_pointer_008();
	}

	if (vflag == 9 || vflag == 888)
	{
		uninit_pointer_009();
	}

	if (vflag == 10 || vflag == 888)
	{
		uninit_pointer_010();
	}

	if (vflag == 11 || vflag == 888)
	{
		uninit_pointer_011();
	}

	if (vflag == 12 || vflag == 888)
	{
		uninit_pointer_012();
	}

	if (vflag == 13 || vflag == 888)
	{
		uninit_pointer_013();
	}

	if (vflag == 14 || vflag == 888)
	{
		uninit_pointer_014();
	}

	if (vflag == 15 || vflag == 888)
	{
		uninit_pointer_015();
	}

	if (vflag == 16 || vflag == 888)
	{
		uninit_pointer_016();
	}

	if (vflag == 17 || vflag == 888)
	{
		uninit_pointer_017();
	}
}
