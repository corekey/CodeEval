/***********************************************************************
 *
 * Defect Classification
 * ---------------------
 * Description: Defect code used to identify improper pointer operations 
 *
 ***********************************************************************/

#include "HeaderFile.h"

/***********************************************************************
 *
 * Defect type: Improper pointer operations  
 * Complexity: Subtraction of pointers representing two distinct arrays 
 *
 ***********************************************************************/
void improper_ptr_operation_001 ()
{
	char buf1[5];
	char buf2[5];
	intptr_t offset;
	
	offset = buf2 - buf1; /* ERROR: Incorrect pointer arithmetic */
	sink = offset;
}

/***********************************************************************
 *
 * Types of defects: an improper pointer arithmetic
 * Complexity: incorrect pointer scaling
 * 
 * In this example, buf is intended to point to the second byte of ptr.
 * But adding 1 to ptr actually adds sizeof(int) to ptr, giving a result that is incorrect (3 bytes off on 32-bit platforms).
 * If the resulting memory address is read, this could potentially be an information leak.
 * If it is a write, it could be a security-critical write to unauthorized memory-- whether or not it is a buffer overflow.
 * Note that the above code may also be wrong in other ways, particularly in a little endian environment.
 *
 ***********************************************************************/
void improper_ptr_operation_002 ()
{
	int x= 10;
	int *ptr = &x;
	char *buf;

	buf = (char *)(ptr+1); /* ERROR: Incorrect pointer arithmetic */
	psink = buf;
}

/***********************************************************************
 *
 * Defect type: Improper pointer operations
 * Main 
 *
 ***********************************************************************/
extern volatile int vflag;

void improper_ptr_operation_main ()
{
	if (vflag ==1 || vflag ==888)
	{
		improper_ptr_operation_001();
	}

	if (vflag ==2 || vflag ==888)
	{
		improper_ptr_operation_002();
	}
}
