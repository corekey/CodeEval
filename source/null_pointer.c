/***********************************************************************
 *
 * Defect Classification
 * ---------------------
 * Description: Defect code used to identify dereferencing of null pointers
 *
 ***********************************************************************/

#include "HeaderFile.h"

int rand (void);

/***********************************************************************
 *
 * Defect type: NULL pointer derefernce 
 * Complexity: Assignment of a constant to a NULL pointer 
 *
 ***********************************************************************/
void null_pointer_001 ()
{
	int *p = NULL;
	
	*p = 1; /* ERROR: NULL pointer dereference */
}

/***********************************************************************
 *
 * Defect type: NULL pointer derefernce 
 * Complexity: Assignment of NULL pointer dereference to variable 
 *
 ***********************************************************************/
void null_pointer_002 ()
{
	int *p = NULL;
	int ret;

	ret = *p; /* ERROR: NULL pointer dereference */
}

/***********************************************************************
 *
 * Defect type: NULL pointer derefernce
 * Complexity: Assignment of constant to a NULL double pointer 
 *
 ***********************************************************************/
void null_pointer_003 ()
{
	int **pp;
	int *p = NULL;

	pp = &p;
	**pp = 1; /* ERROR: NULL pointer dereference */
}

/***********************************************************************
 *
 * Defect type: NULL pointer derefernce
 * Complexity: Assignment of constant to a NULL structure pointer 
 *
 ***********************************************************************/
typedef struct {
	int a;
	int b;
	int c;
} null_pointer_structure;

void null_pointer_004 ()
{
	null_pointer_structure *p = NULL;
	
	p->a = 1; /* ERROR: NULL pointer dereference */
}

/***********************************************************************
 *
 * Defect type: NULL pointer derefernce
 * Complexity: Assignment of constant to a NULL union pointer 
 *
 ***********************************************************************/
typedef union {
	null_pointer_structure s1;
	null_pointer_structure s2;
	int s3;
} null_pointer_union;

void null_pointer_005 ()
{
	null_pointer_union *p = NULL;
	
	p->s1.a = 1; /* ERROR: NULL pointer dereference */
}

/***********************************************************************
 *
 * Defect type: NULL pointer derefernce
 * Complexity: Assignment of random variable to NULL pointer 
 *
 ***********************************************************************/
void null_pointer_006 ()
{
	int *p;
	
	p = (int *)(intptr_t)rand();
	*p = 1; /* ERROR: NULL pointer dereference */
}

/***********************************************************************
 *
 * Defect type: NULL pointer derefernce
 * Complexity: Assignment of random variable using linear equation to NULL pointer 
 *
 ***********************************************************************/
void null_pointer_007 ()
{
	int *p;
	int a = 3;
	
	p = (int *)(intptr_t)((2 * a) - 6);
	*p = 1; /* ERROR: NULL pointer dereference */
}

/***********************************************************************
 *
 * Defect type: NULL pointer derefernce
 * Complexity: Assignment of return value from function call to NULL pointer 
 *
 ***********************************************************************/
int* null_pointer_008_func_001 ()
{
	return NULL;
}

void null_pointer_008 ()
{
	int *p;

	p = null_pointer_008_func_001();
	*p = 1; /* ERROR: NULL pointer dereference */
}

/***********************************************************************
 *
 * Defect type: NULL pointer derefernce
 * Complexity: Write to NULL pointer passed as function argument 
 *
 ***********************************************************************/
void null_pointer_009_func_001 (int *p)
{
	*p = 1; /* ERROR: NULL pointer dereference */
}

void null_pointer_009 ()
{
	null_pointer_009_func_001(NULL);
}

/***********************************************************************
 *
 * Defect type: NULL pointer derefernce
 * Complexity: Write to alias of NULL pointer 
 *
 ***********************************************************************/
void null_pointer_010 ()
{
	int *p = NULL;
	int *p1;
	
	p1 = p;
	*p1 = 1; /* ERROR: NULL pointer dereference */
}

/***********************************************************************
 *
 * Defect type: NULL pointer derefernce
 * Complexity: Write to double alias of NULL pointer 
 *
 ***********************************************************************/
void null_pointer_011 ()
{
	int *p = NULL;
	int *p1;
	int *p2;
	
	p1 = p;
	p2 = p1;
	*p2 = 1; /* ERROR: NULL pointer dereference */
}

/***********************************************************************
 *
 * Defect type: NULL pointer derefernce
 * Complexity: Write to NULL address using array indexing  
 *
 ***********************************************************************/
void null_pointer_012 ()
{
	int *p = NULL;
	
	p[3] = 1; /* ERROR: NULL pointer dereference */
}

/***********************************************************************
 *
 * Defect type: NULL pointer derefernce
 * Complexity: Write to pointer assigned NULL in function call 
 *
 ***********************************************************************/
