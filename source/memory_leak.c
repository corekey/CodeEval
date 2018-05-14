/***********************************************************************
 *
 * Defect Classification
 * ---------------------
 * Description: Defect code used to identify memory leak 
 *
 ***********************************************************************/

#include "HeaderFile.h"

int rand (void);

/***********************************************************************
 *
 * Defect type: Memory leak 
 * Complexity: Memory leak due to non-terminating for loop
 *
 ***********************************************************************/
void memory_leak_001 ()
{
	int i;
	char *buf;
	for (i=0;;i++)
	{
		buf=(char*) calloc(5,sizeof(char)); /* ERROR: Memory leak */
		if(buf!=NULL)
		{
			buf[0]=1;
		}
	}
} 

/***********************************************************************
 *
 * Defect type: Memory leak 
 * Complexity: Only spine of 2D array is freed
 *
 ***********************************************************************/
void memory_leak_002 ()
{
	int **ptr = (int**) malloc(5*sizeof(int*));
	int i,j;

	for(i=0;i<5;i++)
	{
		ptr[i]=(int*) malloc(5*sizeof(int)); /* ERROR: Memory leak */
	}

	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			*(*(ptr+i)+j)=i;
		}
	}
	free(ptr);
} 

/***********************************************************************
 *
 * Defect type: Memory leak 
 * Complexity: Dynamically allocated string not freed 
 *
 ***********************************************************************/
void memory_leak_003_func_001 (int len,char **stringPtr)
{
	char * p = malloc(sizeof(char) * (len+1)); /* ERROR: Memory leak */
	*stringPtr = p;
}

void memory_leak_003 ()
{
	char *str = "This is a string";
	char *str1;
	memory_leak_003_func_001(strlen(str),&str1);
	strcpy(str1,str);
}

/***********************************************************************
 *
 * Defect type: Memory leak 
 * Complexity: Dynamically allocated structure member not freed 
 *
 ***********************************************************************/
typedef struct {
	int a;
	int b;
	char *buf;

} memory_leak_004_s_001;

void memory_leak_004 ()
{
	memory_leak_004_s_001* s=(memory_leak_004_s_001*) calloc(5,sizeof(memory_leak_004_s_001)) ;
	char *s1="This is a string";
	int i;
	
	if(s!=NULL)
	{
		for(i= 0; i<5 ;i++)
		{
			(s+i)->buf = (char*)malloc(25* sizeof(char)); /* ERROR: Memory leak */
		}
	}
	strcpy((s+4)->buf,s1);
	free(s);
} 

/***********************************************************************
 *
 * Defect type: Memory leak 
 * Complexity: Free of dynamically allocated memory appears inside if statement that never executes 
 *
 ***********************************************************************/
void memory_leak_005()
{
	float *ptr;
	int flag=10;

	if(flag > 0)
	{
		ptr= (float*) malloc(5*sizeof(float)); /* ERROR: Memory leak */
		if(ptr!=NULL)
		{
        		*(ptr+1) = 10.5;
		}
	}
    	
	if(flag < 0)
    	{
		free(ptr);
	}
}

/***********************************************************************
 *
 * Defect type: Memory leak 
 * Complexity: Free of dynamically allocated memory appears inside if statement that never executes 
 *
 ***********************************************************************/
void memory_leak_006()
{
	double *dptr;
	int flag=0;

	if(flag == 0)
	{
		dptr= (double*) malloc(5*sizeof(double)); /* ERROR: Memory leak */
		if(dptr!=NULL)
		{
           		*(dptr+1) = 10.50000;
		}
	}
    
    	if(flag !=0)
	{
		free(dptr);
	}
}

/***********************************************************************
 *
 * Defect type: Memory leak 
 * Complexity: Certain paths of switch statement lead to leaked memory 
 *
 ***********************************************************************/
void *vptr;

