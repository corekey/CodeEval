/***********************************************************************
 *
 * Defect Classification
 * ---------------------
 * Description: Defect code used to identify improper NULL termination
 *
 ***********************************************************************/

#include "HeaderFile.h"

/***********************************************************************
 *
 * Defect type: Improper NULL termination 
 * Complexity: Use of strcat function on character array with no terminating character 
 *
 ***********************************************************************/
void improper_null_termination_001 ()
{
	char src[] = "Source string";
	char dest[11] = {'d','e','s','t','i','n','a','t','i','o','n'};
	
	strcat(dest, src); /* ERROR: Improper NULL termination */
}

/***********************************************************************
 *
 * Defect type: Improper NULL termination 
 * Complexity: Use of strcpy function on character array with no terminating character 
 *
 ***********************************************************************/
char *cvt(const char *s)
{
	static char buf[12];  // 8x3 largest file name
	char *p;

	strcpy( buf, s ); /* ERROR: Improper NULL termination */
	while((p = strstr( buf, "shower" )))
		/* strstr() can scan out-of-bounds memory while searching, since
		 * no terminating null. it will do this on the 2nd pass through the loop.
		 */
	{
		strncpy( p, "fl", 2 );
	}
}

void improper_null_termination_002()
{
	printf( "%s\n", cvt( " showers.txt" ) );
}

/***********************************************************************
 *
 * Defect type: Improper NULL termination 
 * Complexity: Use of strlen function on character array with no terminating character 
 *
 ***********************************************************************/
void improper_null_termination_003()
{
	char a[10] = {'b','a','d','_','s','t','r','i','n','g'};
	
	strlen(a); /* ERROR: Improper NULL termination */
}

/***********************************************************************
 *
 * Defect type: Improper NULL termination 
 * Main 
 *
 ***********************************************************************/
extern volatile int vflag;

void improper_null_termination_main ()
{
	if (vflag == 1 || vflag == 888)
	{
		improper_null_termination_001();
	}

	if (vflag == 2 || vflag == 888)
	{
		improper_null_termination_002();
	}

	if (vflag == 3 || vflag == 888)
	{
		improper_null_termination_003();
	}
}