int *null_pointer_013_func_001 (void)
{
	return (NULL);
}

void null_pointer_013 ()
{
	int *p;
	
	p = null_pointer_013_func_001();
	if (p != NULL)
	{
		*p = 1;
	}
	*p = 2; /* ERROR: NULL pointer dereference */
}

/***********************************************************************
 *
 * Defect type: NULL pointer derefernce
 * Complexity: NULL pointer access after function call
 *
 ***********************************************************************/
int *null_pointer_014_func_001 (void)
{
	return (NULL);
}

void null_pointer_014 ()
{
	int *p;
	p = null_pointer_014_func_001();
	*p = 1; /* ERROR: NULL pointer dereference */
	if (p != NULL)
	{
		*p = 2;
	}
}

/***********************************************************************
 *
 * Defect type: NULL pointer derefernce
 * Complexity: Use of strcpy function to copy string to NULL location  
 *
 ***********************************************************************/
# define INDEX 'a'

static unsigned char a =INDEX;

char * null_pointer_015_gbl_ptr;

void null_pointer_015_func_001 (int len)
{
	null_pointer_015_gbl_ptr=NULL;
	if(a != INDEX)
	{
		null_pointer_015_gbl_ptr= malloc(sizeof(char) * (len+1));
	}
}

void null_pointer_015 ()
{
	char *str = "This is a string";
	null_pointer_015_func_001(strlen(str));
	strcpy(null_pointer_015_gbl_ptr,str); /* ERROR: NULL pointer dereference */
	free(null_pointer_015_gbl_ptr);
	null_pointer_015_gbl_ptr = NULL;
}

/***********************************************************************
 *
 * Defect type: NULL pointer derefernce
 * Complexity: When using a double pointer to long , memory allocated in another function inside goto label and if condition
 *
 ***********************************************************************/
long ** null_pointer_016_gbl_doubleptr;

void null_pointer_016_func_001()
{
	int i,j;
	null_pointer_016_gbl_doubleptr=(long**) malloc(10*sizeof(long*));

	for(i=0;i<10;i++)
	{
		null_pointer_016_gbl_doubleptr[i]=(long*) malloc(10*sizeof(long));
	}
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			null_pointer_016_gbl_doubleptr[i][j]=i;
		}
	}
}

void null_pointer_016()
{
	int flag=0,i,j;
	null_pointer_016_gbl_doubleptr=NULL;
	
	goto label;
    	
	if(flag == 0)
	{
		for(i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
			{
				null_pointer_016_gbl_doubleptr[i][j] += 1; /* ERROR: NULL pointer dereference */
			}
			free (null_pointer_016_gbl_doubleptr[i]);
			null_pointer_016_gbl_doubleptr[i] = NULL;
	   	}
	    	free(null_pointer_016_gbl_doubleptr);
	    	null_pointer_016_gbl_doubleptr = NULL;
	}

label:
    	if(flag != 0)
    	{
    		null_pointer_016_func_001();
    	}
}

/***********************************************************************
 *
 * Defect type: NULL pointer derefernce
 * Complexity: When using a double pointer a global char 
 *
 ***********************************************************************/
char **null_pointer_017dst = NULL;

void null_pointer_017_func_001(int flag)
{
	int i;
	
	while(flag)
	{
		null_pointer_017dst = (char**) malloc(5*sizeof(char*));
		for(i=0;i<5;i++)
		{
		    	null_pointer_017dst[i]=(char*) malloc(15*sizeof(char));
		}
		break;
	}
}

void null_pointer_017 ()
{
	int i;

    	null_pointer_017_func_001(0);

	for(i=0;i<5;i++)
    	{
    		strcpy (null_pointer_017dst[i],"STRING"); /* ERROR: NULL pointer dereference */
    	}
	
	while(1)
	{
		for(i=0;i<5;i++)
	    	{
			free(null_pointer_017dst[i]);
			null_pointer_017dst[i] = NULL;
	    	}
	    	
		free(null_pointer_017dst);
	    	null_pointer_017dst = NULL;
	    	break;
	}
}

/***********************************************************************
 *
 * Defect type: NULL pointer derefernce
 * Complexity: Use of global pointer in if statement 
 *
 ***********************************************************************/
int *ptr;

void null_pointer_018()
{
	if(NULL == ptr)
	{
		*ptr = 1; /* ERROR: NULL pointer dereference */
	}
}

/***********************************************************************
 *
 * Defect type: NULL pointer derefernce
 * Complexity:  use of a pointer with value 0 in argument
 * http://www.gimpel.com/html/newbugs/bug413.htm
 *
 ***********************************************************************/
int null_pointer_019_func_001( char *buf, char ch )
{
	static int total = 0;
	int n;
	char *p;
	if( buf )
	{
		n = total;
		total = 0;
		return n; /* ERROR: NULL pointer dereference */
	}
	
	for( p = buf; *p; p++ ) 
	{
		if( *p == ch )
		{
			total++;
		}
	}
	return 0;
}