int memory_leak_007_func_001 (int flag)
{
	switch (flag)
	{
		case 1:
		{
			vptr = (int *)calloc(10, sizeof(int)); /* ERROR: Memory leak */
			if(vptr!=NULL)
			{
			   	*((int*)vptr+1) = 10;
			}
			return 1;
		}
		case 2:
		{
			vptr = (char *)calloc(10, sizeof(char)); /* ERROR: Memory leak */
			if(vptr!=NULL)
			{
			   	*((char*)vptr+2) = 'a';
			}
			return 2;
		}
		case 3:
		{
			vptr = (float *)calloc(10, sizeof(float)); /* ERROR: Memory leak */
			if(vptr!=NULL)
			{
			   	*((float*)vptr+3) = 5.5;
			}
			return 3;
		}
		default:
			return -1;
	}
}

void memory_leak_007 ()
{
	int ret;
	
	ret = memory_leak_007_func_001 (rand());
	if(ret == 0)
	{
		if(vptr!=NULL)
		{
			free(vptr);
		}
	}
} 

/***********************************************************************
 *
 * Defect type: Memory leak 
 * Complexity: Pointer alias not freed 
 *
 ***********************************************************************/
void memory_leak_008 ()
{
	int *ptr = (int*) malloc(5 * sizeof(int));
	int *p = (int*) malloc(5 * sizeof(int)); /* ERROR: Memory leak */
	 
	if(ptr !=NULL)
	{
		p = ptr;
		*(p+1) = 1;
		free(ptr);
	}
} 

/***********************************************************************
 *
 * Defect type: Memory leak 
 * Complexity: Pointer alias cast to different type not freed 
 *
 ***********************************************************************/
void memory_leak_009 ()
{
	float *ptr=(float*) malloc(5 * sizeof(float));
	int *p = (int*) malloc(5 * sizeof(int)); /* ERROR: Memory leak */
	
	if(ptr !=NULL)
	{
          	p = (int *)ptr;
	   	*(p+1) = 1.5;
	   	free (ptr);
	   	ptr = NULL;
	}
} 

/***********************************************************************
 *
 * Defect type: Memory leak 
 * Complexity: Pointer alias not freed
 *
 ***********************************************************************/
void memory_leak_010 ()
{
	int *ptr = (int*) calloc(5,sizeof(int));
	int *p1 = (int*) calloc(5,sizeof(int)); /* ERROR: Memory leak */
	int *p2 = NULL;
	
	p1 = ptr;
	p2 = p1;
	*(p2+4) = 1;
	free(ptr);
} 

/***********************************************************************
 *
 * Defect type: Memory leak 
 * Complexity: Array assigned to union member not freed  
 *
 ***********************************************************************/
typedef union {
    char * u1;
    char * u2;
} memory_leak_011_uni_001;

void memory_leak_011()
{
    	char * buf = NULL;
    	memory_leak_011_uni_001 un;
    	buf = (char *)calloc(50, sizeof(char)); /* ERROR: Memory leak */
	
	if(buf!=NULL)
	{
    		strcpy(buf, "This Is A String");
    		un.u1 = buf;
	}
    	buf = un.u2;
}

/***********************************************************************
 *
 * Defect type: Memory leak 
 * Complexity: Dynamically allocated union not freed 
 *
 ***********************************************************************/
typedef struct {
	int a;
	int b;
} memory_leak_012_s_001;

typedef struct {
	int a;
	int b;
} memory_leak_012_s_002;

typedef struct {
	int a;
	int b;
} memory_leak_012_s_003;

typedef union {
	memory_leak_012_s_001 s1;
	memory_leak_012_s_002 s2;
	memory_leak_012_s_003 s3;
} memory_leak_union;

void memory_leak_012 ()
{
	memory_leak_union *u = (memory_leak_union * )malloc(5*sizeof( memory_leak_union ));
	memory_leak_union *p = (memory_leak_union * )malloc(5*sizeof( memory_leak_union )); /* ERROR: Memory leak */
	p = u;
	p->s1.a = 1;
	free(u);
}

