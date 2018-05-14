/***********************************************************************
 *
 * Defect Classification
 * ---------------------
 * Description: Defect code used to identify division by zero
 *
 ***********************************************************************/

#include "HeaderFile.h"

int rand (void);

/***********************************************************************
 *
 * Defect type: Division by zero
 * Complexity: Divison by zero assignment
 *
 ***********************************************************************/
void zero_division_001 (int flag)
{
	char 	 cdividend = 100, cret;
	short 	 sdividend = 100, sret;
	int 	 idividend = 100, iret;
	long 	 ldividend = 100, lret;

	switch (flag)
	{
		case 1: cret = cdividend / 0; /* ERROR: Division by zero */
			break;
		case 2: sret = sdividend / 0; /* ERROR: Division by zero */
			break;
		case 3: iret = idividend / 0; /* ERROR: Division by zero */
			break;
		case 4: lret = ldividend / 0; /* ERROR: Division by zero */
			break;
		default:
			break;
	}
}

/***********************************************************************
 *
 * Defect type: Division by zero
 * Complexity: Compound division by zero
 *
 ***********************************************************************/
void zero_division_002 (int flag)
{
	char 	 cdividend = 100;
	short 	 sdividend = 100;
	int 	 idividend = 100;
	long 	 ldividend = 100;

	switch (flag)
	{
		case 1: cdividend /= 0; /* ERROR: Division by zero */
			break;
		case 2: sdividend /= 0; /* ERROR: Division by zero */
			break;
		case 3: idividend /= 0; /* ERROR: Division by zero */
			break;
		case 4: ldividend /= 0; /* ERROR: Division by zero */
			break;
		default: 
			break;
	}
}

/***********************************************************************
 *
 * Defect type: Division by zero
 * Complexity: Compound divison by zero using global variabe 
 *
 ***********************************************************************/
int zero_division_003_dividend_gbl = 100;

static int zero_division_003_divisor_gbl = 1;

void zero_division_003_func_001 ()
{
	zero_division_003_dividend_gbl %= zero_division_003_divisor_gbl; /* ERROR: Division by zero */
}

void zero_division_003 ()
{
	zero_division_003_divisor_gbl--;
	zero_division_003_func_001 ();
}

/***********************************************************************
 *
 * Defect type: Division by zero
 * Complexity: Compound divison by zero using array element as divisor
 *
 ***********************************************************************/
void zero_division_004 ()
{
	int dividend = 100;
	int divisors[5] = {2, 1, 0, 3, 4};
	int ret;
	
	ret = dividend / divisors[2]; /* ERROR: Division by zero */
}

/***********************************************************************
 *
 * Defect type: Division by zero
 * Complexity: Division by zero using pointer dereference as divisor
 *
 ***********************************************************************/
int zero_division_005_gbl_divisor = 0;

void zero_division_005 ()
{
	int dividend = 100;
	int *p;
	int ret;
	
	p = &zero_division_005_gbl_divisor;
	ret = dividend / (*p); /* ERROR: Division by zero */
}

/***********************************************************************
 *
 * Defect type: Division by zero
 * Complexity: Division by zero using structure member as divisor
 *
 ***********************************************************************/
typedef struct {
	int a;
	int b;
	int divisor;
} zero_division_006_s_001;

void zero_division_006 ()
{
	int dividend = 100, ret;
	zero_division_006_s_001 zero_division_006_structure;
	
	zero_division_006_structure.divisor = 0;
	ret = dividend / zero_division_006_structure.divisor; /* ERROR: Division by zero */
}

/***********************************************************************
 *
 * Defect type: Division by zero
 * Complexity: Division by zero using variable divisor
 *
 ***********************************************************************/
void zero_division_007 (int flag)
{
	char 	 cdividend = 100, cdivisor = 0, cret;
	short 	 sdividend = 100, sdivisor = 0, sret;
	int 	 idividend = 100, idivisor = 0, iret;
	long 	 ldividend = 100, ldivisor = 0, lret;

	switch (flag)
	{
		case 1: cret = cdividend / cdivisor; /* ERROR: Division by zero */
			break;
		case 2: sret = sdividend / sdivisor; /* ERROR: Division by zero */
			break;
		case 3: iret = idividend / idivisor; /* ERROR: Division by zero */
			break;
		case 4: lret = ldividend / ldivisor; /* ERROR: Division by zero */
			break;
		default:
			break;
	}
}

/***********************************************************************
 *
 * Defect type: Division by zero
 * Complexity: Modulus by zero using variable divisor
 *
 ***********************************************************************/
