/***********************************************************************
 *
 * Defect Classification
 * ---------------------
 * Description: Defect code used to identify improper data type conversion and mismatch
 *
 ***********************************************************************/

#include "HeaderFile.h"

int rand (void);

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Loss of sign due to cast 
 *
 ***********************************************************************/
void improper_conv_mismatch_001 ()
{
	unsigned char a = 0xff;
	char ret;
	
	ret = a; /* ERROR: Improper data type conversion */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Loss of sign due to cast 
 *
 ***********************************************************************/
void improper_conv_mismatch_002 ()
{
	unsigned short a = 0xffff;
	short ret;
	
	ret = a; /* ERROR: Improper data type conversion */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Loss of sign due to cast 
 *
 ***********************************************************************/
void improper_conv_mismatch_003 ()
{
	unsigned int a = 0xffffffff;
	int ret;
	
	ret = a; /* ERROR: Improper data type conversion */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Loss of sign due to cast 
 *
 ***********************************************************************/
void improper_conv_mismatch_004 ()
{
	unsigned long a = 0xffffffff;
	long ret;
	
	ret = a; /* ERROR: Improper data type conversion */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Loss of sign due to cast 
 *
 ***********************************************************************/
void improper_conv_mismatch_005 ()
{
	char a = -1;
	unsigned char ret;
	
	ret = a; /* ERROR: Improper data type conversion */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Loss of sign due to cast 
 *
 ***********************************************************************/
void improper_conv_mismatch_006 ()
{
	short a = -1;
	unsigned short ret;
	
	ret = a; /* ERROR: Improper data type conversion */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Loss of sign due to cast 
 *
 ***********************************************************************/
void improper_conv_mismatch_007 ()
{
	int a = -1;
	unsigned int ret;
	
	ret = a; /* ERROR: Improper data type conversion */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Loss of sign due to cast 
 *
 ***********************************************************************/
void improper_conv_mismatch_008 ()
{
	long a = -1;
	unsigned long ret;
	
	ret = a; /* ERROR: Improper data type conversion */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Loss of sign due to cast 
 *
 ***********************************************************************/
typedef struct {
	unsigned int a : 5;
	signed int ret : 5;
} improper_conv_mismatch_009_s_001;

void improper_conv_mismatch_009 ()
{
	improper_conv_mismatch_009_s_001 s;
	s.a = 0x1f;
	s.ret = s.a; /* ERROR: Improper data type conversion */
	sink = s.ret;
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Loss of sign due to cast 
 *
 ***********************************************************************/
typedef struct {
	signed int a : 5;
	unsigned int ret : 5;
} improper_conv_mismatch_010_s_001;

void improper_conv_mismatch_010 ()
{
	improper_conv_mismatch_010_s_001 s;
	s.a = -1;
	s.ret = s.a; /* ERROR: Improper data type conversion */
	sink = s.ret;
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Loss of sign due to cast 
 *
 ***********************************************************************/
void improper_conv_mismatch_011 ()
{
	unsigned int ret;

	ret = -1; /* ERROR: Improper data type conversion */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Loss of sign due to cast
 *
 ***********************************************************************/
void improper_conv_mismatch_012 ()
{
	int a;
	unsigned int ret;

	a = rand() - 1073741823;
	ret = a; /* ERROR: Improper data type conversion */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Loss of sign due to cast linear equation
 *
 ***********************************************************************/
void improper_conv_mismatch_013 ()
{
	int a = -1;
	unsigned int ret;
	
	ret = (5 * a) + 4; /* ERROR: Improper data type conversion */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Loss of sign due to cast nonlinear equation
 *
 ***********************************************************************/
void improper_conv_mismatch_014 ()
{
	int a = 2;
	unsigned int ret;
	
	ret = (a * a) - 5; /* ERROR: Improper data type conversion */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Loss of sign due to cast from return value of function call 
 *
 ***********************************************************************/
unsigned int improper_conv_mismatch_015_gbl;

int improper_conv_mismatch_015_func_001 ()
{
	return -1;
}

void improper_conv_mismatch_015 ()
{
	improper_conv_mismatch_015_gbl = improper_conv_mismatch_015_func_001(); /* ERROR: Improper data type conversion */
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Loss of sign due to cast of argument in function call 
 *
 ***********************************************************************/
unsigned int improper_conv_mismatch_016_gbl;

void improper_conv_mismatch_016_func_001 (int a)
{
	improper_conv_mismatch_016_gbl = a; /* ERROR: Improper data type conversion */
}

void improper_conv_mismatch_016 ()
{
	improper_conv_mismatch_016_func_001(-1);
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Loss of sign due to cast when referencing array element 
 *
 ***********************************************************************/
int improper_conv_mismatch_017_gbl_buf[5] = {1, 2, 3, -4, 5};

unsigned int improper_conv_mismatch_017_gbl;

void improper_conv_mismatch_017 ()
{
	improper_conv_mismatch_017_gbl = improper_conv_mismatch_017_gbl_buf[3]; /* ERROR: Improper data type conversion */
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Loss of sign due to cast of variable alias 
 *
 ***********************************************************************/
void improper_conv_mismatch_018 ()
{
	int a = -1, a1;
	unsigned int ret;
	
	a1 = a;
	ret = a1; /* ERROR: Improper data type conversion */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Loss of sign due to cast of variable double alias 
 *
 ***********************************************************************/
void improper_conv_mismatch_019 ()
{
	int a = -1, a1, a2;
	unsigned int ret;
	
	a1 = a;
	a2 = a1;
	ret = a2; /* ERROR: Improper data type conversion */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: signed-unsigned mix with divide
 *     Signed-unsigned mix with divide  -- one of the operands to / or %
 *     was signed and the other unsigned; moreover the signed quantity could be negative.
 *     n = n / u
 *     if n is -2 and u is 2, will not assign -1 to n but will assign some very large value.
 *     To resolve this problem, either cast the integer to unsigned if
 *     you know it can never be less than zero or cast the unsigned to
 *     an integer if you know it can never exceed the maximum integer.
 * http://www.gimpel.com/html/bugs/bug573.htm
 *
 ***********************************************************************/
void improper_conv_mismatch_020 ()
{
	const int march[31] = {
		 8, 5, 7, 2, -4, -14,  -7, -4, -2,  0,
		 0, 2, 5, 7,  2,  -4, -14, -7, -4, -2,
		 1, 7, 2, 2, -2,  -3,  -4,  6, -4,  3, 9
	};
	
	unsigned i, count = 31;
    	int sum = 0;
	
	for( i = 0; i < count; i++ )
	{
		sum += march[ i ];
	}
	printf(	"\t\t\"The average low temperature in March was"
		" %d degrees\"\n",
		sum / count ); /* ERROR: overflow in conversation */
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Loss of sign of strncat function 
 * http://www.gimpel.com/html/bugs/bug671.htm
 *
 ***********************************************************************/
void improper_conv_mismatch_021 ()
{
	char src[100] = "Static Analysis ";
	char dest[200];

    	(void)strncat( dest, src, length ); /* ERROR: Loss of sign */
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Loss of precision due to cast 
 *
 ***********************************************************************/
void improper_conv_mismatch_022 ()
{
	char ret;
	short a = 0x80;
	
	ret = a; /* ERROR: Precision lost because of cast */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Loss of precision due to cast 
 *
 ***********************************************************************/
void improper_conv_mismatch_023 ()
{
	short ret;
	int a = 0x8000;
	
	ret = a; /* ERROR: Precision lost because of cast */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Loss of precision due to cast 
 *
 ***********************************************************************/
void improper_conv_mismatch_024 ()
{
	short ret;
	long a = 0x8000;
	
	ret = a; /* ERROR: Precision lost because of cast */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Loss of precision due to cast 
 *
 ***********************************************************************/
void improper_conv_mismatch_025 ()
{
	int ret;
	float a = 2.14748365e+09F; /* 0x80000000 */
	
	ret = a; /* ERROR: Precision lost because of cast */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Loss of precision due to cast 
 *
 ***********************************************************************/
void improper_conv_mismatch_026 ()
{
	long ret;
	float a = 2.14748365e+09F; /* 0x80000000 */
	
	ret = a; /* ERROR: Precision lost because of cast */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Loss of precision due to cast 
 *
 ***********************************************************************/
void improper_conv_mismatch_027 ()
{
	float ret;				/* MAX: 2^127 * (2 - 2^(-23)) */
	double a = 3.4028235677973366e+38;	/*      2^127 * (2 - 2^(-24)) */
	
	ret = a; /* ERROR: Precision lost because of cast */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Loss of precision due to cast 
 *
 ***********************************************************************/
void improper_conv_mismatch_028 ()
{
	unsigned char ret;
	unsigned short a = 0x0100;

	ret = a; /* ERROR: Precision lost because of cast */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Loss of precision due to cast 
 *
 ***********************************************************************/
void improper_conv_mismatch_029 ()
{
	unsigned short ret;
	unsigned int a = 0x00010000;
	
	ret = a; /* ERROR: Precision lost because of cast */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Loss of precision due to cast 
 *
 ***********************************************************************/
void improper_conv_mismatch_030 ()
{
	unsigned short ret;
	unsigned long a = 0x00010000;
	
	ret = a; /* ERROR: Precision lost because of cast */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Loss of precision due to cast 
 *
 ***********************************************************************/
typedef struct {
	signed int ret : 5;
	signed int a : 7;
} improper_conv_mismatch_031_s_001;

void improper_conv_mismatch_031 ()
{
	improper_conv_mismatch_031_s_001 s;
	s.a = 0x1f;
	s.ret = s.a; /* ERROR: Precision lost because of cast */
	sink = s.ret;
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Loss of precision due to cast 
 *
 ***********************************************************************/
void improper_conv_mismatch_032 ()
{
	short ret;
	
	ret = 0x8000; /* ERROR: Precision lost because of cast */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Possible loss of precision due to use of random number as argument to cast
 *
 ***********************************************************************/
void improper_conv_mismatch_033 ()
{
	short ret;
	int a;
	
	a = rand();
	ret = a; /* ERROR: Precision lost because of cast */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Loss of precision due to cast of a linear equation 
 *
 ***********************************************************************/
void improper_conv_mismatch_034 ()
{
	short ret;
	int a = 129;

	ret = (254 * a) + 2; /* ERROR: Precision lost because of cast */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Loss of precision due to cast of a nonlinear equation 
 *
 ***********************************************************************/
void improper_conv_mismatch_035 ()
{
	short ret;
	int a = 181;

	ret = (a * a) + 7; /* ERROR: Precision lost because of cast */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Loss of precision due to cast of return value of function call as argument 
 *
 ***********************************************************************/
int improper_conv_mismatch_036_func_001 ()
{
	return 0x8000;
}

void improper_conv_mismatch_036 ()
{
	short ret;
	
	ret = improper_conv_mismatch_015_func_001(); /* ERROR: Precision lost because of cast */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Loss of precision due to cast of function argument  
 *
 ***********************************************************************/
void improper_conv_mismatch_037_func_001 (int a)
{
	short ret;
	ret = a; /* ERROR: Precision lost because of cast */
	sink = ret;
}

void improper_conv_mismatch_037 ()
{
	improper_conv_mismatch_037_func_001(0x8000);
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Loss of precision due to cast of array element
 *
 ***********************************************************************/
void improper_conv_mismatch_038 ()
{
	short ret;
	int buf[5] = {0x0111, 0x0001, 0x0011, 0x8000, 0x1111};
	
	ret = buf[3]; /* ERROR: Precision lost because of cast */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Loss of precision due to cast of alias 
 *
 ***********************************************************************/
void improper_conv_mismatch_039 ()
{
	short ret;
	int a = 0x8000;
	int a1;

	a1 = a;
	ret = a1; /* ERROR: Precision lost because of cast */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Loss of precision due to cast of double alias 
 *
 ***********************************************************************/
void improper_conv_mismatch_040 ()
{
	short ret;
	int a = 0x8000;
	int a1;
	int a2;

	a1 = a;
	a2 = a1;
	ret = a2; /* ERROR: Precision lost because of cast */
	sink = ret;
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Loss of precision during assignment in while loop control condition 
 * http://www.gimpel.com/html/bugs/bug524.htm
 *
 ***********************************************************************/
double abs_20( double x ) { return x >= 0 ? x : -x; }

double sqrt_20( double y )
{
	double x = 1.0;         
	int error;

	if( y <= 0 ) { return 0; }
	while( abs_20( error = y - x * x ) > .0005 )  /* ERROR: Precision lost because of cast */
	{
		x = x + error / (2 * x);
	}
	return x;
}

void improper_conv_mismatch_041(void)
{
	(void) printf( "\t\tsqrt(%d) = %8.3f\n", 2, sqrt_20(2) );
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Loss of precision due to cast 
 *     Small bit field is signed rather than unsigned  -- A small bit field
 *     (less than an int wide) was found and the base type is signed rather
 *     than unsigned.  Since the most significant bit is a sign bit this
 *     practice can produce surprising results.  For example,
 *            struct { int b:1; } s;
 *            s.b = 1;
 *            if( s.b > 0 ) // should succeed but actually fails
 * http://www.gimpel.com/html/bugs/bug806.htm
 *
 ***********************************************************************/
struct pumpkin { int nose:1, eyes:2; } p = { 1, 2 }; /* ERROR: Precision lost because of cast */

int f(void)
{
	if( p.nose > 0 && p.eyes > 1 ) { return 1; }
	else { return 0; }
}

void improper_conv_mismatch_042(void)
{
	if( f() ) { (void) printf( "\t\tnose and eyes\n" ); }
	else { (void) printf( "\t\tmalformed\n" ); }
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Check Assertion on Unsigned Integer
 *
 ***********************************************************************/
void improper_conv_mismatch_101 ()
{
	 printf("Storage size for int : %d \n", sizeof(int)); /* ERROR: Type mismatch */
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Comparing type 'char' with EOF 
 * http://www.gimpel.com/html/newbugs/bug583.htm
 *
 *     Comparing type 'Type' with EOF  -- The message is issued when
 *     some form of character is compared against the EOF macro.  EOF is
 *     normally defined to be -1.  For example:
 *
 *                while( (ch = getchar()) != EOF ) ...
 *
 *      If ch is defined to be an int all is well.  If however it is
 *      defined to be some form of char, then trouble might ensue.  If ch
 *      is an unsigned char then it can never equal EOF.  If ch is a
 *      signed char then you could get a premature termination because
 *      some data character happened to be all ones.
 *
 *      Note that getchar returns an int.  The reason it returns an int
 *      and not a char is because it must be capable of returning 257
 *      different values (256 different characters plus EOF, assuming an
 *      8-bit character).  Once this value is assigned to a char only 256
 *      values are then possible -- a clear loss of information.
 *
 ***********************************************************************/
char Cairo[] = "abcdefg";

char Tokyo[] = "hijklmn";

void improper_conv_mismatch_102 ()
{
	enum { NC = 2 };
	char *Cities[NC] = { Cairo, Tokyo };
	FILE *f[NC] = {0};

	char ch;
	int i;

	for (i = 0; i < NC; i++)
	{
		f[i] = fopen(Cities[i], "wb");
		if (!f[i])
		{
			for (i = 0; i < NC; i++)
			{
				if(f[i])
				{
					(void)fclose(f[i]);
				}
			}
		}
	}
	while ((ch = getchar()) != EOF) /* ERROR overflow in conversion*/
	{
		for (i = 0; i < NC; i++)
		{
			putc(ch, f[i]);
		}
	}
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Indirect objects inconsistent with format 
 * http://www.gimpel.com/html/bugs/bug561.htm
 *
 ***********************************************************************/
void improper_conv_mismatch_103(void)
{
	typedef short int Integer;
	const char *input = "3 4 5";
	Integer a[3];
	
	#define x a[0]
	#define y a[1]
	#define z a[2]

	(void) sscanf( input, "%d %d %d", &x, &y, &z ); /* ERROR: type mismatch */
	if( x*x + y*y == z*z )
	{
		(void) printf( "\t\t%s is a right triangle\n", input );
	}
	else
	{
		(void) printf( "\t\t%s is not a right triangle\n", input );
	}
	
	#undef x
	#undef y
	#undef z
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Complexity: Type mismatch, too few arguments to printf function 
 * http://www.gimpel.com/html/bugs/bug558.htm
 *
 ***********************************************************************/
void improper_conv_mismatch_104(void)
{
	(void) printf( "%s %s\n", "Greetings to all people" "on Earth" ); /* ERROR: Format string and arguments mismatch */
	// (void) printf( "\t\t%s %s\n","Greetings to all people", "on Earth" );
}

/***********************************************************************
 *
 * Defect type: Improper data type conversion and mismatch 
 * Main 
 *
 ***********************************************************************/
extern volatile int vflag;

void improper_conv_mismatch_main ()
{
	if (vflag == 1 || vflag == 888)
	{
		improper_conv_mismatch_001();
	}

	if (vflag == 2 || vflag == 888)
	{
		improper_conv_mismatch_002();
	}

	if (vflag == 3 || vflag == 888)
	{
		improper_conv_mismatch_003();
	}

	if (vflag == 4 || vflag == 888)
	{
		improper_conv_mismatch_004();
	}

	if (vflag == 5 || vflag == 888)
	{
		improper_conv_mismatch_005();
	}

	if (vflag == 6 || vflag == 888)
	{
		improper_conv_mismatch_006();
	}

	if (vflag == 7 || vflag == 888)
	{
		improper_conv_mismatch_007();
	}

	if (vflag == 8 || vflag == 888)
	{
		improper_conv_mismatch_008();
	}

	if (vflag == 9 || vflag == 888)
	{
		improper_conv_mismatch_009();
	}

	if (vflag == 10 || vflag == 888)
	{
		improper_conv_mismatch_010();
	}

	if (vflag == 11 || vflag == 888)
	{
		improper_conv_mismatch_011();
	}

	if (vflag == 12 || vflag == 888)
	{
		improper_conv_mismatch_012();
	}

	if (vflag == 13 || vflag == 888)
	{
		improper_conv_mismatch_013();
	}

	if (vflag == 14 || vflag == 888)
	{
		improper_conv_mismatch_014();
	}

	if (vflag == 15 || vflag == 888)
	{
		improper_conv_mismatch_015();
	}

	if (vflag == 16 || vflag == 888)
	{
		improper_conv_mismatch_016();
	}

	if (vflag == 17 || vflag == 888)
	{
		improper_conv_mismatch_017();
	}

	if (vflag == 18 || vflag == 888)
	{
		improper_conv_mismatch_018();
	}

	if (vflag == 19 || vflag == 888)
	{
		improper_conv_mismatch_019();
	}

	if (vflag == 20 || vflag == 888)
	{
		improper_conv_mismatch_020();
	}

	if (vflag == 21 || vflag == 888)
	{
		improper_conv_mismatch_021();
	}

	if (vflag == 22 || vflag == 888)
	{
		improper_conv_mismatch_022();
	}

	if (vflag == 23 || vflag == 888)
	{
		improper_conv_mismatch_023();
	}

	if (vflag == 24 || vflag == 888)
	{
		improper_conv_mismatch_024();
	}

	if (vflag == 25 || vflag == 888)
	{
		improper_conv_mismatch_025();
	}

	if (vflag == 26 || vflag == 888)
	{
		improper_conv_mismatch_026();
	}

	if (vflag == 27 || vflag == 888)
	{
		improper_conv_mismatch_027();
	}

	if (vflag == 28 || vflag == 888)
	{
		improper_conv_mismatch_028();
	}

	if (vflag == 29 || vflag == 888)
	{
		improper_conv_mismatch_029();
	}

	if (vflag == 30 || vflag == 888)
	{
		improper_conv_mismatch_030();
	}

	if (vflag == 31 || vflag == 888)
	{
		improper_conv_mismatch_031();
	}

	if (vflag == 32 || vflag == 888)
	{
		improper_conv_mismatch_032();
	}

	if (vflag == 33 || vflag == 888)
	{
		improper_conv_mismatch_033();
	}

	if (vflag == 34 || vflag == 888)
	{
		improper_conv_mismatch_034();
	}

	if (vflag == 35 || vflag == 888)
	{
		improper_conv_mismatch_035();
	}

	if (vflag == 36 || vflag == 888)
	{
		improper_conv_mismatch_036();
	}

	if (vflag == 37 || vflag == 888)
	{
		improper_conv_mismatch_037();
	}

	if (vflag == 38 || vflag == 888)
	{
		improper_conv_mismatch_038();
	}

	if (vflag == 39 || vflag == 888)
	{
		improper_conv_mismatch_039();
	}

	if (vflag == 40 || vflag == 888)
	{
		improper_conv_mismatch_040();
	}

	if (vflag == 41 || vflag == 888)
	{
		improper_conv_mismatch_041();
	}

	if (vflag == 42 || vflag == 888)
	{
		improper_conv_mismatch_042();
	}

	if (vflag == 101 || vflag == 888)
	{
		improper_conv_mismatch_101();
	}

	if (vflag == 102 || vflag == 888)
	{
		improper_conv_mismatch_102();
	}

	if (vflag == 103 || vflag == 888)
	{
		improper_conv_mismatch_103();
	}

	if (vflag == 104 || vflag == 888)
	{
		improper_conv_mismatch_104();
	}
}