/***********************************************************************
 *
 * Defect type: Memory leak 
 * Complexity: Dynamically allocated union and union members not freed 
 *
 ***********************************************************************/
typedef struct{
	int a;
	int b;
} memory_leak_013_s_001;

typedef struct {
	int a;
	int b;
} memory_leak_013_s_002;

typedef struct {
	int a;
	int b;
} memory_leak_013_s_003;

typedef union {
	memory_leak_013_s_001 *s1;
	memory_leak_013_s_002 *s2;
	memory_leak_013_s_003 *s3;
} memory_leak_013_uni_001;

void memory_leak_013 ()
{
	memory_leak_013_uni_001 *u = (memory_leak_013_uni_001 * )malloc(5*sizeof( memory_leak_013_uni_001 ));
	
	if(u!=NULL)
	{
		u->s1 = (memory_leak_013_s_001 *) malloc(sizeof(memory_leak_013_s_001));
	}
	
	memory_leak_013_uni_001 *p  = (memory_leak_013_uni_001 * )malloc(5*sizeof( memory_leak_013_uni_001 )); /* ERROR: Memory leak */
	p->s1 = (memory_leak_013_s_001 *) malloc(sizeof(memory_leak_013_s_001));
	
	if(u!=NULL)
	{
		p = u;
		p->s1->a = 1;
    		free(p->s1);
		free(p);
	}
}

/***********************************************************************
 *
 * Defect type: Memory leak 
 * Complexity: Dynamically allocated pointer with multiple aliases not freed 
 *
 ***********************************************************************/
void memory_leak_014 ()
{
   	float * fptr = NULL;
    	float **fp1 = &fptr;
    	float **fp2 = &fptr;
        float * fptr3 = *fp1;
    	
        fptr = (float *)calloc(10, sizeof(float)); /* ERROR: Memory leak */
        
	if(fptr!=NULL)
        {
        	*(fptr+3) = 50.5;
        	*fp1 = fptr;
        }
        float * fptr1;
        fptr1 = *fp2;
} 

/***********************************************************************
 *
 * Defect type: Memory leak 
 * Complexity: Memory allocated and returned from one function for use in another function not freed
 *
 ***********************************************************************/
char * memory_leak_015_func_001 (int len)
{
	char *stringPtr = malloc(sizeof(char) * (len+1)); /* ERROR: Memory leak */

	return stringPtr;
}

void memory_leak_015 ()
{
	char *str = "This is a string";
	char *str1 = memory_leak_015_func_001(strlen(str));
	if(str1!=NULL)
	{
	    strcpy(str1,str);
	}
}

/***********************************************************************
 *
 * Defect type: Memory leak 
 * Complexity: Memory allocated in a function and used in another function not freed
 *
 ***********************************************************************/
# define INDEX 'a'

static unsigned char a =INDEX;

char * memory_leak_016_gbl_ptr;

void memory_leak_016_func_001 (int len)
{
	memory_leak_016_gbl_ptr=NULL;
	if(a == INDEX)
	{
		memory_leak_016_gbl_ptr= malloc(sizeof(char) * (len+1)); /* ERROR: Memory leak */
	}
}

void memory_leak_016 ()
{
	char *str = "This is a string";
	memory_leak_016_func_001(strlen(str));
	strcpy(memory_leak_016_gbl_ptr,str);
}

/***********************************************************************
 *
 * Defect type: Memory leak 
 * Complexity: Double pointer to long allocated but not freed 
 *
 ***********************************************************************/
long ** memory_leak_017_gbl_doubleptr;

void memory_leak_017_func_001()
{
	int i,j;
	memory_leak_017_gbl_doubleptr=(long**) malloc(10*sizeof(long*)); /* ERROR: Memory leak */

	for(i=0;i<10;i++)
	{
		memory_leak_017_gbl_doubleptr[i]=(long*) malloc(10*sizeof(long));
	}
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			memory_leak_017_gbl_doubleptr[i][j]=i;
		}
	}
}

