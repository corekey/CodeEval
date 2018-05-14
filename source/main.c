/*
 ============================================================================
 Description : Main section of Test Suite, Software Analysis - FY2013 (Ansi-style)
 ============================================================================
 */

#include "HeaderFile.h"

volatile int vflag;
volatile int vflag_copy;
volatile int vflag_file;

int idx, sink;
double dsink;
void *psink;
float divisor_zero;
int devidend_zero_division=1000;
int length;

int main(int argc,char*argv[])
{
	if(argv[1])
	{

		vflag_copy = atoi(argv[1]);
		vflag_file = (int)floor((double)vflag_copy/1000.0);
		vflag = (int)floor((int)vflag_copy%1000);
		printf("vflag_file = %d vflag_func = %d vflag_copy =%d \n" , vflag_file, vflag,vflag_copy);

	
		/* IMPROPER RESOURCE MANAGEMENT */
		
		if (vflag_file == 1 || vflag_file == 888)
		{
			buffer_overflow_main ();			/* Buffer overflow */
			/* _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ */ 
		}

		if (vflag_file == 2 || vflag_file == 888)
		{
			buffer_underflow_main();			/* Buffer underflow */
			/* _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ */ 
		}

		if (vflag_file == 3 || vflag_file == 888)
		{
			uninit_memory_access_main();			/* Uninitialized memory access */
			/* _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ */ 
		}

		if (vflag_file == 4 || vflag_file == 888)
		{
			memory_leak_main();				/* Memory leak */
			/* _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ */ 
		}

		if (vflag_file == 5 || vflag_file == 888)
		{
			invalid_memory_access_main();			/* Invalid memory access */
			/* _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ */ 
		}

		if (vflag_file == 6 || vflag_file == 888)
		{
			double_free_main ();				/* Double free*/
			/* _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ */ 
		}

		if(vflag_file== 7 || vflag_file == 888)
		{
			free_nondynamic_allocated_memory_main ();	/* Free non dynamic allocated memory */
			/* _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ */ 
		}

		if (vflag_file == 8 || vflag_file == 888)
		{
			return_local_main();				/* Return of local variables */
			/* _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ */ 
		}

		if (vflag_file == 9 || vflag_file == 888)
		{
			littlemem_st_main();				/* Allocate small size of memory for type struct/union (static) */
			/* _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ */ 
		}

		if (vflag_file == 10 || vflag_file == 888)
		{
			ow_memcpy_main();				/* Memory copy at overlapping areas */
			/* _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ */ 
		}

		/* ILLEGAL OPERATIONS */

		if (vflag_file == 11 || vflag_file == 888)
		{
			data_overflow_main();				/* Data overflow */
			/* _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ */ 
		}

		if (vflag_file == 12 || vflag_file == 888)
		{
			data_underflow_main();				/* Data underflow */
			/* _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ */ 
		}

		if (vflag_file == 13 || vflag_file == 888)
		{
			invalid_float_operation_main();			/* Invalid floating point operation */
			/* _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ */ 
		}

		if (vflag_file == 14 || vflag_file == 888)
		{
			zero_division_main();				/* Division by zero */
			/* _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ */ 
		}

		if (vflag_file == 15 || vflag_file == 888)
		{
			bit_shift_main();				/* Bit shift errors */
			/* _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ */ 
		}

		if (vflag_file == 16 || vflag_file == 888)
		{
			improper_conv_mismatch_main();			/* Improper data type conversion and data type mismatch */
			/* _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ */ 
		}

		if (vflag_file == 17 || vflag_file == 888)
		{
			assertion_violation_main();			/* Assertion violation*/
			/* _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ */ 
		}

		if (vflag_file == 18 || vflag_file == 888)
		{
			improper_null_termination_main();		/* Improper null termination*/
			/* _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ */ 
		}

		if (vflag_file == 19 || vflag_file == 888)
		{
			func_pointer_main();				/* Invalid function pointer casting */
			/* _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ */ 
		}

		if (vflag_file == 20 || vflag_file == 888)
		{
			null_pointer_main();				/* NULL pointer reference (access) */
			/* _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ */ 
		}

		if (vflag_file == 21 || vflag_file == 888)
		{
			improper_ptr_operation_main();			/* Improper pointer arithmetic */
			/* _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ */ 
		}

		if (vflag_file == 22 || vflag_file == 888)
		{
			uninit_pointer_main();				/* Uninitialized pointer */
			/* _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ */ 
		}

		/* INAPPROPRIATE CODE */

		if (vflag_file == 23 || vflag_file == 888)
		{
			uninit_var_main();				/* Uninitialized variable */
			/* _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ */ 
		}

		if (vflag_file == 24 || vflag_file == 888)
		{
			endless_loop_main();				/* Unintentional endless loop */
			/* _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ */ 
		}

		if (vflag_file == 25 || vflag_file == 888)
		{
			function_return_value_unchecked_main();		/* Return value of function never checked */
			/* _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ */ 
		}

		if(vflag_file == 26 || vflag_file == 888)
		{
			improper_termination_of_block_main ();		/* Improper termination of block */
			/* _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ */ 
		}

		if (vflag_file == 27 || vflag_file == 888)
		{
			unreachable_code_main();			/* Unreachable code elimination */
			/* _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ */ 
		}

		if (vflag_file == 28 || vflag_file == 888)
		{
			dead_code_main();				/* Dead code */
			/* _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ */ 
		}

		if (vflag_file == 29 || vflag_file == 888 )
		{
			conflicting_cond_main();			/* Conflicting condition */
			/* _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ */ 
		}

		if (vflag_file == 30 || vflag_file == 888)
		{
			not_return_main();				/* Non void function does not return value */
			/* _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ */ 
		}
		
		/* CONCURRENCY RELATED ISSUES */
		
		/* Dead lock
		if (vflag_file ==31 || vflag_file == 888)
		{
			dead_lock_main();
		}
	    */

		/* Double lock
		if (vflag_file ==32 || vflag_file == 888)
		{
			double_lock_main();
		}
	    */

		/* Double Release
		if (vflag_file ==33 || vflag_file == 888)
		{
			double_release_main();
		}
	    */

		/* Live Lock
		if (vflag_file ==34 || vflag_file == 888)
		{
			livelock_main();
		}
	    */

		/*Lock never unlock main main
		if (vflag_file ==35 || vflag_file == 888)
		{
			lock_never_unlock_main();
		}
	    */


		/* Race condition 
		if (vflag_file ==36 || vflag_file == 888)
		{
			race_condition_main ();
		}
	    */

		/* Sleep lock
		if (vflag_file ==37 || vflag_file == 888)
		{
			sleep_lock_main();
		}
	    */

		/*Unlock without lock main
		if (vflag_file ==38 || vflag_file == 888)
		{
			unlock_without_lock_main();
		}
	    */
		
			printf("Printed from main function ");
		}
	else
	{
		printf("Enter File XXX and Function XXX \n");
		printf("Example: To Execute 2nd File 3rd Function , Enter 002003 \n");
		printf("Example: To Execute All Files ,Enter 888888 \n");
		printf("Example: To Execute All functions in a File :Sample - To execute all functions in 3rd file,Enter 003888 \n");
	}
    	return 0;
}
