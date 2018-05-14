/***********************************************************************
 *
 * Defect Classification
 * ---------------------
 * Description: Defect code used to identify data overflow 
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
#define MAX_INT  2147483647
#define MAX_CHAR 127

int rand (void);

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Beyond upper bound of character size 
 *
 ***********************************************************************/
void data_overflow_001  ()
{
	char max = 0x7f;
	char ret;
	
	ret = max + 1; /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Beyond upper bound of short integer size 
 *
 ***********************************************************************/
void data_overflow_002  ()
{
	short max = 0x7fff;
	short ret;
	
	ret = max + 1; /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Beyond upper bound of integer size 
 *
 ***********************************************************************/
void data_overflow_003  ()
{
	int max = 0x7fffffff;
	int ret;

	ret = max + 1; /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Beyond upper bound of long integer size 
 *
 ***********************************************************************/
void data_overflow_004  ()
{
	long max = 0x7fffffff;
	long ret;
	
	ret = max + 1; /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Beyond upper bound of unsigned character size 
 *
 ***********************************************************************/
void data_overflow_005  ()
{
	unsigned char max = 0xff;
	unsigned char ret;
	
	ret = max + 1; /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Beyond upper bound of unsigned short size 
 *
 ***********************************************************************/
void data_overflow_006  ()
{
	unsigned short max = 0xffff;
	unsigned short ret;
	
	ret = max + 1; /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Beyond upper bound of unsigned integer size 
 *
 ***********************************************************************/
void data_overflow_007  ()
{
	unsigned int max = 0xffffffff;
	unsigned int ret;
	
	ret = max + 1; /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Beyond upper bound of unsigned long integer size 
 *
 ***********************************************************************/
void data_overflow_008  ()
{
	unsigned long max = 0xffffffff;
	unsigned long ret;

	ret = max + 1; /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Beyond upper bound of signed integer bitfield size  
 *
 ***********************************************************************/
typedef struct {
	signed int max : 5;
	signed int ret : 5;
} data_overflow_009_s_001;

void data_overflow_009  ()
{
	data_overflow_009_s_001 s;
	
	s.max = 0x0f;
	s.ret = s.max + 1; /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Beyond upper bound of unsigned integer bitfield size  
 *
 ***********************************************************************/
typedef struct {
	unsigned int max : 5;
	unsigned int ret : 5;
} data_overflow_010_s_001;

void data_overflow_010  ()
{
	data_overflow_010_s_001 s;
	
	s.max = 0x1f;
	s.ret = s.max + 1; /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Beyond upper bound of integer size using incremenet operator 
 *
 ***********************************************************************/
void data_overflow_011  ()
{
	int max = 0x7fffffff;
	int ret;

	max ++;
	ret = max; /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Beyond upper bound of integer size using constant 
 *
 ***********************************************************************/
void data_overflow_012  ()
{
	int max = 0x7fffff80;
	int ret;
	
	ret = max + 128; /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Beyond upper bound of integer size using multiplication 
 *
 ***********************************************************************/
void data_overflow_013  ()
{
	int max = 0x40000000;
	int ret;

	ret = max * 2; /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Beyond upper bound of integer size using variable  
 *
 ***********************************************************************/
void data_overflow_014  ()
{
	int max = 0x7fffffff;
	int d = 1;
	int ret;

	ret = max + d; /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Beyond upper bound of integer size using random number 
 *
 ***********************************************************************/
void data_overflow_015  ()
{
	int max = 0x7fffffff;
	int d;
	int ret;
	
	d = rand ();
	ret = max + d; /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Beyond upper bound of integer size using linear equation 
 *
 ***********************************************************************/
void data_overflow_016  ()
{
	int max = 429496729;
	int ret;

	ret = (5 * max) + 3; /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Beyond upper bound of integer size using nonlinear equation 
 *
 ***********************************************************************/
void data_overflow_017  ()
{
	int max = 46340;
	int ret;
	
	ret = (max * max) + 88048; /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Beyond upper bound of integer size using return value of function call 
 *
 ***********************************************************************/
int data_overflow_018_func_001  ()
{
	return 1;
}

void data_overflow_018  ()
{
	int max = 0x7fffffff;
	int ret;

	ret = max + data_overflow_018_func_001 (); /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Beyond upper bound of integer size using function argument 
 *
 ***********************************************************************/
void data_overflow_019 (int d)
{
	int max = 0x7fffffff;
	int ret;
	
	ret = max + d; /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Beyond upper bound of integer size using array element 
 *
 ***********************************************************************/
void data_overflow_020  ()
{
	int max = 0x7fffffff;
	int dlist[4] = {0, 1, -2, -1};
	int ret;

	ret = max + dlist[1]; /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Beyond upper bound of integer size using alias 
 *
 ***********************************************************************/
void data_overflow_021  ()
{
	int max = 0x7fffffff;
	int d = 1;
	int d1;
	int ret;

	d1 = d;
	ret = max + d1; /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Beyond upper bound of integer size using alias 
 *
 ***********************************************************************/
void data_overflow_022  ()
{
	int max = 0x7fffffff;
	int d = 1;
	int d1;
	int d2;
	int ret;
	
	d1 = d;
	d2 = d1;
	ret = max + d2; /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Beyond upper bound of integer size using constant operands 
 *
 ***********************************************************************/
void data_overflow_023  ()
{
	int ret;

	ret = 0x7fffffff + 1; /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Beyond upper bound of float size 
 *
 ***********************************************************************/
void data_overflow_024  ()
{
	float ret;

	/* 0 11111110 11111111111111111111111 */
	float max = 3.40282347e+38F;

	/* 0 11100111 00000000000000000000000 */
	ret = max + 2.02824096e+31F; /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Beyond upper bound of double size 
 *
 ***********************************************************************/
void data_overflow_025  ()
{
	double ret;

	/* 0 11111111110 1111111111111111111111111111111111111111111111111111 */
	double max = 1.7976931348623157e+308;

	/* 0 11111001010 0000000000000000000000000000000000000000000000000000 */
	ret = max + 1.9958403095347198e+292; /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Suspicious truncation
 * http://www.gimpel.com/html/bugs/bug647.htm
 *
 ***********************************************************************/
int no_of_trees(void)		{ return 105000; }

int leaves_per_tree(void)	{ return 25000; }

long total(void)
{
	return no_of_trees () * leaves_per_tree (); /* ERROR: Data overflow */
}
void data_overflow_026(void)
{

	(void)printf( "\t\tThere are %ld leaves in the forest\n", total () );
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Overflow using pow function 
 *
 ***********************************************************************/
void data_overflow_027 ()
{
	double num=10^3700;
	double exponent=10^37;
	double ans;
	
	ans = pow(num,exponent); /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Overflow using pow function 
 *
 ***********************************************************************/
void data_overflow_028 ()
{
	float num=1.004;
	int exponent=3;
	double ans;
	
	ans = pow(num,exponent); /* ERROR: Data overflow */

}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Overflow using pow function 
 *
 ***********************************************************************/
void data_overflow_029 ()
{
	double arr[]={2.0,1.2,3.9,10^3800,4.0};
	int i;
	double exponent=2;
	double ans;

	for(i=0;i<(sizeof(arr)/sizeof(double));i++)
	{
		double temp=arr[i];
		ans = pow(temp,exponent); /* ERROR: Data overflow */
	}
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Overflow using pow function 
 *
 ***********************************************************************/
void data_overflow_030 ()
{
	double arr[]={2.0,1.2,3.9,10^3008,4.0};
	double* arr1=arr;
	double **arr2=&arr1;
	double exponent=2;
	int i;
	double ans;

	for(i=0;i<5;i++)
	{
		double temp=*(*arr2+i);
		ans = pow(temp,exponent); /* ERROR: Data overflow */
	}

}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Overflow using pow function 
 *
 ***********************************************************************/
void data_overflow_031 ()
{
	double arr[]={2.0,1.2,3.9,8^3800,4.0};
	double* arr1=arr;
	double exponent=2;
	int i;
	double ans;

	for(i=0;i<(sizeof(arr)/sizeof(double));i++)
	{
		double temp=arr1[i];
		ans = pow(temp,exponent); /* ERROR: Data overflow */
	}
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Overflow using pow function 
 *
 ***********************************************************************/
double data_overflow_032_func_001 ()
{
	return 10^3800;
}

void data_overflow_032 ()
{
	double exponent=2;
	double ans;
	ans = pow(data_overflow_032_func_001 (),exponent); /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Overflow using pow function 
 *
 ***********************************************************************/
typedef struct
{
	double arr[1];
}pow_related_errors_007_s;

void data_overflow_033 ()
{
	double exponent=2;
	double ans;
	double ans1;
	pow_related_errors_007_s* newarr = (pow_related_errors_007_s *)malloc(sizeof(pow_related_errors_007_s));
	pow_related_errors_007_s* ptr_newarr =(pow_related_errors_007_s *)malloc(sizeof(pow_related_errors_007_s));

	newarr->arr[0]=10^3800;
	ptr_newarr->arr[0]=10^3800;

	ans = pow(newarr->arr[0],exponent);
	ans1=pow(ptr_newarr->arr[0],newarr->arr[0]); /* ERROR: Data overflow */
	free(newarr);
	free(ptr_newarr);
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Overflow using pow function 
 *
 ***********************************************************************/
void data_overflow_034 ()
{
	double base=10^3700;
	double exponent=2;
	double ans;
	
	ans = pow(base,exponent); /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Overflow using pow function 
 *
 ***********************************************************************/
void data_overflow_035 ()
{
	double base=-0.0000000000000000000000000000000000036;
	double exponent=-2;
	double ans;
	
	ans = pow(base,exponent); /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Overflow using pow function 
 *
 ***********************************************************************/
void data_overflow_036 ()
{
	double base=0.0000000000000000000000000000000000036;
	double exponent=20000;
	double ans;
	
	ans = pow(base,exponent); /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Overflow using pow function 
 *
 ***********************************************************************/
void data_overflow_037 ()
{
	double base=-0.0000000000000000000000000000000000036;
	double exponent=20000;
	double ans;
	
	ans = pow(base,exponent); /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Overflow using pow function 
 *
 ***********************************************************************/
void data_overflow_038 ()
{
	double base=-0.0000000000000000000000000000000000036;
	double exponent=20000;
	double ans;

	ans = pow(base,exponent); /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Overflow using pow function 
 *
 ***********************************************************************/
void data_overflow_039 ()
{
	double base=-0.0000000000000000000000000000000000036;
	double exponent=2000;
	double ans;

	ans = pow(base,exponent); /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Overflow using pow function 
 *
 ***********************************************************************/
void data_overflow_040 ()
{
	double base=0.0000000000000000000000000000000000036;
	double exponent=21000;
	double ans;
	
	ans = pow(base,exponent); /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Overflow using pow function 
 *
 ***********************************************************************/
void data_overflow_041 ()
{
	double base=-10^3600;
	double exponent=21;
	double ans;
	
	ans = pow(base,exponent); /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Overflow using pow function 
 *
 ***********************************************************************/
void data_overflow_042 ()
{
	double base=10^36;
	double exponent=20000;
	double ans;
	
	ans = pow(base,exponent); /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Overflow using pow function 
 *
 ***********************************************************************/
void data_overflow_043 ()
{
	double base=10^36;
	double exponent=-10^36;
	double ans;
	
	ans = pow(base,exponent); /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Overflow using pow function 
 *
 ***********************************************************************/
void data_overflow_044 ()
{
	double base=-10^36;
	double exponent=-10^36;
	double ans;
	
	ans = pow(base,exponent); /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Overflow using pow function 
 *
 ***********************************************************************/
void data_overflow_045 ()
{
	double base=0.0004;
	double exponent=-10^3600;
	double ans;
	
	ans = pow(base,exponent); /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Overflow using pow function 
 *
 ***********************************************************************/
void data_overflow_046 ()
{
	double base=-0.0004;
	double exponent=-10^3600;
	double ans;
	
	ans = pow(base,exponent); /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Overflow using pow function 
 *
 ***********************************************************************/
void data_overflow_047 ()
{
	double base=100;
	double exponent=-10^3500;
	double ans;
	
	ans = pow(base,exponent); /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Overflow using pow function 
 *
 ***********************************************************************/
void data_overflow_048 ()
{
	double base=-100;
	double exponent=-10^35000;
	double ans;
	
	ans = pow(base,exponent); /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Overflow using pow function 
 *
 ***********************************************************************/
void data_overflow_049 ()
{
	double base=0.0004;
	double exponent=-10^35000;
	double ans;
	
	ans = pow(base,exponent); /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Overflow using pow function 
 *
 ***********************************************************************/
void data_overflow_050 ()
{
	double base=-0.0004;
	double exponent=-10^35000;
	double ans;
	
	ans = pow(base,exponent); /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Overflow using pow function 
 *
 ***********************************************************************/
void data_overflow_051 ()
{
	double base=10^3300;
	double exponent=0.000004;
	double ans;
	
	ans = pow(base,exponent); /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Overflow using pow function 
 *
 ***********************************************************************/
void data_overflow_052 ()
{
	double base=10^10;
	double exponent=7000;
	double ans;

	ans = pow(base,exponent); /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Overflow using pow function 
 *
 ***********************************************************************/
void data_overflow_053 ()
{
	double base=-100^10;
	double exponent=7000;
	double ans;

	ans = pow(base,exponent); /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Overflow using pow function 
 *
 ***********************************************************************/
void data_overflow_054 ()
{
	double base=-10^10;
	double exponent=-7100;
	double ans;

	ans = pow(base,exponent); /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Complexity: Overflow using pow function 
 *
 ***********************************************************************/
void data_overflow_055 ()
{
	double base=-10^30;
	double exponent=-10^3000;
	double ans;
	
	ans = pow(base,exponent); /* ERROR: Data overflow */
}

/***********************************************************************
 *
 * Defect type: Data overflow 
 * Main 
 *
 ***********************************************************************/
extern volatile int vflag;

void data_overflow_main  ()
{
	if (vflag == 1 || vflag == 888)
	{
		data_overflow_001 ();
	}

	if (vflag == 2 || vflag == 888)
	{
		data_overflow_002 ();
	}

	if (vflag == 3 || vflag == 888)
	{
		data_overflow_003 ();
	}

	if (vflag == 4 || vflag == 888)
	{
		data_overflow_004 ();
	}

	if (vflag == 5 || vflag == 888)
	{
		data_overflow_005 ();
	}

	if (vflag == 6 || vflag == 888)
	{
		data_overflow_006 ();
	}

	if (vflag == 7 || vflag == 888)
	{
		data_overflow_007 ();
	}

	if (vflag == 8 || vflag == 888)
	{
		data_overflow_008 ();
	}

	if (vflag == 9 || vflag == 888)
	{
		data_overflow_009 ();
	}

	if (vflag == 10 || vflag == 888)
	{
		data_overflow_010 ();
	}

	if (vflag == 11 || vflag == 888)
	{
		data_overflow_011 ();
	}

	if (vflag == 12 || vflag == 888)
	{
		data_overflow_012 ();
	}

	if (vflag == 13 || vflag == 888)
	{
		data_overflow_013 ();
	}

	if (vflag == 14 || vflag == 888)
	{
		data_overflow_014 ();
	}

	if (vflag == 15 || vflag == 888)
	{
		data_overflow_015 ();
	}

	if (vflag == 16 || vflag == 888)
	{
		data_overflow_016 ();
	}

	if (vflag == 17 || vflag == 888)
	{
		data_overflow_017 ();
	}

	if (vflag == 18 || vflag == 888)
	{
		data_overflow_018 ();
	}

	if (vflag == 19 || vflag == 888)
	{
		data_overflow_019 (2);
	}

	if (vflag == 20 || vflag == 888)
	{
		data_overflow_020 ();
	}

	if (vflag == 21 || vflag == 888)
	{
		data_overflow_021 ();
	}

	if (vflag == 22 || vflag == 888)
	{
		data_overflow_022 ();
	}

	if (vflag == 23 || vflag == 888)
	{
		data_overflow_023 ();
	}

	if (vflag == 24 || vflag == 888)
	{
		data_overflow_024 ();
	}

	if (vflag == 25 || vflag == 888)
	{
		data_overflow_025 ();
	}
	
	if (vflag == 26 || vflag == 888)
	{
		data_overflow_026 ();
	}
	
	if (vflag == 26 || vflag == 888)
	{
		data_overflow_026 ();
	}
	
	if (vflag == 27 || vflag == 888)
	{
		data_overflow_027 ();
	}
	
	if (vflag == 28 || vflag == 888)
	{
		data_overflow_028 ();
	}
	
	if (vflag == 29 || vflag == 888)
	{
		data_overflow_029 ();
	}
	
	if (vflag == 30 || vflag == 888)
	{
		data_overflow_030 ();
	}
	
	if (vflag == 31 || vflag == 888)
	{
		data_overflow_031 ();
	}
	if (vflag == 32 || vflag == 888)
	{
		data_overflow_032 ();
	}
	
	if (vflag == 33 || vflag == 888)
	{
		data_overflow_033 ();
	}
	
	if (vflag == 34 || vflag == 888)
	{
		data_overflow_034 ();
	}
	
	if (vflag == 35 || vflag == 888)
	{
		data_overflow_035 ();
	}
	
	if (vflag == 36 || vflag == 888)
	{
		data_overflow_036 ();
	}
	
	if (vflag == 37 || vflag == 888)
	{
		data_overflow_037 ();
	}
	
	if (vflag == 38|| vflag == 888)
	{
		data_overflow_038 ();
	}
	
	if (vflag == 39 || vflag == 888)
	{
		data_overflow_039 ();
	}
	
	if (vflag == 40 || vflag == 888)
	{
		data_overflow_040 ();
	}
	
	if (vflag == 41 || vflag == 888)
	{
		data_overflow_041 ();
	}
	
	if (vflag == 42 || vflag == 888)
	{
		data_overflow_042 ();
	}
	
	if (vflag == 43 || vflag == 888)
	{
		data_overflow_043 ();
	}
	
	if (vflag == 44 || vflag == 888)
	{
		data_overflow_044 ();
	}
	
	if (vflag == 45 || vflag == 888)
	{
		data_overflow_045 ();
	}
	
	if (vflag == 46 || vflag == 888)
	{
		data_overflow_046 ();
	}
	
	if (vflag == 47 || vflag == 888)
	{
		data_overflow_047 ();
	}
	
	if (vflag == 48 || vflag == 888)
	{
		data_overflow_048 ();
	}
	
	if (vflag == 49 || vflag == 888)
	{
		data_overflow_049 ();
	}
	
	if (vflag == 50 || vflag == 888)
	{
		data_overflow_050 ();
	}
	
	if (vflag == 51 || vflag == 888)
	{
		data_overflow_051 ();
	}
	
	if (vflag == 52 || vflag == 888)
	{
		data_overflow_052 ();
	}
	
	if (vflag == 53 || vflag == 888)
	{
		data_overflow_053 ();
	}
	
	if (vflag == 54 || vflag == 888)
	{
		data_overflow_054 ();
	}
	
	if (vflag == 55 || vflag == 888)
	{
		data_overflow_055 ();
	}
}
