/***********************************************************************
 *
 * Defect Classification
 * ---------------------
 * Description: Defect code used to identify use of uninitialized variable
 *
 ***********************************************************************/

#include "HeaderFile.h"

/***********************************************************************
 *
 * Defect type: Uninitialized variable use 
 * Complexity: Read of uninitialized variable
 *
 ***********************************************************************/
void uninit_var_001 (int flag)
{
	char 	 cret, a;
	short 	 sret, b;
	unsigned uret, c;
	int 	 iret, d;
	long 	 lret, e;
	float 	 fret, f;
	double 	 dret, g;
	
	switch (flag)
	{
		case 1: cret = a; /* ERROR: Uninitialized variable */
			break;
		case 2: sret = b; /* ERROR: Uninitialized variable */
			break;
		case 3: uret = c; /* ERROR: Uninitialized variable */
			break;
		case 4: iret = d; /* ERROR: Uninitialized variable */
			break;
		case 5: lret = e; /* ERROR: Uninitialized variable */
			break;
		case 6: fret = f; /* ERROR: Uninitialized variable */
			break;
		case 7: dret = g; /* ERROR: Uninitialized variable */
			break;
		default:
			break;
	}
}

/***********************************************************************
 *
 * Defect type: Uninitialized variable use 
 * Complexity: Read of uninitialized array element
 *
 ***********************************************************************/
void uninit_var_002 (int flag)
{
	char 	 cbuf[5], cret;
	short 	 sbuf[5], sret;
	unsigned ubuf[5], uret;
	int 	 ibuf[5], iret;
	long 	 lbuf[5], lret;
	float 	 fbuf[5], fret;
	double 	 dbuf[5], dret;

	switch (flag)
	{
		case 1: cret = cbuf[3]; /* ERROR: Uninitialized variable */
			break;
		case 2: sret = sbuf[3]; /* ERROR: Uninitialized variable */
			break;
		case 3: uret = ubuf[3]; /* ERROR: Uninitialized variable */
			break;
		case 4: iret = ibuf[3]; /* ERROR: Uninitialized variable */
			break;
		case 5: lret = lbuf[3]; /* ERROR: Uninitialized variable */
			break;
		case 6: fret = fbuf[3]; /* ERROR: Uninitialized variable */
			break;
		case 7: dret = dbuf[3]; /* ERROR: Uninitialized variable */
			break;
		default:
			break;
	}
}

/***********************************************************************
 *
 * Defect type: Uninitialized variable use 
 * Complexity: Read of uninitialized 2D array element
 *
 ***********************************************************************/
void uninit_var_003 (int flag)
{
	char 	 cbuf[5][5], cret;
	short 	 sbuf[5][5], sret;
	unsigned ubuf[5][5], uret;
	int 	 ibuf[5][5], iret;
	long 	 lbuf[5][5], lret;
	float 	 fbuf[5][5], fret;
	double 	 dbuf[5][5], dret;

	switch (flag)
	{
		case 1: cret = cbuf[3][1]; /* ERROR: Uninitialized variable */
			break;
		case 2: sret = sbuf[3][1]; /* ERROR: Uninitialized variable */
			break;
		case 3: uret = ubuf[3][1]; /* ERROR: Uninitialized variable */
			break;
		case 4: iret = ibuf[3][1]; /* ERROR: Uninitialized variable */
			break;
		case 5: lret = lbuf[3][1]; /* ERROR: Uninitialized variable */
			break;
		case 6: fret = fbuf[3][1]; /* ERROR: Uninitialized variable */
			break;
		case 7: dret = dbuf[3][1]; /* ERROR: Uninitialized variable */
			break;
		default:
			break;
	}
}

/***********************************************************************
 *
 * Defect type: Uninitialized variable use 
 * Complexity: Read of possibly uninitialized float due to empty else clause
 *
 ***********************************************************************/
static const int UNINIT_VAR_004_TRUE = 1; /* true */

static const int UNINIT_VAR_004_FALSE = 0; /*false */