void zero_division_008 (int flag)
{
	char 	 cdividend = 100, cdivisor = 0, cret;
	short 	 sdividend = 100, sdivisor = 0, sret;
	int 	 idividend = 100, idivisor = 0, iret;
	long 	 ldividend = 100, ldivisor = 0, lret;

	switch(flag)
	{
		case 1: cret = cdividend % cdivisor; /* ERROR: Division by zero */
			break;
		case 2: sret = sdividend % sdivisor; /* ERROR: Division by zero */
			break;
		case 3: iret = idividend % idivisor; /* ERROR: Division by zero */
			break;
		case 4: lret = ldividend % ldivisor; /* ERROR: Division by zero */
			break;
		default:
			break;
	}
}

/***********************************************************************
 *
 * Defect type: Division by zero
 * Complexity: Possible division by zero using result of rand function as divisor
 *
 ***********************************************************************/
void zero_division_009 ()
{
	int dividend = 100, divisor, ret;
	
	divisor = rand ();
	ret = dividend / divisor; /* ERROR: Division by zero */
}

/***********************************************************************
 *
 * Defect type: Division by zero
 * Complexity: Divison by zero using result of linear equation as divisor 
 *
 ***********************************************************************/
void zero_division_010 ()
{
	int dividend = 100, divisor = 2, ret;

	ret = dividend / (2 * divisor - 4); /* ERROR: Division by zero */
}

/***********************************************************************
 *
 * Defect type: Division by zero
 * Complexity: Divison by zero using result of nonlinear equation as divisor 
 *
 ***********************************************************************/
void zero_division_011 ()
{
	int dividend = 100, divisor = 2, ret;
	
	ret = dividend / (divisor * divisor - 4); /* ERROR: Division by zero */
}

/***********************************************************************
 *
 * Defect type: Division by zero
 * Complexity: Divison by zero using return value of function call as divisor 
 *
 ***********************************************************************/
int zero_division_012_func_001 ()
{
	return 0;
}

void zero_division_012 ()
{
	int dividend = 100, ret;
	
	ret = dividend / zero_division_012_func_001 (); /* ERROR: Division by zero */
}

/***********************************************************************
 *
 * Defect type: Division by zero
 * Complexity: Divison by zero using function argument as divisor 
 *
 ***********************************************************************/
void zero_division_013 (int divisor)
{
	int dividend = 100, ret;
	
	ret = dividend / divisor; /* ERROR: Division by zero */
}

/***********************************************************************
 *
 * Defect type: Division by zero
 * Complexity: Divison by zero using alias to variable as divisor  
 *
 ***********************************************************************/
void zero_division_014 ()
{
	int dividend = 100, divisor = 0, divisor1, ret;
	
	divisor1 = divisor;
	ret = dividend / divisor1; /* ERROR: Division by zero */
}

/***********************************************************************
 *
 * Defect type: Division by zero
 * Complexity: Divison by zero using double alias to variable as divisor  
 *
 ***********************************************************************/
int *zero_division_015_gbl_divisor ;

void zero_division_015_func_001 ()
{
	zero_division_015_gbl_divisor = malloc(1*sizeof(int));
	*zero_division_015_gbl_divisor= -1;
}

void zero_division_015_func_002 ()
{
	(*zero_division_015_gbl_divisor)++;
}

void zero_division_015 ()
{
	int dividend = 100, divisor1, divisor2, ret;
	
	zero_division_015_func_001 ();
	zero_division_015_func_002 ();
	divisor1 = *zero_division_015_gbl_divisor;
	divisor2 = divisor1;
	ret = dividend / divisor2; /* ERROR: Division by zero */
}

/***********************************************************************
 *
 * Defect Type: Division by zero
 * Complexity: divide (/) Basic type double/int
 * http://www.gimpel.com/html/bugs/bug795.htm
 *
 ***********************************************************************/
#define N 6

double zero_division_016_func_001( int n )
{
	double wind_velocity[N] = { 0.0, 14.1, 5.6, 6.0, 23.3, 15.0 };
	int j = 0;
	double sum = 0.0;

	for( int i = 1; i <= n; i++ )
	{
		sum += wind_velocity[i];
		j = i;
	}
	return wind_velocity[j] / j; /* ERROR: Division by zero */
}

void zero_division_016 ()
{
	for( int i = 0; i < N; i++ )
	{
		printf( "%d %g\n", i , zero_division_016_func_001(i) );
	}
}

/***********************************************************************
 *
 * Defect type: Division by zero
 * Complexity: Possible division by zero where divisor is return of a stubbed function
 *
 ***********************************************************************/
void zero_division_017 ()
{
	int dividend = devidend_zero_division;
	float divisor_017, ret;
	
	divisor_017 = zero_division_017_func_001 ();
	ret = dividend / divisor_017; /* ERROR: Division by zero */
}