void memory_leak_017()
{
	int flag=0,i,j;
	memory_leak_017_gbl_doubleptr=NULL;
goto label;

    	if(flag == 0)
	{
		for(i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
			{
				memory_leak_017_gbl_doubleptr[i][j] += 1;
			}
			free (memory_leak_017_gbl_doubleptr[i]);
			memory_leak_017_gbl_doubleptr[i] = NULL;
		}
	}

label:
    	if(flag == 0)
    	{
    		memory_leak_017_func_001();
    	}
}

/***********************************************************************
 *
 * Defect type: Memory leak 
 * Complexity: Double pointer to long allocated but not freed 
 *
 ***********************************************************************/
char **memory_leak_018dst;

void memory_leak_018_func_001()
{
	memory_leak_018dst = NULL;
	int i;
	while(1)
	{
		memory_leak_018dst = (char**) malloc(5*sizeof(char*));
	    	for(i=0;i<5;i++)
		{
			memory_leak_018dst[i]=(char*) malloc(15*sizeof(char)); /* ERROR: Memory leak */
		}
		break;
	}
}

void memory_leak_018 ()
{
	int i;

    	memory_leak_018_func_001();
    	for(i=0;i<5;i++)
    	{
    		strcpy (memory_leak_018dst[i],"STRING");
    	}
	
	while(1)
	{
		for(i=0;i<5;i++)
	    	{	
                	;
	    	}	
	    
	    	free(memory_leak_018dst);
	    	memory_leak_018dst = NULL;
	    	break;
	}
}

/***********************************************************************
 *
 * Defect type: Memory leak 
 * Complexity: Failure to close file 
 *
 ***********************************************************************/
void memory_leak_019 ()
{
	FILE * ptr = fopen("memory_leak.txt", "r"); /* ERROR: Memory leak */
	if (ptr == NULL) { return; }
}

/***********************************************************************
 *
 * Defect type: Memory leak 
 * Main 
 *
 ***********************************************************************/
extern volatile int vflag;

void memory_leak_main ()
{
	if (vflag == 1 || vflag == 888)
	{
		memory_leak_001();
	}

	if (vflag == 2 || vflag == 888)
	{
		memory_leak_002();
	}

	if (vflag == 3 || vflag == 888)
	{
		memory_leak_003();
	}

	if (vflag == 4 || vflag == 888)
	{
		memory_leak_004();
	}

	if (vflag == 5 || vflag == 888)
	{
		memory_leak_005();
	}

	if (vflag == 6 || vflag == 888)
	{
		memory_leak_006();
	}

	if (vflag == 7 || vflag == 888)
	{
		memory_leak_007();
	}

	if (vflag == 8 || vflag == 888)
	{
		memory_leak_008();
	}

	if (vflag == 9 || vflag == 888)
	{
		memory_leak_009();
	}

	if (vflag == 10 || vflag == 888)
	{
		memory_leak_010();
	}

	if (vflag == 11 || vflag == 888)
	{
		memory_leak_011();
	}

	if (vflag == 12 || vflag == 888)
	{
		memory_leak_012();
	}

	if (vflag == 13 || vflag == 888)
	{
		memory_leak_013();
	}

	if (vflag == 14 || vflag == 888)
	{
		memory_leak_014();
	}

	if (vflag == 15 || vflag == 888)
	{
		memory_leak_015();
	}

	if (vflag == 16 || vflag == 888)
	{
		memory_leak_016();
	}

	if (vflag == 17 || vflag == 888)
	{
		memory_leak_017();
	}

	if (vflag == 18 || vflag == 888)
	{
		memory_leak_018();
	}
	
	if (vflag == 19 || vflag == 888)
	{
		memory_leak_019();
	}
}