void uninit_var_004 ()
{
	float dvar,dvar1,ret;

    	if(UNINIT_VAR_004_TRUE ==0)
    	{
		dvar = 10.0;
    	}
	else if (UNINIT_VAR_004_FALSE !=0 )
    	{	
		dvar1 = 25.8;
    	}
	else
    	{
		;
    	}
	ret = dvar; /* ERROR: Uninitialized variable */
}

/***********************************************************************
 *
 * Defect type: Uninitialized variable use 
 * Complexity: Return of uninitialized variable due to if statemet block not executing  
 *
 ***********************************************************************/
int uninit_var_005_func_001 (void)
{
	int ret;
	
	if (0)
	{
		ret = 1;
	}
	return ret; /* ERROR: Uninitialized variable */
}

void uninit_var_005 ()
{
	int a;
	
	a = uninit_var_005_func_001();
}

/***********************************************************************
 *
 * Defect type: Uninitialized variable use 
 * Complexity: Conditional expression results in assignment of uninitialized variable to another variable  
 *
 ***********************************************************************/
void uninit_var_006 ()
{
    long a;
    int flag = 0;

    (flag == 10) ? (a = 1) : (flag = a); /* ERROR: Uninitialized variable */
}

/***********************************************************************
 *
 * Defect type: Uninitialized variable use 
 * Complexity: Uninitialized structure member  
 *
 ***********************************************************************/
typedef struct {
	int a;
	int b;
	int uninit;
} uninit_var_007_s_001;

void uninit_var_007 ()
{
	uninit_var_007_s_001 s;
	int ret;
	
	s.a = 1;
	s.b = 1;
	ret = s.uninit; /* ERROR: Uninitialized variable */
}

/***********************************************************************
 *
 * Defect type: Uninitialized variable use 
 * Complexity: Uninitialized variable used in return expression 
 *
 ***********************************************************************/
int uninit_var_008_func_001 (int a)
{
	static int ret;
	
	return ret - a; /* ERROR: Uninitialized variable */
}

void uninit_var_008 ()
{
    	int flag = 1;
    	int data;
   
   	while(uninit_var_008_func_001(flag) > 0)
    	{
    		data +=flag; /* ERROR: Uninitialized variable */
    	}
}

/***********************************************************************
 *
 * Defect type: Uninitialized variable use 
 * Complexity: Uninitialized string used as source for strcpy function 
 *
 ***********************************************************************/
void uninit_var_009_func_001 (char buf[])
{
	char ret[25];
	
	strcpy(buf,ret); /* ERROR: Uninitialized variable */
}

void uninit_var_009 ()
{
	char buf[25];
	
	uninit_var_009_func_001(buf);
}

/***********************************************************************
 *
 * Defect type: Uninitialized variable use 
 * Complexity: Uninitialized function argument used to initialize integer array 
 *
 ***********************************************************************/
void uninit_var_010_func_001 (int buf[][6])
{
	int ret[5][6];
	int i,j;

	for (i=0;i<5;i++)
	{
		for (j=0;j<6;j++)
		{
			buf[i][j] = ret[i][j]; /* ERROR: Uninitialized variable */
		}
	}
}

void uninit_var_010 ()
{
	int buf[5][6];
	
	uninit_var_010_func_001(buf);
}

/***********************************************************************
 *
 * Defect type: Uninitialized variable use 
 * Complexity: Uninitialized function argument used to initialize integer  
 *
 ***********************************************************************/
int uninit_var_011_func_001 (int arr1[],int a)
{
	int ret = 0;
	
	if(arr1[0] > 0)
	{
		ret = a + arr1[1]; /* ERROR: Uninitialized variable */
	}	
	return ret;
}

void uninit_var_011 ()
{
	int arr[5];
	int p;

	p = uninit_var_011_func_001(arr,(sizeof(arr)/sizeof(int)));
}

/***********************************************************************
 *
 * Defect type: Uninitialized variable use 
 * Complexity: Uninitialized structure member used in switch statement control expression 
 *
 ***********************************************************************/
typedef struct {
	unsigned int a;
	unsigned int b;
	unsigned int uninit;

} uninit_var_012_s_001;

int uninit_var_012_func_001 (uninit_var_012_s_001 s1)
{
	switch ( (s1.a + s1.b +s1.uninit) ) /* ERROR: Uninitialized variable */
	{
		case 5:
			return 5;
		case 6:
			return 6;
		case 7:
			return 7;
		default:
			return -1;
	}
}

