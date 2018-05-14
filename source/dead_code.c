/***********************************************************************
 *
 * Defect Classification
 * ---------------------
 * Description: Defect code used to identify dead code
 *
 ***********************************************************************/

#include "HeaderFile.h"

/***********************************************************************
 *
 * Defect type: Dead code
 * Complexity: Value of expression not assigned to variable
 *
 ***********************************************************************/
void dead_code_001()
{
	int a = 0, b = 3;
	
	(a + b) * b - a; /* ERROR: Dead code */
}

/***********************************************************************
 *
 * Defect type: Dead code
 * Complexity: Variable assigned but never used
 *
 ***********************************************************************/
int dead_code_002()
{
	int a = 2, b = 3, c;
	
	c = (a + b) * b - a * b; /* ERROR: Dead code */
	return a * b;
}

/***********************************************************************
 *
 * Defect type: Dead code
 * Complexity: Structure member assigned but never used
 *
 ***********************************************************************/
typedef struct {
	int a;
	int b;
	int unuse;
} dead_code_structure;

void dead_code_003()
{
	dead_code_structure s;
	s.a = 1;
	s.b = 2;
	s.unuse = s.a + s.b; /* ERROR: Dead code */
}

/***********************************************************************
 *
 * Defect type: Dead code
 * Complexity: Union member assigned but never used
 *
 ***********************************************************************/
typedef union {
	dead_code_structure s1;
	dead_code_structure s2;
	int s3;
} dead_code_union;

void dead_code_004()
{
	dead_code_union u;
	u.s1.a = 1;
	u.s1.b = 2;
	u.s3 = u.s1.a; /* ERROR: Dead code */
}

/***********************************************************************
 *
 * Defect type: Dead code
 * Complexity: Global variable assigned but never used
 *
 ***********************************************************************/
int dead_code_005_glb_a = 1;
int dead_code_005_glb_b = 2;
int dead_code_005_glb_unuse;

void dead_code_005()
{
	dead_code_005_glb_unuse = dead_code_005_glb_a + dead_code_005_glb_b; /* ERROR: Dead code */
}

/***********************************************************************
 *
 * Defect type: Dead code
 * Complexity: Static global variable assigned but never used
 *
 ***********************************************************************/
static int dead_code_006_glb_a = 1;
static int dead_code_006_glb_b = 2;
static int dead_code_006_glb_unuse;

void dead_code_006()
{
	dead_code_006_glb_unuse = dead_code_006_glb_a + dead_code_006_glb_b; /* ERROR: Dead code */
}

/***********************************************************************
 *
 * Defect type: Dead code
 * Complexity: Static variable with function scope assigned but never used
 *
 ***********************************************************************/
void dead_code_007()
{
	static int a = 1;
	static int b = 2;
	static int unuse;

	if(a==1)
	{
	    unuse = a + b; /* ERROR: Dead code */
	}
}

/***********************************************************************
 *
 * Defect type: Dead code
 * Complexity: Global union member assigned but never used
 *
 ***********************************************************************/
dead_code_union dead_code_008_uni_gbl;

void dead_code_008()
{
	dead_code_008_uni_gbl.s1.a = 1;
	dead_code_008_uni_gbl.s1.b = 2;
	dead_code_008_uni_gbl.s3 = dead_code_008_uni_gbl.s1.a + dead_code_008_uni_gbl.s1.b; /* ERROR: Dead code */
}

/***********************************************************************
 *
 * Defect type: Dead code
 * Complexity: Variable declared but never assigned or used
 *
 ***********************************************************************/
int dead_code_009()
{
	int a; /* ERROR: Dead code */
	int b = 5;
	int c = 10;

	return b + c;
}

/***********************************************************************
 *
 * Defect type: Dead code
 * Complexity: Uselss assignment, variable overwritten before use
 *
 ***********************************************************************/
void dead_code_010()
{
	int a = 0, b, c;
	
	b = rand();
	c = a + b; /* ERROR: Dead code */
	c = a - b;
}

/***********************************************************************
 *
 * Defect type: Dead code
 * Complexity: Useless function call
 *
 ***********************************************************************/
 
 /* SEE CALL TO FUNCTION dead_code_001 () in main */
 /* NOTICE THAT THE RETURN VALUE OF dead_code_009 () IS NEVER ASSIGNED TO A VARIABLE in main */

/***********************************************************************
 *
 * Defect type: Dead code
 * Main 
 *
 ***********************************************************************/
extern volatile int vflag;

void dead_code_main()
{
    	int ret;
	
	if (vflag == 1 || vflag == 888)
	{
		dead_code_001(); /*ERROR: Dead code */
	}
	
	if (vflag == 2 || vflag == 888)
	{
		ret = dead_code_002();
	}
	
	if (vflag == 3 || vflag == 888)
	{
		dead_code_003();
	}
	
	if (vflag == 4 || vflag == 888)
	{
		dead_code_004();
	}
	
	if (vflag == 5 || vflag == 888)
	{
		dead_code_005();
	}
	
	if (vflag == 6 || vflag == 888)
	{
		dead_code_006();
	}
	
	if (vflag == 7 || vflag == 888)
	{
		dead_code_007();
	}
	
	if (vflag == 8 || vflag == 888)
	{
		dead_code_008();
	}
	
	if (vflag == 9 || vflag == 888)
	{
		dead_code_009(); /*ERROR: Dead code  */
	}
	
	if (vflag == 10 || vflag == 888)
	{
		dead_code_010(); /*ERROR: Dead code  */
	}
}