void null_pointer_019()
{ 
	int ret;
	ret = null_pointer_019_func_001( 0, ' ');
}

/***********************************************************************
 *
 * Defect type: NULL pointer derefernce
 * Complexity:  use of null pointer in left argument to operator '->'
 * http://www.gimpel.com/html/newbugs/bug794.htm
 *
 ***********************************************************************/
struct Basket {
	int Value;
	struct Basket *NextBasket;
};

struct Basket *null_pointer_020_func_001(struct Basket *FirstBasketInList, struct Basket *NewBasket )
{
	struct Basket *BasketInList   = FirstBasketInList;
	struct Basket *PreviousBasket = NULL;

	while( BasketInList->Value <= NewBasket->Value ) /* ERROR: NULL pointer dereference */
	{
		PreviousBasket = BasketInList;
		BasketInList   = BasketInList->NextBasket;
	}
	PreviousBasket->NextBasket = NewBasket;
	NewBasket->NextBasket      = BasketInList;
	return FirstBasketInList;
}

void null_pointer_020()
{
	(void)null_pointer_020_func_001(NULL, NULL);
}

/***********************************************************************
 *
 * Defect type: NULL pointer derefernce
 * Complexity:  pass a null pointer to a library function - fgets
 * http://www.gimpel.com/html/bugs/bug418.htm
 *
 ***********************************************************************/
static int null_pointer_021_func_001( const char * filename )
{
	FILE *file = 0;
	enum { BUFLEN = 300};
	char buf[BUFLEN];
	int cnt = 0;

	fopen( filename, "r" );
	while( fgets( buf, BUFLEN, file ) ) /* ERROR: NULL pointer dereference */
	{
		cnt++;
	}
	fclose( file );
	return cnt;
}

void null_pointer_021(void)
{
	int ct = null_pointer_021_func_001( "Sally's presents" );
}

/***********************************************************************
 *
 * Defect type: NULL pointer derefernce
 * Complexity:  use of a pointer with NULL in argument
 * http://www.gimpel.com/html/bugs/bug613.htm
 *
 ***********************************************************************/
int null_pointer_022_func_001( char *buf, char letter )
{
	int n = 0;
	char *p;
	
	for( p = buf; *p; p++ )
	{
		if( *p == letter )
		{
			n++;
		}
	}
	return n;
}

void null_pointer_022(void)
{
	int number =2;
	char *buffer[2] = { NULL, NULL };
	char *p = buffer[1];
	(void) null_pointer_022_func_001( p, 'e' );
}

/***********************************************************************
 *
 * Defect type: NULL pointer derefernce
 * Main 
 *
 ***********************************************************************/
extern volatile int vflag;

void null_pointer_main ()
{
	if (vflag == 1 || vflag == 888)
	{
		null_pointer_001();
	}

	if (vflag == 2 || vflag == 888)
	{
		null_pointer_002();
	}

	if (vflag == 3 || vflag == 888)
	{
		null_pointer_003();
	}

	if (vflag == 4 || vflag == 888)
	{
		null_pointer_004();
	}

	if (vflag == 5 || vflag == 888)
	{
		null_pointer_005();
	}

	if (vflag == 6 || vflag == 888)
	{
		null_pointer_006();
	}

	if (vflag == 7 || vflag == 888)
	{
		null_pointer_007();
	}

	if (vflag == 8 || vflag == 888)
	{
		null_pointer_008();
	}

	if (vflag == 9 || vflag == 888)
	{
		null_pointer_009();
	}

	if (vflag == 10 || vflag == 888)
	{
		null_pointer_010();
	}

	if (vflag == 11 || vflag == 888)
	{
		null_pointer_011();
	}

	if (vflag == 12 || vflag == 888)
	{
		null_pointer_012();
	}

	if (vflag == 13 || vflag == 888)
	{
		null_pointer_013();
	}

	if (vflag == 14 || vflag == 888)
	{
		null_pointer_014();
	}

	if (vflag == 15 || vflag == 888)
	{
		null_pointer_015();
	}

	if (vflag == 16 || vflag == 888)
	{
		//null_pointer_016();
	}

	if (vflag == 17 || vflag == 888)
	{
		null_pointer_017();
	}
	
	if (vflag == 18 || vflag == 888)
	{
		null_pointer_018();
	}
	
	if (vflag == 19 || vflag == 888)
	{
		null_pointer_019();
	}
	
	if (vflag == 20 || vflag == 888)
	{
		null_pointer_020();
	}
	
	if (vflag == 21 || vflag == 888)
	{
		null_pointer_021();
	}
	
	if (vflag == 22 || vflag == 888)
	{
		null_pointer_022();
	}
}
