/***********************************************************************
 *
 * Defect Classification
 * ---------------------
 * Description: Defect code used to identify the assignment of a buffer to small for a structure
 *
 ***********************************************************************/

#include "HeaderFile.h"

/***********************************************************************
 *
 * Defect type: Assignment of a buffer too small for a strucutre member 
 * Complexity: Read of structure member that has been casted from an array too small for structure memory 
 *
 ***********************************************************************/
typedef struct {
	int a;
	int b;
	int c;
} littlemem_st_structure;

void littlemem_st_001 ()
{
	char buf[10];
	littlemem_st_structure *p;
	int ret, i;

	for (i = 0;i < 10;i ++)
	{
		buf[i] = 1;
	}

	p = (littlemem_st_structure *)buf;
	ret = p->c; /* ERROR: Little memory or overflow */
    	printf("%d \n",p->c);
}

/***********************************************************************
 *
 * Defect type: Assignment of a buffer too small for a strucutre member 
 * Complexity: Write to structure member that has been casted from an array too small for structure memory 
 *
 ***********************************************************************/
void littlemem_st_002 ()
{
	char buf[10];
	littlemem_st_structure *p;
	p = (littlemem_st_structure *)buf;
	p->c = 1; /* ERROR: Little memory or overflow */
}

/***********************************************************************
 *
 * Defect type: Assignment of a buffer too small for a strucutre member 
 * Complexity: Write to union member that has been casted from an array too small for structure memory 
 *
 ***********************************************************************/
typedef union {
	char a;
	short b;
	int c;
} littlemem_st_003_uni_001;

void littlemem_st_003 ()
{
	char buf[2];
	littlemem_st_003_uni_001 *p;
	p = (littlemem_st_003_uni_001 *)buf;
	p->c = 1; /* ERROR: Little memory or overflow */
}

/***********************************************************************
 *
 * Defect type: Assignment of a buffer too small for a strucutre member 
 * Complexity: Write to global structure member that has been casted from an array too small for structure memory 
 *
 ***********************************************************************/
littlemem_st_structure *littlemem_st_004_s_001_gbl_str;

void littlemem_st_004 ()
{
	char buf[10];

	littlemem_st_004_s_001_gbl_str = (littlemem_st_structure *)buf;
	littlemem_st_004_s_001_gbl_str->c = 1; /* ERROR: Little memory or overflow */
}

/***********************************************************************
 *
 * Defect type: Assignment of a buffer too small for a strucutre member 
 * Complexity: Write to global structure member that has been casted from an array too small for structure memory 
 *
 ***********************************************************************/
littlemem_st_structure *littlemem_st_005_s_001_gbl_str;

char littlemem_st_005_gbl_buf[10];

void littlemem_st_005_func_001 ()
{
	littlemem_st_005_s_001_gbl_str = (littlemem_st_structure *)littlemem_st_005_gbl_buf;
}

void littlemem_st_005 ()
{
	littlemem_st_005_func_001();
	littlemem_st_005_s_001_gbl_str->c = 1; /* ERROR: Little memory or overflow */
}

/***********************************************************************
 *
 * Defect type: Assignment of a buffer too small for a strucutre member 
 * Complexity: Write to global structure member that has been casted from an array too small for structure memory 
 *
 ***********************************************************************/
littlemem_st_structure *littlemem_st_006_s_001_gbl_str;

#define MAX_STR 10

char littlemem_st_006_gbl_buf[10];

void littlemem_st_006_func_001 ()
{
	littlemem_st_006_s_001_gbl_str = (littlemem_st_structure *)littlemem_st_006_gbl_buf;
}

void littlemem_st_006_func_002 (int flag)
{
	if(flag == MAX_STR)
	{
		littlemem_st_006_s_001_gbl_str->c = 1; /* ERROR: Little memory or overflow */
	}
}

void littlemem_st_006 ()
{
	littlemem_st_006_func_001();
	littlemem_st_006_func_002(10);
}

/***********************************************************************
 *
 * Defect type: Assignment of a buffer too small for a strucutre member 
 * Complexity: Write to global structure member that has been casted from an array too small for structure memory 
 *
 ***********************************************************************/
littlemem_st_structure *littlemem_st_007_s_001_gbl_str;

char littlemem_st_007_gbl_buf[10];

void littlemem_st_007_func_001 ()
{
	littlemem_st_007_s_001_gbl_str = (littlemem_st_structure *)littlemem_st_007_gbl_buf;
}

void littlemem_st_007_func_002 (int flag)
{
	int i;
	for(i=0;i<2;i++)
	{
		if(flag == MAX_STR)
		{
			;
		}
		else
		{
			littlemem_st_007_s_001_gbl_str->c = 1; /* ERROR: Little memory or overflow */
		}
	}
}

void littlemem_st_007 ()
{
	littlemem_st_007_func_001();
	littlemem_st_007_func_002(1);
}

