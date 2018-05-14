/*
 * HeaderFile.h
 *
 */

#ifndef HEADERFILE_H_
#define HEADERFILE_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//#include <pthread.h>
#include <ctype.h>
//#include <unistd.h>
#include <limits.h>
#include <assert.h>

extern int idx, sink;
extern double dsink;
extern void *psink;
extern float divisor_zero;
extern int devidend_zero_division;
extern int length;
void assertion_violation_main (void);
void bit_shift_main (void);
void buffer_overflow_main (void);
void buffer_underflow_main (void);
void conflicting_cond_main (void);
void data_overflow_main (void);
void data_underflow_main (void);
void dead_code_main (void);
void double_free_main (void);
void endless_loop_main (void);
void free_nondynamic_allocated_memory_main (void);
void func_pointer_main (void);
void function_return_value_unchecked_main (void);
void improper_conv_mismatch_main (void);
void improper_null_termination_main (void);
void improper_ptr_operation_main (void);
void improper_termination_of_block_main (void);
void invalid_float_operation_main (void);
void invalid_memory_access_main (void);
void littlemem_st_main (void);
void memory_leak_main (void);
void not_return_main (void);
void null_pointer_main (void);
void ow_memcpy_main (void);
void return_local_main (void);
void uninit_memory_access_main (void);
void uninit_pointer_main (void);
void uninit_var_main (void);
void unreachable_code_main (void);
void zero_division_main (void);
/*
# define PRINT_DEBUG 0
*/
typedef int intptr_t;

#endif /* HEADERFILE_H_ */