void uninit_var_012 ()
{
	int ret;
	uninit_var_012_s_001 s,r;
	
	s.a = 2;
	s.b = 1;
	ret = uninit_var_012_func_001 (s);
	if(ret >=0)
	{
		r = s;
	}
}

/***********************************************************************
 *
 * Defect type: Uninitialized variable use 
 * Complexity: Uninitialized enumerated variable 
 *
 ***********************************************************************/
typedef enum
{
	ZERO,
	ONE,
	TWO 
} values;

int uninit_var_013_func_001 (void )
{
	values val; 
	return val; /* ERROR: Uninitialized variable */
}

void uninit_var_013 ()
{
    int a;
    a = uninit_var_013_func_001();
}

/***********************************************************************
 *
 * Defect type: Uninitialized variable use 
 * Complexity: Loading of integer into structure member using uninitialized structure member 
 *
 ***********************************************************************/
typedef struct {
	int a;
	int b;
	int uninit;
} uninit_var_014_s_001;

uninit_var_014_s_001 uninit_var_014_func_001 (uninit_var_014_s_001 s1)
{
	uninit_var_014_s_001 ret;
	ret.a = (++s1.a);
	ret.b = (++s1.b);
	ret.uninit = (++s1.uninit); /* ERROR: Uninitialized variable */
	return ret;
}

void uninit_var_014 ()
{
	uninit_var_014_s_001 s,r;
	s.a = 1;
	s.b = 1;
	r = uninit_var_014_func_001(s);
}

/***********************************************************************
 *
 * Defect type: Uninitialized variable use 
 * Complexity: Array partially initialized using macros in function  
 *
 ***********************************************************************/
#define ZERO 0
#define ONE  1
#define TWO  2

void uninit_var_015_func_001 (int a[] )
{
	a[0] = ZERO;
	a[2] = TWO;
}

void uninit_var_015 ()
{
    int a[3],ret;
    uninit_var_015_func_001(a);
    ret = a[1]; /* ERROR: Uninitialized variable */
}

/***********************************************************************
 *
 * Defect type: Uninitialized variable use 
 * Complexity: Use of goto statement skips variable initialization 
 *
 ***********************************************************************/
int uninit_var_016 ()
{
	int a, b = 5, ret;

	a = 1 + b;
	goto mylabel;
	ret = b * a * 19;
mylabel:
	return ret; /* ERROR: Uninitialized variable */
}

/***********************************************************************
 *
 * Defect type: Uninitialized variable use 
 * Main 
 *
 ***********************************************************************/
extern volatile int vflag;

void uninit_var_main ()
{
	if (vflag == 1 || vflag == 888)
	{
		uninit_var_001(3);
	}

	if (vflag == 2 || vflag == 888)
	{
		uninit_var_002(3);
	}

	if (vflag == 3 || vflag == 888)
	{
		uninit_var_003(3);
	}

	if (vflag == 4 || vflag == 888)
	{
		uninit_var_004();
	}

	if (vflag == 5 || vflag == 888)
	{
		uninit_var_005();
	}

	if (vflag == 6 || vflag == 888)
	{
		uninit_var_006();
	}

	if (vflag == 7 || vflag == 888)
	{
		uninit_var_007();
	}

	if (vflag == 8 || vflag == 888)
	{
		uninit_var_008();
	}

	if (vflag == 9 || vflag == 888)
	{
		uninit_var_009();
	}

	if (vflag == 10 || vflag == 888)
	{
		uninit_var_010();
	}

	if (vflag == 11 || vflag == 888)
	{
		uninit_var_011();
	}

	if (vflag == 12 || vflag == 888)
	{
		uninit_var_012();
	}

	if (vflag == 13 || vflag == 888)
	{
		uninit_var_013();
	}

	if (vflag == 14 || vflag == 888)
	{
		uninit_var_014();
	}

	if (vflag == 15 || vflag == 888)
	{
		uninit_var_015();
	}
	
	if (vflag == 16 || vflag == 888)
	{
		(void) uninit_var_016();
	}
}
