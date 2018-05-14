/***********************************************************************
 *
 * Defect Classification
 * ---------------------
 * Description: Defect code used to identify invalid bitwise shift
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
#define BITSIZE_INT 32
#define BITSIZE_LONG 32
#define BITSIZE_UNSIGNED 32
#define BITSIZE_UNSIG_LONG 32

int rand (void);

/***********************************************************************
 *
 * Defect type: Invalid bitwise shift
 * Complexity: Left shift beyond size of int
 *
 ***********************************************************************/
void bit_shift_001 ()
{
	int ret, a = 1;

	ret = a << BITSIZE_INT; /* ERROR: Bitwise shift error */
	sink = ret;	
}

/***********************************************************************
 *
 * Defect type: Invalid bitwise shift
 * Complexity: Left shift beyond size of unsigned int
 *
 ***********************************************************************/
void bit_shift_002 ()
{
	unsigned int ret, a = 1;

	ret = a << BITSIZE_UNSIGNED; /* ERROR: Bitwise shift error */
	sink = ret;	
}

/***********************************************************************
 *
 * Defect type: Invalid bitwise shift
 * Complexity: Left shift beyond size of long
 *
 ***********************************************************************/
void bit_shift_003 ()
{
	long int ret, a = 1;

	ret = a << BITSIZE_LONG; /* ERROR: Bitwise shift error */
	sink = ret;	
}

/***********************************************************************
 *
 * Defect type: Invalid bitwise shift
 * Complexity: Left shift beyond size of usinged long
 *
 ***********************************************************************/
void bit_shift_004 ()
{
	unsigned long int ret, a = 1;

	ret = a << BITSIZE_UNSIG_LONG; /* ERROR: Bitwise shift error */
	sink = ret;	
}

/***********************************************************************
 *
 * Defect type: Invalid bitwise shift
 * Complexity: Right shift beyond size of int
 *
 ***********************************************************************/
void bit_shift_005 ()
{
	int ret, a = 1;

	ret = a >> BITSIZE_INT; /* ERROR: Bitwise shift error */
	sink = ret;	
}

/***********************************************************************
 *
 * Defect type: Invalid bitwise shift
 * Complexity: Right shift beyond size of unsigned int
 *
 ***********************************************************************/
void bit_shift_006 ()
{
	unsigned int ret, a = 1;

	ret = a >> BITSIZE_UNSIGNED; /* ERROR: Bitwise shift error */
	sink = ret;	
}

/***********************************************************************
 *
 * Defect type: Invalid bitwise shift
 * Complexity: Right shift beyond size of long
 *
 ***********************************************************************/
void bit_shift_007 ()
{
	long int ret, a = 1;

	ret = a >> BITSIZE_LONG; /* ERROR: Bitwise shift error */
	sink = ret;	
}

/***********************************************************************
 *
 * Defect type: Invalid bitwise shift
 * Complexity: Right shift beyond size of usinged long
 *
 ***********************************************************************/
void bit_shift_008 ()
{
	unsigned long int ret, a = 1;

	ret = a >> BITSIZE_UNSIG_LONG; /* ERROR: Bitwise shift error */
	sink = ret;	
}

/***********************************************************************
 *
 * Defect type: Invalid bitwise shift
 * Complexity: Left shift by negative shift count
 *
 ***********************************************************************/
void bit_shift_009 ()
{
	int ret, a = 1;

	ret = a << -1; /* ERROR: Bitwise shift error */
	sink = ret;	
}

/***********************************************************************
 *
 * Defect type: Invalid bitwise shift
 * Complexity: Right shift by negative shift count
 *
 ***********************************************************************/
void bit_shift_010 ()
{
	int ret, a = 1;

	ret = a >> -1; /* ERROR: Bitwise shift error */
	sink = ret;	
}

/***********************************************************************
 *
 * Defect type: Invalid bitwise shift
 * Complexity: Left shift beyond size of int using variable
 *
 ***********************************************************************/