/***********************************************************************
 *
 * Defect type: Assignment of a buffer too small for a strucutre member 
 * Complexity: Write to global structure member that has been casted from an array too small for structure memory 
 *
 ***********************************************************************/
littlemem_st_structure *littlemem_st_008_s_001_gbl_str;

#define MAX_STR2 10

#define MAX_STR3 1

char littlemem_st_008_gbl_buf[10];

void littlemem_st_008_func_001 ()
{
	littlemem_st_008_s_001_gbl_str = (littlemem_st_structure *)littlemem_st_008_gbl_buf;
}

void littlemem_st_008_func_002 (int flag)
{
	int i=0;
	while(i<2)
	{
		if(flag == MAX_STR2)
		{
			;
		}
		else if(flag == MAX_STR3)
		{
			littlemem_st_007_s_001_gbl_str->c = 1; /* ERROR: Little memory or overflow */
		}
	    	i++;
	}
}

void littlemem_st_008 ()
{
	littlemem_st_008_func_001();
	littlemem_st_008_func_002(1);
}

/***********************************************************************
 *
 * Defect type: Assignment of a buffer too small for a strucutre member 
 * Complexity: Write to global structure member that has been casted from an array too small for structure memory 
 *
 ***********************************************************************/
littlemem_st_structure *littlemem_st_009_s_001_gbl_str;

#define MAX_2 10

#define MAX_3 1

char littlemem_st_009_gbl_buf[10];

void littlemem_st_009_func_001 ()
{
	littlemem_st_009_s_001_gbl_str = (littlemem_st_structure *)littlemem_st_009_gbl_buf;
}

void littlemem_st_009_func_002 (int flag)
{
	int i=0;
	do
	{
		if(flag == MAX_2)
		{
			;
		}
		else if(flag == MAX_3)
		{
			littlemem_st_007_s_001_gbl_str->c = 1; /* ERROR: Little memory or overflow */
		}
	    	i++;
	}while(i<2);
}

void littlemem_st_009 ()
{
	littlemem_st_009_func_001();
	littlemem_st_009_func_002(1);
}

/***********************************************************************
 *
 * Defect type: Assignment of a buffer too small for a strucutre member 
 * Complexity: Write to global structure member that has been casted from an array too small for structure memory 
 *
 ***********************************************************************/
littlemem_st_structure *littlemem_st_010_s_001_gbl_str;

char littlemem_st_010_gbl_buf[10];

void littlemem_st_010_func_001 ()
{
	littlemem_st_010_s_001_gbl_str = (littlemem_st_structure *)littlemem_st_010_gbl_buf;
}

void littlemem_st_010_func_002 (int flag)
{
	goto label;
	label:
		littlemem_st_007_s_001_gbl_str->c = 1; /* ERROR: Little memory or overflow */
}

void littlemem_st_010 ()
{
	littlemem_st_010_func_001();
	littlemem_st_010_func_002(1);
}

/***********************************************************************
 *
 * Defect type: Assignment of a buffer too small for a strucutre member 
 * Complexity: Write to global structure member that has been casted from an array too small for structure memory 
 *
 ***********************************************************************/
littlemem_st_structure *littlemem_st_011_s_001_gbl_str;

char littlemem_st_011_gbl_buf[10];

void littlemem_st_011_func_001 ()
{
	littlemem_st_011_s_001_gbl_str = (littlemem_st_structure *)littlemem_st_011_gbl_buf;
}

void littlemem_st_011_func_002 (int flag)
{
	int i=0;
	goto label;

	label:
	while(i<2)
	{
		littlemem_st_007_s_001_gbl_str->c = 1; /* ERROR: Little memory or overflow */
	    	i++;
	}
}

void littlemem_st_011 ()
{
	littlemem_st_011_func_001();
	littlemem_st_011_func_002(1);
}

/***********************************************************************
 *
 * Defect type: Assignment of a buffer too small for a strucutre member 
 * Main 
 *
 ***********************************************************************/
extern volatile int vflag;

void littlemem_st_main ()
{
	if (vflag == 1 || vflag == 888)
	{
		littlemem_st_001();
	}

	if (vflag == 2 || vflag == 888)
	{
		littlemem_st_002();
	}

	if (vflag == 3 || vflag == 888)
	{
		littlemem_st_003();
	}

	if (vflag == 4 || vflag == 888)
	{
		littlemem_st_004();
	}

	if (vflag == 5 || vflag == 888)
	{
		littlemem_st_005();
	}

	if (vflag == 6 || vflag == 888)
	{
		littlemem_st_006();
	}

	if (vflag == 7 || vflag == 888)
	{
		littlemem_st_007();
	}

	if (vflag == 8 || vflag == 888)
	{
		littlemem_st_008();
	}

	if (vflag == 9 || vflag == 888)
	{
		littlemem_st_009();
	}

	if (vflag == 10 || vflag == 888)
	{
		littlemem_st_010();
	}

	if (vflag == 11 || vflag == 888)
	{
		littlemem_st_011();
	}
}
