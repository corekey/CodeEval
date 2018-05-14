/***********************************************************************
 *
 * Defect Classification
 * ---------------------
 * Description: Defect code used to identify invalid operations on floats
 *
 ***********************************************************************/

#include "HeaderFile.h"

/***********************************************************************
 *
 * Defect type: Invalid operation on float 
 * Complexity: Test of equality between floating point variable and constant 
 *
 ***********************************************************************/
void invalid_float_operation_001()
{
	float flt = 1.0, ret;
	
	if (flt == 1.1) /* ERROR: Invalid floating point operation */
	{
		ret = flt;
	}
}

/***********************************************************************
 *
 * Defect type: Invalid operation on float 
 * Complexity: Test of equality between two floating point variables 
 *
 ***********************************************************************/
float floatcom = 3.3;

void invalid_float_operation_002()
{
	float flt, ret;
	
	flt = floatcom;
	if (flt == floatcom) /* ERROR: Invalid floating point operation */
	{
	    	ret = flt;
	}
	else
	{
		ret = floatcom;
	}
}

/***********************************************************************
 *
 * Defect type: Invalid operation on float 
 * Complexity: Test of inequality between two floating point variables  
 *
 ***********************************************************************/
void invalid_float_operation_003()
{
	float flt, ret;
	
	flt = floatcom;
	if (flt != (0.0F)) /* ERROR: Invalid floating point operation */
	{
	    	ret = flt;
	}
	else
	{
		ret = flt + 0.5;
	}
}

/***********************************************************************
 *
 * Defect type: Invalid operation on float 
 * Complexity: Test of inequality between floating point variable and constant 
 *
 ***********************************************************************/
void invalid_float_operation_004()
{
    	float f;
    	
	for (f = 1.0; f != 2.0; f = f + 0.1) /* ERROR: Invalid floating point operation */
    	{    
		(void) printf("Value: %f\n", f);
	}
}	

/***********************************************************************
 *
 * Defect type: Invalid operation on float 
 * Complexity: Modular arithmetic on floating point number 
 *
 ***********************************************************************/
void invalid_float_operation_005()
{
    	float f = 6.0, res;
	
	/* Compilation will fail unless the line below is commented out */
	//res = f % 3; /* ERROR: Invalid floating point operation */
}

/***********************************************************************
 *
 * Defect type: Invalid operation on float 
 * Main 
 *
 ***********************************************************************/
extern volatile int vflag;

void invalid_float_operation_main()
{
	if (vflag == 1 || vflag == 888)
	{
		invalid_float_operation_001();
	}

	if (vflag == 2 || vflag == 888)
	{
		invalid_float_operation_002();
	}

	if (vflag == 3 || vflag == 888)
	{
		invalid_float_operation_003();
	}

	if (vflag == 4 || vflag == 888)
	{
		invalid_float_operation_004();
	}
	
	if (vflag == 5 || vflag == 888)
	{
		invalid_float_operation_005();
	}
}