void bit_shift_011 ()
{
	int a = 1, ret;
	int shift = BITSIZE_INT;
	
	ret = a << shift; /* ERROR: Bitwise shift error */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Invalid bitwise shift
 * Complexity: Right shift beyond size of int using variable
 *
 ***********************************************************************/
void bit_shift_012 ()
{
	int a = 1, ret;
	int shift = BITSIZE_INT;
	
	ret = a >> shift; /* ERROR: Bitwise shift error */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Invalid bitwise shift
 * Complexity: Possible left shift beyond size of int using rand()
 *
 ***********************************************************************/
void bit_shift_013 ()
{
	int a = 1, ret;
	
	ret = a << rand(); /* ERROR: Bitwise shift error */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Invalid bitwise shift
 * Complexity: Possible right shift beyond size of int using rand()
 *
 ***********************************************************************/
void bit_shift_014 ()
{
	int a = 1, ret;
	
	ret = a >> rand(); /* ERROR: Bitwise shift error */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Invalid bitwise shift
 * Complexity: Left shift beyond size of int using result of linear equation
 *
 ***********************************************************************/
void bit_shift_015 ()
{
	int a = 1, ret;
	int shift = 6;
	
	ret = a << ((5 * shift) + 2); /* ERROR: Bitwise shift error */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Invalid bitwise shift
 * Complexity: Right shift beyond size of int using result of linear equation
 *
 ***********************************************************************/
void bit_shift_016 ()
{
	int a = 1, ret;
	int shift = 6;
	
	ret = a >> ((5 * shift) + 2); /* ERROR: Bitwise shift error */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Invalid bitwise shift
 * Complexity: Left shift beyond size of int using result of nonlinear equation
 *
 ***********************************************************************/
void bit_shift_017 ()
{
	int a = 1, ret;
	int shift = 6;
	
	ret = a << ((shift * shift) + 7); /* ERROR: Bitwise shift error */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Invalid bitwise shift
 * Complexity: Right shift beyond size of int using result of nonlinear equation
 *
 ***********************************************************************/
void bit_shift_018 ()
{
	int a = 1, ret;
	int shift = 6;
	
	ret = a >> ((shift * shift) + 7); /* ERROR: Bitwise shift error */
	sink = ret;
}


/***********************************************************************
 *
 * Defect type: Invalid bitwise shift
 * Complexity: Left shift beyond size of int using return value of function call
 *
 ***********************************************************************/
int bit_shift_019_func_001 ()
{
	return BITSIZE_INT;
}

void bit_shift_019 ()
{
	int a = 1, ret;
	
	ret = a << bit_shift_019_func_001 (); /* ERROR: Bitwise shift error */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Invalid bitwise shift
 * Complexity: Right shift beyond size of int using return value of function call
 *
 ***********************************************************************/
int bit_shift_020_func_001 ()
{
	return BITSIZE_INT;
}

void bit_shift_020 ()
{
	int a = 1, ret;
	
	ret = a >> bit_shift_020_func_001 (); /* ERROR: Bitwise shift error */
	sink = ret;
}


/***********************************************************************
 *
 * Defect type: Invalid bitwise shift
 * Complexity: Left shift beyond size of int using function argument
 *
 ***********************************************************************/
void bit_shift_021 (int shift)
{
	int a = 1, ret;
	
	ret = a << shift; /* ERROR: Bitwise shift error */
	sink = ret;	
}

/***********************************************************************
 *
 * Defect type: Invalid bitwise shift
 * Complexity: Right shift beyond size of int using function argument
 *
 ***********************************************************************/
void bit_shift_022 (int shift)
{
	int a = 1, ret;
	
	ret = a >> shift; /* ERROR: Bitwise shift error */
	sink = ret;	
}

/***********************************************************************
 *
 * Defect type: Invalid bitwise shift
 * Complexity: Left shift beyond size of int using value of array element
 *
 ***********************************************************************/
void bit_shift_023 ()
{
	int a = 1, ret;
	int shifts[5] = {8, 40, 16, 32, 24};
	
	ret = a << shifts[3]; /* ERROR: Bitwise shift error */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Invalid bitwise shift
 * Complexity: Right shift beyond size of int using value of array element
 *
 ***********************************************************************/
void bit_shift_024 ()
{
	int a = 1, ret;
	int shifts[5] = {8, 40, 16, 32, 24};
	
	ret = a >> shifts[3]; /* ERROR: Bitwise shift error */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Invalid bitwise shift
 * Complexity: Left shift beyond size of int using value of alias to variable
 *
 ***********************************************************************/
void bit_shift_025 ()
{
	int a = 1, ret;
	int shift, shift1;
	
	shift = BITSIZE_INT;
	shift1 = shift;
	ret = a << shift1; /* ERROR: Bitwise shift error */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Invalid bitwise shift
 * Complexity: Right shift beyond size of int using value of alias to variable
 *
 ***********************************************************************/
void bit_shift_026 ()
{
	int a = 1, ret;
	int shift, shift1;
	
	shift = BITSIZE_INT;
	shift1 = shift;
	ret = a >> shift1; /* ERROR: Bitwise shift error */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Invalid bitwise shift
 * Complexity: Left beyond size of int using value of double alias to variable
 *
 ***********************************************************************/
void bit_shift_027 ()
{
	int a = 1, ret;
	int shift, shift1, shift2;

	shift = BITSIZE_INT;
	shift1 = shift;
	shift2 = shift1;
	ret = a << shift2; /* ERROR: Bitwise shift error */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Invalid bitwise shift
 * Complexity: Right beyond size of int using value of double alias to variable
 *
 ***********************************************************************/
void bit_shift_028 ()
{
	int a = 1, ret;
	int shift, shift1, shift2;

	shift = BITSIZE_INT;
	shift1 = shift;
	shift2 = shift1;
	ret = a >> shift2; /* ERROR: Bitwise shift error */
	sink = ret;
}


/***********************************************************************
 *
 * Defect type: Invalid bitwise shift
 * Complexity: Left shift beyond size of int using constant operands
 *
 ***********************************************************************/
void bit_shift_029 ()
{
	int ret;
	
	ret = 1 << BITSIZE_INT; /* ERROR: Bitwise shift error */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Invalid bitwise shift
 * Complexity: Right shift beyond size of int using constant operands
 *
 ***********************************************************************/
void bit_shift_030 ()
{
	int ret;
	
	ret = 1 >> BITSIZE_INT; /* ERROR: Bitwise shift error */
	sink = ret;
}

/***********************************************************************
 *
 * Types of defects: Invalid bitwise shift
 * Complexity: overflow in shift left as a result of macro definition
 * http://www.gimpel.com/html/bugs/bug648.htm
 *
 ***********************************************************************/
#define TwoToThePowerOf(n)(2 << (n))

unsigned bit_shift_031_func_001( int n )
{
	if( TwoToThePowerOf(32)& n ) /* ERROR: Bitwise shift error */
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void bit_shift_031 ()
{
	unsigned ret;
	
	ret = bit_shift_031_func_001(-1);
}

/***********************************************************************
 *
 * Defect type: Invalid bitwise shift
 * Complexity: Left shift beyond size of int using compound assignment and conditional
 *
 ***********************************************************************/
void bit_shift_032 ()
{
	int a = 1, ret = 1;

	ret <<= (a == 1) ? BITSIZE_INT: -1; /* ERROR: Bitwise shift error */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Invalid bitwise shift
 * Complexity: Right shift beyond size of int using compound assignment and conditional
 *
 ***********************************************************************/
void bit_shift_033 ()
{
	int a = 1, ret = 1;

	ret >>= (a == 1) ? BITSIZE_INT: -1; /* ERROR: Bitwise shift error */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Invalid bitwise shift
 * Main 
 *
 ***********************************************************************/
extern volatile int vflag;

void bit_shift_main ()
{
	if (vflag == 1 || vflag == 888)
	{
		bit_shift_001 ();
	}

	if (vflag == 2 || vflag == 888)
	{
		bit_shift_002 ();
	}

	if (vflag == 3 || vflag == 888)
	{
		bit_shift_003 ();
	}

	if (vflag == 4 || vflag == 888)
	{
		bit_shift_004 ();
	}

	if (vflag == 5 || vflag == 888)
	{
		bit_shift_005 ();
	}

	if (vflag == 6 || vflag == 888)
	{
		bit_shift_006 ();
	}

	if (vflag == 7 || vflag == 888)
	{
		bit_shift_007 ();
	}

	if (vflag == 8 || vflag == 888)
	{
		bit_shift_008 ();
	}

	if (vflag == 9 || vflag == 888)
	{
		bit_shift_009 ();
	}

	if (vflag == 10 || vflag == 888)
	{
		bit_shift_010 ();
	}

	if (vflag == 11 || vflag == 888)
	{
		bit_shift_011 ();
	}

	if (vflag == 12 || vflag == 888)
	{
		bit_shift_012 ();
	}

	if (vflag == 13 || vflag == 888)
	{
		bit_shift_013 ();
	}

	if (vflag == 14 || vflag == 888)
	{
		bit_shift_014 ();
	}

	if (vflag == 15 || vflag == 888)
	{
		bit_shift_015 ();
	}
	
	if (vflag == 16 || vflag == 888)
	{
		bit_shift_016 ();
	}
	if (vflag == 17 || vflag == 888)
	{
		bit_shift_017 ();
	}

	if (vflag == 18 || vflag == 888)
	{
		bit_shift_018 ();
	}

	if (vflag == 19 || vflag == 888)
	{
		bit_shift_019 ();
	}

	if (vflag == 20 || vflag == 888)
	{
		bit_shift_020 ();
	}

	if (vflag == 21 || vflag == 888)
	{
		bit_shift_021 (BITSIZE_INT);
	}

	if (vflag == 22 || vflag == 888)
	{
		bit_shift_022 (BITSIZE_INT);
	}

	if (vflag == 23 || vflag == 888)
	{
		bit_shift_023 ();
	}

	if (vflag == 24 || vflag == 888)
	{
		bit_shift_024 ();
	}

	if (vflag == 25 || vflag == 888)
	{
		bit_shift_025 ();
	}

	if (vflag == 26 || vflag == 888)
	{
		bit_shift_026 ();
	}

	if (vflag == 27 || vflag == 888)
	{
		bit_shift_027 ();
	}
	
	if (vflag == 28 || vflag == 888)
	{
		bit_shift_028 ();
	}

	if (vflag == 29 || vflag == 888)
	{
		bit_shift_029 ();
	}

	if (vflag == 30 || vflag == 888)
	{
		bit_shift_030 ();
	}
	
	if (vflag == 31 || vflag == 888)
	{
		bit_shift_031 ();
	}
	
	if (vflag == 32 || vflag == 888)
	{
		bit_shift_032 ();
	}
	
	if (vflag == 33 || vflag == 888)
	{
		bit_shift_033 ();
	}
}