/***********************************************************************
 *
 * Defect type: Division by zero
 * Complexity: Possible division by zero where divisor is uninitialized global variable 
 *
 ***********************************************************************/
void zero_division_018 ()
{
	float dividend = 3.14, ret;

	ret = dividend / divisor_zero; /* ERROR: Division by zero */
}

/***********************************************************************
 *
 * Defect type: Division by zero
 * Complexity: Division by zero where divisor is result of call to math library function
 *
 ***********************************************************************/
void zero_division_019 ()
{
	double x, divident = 17, ret;
	
 	x = (double) (rand() % 10);
	ret = dividend / sin(x); /* ERROR: Division by zero */
}

/***********************************************************************
 *
 * Defect type: Division by zero
 * Complexity: Compound division by zero using result of conditional expression as divisor 
 *
 ***********************************************************************/
void zero_division_020 ()
{
	int dividend = 17, a = 100;

	dividend /= (a == 100) ? 0: 10; /* ERROR: Division by zero */
}

/***********************************************************************
 *
 * Defect type: Division by zero
 * Complexity: Modulus by zero assignment
 *
 ***********************************************************************/
void zero_division_021 (int flag)
{
	char 	 cdividend = 100, cret;
	short 	 sdividend = 100, sret;
	int 	 idividend = 100, iret;
	long 	 ldividend = 100, lret;

	switch(flag)
	{
		case 1: cret = cdividend % 0; /* ERROR: Division by zero */
			break;
		case 2: sret = sdividend % 0; /* ERROR: Division by zero */
			break;
		case 3: iret = idividend % 0; /* ERROR: Division by zero */
			break;
		case 4: lret = ldividend % 0; /* ERROR: Division by zero */
			break;
		default: 
			break;
	}
}

/***********************************************************************
 *
 * Defect type: Division by zero
 * Complexity: Compound modulus by zero
 *
 ***********************************************************************/
void zero_division_022 (int flag)
{
	char 	 cdividend = 100;
	short 	 sdividend = 100;
	int 	 idividend = 100;
	long 	 ldividend = 100;

	switch(flag)
	{
		case 1: cdividend %= 0; /* ERROR: Division by zero */
			break;
		case 2: sdividend %= 0; /* ERROR: Division by zero */
			break;
		case 3: idividend %= 0; /* ERROR: Division by zero */
			break;
		case 4: ldividend %= 0; /* ERROR: Division by zero */
			break;
		default:
			break;
	}
}

/***********************************************************************
 *
 * Defect type: Division by zero
 * Main 
 *
 ***********************************************************************/
extern volatile int vflag;

void zero_division_main ()
{
	if (vflag == 1 || vflag == 888)
	{
		zero_division_001 (3);
	}

	if (vflag == 2 || vflag == 888)
	{
		zero_division_002 (3);
	}

	if (vflag == 3 || vflag == 888)
	{
		zero_division_003 ();
	}

	if (vflag == 4 || vflag == 888)
	{
		zero_division_004 ();
	}

	if (vflag == 5 || vflag == 888)
	{
		zero_division_005 ();
	}

	if (vflag == 6 || vflag == 888)
	{
		zero_division_006 ();
	}

	if (vflag == 7 || vflag == 888)
	{
		zero_division_007 (3);
	}

	if (vflag == 8 || vflag == 888)
	{
		zero_division_008 (3);
	}

	if (vflag == 9 || vflag == 888)
	{
		zero_division_009 ();
	}

	if (vflag == 10 || vflag == 888)
	{
		zero_division_010 ();
	}

	if (vflag == 11 || vflag == 888)
	{
		zero_division_011 ();
	}

	if (vflag == 12 || vflag == 888)
	{
		zero_division_012 ();
	}

	if (vflag == 13 || vflag == 888)
	{
		zero_division_013 (0);
	}

	if (vflag == 14 || vflag == 888)
	{
		zero_division_014 ();
	}

	if (vflag == 15 || vflag == 888)
	{
		zero_division_015 ();
	}

	if (vflag == 16 || vflag == 888)
	{
		zero_division_016 ();
	}

	if (vflag == 17 || vflag == 888)
	{
		zero_division_017 ();
	}

	if (vflag == 18 || vflag == 888)
	{
		zero_division_018 ();
	}

	if (vflag == 19 || vflag == 888)
	{
		zero_division_019 ();
	}

	if (vflag == 20 || vflag == 888)
	{
		zero_division_020 ();
	}
	
	if (vflag == 21 || vflag == 888)
	{
		zero_division_021 (3);
	}
	
	if (vflag == 22 || vflag == 888)
	{
		zero_division_022 (3);
	}
}
