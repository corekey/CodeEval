/***********************************************************************
 *
 * Defect Classification
 * ---------------------
 * Description: Defect code used to identify buffer overflow
 *
 ***********************************************************************/

#include "HeaderFile.h"

int rand (void);

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of array
 *
 ***********************************************************************/
void buffer_overflow_001 (int flag)
{
	char  	cbuf[5];
	short 	sbuf[5];
	int 	ibuf[5];
	long 	lbuf[5];
	float 	fbuf[5];
	double 	dbuf[5];

	switch (flag)
	{
		case 1: cbuf[5] = 1;   	/* ERROR: Buffer overflow  */
			break;
		case 2: sbuf[5] = 1;   	/* ERROR: Buffer overflow  */
			break;
		case 3: ibuf[5] = 1;   	/* ERROR: Buffer overflow  */
			break;
		case 4: lbuf[5] = 1;  	/* ERROR: Buffer overflow  */
			break;
		case 5: fbuf[5] = 1.0; 	/* ERROR: Buffer overflow  */
			break;
		case 6: dbuf[5] = 1.0; 	/* ERROR: Buffer overflow  */
			break;
		default:
			break;
	}
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Read beyond bounds of array
 *
 ***********************************************************************/
void buffer_overflow_002 (int flag)
{
	char 	cbuf[5] = {1, 2, 3, 4, 5}, ret_c;
	short 	sbuf[5] = {1, 2, 3, 4, 5}, ret_s;
	int 	ibuf[5] = {1, 2, 3, 4, 5}, ret_i;
	long 	lbuf[5] = {1, 2, 3, 4, 5}, ret_l;
	float 	fbuf[5] = {1, 2, 3, 4, 5}, ret_f;
	double 	dbuf[5] = {1, 2, 3, 4, 5}, ret_d;
	
	switch (flag)
	{
		case 1: ret_c = cbuf[5]; /* ERROR: Buffer overflow  */
			break;
		case 2: ret_s = sbuf[5]; /* ERROR: Buffer overflow  */
			break;
		case 3: ret_i = ibuf[5]; /* ERROR: Buffer overflow  */
			break;
		case 4: ret_l = lbuf[5]; /* ERROR: Buffer overflow  */
			break;
		case 5: ret_f = fbuf[5]; /* ERROR: Buffer overflow  */
			break;
		case 6: ret_d = dbuf[5]; /* ERROR: Buffer overflow  */
			break;
		default:
			break;
	}
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of 2D array
 *
 ***********************************************************************/
void buffer_overflow_003 (int flag)
{
	char 	buf1[5][6];
	short 	buf2[5][6];
	int 	buf3[5][6];
	long 	buf4[5][6];
	float 	buf5[5][6];
	double 	buf6[5][6];

	switch(flag)
	{
		case 1: buf1[5][5] = 1;   /* ERROR: Buffer overflow  */
			break;
		case 2: buf2[5][5] = 1;   /* ERROR: Buffer overflow  */
			break;
		case 3: buf3[5][5] = 1;   /* ERROR: Buffer overflow  */
			break;
		case 4: buf4[5][5] = 1;   /* ERROR: Buffer overflow  */
			break;
		case 5: buf5[5][5] = 1.0; /* ERROR: Buffer overflow  */
			break;
		case 6: buf6[5][5] = 1.0; /* ERROR: Buffer overflow  */
			break;
		default:
			break;
	}
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of 3D array
 *
 ***********************************************************************/
void buffer_overflow_004 (int flag)
{
	char 	buf1[5][6][7];
	short 	buf2[5][6][7];
	int 	buf3[5][6][7];
	long 	buf4[5][6][7];
	float 	buf5[5][6][7];
	double 	buf6[5][6][7];

	switch(flag)
	{
		case 1: buf1[5][5][6] = 1;   /* ERROR: Buffer overflow  */
			break;
		case 2: buf2[5][5][6] = 1;   /* ERROR: Buffer overflow  */
			break;
		case 3: buf3[5][5][6] = 1;   /* ERROR: Buffer overflow  */
			break;
		case 4: buf4[5][5][6] = 1;   /* ERROR: Buffer overflow  */
			break;
		case 5: buf5[5][5][6] = 1.0; /* ERROR: Buffer overflow  */
			break;
		case 6: buf6[5][5][6] = 1.0; /* ERROR: Buffer overflow  */
			break;
		default:
			break;
	}
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of 2D array using pointer buffer
 *
 ***********************************************************************/
void buffer_overflow_005 ()
{
	int buf1[6];
	int buf2[6];
	int buf3[6];
	int buf4[6];
	int buf5[5];
	int *pbuf[5] = {buf1, buf2, buf3, buf4, buf5};

	pbuf[4][5] = 1; /* ERROR: Buffer overflow  */
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of structure array 
 *
 ***********************************************************************/
typedef struct {
	int a;
	int b;
	int buf[5];
} buffer_overflow_structure;

void buffer_overflow_006 ()
{
	buffer_overflow_structure sbuf[5];

	sbuf[5].a = 1; 	   /* ERROR: Buffer overflow  */
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of array structure member 
 *
 ***********************************************************************/
buffer_overflow_structure buffer_overflow_007_s_gbl; 

void buffer_overflow_007 ()
{
	buffer_overflow_007_s_gbl.buf[5] = 1; /* ERROR: Buffer overflow  */
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Possible write beyond bounds of array using random index 
 *
 ***********************************************************************/
void buffer_overflow_008 ()
{
	int buf[5];
	int index;

	index = rand ();
	buf[index] = 1; 	/* ERROR: Buffer overflow  */
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of array using result of linear equation index 
 *
 ***********************************************************************/
void buffer_overflow_009 ()
{
	int buf[5];
	int index = 2;

	buf[(2 * index) + 1] = 1;      /* ERROR: Buffer overflow  */
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of array using result of nonlinear equation as index 
 *
 ***********************************************************************/
void buffer_overflow_010 ()
{
	int buf[5];
	int index = 2;

	buf[(index * index) + 1] = 1; 	   /* ERROR: Buffer overflow  */
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of array using return value of function call as index 
 *
 ***********************************************************************/
int buffer_overflow_011_func_001 ()
{
	return 5;
}

void buffer_overflow_011 ()
{
	int buf[5];

	buf[buffer_overflow_011_func_001 ()] = 1; /* ERROR: Buffer overflow  */
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of array using function argument as index 
 *
 ***********************************************************************/
void buffer_overflow_012 (int index)
{
	int buffer_overflow_012_buf[5];

	buffer_overflow_012_buf[index] = 1; 	/* ERROR: Buffer overflow  */
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of array using array element as index 
 *
 ***********************************************************************/
void buffer_overflow_013 ()
{
	int buf[5];
	int indexes[4] = {3, 4, 5, 6};
	int index = 2;

	buf[indexes[index]] = 1;       /* ERROR: Buffer overflow  */
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of array using alias to variable index  
 *
 ***********************************************************************/
void buffer_overflow_014 ()
{
	int buf[5];
	int index = 5;
	int index1;
	
	index1 = index;
	buf[index1] = 1;     /* ERROR: Buffer overflow  */
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of array using double alias to variable index  
 *
 ***********************************************************************/
void buffer_overflow_015 ()
{
	int buf[5];
	int index = 5;
	int index1;
	int index2;

	index1 = index;
	index2 = index1;
	buf[index2] = 1;     /* ERROR: Buffer overflow  */
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of array using offset to double pointer 
 *
 ***********************************************************************/
void buffer_overflow_016 ()
{
	int buf[5];
	int *p;
	int **pp;

	p = buf;
	pp = &p;
	*(*pp + 5) = 1; /* ERROR: Buffer overflow  */
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of array using pointer alias
 *
 ***********************************************************************/
void buffer_overflow_017 ()
{
	int buf[5];
	int *p1;
	int *p2;
	
	p1 = buf;
	p2 = p1;
	p2[5] = 1;     /* ERROR: Buffer overflow  */
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of global array using alias to array 
 *
 ***********************************************************************/
int buffer_overflow_018_buf_gbl[5];

void buffer_overflow_018 ()
{
	int *p;
	
	p = buffer_overflow_018_buf_gbl;
	p[5] = 1;     /* ERROR: Buffer overflow  */
}

/***********************************************************************
 *
 * Types of defects: buffer overflow ( static buffer )
 * Complexity: 
 * http://www.gimpel.com/html/newbugs/bug415.htm
 *
 ***********************************************************************/
enum {
	Whiskey = 1,		Vodka = 2,			DryVermouth = 4,	IrishCream = 8,
	CrDeCacoa = 0x10,	CrDeMenthe = 0x20,	Grenadine = 0x40,	LimeJuice = 0x80
};

struct Recipe { unsigned id; const char *name; unsigned ingred; } drinks[] =
{
	{1, "Wild Irish Rose",	Whiskey		| Grenadine		| LimeJuice},
	{2, "Irish Martini",	Whiskey		| DryVermouth	| Vodka},
	{3, "Irish Paddy",		CrDeCacoa	| CrDeMenthe	| IrishCream},
	{0, "", 0}
};

unsigned buffer_overflow_019_func_001(char *name)
{
	for (unsigned i = 0;
		drinks[sizeof(drinks) / sizeof(drinks[0])].id; /* ERROR: Buffer overflow  */
		i++ )
	{
		if ( strcmp( drinks[i].name, name ) == 0 )
		{
			return drinks[i].ingred;
		}
	}
	return 0;
}

void buffer_overflow_019 ()
{
	(void)buffer_overflow_019_func_001("Irish Patty");
}

/***********************************************************************
 *
 * Types of defects: buffer overflow ( static buffer )
 * Complexity: Out of upper bound of a array in an infinite for loop
 * http://www.gimpel.com/html/bugs/bug662.htm
 *
 ***********************************************************************/
#define NPARTIES 5

#define EOF -1

#define fetch_vote 5

int vote[ NPARTIES - 1 ];

void buffer_overflow_020 ()
{
	int v;
	for (;;)
	{
		v = fetch_vote;
		if ( v == EOF )
		{
			break;
		}

		if ( v <= NPARTIES )
		{
			vote[v]++; /* ERROR: Buffer overflow  */
		}
	}
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of array in nested for loop 
 *
 ***********************************************************************/
void buffer_overflow_021 ()
{
	char buf[5][6];
	int i;
	int j;
	
	for (i = 0; i <= 5; i ++)
	{
		for (j = 0; j <= 6; j ++)
		{
			buf[i][j] = (i+j) % 2 ? ' ' : '*'; /* ERROR: Buffer overflow  */
		}
	}
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of array in nested for loop using pointer buffer 
 *
 ***********************************************************************/
void buffer_overflow_022 ()
{
	int buf1[6];
	int buf2[6];
	int buf3[6];
	int buf4[6];
	int buf5[5];
	int *pbuf[5] = {buf1, buf2, buf3, buf4, buf5};
	int i;
	int j;

	for (i = 0; i < 5; i ++)
	{
		for (j = 0; j < 6; j ++)
		{
			pbuf[i][j] = 1;     /* ERROR: Buffer overflow  */
		}
	}
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of array in for loop using increment offset to pointer 
 *
 ***********************************************************************/
void buffer_overflow_023 ()
{
	int buf[5];
	int *p;
	int i;

	p = buf;
	for (i = 0; i <= 5; i ++)
	{
		*p = 1; /* ERROR: Buffer overflow  */
		p ++;
	}
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of array parameter
 *
 ***********************************************************************/
void buffer_overflow_024_func_001 (int buf[])
{
	buf[5] = 1;     /* ERROR: Buffer overflow  */
}

void buffer_overflow_024 ()
{
	int buf[5];

	buffer_overflow_024_func_001(buf);
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of array pointer parameter
 *
 ***********************************************************************/
void buffer_overflow_025_func_001 (int *p)
{
	p[5] = 1;     /* ERROR: Buffer overflow  */
}

void buffer_overflow_025 ()
{
	int buf[5];

	buffer_overflow_025_func_001(buf);
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of array declared without explicit size
 *
 ***********************************************************************/
void buffer_overflow_026 ()
{
	int buf1[] = {1, 2, 3, 4, 5};
	
	buf1[5] = 1; 	 /* ERROR: Buffer overflow  */
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of 2D array declared without explicit size
 *
 ***********************************************************************/
void buffer_overflow_027 ()
{
	int buf1[] = {1, 2, 3, 4, 5, 6};
	int buf2[] = {1, 2, 3, 4, 5, 6};
	int buf3[] = {1, 2, 3, 4, 5, 6};
	int buf4[] = {1, 2, 3, 4, 5, 6};
	int buf5[] = {1, 2, 3, 4, 5};
	int *pbuf[] = {buf1, buf2, buf3, buf4, buf5};

	pbuf[4][5] = 1; /* ERROR: Buffer overflow  */
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of array using offset to pointer casted to large data type
 *
 ***********************************************************************/
void buffer_overflow_028 ()
{
	char buf[8];
	int *p;

	p = (int*)buf;
	p[2] = 1; /* ERROR: Buffer overflow  */
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of array using offset to pointer casted to smaller data type
 *
 ***********************************************************************/
int buffer_overflow_029_buf_gbl[5];

void buffer_overflow_029 ()
{
	int *p;

	p = (char*)buffer_overflow_029_buf_gbl;
	p[50] = 1; /* ERROR: Buffer overflow  */
}

/***********************************************************************
 *
 * Types of defects: buffer overflow ( static buffer )
 * Complexity: Out of upper bound of a array in 2nd level function call
 * http://www.gimpel.com/html/newbugs/bug661.htm
 *
 ***********************************************************************/
int buffer_overflow_030_func_002(void)
{
	enum {N = 5};
	int Weight[N] = { 3, 1, 4, 5, 2 };
	int i, choice = 0;
	int k = rand () % (3 * N);

	for ( i = 0; i <= N; i++ )
	{
		if ( k >= 0 )
		{
			choice = i;
		}
		k -= Weight[i]; /* ERROR: Buffer overflow  */
	}
	return choice;
}

int buffer_overflow_030_func_001( int vote )
{
	if ( vote == 1 )
	{
		return buffer_overflow_030_func_002 ();
	}
	else
	{
		return vote;
	}
}

void buffer_overflow_030 ()
{
	(void)buffer_overflow_030_func_001(1);
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of array
 *
 ***********************************************************************/
void buffer_overflow_031 (int flag)
{
	char  	cbuf[5];
	short 	sbuf[5];
	int 	ibuf[5];
	long 	lbuf[5];
	float 	fbuf[5];
	double 	dbuf[5];

	switch (flag)
	{
		case 1: *(cbuf + 5) = 1; 	/* ERROR: Buffer overflow  */
			break;
		case 2: *(sbuf + 5) = 1; 	/* ERROR: Buffer overflow  */
			break;
		case 3: *(ibuf + 5) = 1; 	/* ERROR: Buffer overflow  */
			break;
		case 4: *(lbuf + 5) = 1; 	/* ERROR: Buffer overflow  */
			break;
		case 5: *(fbuf + 5) = 1.0; 	/* ERROR: Buffer overflow  */
			break;
		case 6: *(dbuf + 5) = 1.0; 	/* ERROR: Buffer overflow  */
			break;
		default:
			break;
	}
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Read beyond bounds of array
 *
 ***********************************************************************/
void buffer_overflow_032 (int flag)
{
	char 	cbuf[5] = {1, 2, 3, 4, 5}, ret_c;
	short 	sbuf[5] = {1, 2, 3, 4, 5}, ret_s;
	int 	ibuf[5] = {1, 2, 3, 4, 5}, ret_i;
	long 	lbuf[5] = {1, 2, 3, 4, 5}, ret_l;
	float 	fbuf[5] = {1, 2, 3, 4, 5}, ret_f;
	double 	dbuf[5] = {1, 2, 3, 4, 5}, ret_d;
	
	switch (flag)
	{
		case 1: ret_c = *(cbuf + 5); 	/* ERROR: Buffer overflow  */
			break;
		case 2: ret_s = *(sbuf + 5); 	/* ERROR: Buffer overflow  */
			break;
		case 3: ret_i = *(ibuf + 5); 	/* ERROR: Buffer overflow  */
			break;
		case 4: ret_l = *(lbuf + 5); 	/* ERROR: Buffer overflow  */
			break;
		case 5: ret_f = *(fbuf + 5); 	/* ERROR: Buffer overflow  */
			break;
		case 6: ret_d = *(dbuf + 5); 	/* ERROR: Buffer overflow  */
			break;
		default:
			break;
	}
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of structure array 
 *
 ***********************************************************************/
void buffer_overflow_033 ()
{
	buffer_overflow_structure sbuf[5];

	//*(sbuf + 5).a = 1; /* ERROR: Buffer overflow  */
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Possible write beyond bounds of array using random index 
 *
 ***********************************************************************/
void buffer_overflow_034 ()
{
	int buf[5];
	int index;

	index = rand ();
	*(buf + index) = 1; 	/* ERROR: Buffer overflow  */
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of array using result of linear equation index 
 *
 ***********************************************************************/
void buffer_overflow_035 ()
{
	int buf[5];
	int index = 2;

	*(buf + ((2 * index) + 1))= 1; /* ERROR: Buffer overflow  */
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of array using result of nonlinear equation as index 
 *
 ***********************************************************************/
void buffer_overflow_036 ()
{
	int buf[5];
	int index = 2;

	*(buf + ((index * index) + 1))= 1; /* ERROR: Buffer overflow  */
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of array using return value of function call as index 
 *
 ***********************************************************************/
int buffer_overflow_037_func_001 ()
{
	return 5;
}

void buffer_overflow_037 ()
{
	int buf[5];

	*(buf + buffer_overflow_037_func_001 ()) = 1;  /* ERROR: Buffer overflow  */
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of array using function argument as index 
 *
 ***********************************************************************/
void buffer_overflow_038 (int index)
{
	int buf[5];

	*(buf + index) = 1; /* ERROR: Buffer overflow  */
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of array using array element as index 
 *
 ***********************************************************************/
void buffer_overflow_039 ()
{
	int buf[5];
	int indexes[4] = {3, 4, 5, 6};
	int index = 2;

	*(buf + (indexes[index])) = 1; /* ERROR: Buffer overflow  */
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of array using alias to variable index  
 *
 ***********************************************************************/
void buffer_overflow_040 ()
{
	int buf[5];
	int index = 5;
	int index1;
	
	index1 = index;
	*(buf + index1) = 1; /* ERROR: Buffer overflow  */
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of array using double alias to variable index  
 *
 ***********************************************************************/
void buffer_overflow_041 ()
{
	int buf[5];
	int index = 5;
	int index1;
	int index2;

	index1 = index;
	index2 = index1;
	*(buf + index2) = 1; /* ERROR: Buffer overflow  */
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of array using offset to double pointer 
 *
 ***********************************************************************/
void buffer_overflow_042 ()
{
	int buf[5];
	int *p;
	int **pp;

	p = buf;
	pp = &p;
	*(*pp + 5) = 1; /* ERROR: Buffer overflow  */
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of array using pointer alias
 *
 ***********************************************************************/
void buffer_overflow_043 ()
{
	int buf[5];
	int *p1;
	int *p2;
	
	p1 = buf;
	p2 = p1;
	*(p2 + 5) = 1; /* ERROR: Buffer overflow  */
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of global array using alias to array 
 *
 ***********************************************************************/
int buffer_overflow_044_buf_gbl[5];

void buffer_overflow_044 ()
{
	int *p;
	
	p = buffer_overflow_044_buf_gbl;
	*(p + 5) = 1; /* ERROR: Buffer overflow  */
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of array parameter
 *
 ***********************************************************************/
void buffer_overflow_045_func_001 (int buf[])
{
	*(buf + 5) = 1; /* ERROR: Buffer overflow  */
}

void buffer_overflow_045 ()
{
	int buf[5];

	buffer_overflow_045_func_001(buf);
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of array pointer parameter
 *
 ***********************************************************************/
void buffer_overflow_046_func_001 (int *p)
{
	*(p + 5) = 1; /* ERROR: Buffer overflow  */
}

void buffer_overflow_046 ()
{
	int buf[5];

	buffer_overflow_046_func_001(buf);
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of array using offset to pointer casted to large data type
 *
 ***********************************************************************/
void buffer_overflow_047 ()
{
	char buf[8];
	int *p;

	p = (int*)buf;
	*(p + 2) = 1; /* ERROR: Buffer overflow  */
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of array using offset to pointer casted to smaller data type
 *
 ***********************************************************************/
int buffer_overflow_048_buf_gbl[5];

void buffer_overflow_048 ()
{
	int *p;

	p = (char*)buffer_overflow_048_buf_gbl;
	*(p + 50) = 1; /* ERROR: Buffer overflow  */
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of array declared without explicit size
 *
 ***********************************************************************/
void buffer_overflow_049 ()
{
	int buf2[][6] =
		{
			{1, 2, 3, 4, 5, 6},
			{1, 2, 3, 4, 5, 6},
			{1, 2, 3, 4, 5, 6},
			{1, 2, 3, 4, 5, 6},
			{1, 2, 3, 4, 5, 6}
		};
	buf2[5][5] = 1;  /* ERROR: Buffer overflow  */
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of array declared without explicit size
 *
 ***********************************************************************/
void buffer_overflow_050 ()
{
	char buf3[] = "1234";
	
	buf3[5] = 1;	 /* ERROR: Buffer overflow  */
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Stack overflow due to large internal variables
 *
 ***********************************************************************/
void buffer_overflow_101 ()
{
	double buf[1048576]; /* ERROR: Buffer overflow  */
	
	buf[0] = 1.0;
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Stack overflow due to large argument in function call
 *
 ***********************************************************************/
typedef struct {
	char buf[524288];	
	char buf1[65536];
	char buf2[65536];
	char buf3[65536];
	char buf4[65536];
	char buf5[65536];
	char buf6[65536];
	char buf7[65536];
	char buf8[65536];

} buffer_overflow_102_s_001;

void buffer_overflow_102_func_001 (buffer_overflow_102_s_001 s)
{
	s.buf[0] = 1; 
}

void buffer_overflow_102 ()
{
	buffer_overflow_102_s_001 s;	
	buffer_overflow_102_func_001(s); /* ERROR: Buffer overflow  */
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Stack overflow due to large variables and arguments in function call
 *
 ***********************************************************************/
typedef struct {
	char buf[524288];	
	char buf1[131072];  
	char buf2[131072]; 
	char buf3[1024];
	char buf4[1024];
	
} buffer_overflow_103_s_001;

void buffer_overflow_103_func_001 (buffer_overflow_103_s_001 s)
{
	char buf[524288]; /* ERROR: Buffer overflow  */
	
	s.buf[0] = 1;
	buf[0] = 1;
}

void buffer_overflow_103 ()
{
	buffer_overflow_103_s_001 s;
	buffer_overflow_103_func_001(s);
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Stack overflow due to large variables and arguments in function call, multi level
 *
 ***********************************************************************/
typedef struct {
	char buf[524288];
	char buf1[131072];
	char buf2[1024];
	char buf3[1024];

} buffer_overflow_104_s_001;

void buffer_overflow_104_func_002 (buffer_overflow_104_s_001 s)
{
	char buf[131072];
	
	s.buf[0] = 1;
	buf[0] = 1;
}

void buffer_overflow_104_func_001 (buffer_overflow_104_s_001 s)
{
	char buf[131072]; /* ERROR: Buffer overflow  */
	
	buf[0] = 1;
	buffer_overflow_104_func_002(s);
}

void buffer_overflow_104 ()
{
	buffer_overflow_104_s_001 s;
	buffer_overflow_104_func_001(s);
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Stack overflow due to recursive function call
 *
 ***********************************************************************/
typedef struct {
	char buf[262144];

} buffer_overflow_105_s_001;

void buffer_overflow_105_func_001 (buffer_overflow_105_s_001 s, int cnt)
{
	if (cnt > 0)
	{
		buffer_overflow_105_func_001(s, cnt - 1);
	}
	else
	{
		s.buf[0] = 1; /* ERROR: Buffer overflow  */
	}
}

void buffer_overflow_105 ()
{
	char buf[4096];

	buffer_overflow_105_s_001 s;
	buffer_overflow_105_func_001(s, 10);
	buf[0] = 1;
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Stack overflow due to large internal variables, function pointer
 *
 ***********************************************************************/
typedef struct {
	char buf[524288];
	char buf1[131072];
	char buf2[131072];
	char buf3[1024];
	char buf4[1024];

} buffer_overflow_106_s_001;

void buffer_overflow_106_func_001 (buffer_overflow_106_s_001 s)
{
	char buf[524288];
	buf[1] = 10;
	s.buf[0] = 1; /* ERROR: Buffer overflow  */
}

void buffer_overflow_106 ()
{
	buffer_overflow_106_s_001 s;
	void (*func)(buffer_overflow_106_s_001);
	func = buffer_overflow_106_func_001;
	func(s);
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Stack overflow due to large internal variables, function pointer
 *
 ***********************************************************************/
typedef struct {
	char buf[524288];	
	char buf1[131072];  
	char buf2[131072]; 
	char buf3[1024];
	char buf4[1024];
} buffer_overflow_107_s_001;

void buffer_overflow_107_func_002 (buffer_overflow_107_s_001 s)
{
	char buf[262144];
	buf[0] = 1;
	s.buf[0] = 1; /* ERROR: Buffer overflow  */
}

void buffer_overflow_107_func_001 (buffer_overflow_107_s_001 s)
{
	char buf[262144];	
	s.buf[0] = 1;
	buf[0] = 1;
	buffer_overflow_107_func_002(s);
}

void buffer_overflow_107 ()
{
	buffer_overflow_107_s_001 s;
	int flag = 10;
	
	if (flag)
	{
		buffer_overflow_107_func_001(s);
	}
	else
	{
		buffer_overflow_107_func_002(s);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Stack overflow due to infinite function call
 *
 ***********************************************************************/
static void buffer_overflow_108(void)
{
	buffer_overflow_108 ();
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of dynamically allocated array
 *
 ***********************************************************************/
void buffer_overflow_201 (int flag)
{
	char   *cbuf = (char*) calloc(5,sizeof(char));
	short  *sbuf = (short*) calloc(5,sizeof(short));
	int    *ibuf = (int*) calloc(5,sizeof(int));
	long   *lbuf = (long*) calloc(5,sizeof(long));
	float  *fbuf = (float*) calloc(5,sizeof(float));
	double *dbuf = (double*) calloc(5,sizeof(double));
	
	if (cbuf != NULL && sbuf != NULL && ibuf != NULL && lbuf != NULL && fbuf != NULL && dbuf != NULL)
	{
		switch (flag)
		{
			case 1: *(cbuf + 5) = 1; /* ERROR: Buffer overflow  */
				break;
			case 2: *(sbuf + 5) = 1; /* ERROR: Buffer overflow  */
				break;
			case 3: *(ibuf + 5) = 1; /* ERROR: Buffer overflow  */
				break;
			case 4: *(lbuf + 5) = 1; /* ERROR: Buffer overflow  */
				break;
			case 5: *(fbuf + 5) = 1; /* ERROR: Buffer overflow  */
				break;
			case 6: *(dbuf + 5) = 1; /* ERROR: Buffer overflow  */
				break;
			default:
				break;
		}
		free(cbuf);
		free(sbuf);
		free(ibuf);
		free(lbuf);
		free(fbuf);
		free(dbuf);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Read beyond bounds of dynamically allocated array
 *
 ***********************************************************************/
void buffer_overflow_202 (int flag)
{
	char   cret, *cbuf = (char*) calloc(5,sizeof(char));
	short  sret, *sbuf = (short*) calloc(5,sizeof(short));
	int    iret, *ibuf = (int*) calloc(5,sizeof(int));
	long   lret, *lbuf = (long*) calloc(5,sizeof(long));
	float  fret, *fbuf = (float*) calloc(5,sizeof(float));
	double dret, *dbuf = (double*) calloc(5,sizeof(double));
	
	if (cbuf != NULL && sbuf != NULL && ibuf != NULL && lbuf != NULL && fbuf != NULL && dbuf != NULL)
	{
		switch(flag)
		{
			case 1: cret = cbuf[5];     /* ERROR: Buffer overflow  */
				break;
			case 2: sret = sbuf[5];     /* ERROR: Buffer overflow  */
				break;
			case 3: iret = ibuf[5];     /* ERROR: Buffer overflow  */
				break;
			case 4: lret = lbuf[5];     /* ERROR: Buffer overflow  */
				break;
			case 5: fret = fbuf[5];     /* ERROR: Buffer overflow  */
				break;
			case 6: dret = dbuf[5];     /* ERROR: Buffer overflow  */
				break;
			default:
				break;
		}
		free(cbuf);
		free(sbuf);
		free(ibuf);
		free(lbuf);
		free(fbuf);
		free(dbuf);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of dynamically allocated structure 
 *
 ***********************************************************************/
typedef struct
{
	char arr[10];
	int arri[10];
}buffer_overflow_s_005;

void buffer_overflow_203()
{
	buffer_overflow_s_005* ptr_s= malloc(10*sizeof(buffer_overflow_s_005));
	int i;
	
	if(ptr_s!=NULL)
	{
		for(i=0;i<=10;i++)
	    	{
	    		ptr_s[i].arr[i]='a'; /* ERROR: Buffer overflow */
	    	}
	    	free(ptr_s);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of 2D dynamically allocated array
 *
 ***********************************************************************/
void buffer_overflow_204 ()
{
	int **buf = (int**) calloc(5,sizeof(int*));
	int i,j;

	for (i=0;i<5;i++)
	{
		buf[i]=(int*) calloc(5,sizeof(int));
	}
	
	for (i=0;i<5;i++)
	{
		for (j=0;j<=5;j++)
		{
			*(*(buf+i)+j)=i; /* ERROR: Buffer overflow  */
		}
		free(buf[i]);
	}
	free(buf);
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of 2D array, spine non dynamically allocated
 *
 ***********************************************************************/
void buffer_overflow_205 ()
{
	int *buf1 = (int*)calloc(5,sizeof(int));
	int *buf2 = (int*)calloc(5,sizeof(int));
	int *buf3 = (int*)calloc(5,sizeof(int));
	int *buf4 = (int*)calloc(5,sizeof(int));
	int *buf5 = (int*)calloc(5,sizeof(int));
	int **pbuf[5] = {&buf1, &buf2, &buf3, &buf4, &buf5};
	int i, j = 6;

	for (i = 0; i < 5;i++)
	{
		*((*pbuf[i]) + j) = 5; /* ERROR: Buffer overflow  */
	}
	free(buf1);
	free(buf2);
	free(buf3);
	free(buf4);
	free(buf5);
}

/***********************************************************************
 *
 * Types of defects: heap overrun(Types of defects: buffer overflow (Dynamic buffer))
 * Complexity: overrun when calling library function 'memset'
 * http://www.gimpel.com/html/bugs/bug669.htm
 * 
 ***********************************************************************/
void buffer_overflow_206 ()
{
	enum {LEN = 20};
	char *bouq;
	
	bouq = malloc(LEN + 1);
	if (NULL != bouq)
	{
		(void)memset(bouq, LEN, '*'); /* ERROR: Buffer overflow *//* argument 2, 3 swapped */
		bouq[LEN] = 0;
		printf( "\t\tThe bouquet: %s\n", bouq );
		free(bouq);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of dynamically allocated 2D array 
 *
 ***********************************************************************/
void buffer_overflow_207()
{
	int i,j;
	char ** doubleptr=(char**) malloc(10*sizeof(char*));

	for(i=0;i<10;i++)
	{
		doubleptr[i]=(char*) malloc(10*sizeof(char));
	}


	for(i=0;i<10;i++)
	{
		for(j=0;j<=10;j++)
		{
			doubleptr[i][j]='a'; /* ERROR: Buffer overflow */
		}
		free(doubleptr[i]);
	}
	free(doubleptr);
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of dynamically allocated array inside while loop 
 *
 ***********************************************************************/
void buffer_overflow_208 ()
{
	int i=1;
	
	while (i)
	{
		char* buf= (char*) malloc(sizeof(char));
		if (buf!=NULL)
		{
			buf[i+1]='a'; /* ERROR: Buffer overflow */
			free(buf);
		}
		i--;
	}
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of array allocated differently
 *
 ***********************************************************************/
void buffer_overflow_209 ()
{
	int *buf1=(int*) calloc(5,sizeof(int));
	int *buf2=(int*) calloc(3,sizeof(int));
	int i;
	
	for(i=0;i<5;i++)
	{
		*(buf1+i)=i;
	}
    	*(buf2+*(buf1+5))=1; /* ERROR: Buffer overflow */
	free(buf1);
	free(buf2);
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of dynamically allocated array of structures
 *
 ***********************************************************************/
typedef struct {
	int a;
	int b;
	int c;
} buffer_overflow_210_s_001;

void buffer_overflow_210 ()
{
	buffer_overflow_210_s_001* sbuf= calloc(5,sizeof(buffer_overflow_210_s_001)) ;
	
	if (sbuf!=NULL)
	{
		sbuf[5].a = 1; /* ERROR: Buffer overflow  */
	}
	free(sbuf);
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of array member of dynamically allocated structure
 *
 ***********************************************************************/
typedef struct {
	int a;
	int b;
	int buf[5];
} buffer_overflow_211_s_001;

void buffer_overflow_211 ()
{
	buffer_overflow_211_s_001* s=(buffer_overflow_211_s_001*) calloc(5,sizeof(buffer_overflow_211_s_001)) ;
	
	if (s != NULL)
	{
		(s + 5)->buf[4] = 1; /* ERROR: Buffer overflow  */
		free(s);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Variable index used as offset to pointer goes beyond array bounds
 *
 ***********************************************************************/
void buffer_overflow_212 ()
{
	double *buf=(double*) calloc(5,sizeof(double));
	int index = 5;
	
	if(buf != NULL)
	{
		*(buf + index) = 9.0;/*Tool should detect this line as error*/ /*ERROR:Buffer overrun*/
		free(buf);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Variable index out of bounds on long array
 *
 ***********************************************************************/
void  buffer_overflow_213()
{
	long *buf=(long*) calloc(5, sizeof(long));
	int index = 5;
	
	if(buf != NULL)
	{	
		buf[index] = 1; /* ERROR: Buffer overflow */
		free(buf);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of dynamically allocated array using result of linear equation
 *
 ***********************************************************************/
void buffer_overflow_214 ()
{
	int *buf = (int*) calloc(5,sizeof(int));
	int index = 2;
	
	if (buf!=NULL)
	{
		buf[(2 * index) + 1] = 1; /* ERROR: Buffer overflow  */	
		free(buf);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of dynamically allocated array using result of nonlinear equation
 *
 ***********************************************************************/
void buffer_overflow_215 ()
{
	int *buf = (int*) calloc(5,sizeof(int));
	int index = 2;

	if (buf!=NULL)
	{
		*(buf +((index * index) + 1)) = 1; /* ERROR: Buffer overflow  */
		free(buf);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of dynamically allocated array using return value of function call
 *
 ***********************************************************************/
int buffer_overflow_216_func_001 ()
{
	return 5;
}

void buffer_overflow_216 ()
{
	int *buf = (int*) calloc(5,sizeof(int));
	
	if (buf!=NULL)
	{
		*(buf + buffer_overflow_216_func_001 ()) = 1; /* ERROR: Buffer overflow  */
		free(buf);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of dynamically allocated array using function argument
 *
 ***********************************************************************/
void buffer_overflow_217 (int index)
{
	int *buf = (int*) calloc(5,sizeof(int));

	if (buf!=NULL)
	{
		*(buf +index) = 1; /* ERROR: Buffer overflow  */
		free(buf);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of dynamically allocated array using element of array
 *
 ***********************************************************************/
void buffer_overflow_218 ()
{
	int *buf = (int*) calloc(5,sizeof(int));
	int indexes[4] = {3, 4, 5, 6};
	int index = 2;

	if (buf!=NULL)
	{
		buf[indexes[index]] = 1;   /* ERROR: Buffer overflow  */
		free(buf);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of dynamically allocated array using alias to variable
 *
 ***********************************************************************/
void buffer_overflow_219 ()
{
	int *buf = (int*) calloc(5,sizeof(int));
	int index = 5;
	int index1;

	index1 = index;
	if (buf!=NULL)
	{
		buf[index1] = 1;     /* ERROR: Buffer overflow  */
		free(buf);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of dynamically allocated array using double alias to variable
 *
 ***********************************************************************/
void buffer_overflow_220 ()
{
	int *buf = (int*) calloc(5,sizeof(int));
	int index = 5;
	int index1;
	int index2;

	index1 = index;
	index2 = index1;
	if (buf != NULL)
	{
		buf[index2] = 1;     /* ERROR: Buffer overflow  */
		free(buf);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of dynamically allocated array using double alias to pointer
 *
 ***********************************************************************/
void buffer_overflow_221 ()
{
	int *buf = (int*) calloc(5,sizeof(int));
	int *p1;
	int *p2;
	
	if (buf != NULL)
	{
		p1 = buf;
		p2 = p1;
		*(p2 + 5) = 1; /* ERROR: Buffer overflow  */
		free(buf);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of dynamically allocated array using alias to pointer
 *
 ***********************************************************************/
void buffer_overflow_222 ()
{
	int *buf = (int*) calloc(5,sizeof(int));
	int *p;
	
	if (buf!=NULL)
	{
		p = buf;
		*(p + 5) = 1; /* ERROR: Buffer overflow  */
		free(buf);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of dynamically allocated array inside for loop
 *
 ***********************************************************************/
void buffer_overflow_223 ()
{
	int *buf = (int*) calloc(5,sizeof(int));
	int i;
	
	if (buf!=NULL)
	{
		for (i = 0; i <= 5; i ++)
		{
				buf[i] = 1; /* ERROR: Buffer overflow */
		}
		free(buf);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of dynammically allocated array when passing pointer to array as argument to function
 *
 ***********************************************************************/
void buffer_overflow_224_func_001 (int *buf)
{
	buf[5] = 1; /* ERROR: Buffer overflow */
}

void buffer_overflow_224 ()
{
	int *buf = (int*) calloc(5,sizeof(int));

	if (buf!=NULL)
	{
		buffer_overflow_224_func_001(buf);
		free(buf);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of dynamically allocated character array
 ***********************************************************************/
void buffer_overflow_225 ()
{
	char *buf=(char*) calloc(5,sizeof(char));
	int i;
	
	if(buf!=NULL)
	{
		for(i = 0;i <= 5;i++)
		{
			buf[i]='1'; /* ERROR: Buffer overflow */
		}
	    	free(buf);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of dynamically allocated array when casting a pointer from smaller to larger data type
 *
 ***********************************************************************/
void buffer_overflow_226 ()
{
	char *buf = (char*) calloc(5,sizeof(char));
	int *p;

	p = (int*)buf;
	if (buf!=NULL)
	{
		*(p + 5) = 1; /* ERROR: Buffer overflow */
		free(buf);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Complexity: Write beyond bounds of array when casting a pointer from larger to smaller data type
 *
 ***********************************************************************/
void buffer_overflow_227 ()
{
	int *buf = (int*) calloc(5,sizeof(int));
	char *p;
	
	p = (char*)buf;
	if (buf!=NULL)
	{
		*(p + 30) = 1; /* ERROR: Buffer overflow */
		free(buf);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer overflow
 * Main 
 *
 ***********************************************************************/
extern volatile int vflag;

void buffer_overflow_main ()
{
	if (vflag == 1 || vflag == 888)
	{
		buffer_overflow_001 (3);
	}

	if (vflag == 2 || vflag == 888)
	{
		buffer_overflow_002 (3);
	}

	if (vflag == 3 || vflag == 888)
	{
		buffer_overflow_003 (3);
	}

	if (vflag == 4 || vflag == 888)
	{
		buffer_overflow_004 (3);
	}
	
	if (vflag == 5 || vflag == 888)
	{
		buffer_overflow_005 ();
	}

	if (vflag == 6 || vflag == 888)
	{
		buffer_overflow_006 ();
	}

	if (vflag == 7 || vflag == 888)
	{
		buffer_overflow_007 ();
	}

	if (vflag == 8 || vflag == 888)
	{
		buffer_overflow_008 ();
	}

	if (vflag == 9 || vflag == 888)
	{
		buffer_overflow_009 ();
	}

	if (vflag == 10 || vflag == 888)
	{
		buffer_overflow_010 ();
	}

	if (vflag == 11 || vflag == 888)
	{
		buffer_overflow_011 ();
	}

	if (vflag == 12 || vflag == 888)
	{
		buffer_overflow_012 (5);
	}

	if (vflag == 13 || vflag == 888)
	{
		buffer_overflow_013 ();
	}

	if (vflag == 14 || vflag == 888)
	{
		buffer_overflow_014 ();
	}

	if (vflag == 15 || vflag == 888)
	{
		buffer_overflow_015 ();
	}

	if (vflag == 16 || vflag == 888)
	{
		buffer_overflow_016 ();
	}

	if (vflag == 17 || vflag == 888)
	{
		buffer_overflow_017 ();
	}

	if (vflag == 18 || vflag == 888)
	{
		buffer_overflow_018 ();
	}

	if (vflag == 19 || vflag == 888)
	{
		buffer_overflow_019 ();
	}

	if (vflag == 20 || vflag == 888)
	{
		buffer_overflow_020 ();
	}

	if (vflag == 21 || vflag == 888)
	{
		buffer_overflow_021 ();
	}

	if (vflag == 22 || vflag == 888)
	{
		buffer_overflow_022 ();
	}

	if (vflag == 23 || vflag == 888)
	{
		buffer_overflow_023 ();
	}

	if (vflag == 24 || vflag == 888)
	{
		buffer_overflow_024 ();
	}

	if (vflag == 25 || vflag == 888)
	{
		buffer_overflow_025 ();
	}

	if (vflag == 26 || vflag == 888)
	{
		buffer_overflow_026 ();
	}

	if (vflag == 27 || vflag == 888)
	{
		buffer_overflow_027 ();
	}

	if (vflag == 28 || vflag == 888)
	{
		buffer_overflow_028 ();
	}

	if (vflag == 29 || vflag == 888)
	{
		buffer_overflow_029 ();
	}

	if (vflag == 30 || vflag == 888)
	{
		buffer_overflow_030 ();
	}
	
	if (vflag == 31 || vflag == 888)
	{
		buffer_overflow_031 (3);
	}
	
	if (vflag == 32 || vflag == 888)
	{
		buffer_overflow_032 (3);
	}
	
	if (vflag == 33 || vflag == 888)
	{
		buffer_overflow_033 ();
	}
	
	if (vflag == 34 || vflag == 888)
	{
		buffer_overflow_034 ();
	}
	
	if (vflag == 35 || vflag == 888)
	{
		buffer_overflow_035 ();
	}
	
	if (vflag == 36 || vflag == 888)
	{
		buffer_overflow_036 ();
	}
	
	if (vflag == 37 || vflag == 888)
	{
		buffer_overflow_037 ();
	}
	
	if (vflag == 38 || vflag == 888)
	{
		buffer_overflow_038 (5);
	}
	
	if (vflag == 39 || vflag == 888)
	{
		buffer_overflow_039 ();
	}
	
	if (vflag == 40 || vflag == 888)
	{
		buffer_overflow_040 ();
	}
	
	if (vflag == 41 || vflag == 888)
	{
		buffer_overflow_041 ();
	}
	
	if (vflag == 42 || vflag == 888)
	{
		buffer_overflow_042 ();
	}
	
	if (vflag == 43 || vflag == 888)
	{
		buffer_overflow_043 ();
	}
	
	if (vflag == 44 || vflag == 888)
	{
		buffer_overflow_044 ();
	}
	
	if (vflag == 45 || vflag == 888)
	{
		buffer_overflow_045 ();
	}
	
	if (vflag == 46 || vflag == 888)
	{
		buffer_overflow_046 ();
	}
	
	if (vflag == 47 || vflag == 888)
	{
		buffer_overflow_047 ();
	}
	
	if (vflag == 48 || vflag == 888)
	{
		buffer_overflow_048 ();
	}
	
	if (vflag == 49 || vflag == 888)
	{
		buffer_overflow_049 ();
	}
	
	if (vflag == 50 || vflag == 888)
	{
		buffer_overflow_050 ();
	}
	
	if (vflag == 101 || vflag == 888)
	{
		buffer_overflow_101 ();
	}
	
	if (vflag == 102 || vflag == 888)
	{
		buffer_overflow_102 ();
	}
	
	if (vflag == 103 || vflag == 888)
	{
		buffer_overflow_103 ();
	}
	
	if (vflag == 104 || vflag == 888)
	{
		buffer_overflow_104 ();
	}
	
	if (vflag == 105 || vflag == 888)
	{
		buffer_overflow_105 ();
	}
	
	if (vflag == 106 || vflag == 888)
	{
		buffer_overflow_106 ();
	}
	
	if (vflag == 107 || vflag == 888)
	{
		buffer_overflow_107 ();
	}
	
	if (vflag == 108 || vflag == 888)
	{
		buffer_overflow_108 ();
	}
	
	if (vflag == 201 || vflag == 888)
	{
		buffer_overflow_201 (1);
	}

	if (vflag == 202 || vflag == 888)
	{
		buffer_overflow_202 (2);
	}

	if (vflag == 203 || vflag == 888)
	{
		buffer_overflow_203 ();
	}

	if (vflag == 204 || vflag == 888)
	{
		buffer_overflow_204 ();
	}

	if (vflag == 205 || vflag == 888)
	{
		buffer_overflow_205 ();
	}

	if (vflag == 206 || vflag == 888)
	{
		buffer_overflow_206 ();
	}

	if (vflag == 207 || vflag == 888)
	{
		buffer_overflow_207 ();
	}

	if (vflag == 208 || vflag == 888)
	{
		buffer_overflow_208 ();
	}

	if (vflag == 209 || vflag == 888)
	{
		buffer_overflow_209 ();
	}

	if (vflag == 210 || vflag == 888)
	{
		buffer_overflow_210 ();
	}

	if (vflag == 211 || vflag == 888)
	{
		buffer_overflow_211 ();
	}

	if (vflag == 212 || vflag == 888)
	{
		buffer_overflow_212 ();
	}

	if (vflag == 213 || vflag == 888)
	{
		buffer_overflow_213 ();
	}

	if (vflag == 214 || vflag == 888)
	{
		buffer_overflow_214 ();
	}

	if (vflag == 215 || vflag == 888)
	{
		buffer_overflow_215 ();
	}

	if (vflag == 216 || vflag == 888)
	{
		buffer_overflow_216 ();
	}

	if (vflag == 217 || vflag == 888)
	{
		buffer_overflow_217 (5);
	}

	if (vflag == 218 || vflag == 888)
	{
		buffer_overflow_218 ();
	}

	if (vflag == 219 || vflag == 888)
	{
		buffer_overflow_219 ();
	}

	if (vflag == 220 || vflag == 888)
	{
		buffer_overflow_220 ();
	}

	if (vflag == 221 || vflag == 888)
	{
		buffer_overflow_221 ();
	}

	if (vflag == 222 || vflag == 888)
	{
		buffer_overflow_222 ();
	}

	if (vflag == 223 || vflag == 888)
	{
		buffer_overflow_223 ();
	}

	if (vflag == 224 || vflag == 888)
	{
		buffer_overflow_224 ();
	}

	if (vflag == 225 || vflag == 888)
	{
		buffer_overflow_225 ();
	}

	if (vflag == 226 || vflag == 888)
	{
		buffer_overflow_226 ();
	}

	if (vflag == 227 || vflag == 888)
	{
		buffer_overflow_227 ();
	}
}
