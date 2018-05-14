/***********************************************************************
 *
 * Defect Classification
 * ---------------------
 * Description: Defect code used to identify buffer underflow
 *
 ***********************************************************************/

#include "HeaderFile.h"

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Read below bounds of array
 *
 ***********************************************************************/
void buffer_underflow_001 (int flag)
{
	char 	cbuf[5], cret;
	short	sbuf[5], sret;
	int	ibuf[5], iret;
	long	lbuf[5], lret;
	float	fbuf[5], fret;
	double	dbuf[5], dret;

	switch(flag)
	{
		case 1: cret = cbuf[-1]; /* ERROR: Buffer underflow */
			break;
		case 2: sret = sbuf[-1]; /* ERROR: Buffer underflow */
			break;
		case 3: iret = ibuf[-1]; /* ERROR: Buffer underflow */
			break;
		case 4: lret = lbuf[-1]; /* ERROR: Buffer underflow */
			break;
		case 5: fret = fbuf[-1]; /* ERROR: Buffer underflow */
			break;
		case 6: dret = dbuf[-1]; /* ERROR: Buffer underflow */
		defualt:
			break;
	}
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Write below bounds of array
 *
 ***********************************************************************/
void buffer_underflow_002 (int flag)
{
	char 	cbuf[5];
	short	sbuf[5];
	int	ibuf[5];
	long	lbuf[5];
	float	fbuf[5];
	double	dbuf[5];
	
	switch(flag)
	{
		case 1: cbuf[-1] = 1; /* ERROR: Buffer underflow */
			break;
		case 2: sbuf[-1] = 1; /* ERROR: Buffer underflow */
			break;
		case 3: ibuf[-1] = 1; /* ERROR: Buffer underflow */
			break;
		case 4: lbuf[-1] = 1; /* ERROR: Buffer underflow */
			break;
		case 5: fbuf[-1] = 1; /* ERROR: Buffer underflow */
			break;
		case 6: dbuf[-1] = 1; /* ERROR: Buffer underflow */
			break;
		default:
			break;
	}
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Write below bounds of array using variable index
 *
 ***********************************************************************/
void buffer_underflow_003 (int flag)
{
	char 	cbuf[5];
	short	sbuf[5];
	int	ibuf[5];
	long	lbuf[5];
	float	fbuf[5];
	double	dbuf[5];
	int index = -1;

	switch(flag)
	{
		case 1: cbuf[index] = 1; /* ERROR: Buffer underflow */
			break;
		case 2: sbuf[index] = 1; /* ERROR: Buffer underflow */
			break;
		case 3: ibuf[index] = 1; /* ERROR: Buffer underflow */
			break;
		case 4: lbuf[index] = 1; /* ERROR: Buffer underflow */
			break;
		case 6: fbuf[index] = 1; /* ERROR: Buffer underflow */
			break;
		case 7: dbuf[index] = 1; /* ERROR: Buffer underflow */
			break;
		default:
			break;
	}	
}

/***********************************************************************
 *
 * Types of defects: buffer underflow ( static buffer )
 * Complexity: Read below bound of array due to use of sizeof character element as sizeof character array
 * http://www.gimpel.com/html/bugs/bug428.htm
 *
 ***********************************************************************/
enum {LENGTH = 10};

static char a[LENGTH] = "567891234";

static char ith_character( int n )
{
	return a[n]; /* ERROR: Buffer underflow */
}

void buffer_underflow_004 ()
{
	int len = sizeof(a[LENGTH]);
	char c = ith_character( len - 2 );
	
	(void)printf(	"\t\t"
						"\"It's time to celebrate"
						" the %cth of July\"\n",
						c );
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Write below bounds of array using offset to pointer
 *
 ***********************************************************************/
void buffer_underflow_005 (int flag)
{
	char 	cbuf[5];
	short	sbuf[5];
	int	ibuf[5];
	long	lbuf[5];
	float	fbuf[5];
	double	dbuf[5];

	switch(flag)
	{
		case 1: *(cbuf - 1)= 1; /* ERROR: Buffer underflow */
			break;
		case 2: *(sbuf - 1)= 1; /* ERROR: Buffer underflow */
			break;
		case 3: *(ibuf - 1)= 1; /* ERROR: Buffer underflow */
			break;
		case 4: *(lbuf - 1)= 1; /* ERROR: Buffer underflow */
			break;
		case 5: *(fbuf - 1)= 1; /* ERROR: Buffer underflow */
			break;
		case 6: *(dbuf - 1)= 1; /* ERROR: Buffer underflow */
			break;
		default:
			break;
	}
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Read below bounds of array using offset to pointer
 *
 ***********************************************************************/
void buffer_underflow_006 (int flag)
{
	char 	cbuf[5], cret;
	short	sbuf[5], sret;
	int	ibuf[5], iret;
	long	lbuf[5], lret;
	float	fbuf[5], fret;
	double	dbuf[5], dret;

	switch(flag)
	{
		case 1: cret = *(cbuf - 1); /* ERROR: Buffer underflow */
			break;
		case 2: sret = *(sbuf - 1); /* ERROR: Buffer underflow */
			break;
		case 3: iret = *(ibuf - 1); /* ERROR: Buffer underflow */
			break;
		case 4: lret = *(lbuf - 1); /* ERROR: Buffer underflow */
			break;
		case 5: fret = *(fbuf - 1); /* ERROR: Buffer underflow */
			break;
		case 6: dret = *(dbuf - 1); /* ERROR: Buffer underflow */
			break;
		default:
			break;
	}
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Write below bounds of array in for loop
 *
 ***********************************************************************/
void buffer_underflow_007 ()
{
	int buf[5], i;
	
	for (i = 4;i >= -1;i --)
	{
		buf[i] = 1; /* ERROR: Buffer underflow */
	}
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Write below bounds of array in for loop using pointer dereference
 *
 ***********************************************************************/
void buffer_underflow_008 ()
{
	int buf[5], i, *p;
	
	p = &buf[4];
	for (i = 0;i <= 5;i ++)
	{
		*p = 1; /* ERROR: Buffer underflow */
		p --;
	}
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Write below bounds of global array in for loop
 *
 ***********************************************************************/
int buffer_underflow_009_gbl_buf[5];

void buffer_underflow_009 ()
{
	int i;

	for (i = 4;i >= -1;i --)
	{
		buffer_underflow_009_gbl_buf[i] = 1; /* ERROR: Buffer underflow */
	}
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Write below bounds of global array in for loop using pointer dereference
 *
 ***********************************************************************/
int buffer_underflow_010_gbl_buf[5];

void buffer_underflow_010 ()
{
	int *p;
	int i;
	
	p = &buffer_underflow_010_gbl_buf[4];
	for (i = 0;i <= 5;i ++)
	{
		*p = 1; /* ERROR: Buffer underflow */
		p --;
	}
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Write below bounds of global array in while loop
 *
 ***********************************************************************/
int buffer_underflow_011_gbl_buf[5];

void buffer_underflow_011 ()
{
	int i = 4;
	
	while(i >= -1)
	{
		buffer_underflow_011_gbl_buf[i] = 1; /* ERROR: Buffer underflow */
	    	i--;
	}
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Write below bounds of global array in while loop using pointer dereference
 *
 ***********************************************************************/
int buffer_underflow_012_gbl_buf[5];

void buffer_underflow_012 ()
{
	int *p, i = 4;
	
	p = &buffer_underflow_012_gbl_buf[4];
	while(i >= -1)
	{
		*p = 1; /* ERROR: Buffer underflow */
		p --;
		i--;
	}
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Write below bounds of global array in nested if statement
 *
 ***********************************************************************/
int buffer_underflow_013_gbl_buf[5];

void buffer_underflow_013 ()
{
	int i=4;
	int var=0;
	
	while(i >= -1)
	{
		if(var==0)
		{
			buffer_underflow_013_gbl_buf[i] = 1; /* ERROR: Buffer underflow */
	    	}
	    	i--;
	}
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Stack underflow due to infinite while loop 
 *
 ***********************************************************************/
void buffer_underflow_101 ()
{
	char buf[10];
	int len = strlen(buf)- 1;
	
	strcpy(buf, "my string");
	while (buf[len] != 'Z') /* ERROR: Stack underflow */
	{
		len--;
	}
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Stack underflow due to indexing below bounds of structure member 
 *
 ***********************************************************************/
typedef struct {
	char buf[10];
	char buf1[10];
	char buf2[10];
	char buf3[10];
	char buf4[10];
	char buf5[10];
	char buf6[10];
} buffer_underflow_102_s_001;

void buffer_underflow_102_func_001 (buffer_underflow_102_s_001 s)
{
	 int len = strlen(s.buf)- 1;
	 
	 for (;s.buf[len] != 'Z';len--) /* ERROR: Stack underflow */
	 {
	 	;
	 }
}

void buffer_underflow_102 ()
{
	buffer_underflow_102_s_001 s;
	
	strcpy(s.buf,"STRING");
	buffer_underflow_102_func_001(s);
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Stack underflow due to indexing below bounds of structure member 
 *
 ***********************************************************************/
typedef struct {
	char buf[10];
	char buf1[10];
	char buf2[10];
	char buf3[10];
	char buf4[10];
} buffer_underflow_103_s_001;

void buffer_underflow_103_func_001 (buffer_underflow_103_s_001 *s)
{
	char buf[10] = "STRING";
	
	strcpy(s->buf,buf);
}

void buffer_underflow_103_func_002 (buffer_underflow_103_s_001 *s)
{
	 int len = strlen(s->buf)- 1;
	
	do
	 {
		 s->buf[len] = 'A';
		 len--;
	 }
	 while (s->buf[len] != 'Z'); /* ERROR: Stack underflow */
}

void buffer_underflow_103 ()
{
	buffer_underflow_103_s_001 s;
	
	buffer_underflow_103_func_001(&s);
	buffer_underflow_103_func_002(&s);
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Stack underflow due to indexing below bounds of structure member 
 *
 ***********************************************************************/
typedef struct {
	char buf[10];
	char buf1[10];
	char buf2[10];
} buffer_underflow_104_s_001;

void buffer_underflow_104_func_002 (buffer_underflow_104_s_001 *s)
{
	char buf[10] = "STRING";
	
	strcpy(s->buf,buf);
}

buffer_underflow_104_s_001 buffer_underflow_104_func_001 (buffer_underflow_104_s_001 *s)
{
	buffer_underflow_104_s_001 s1;
	int len = strlen(s->buf)- 1;
	
	buffer_underflow_104_func_002(s);
	do
	{
		s->buf[len] = 'B';
		s1.buf[len] = s->buf[len];
		len--;
	}while (s->buf[len] != 'Z'); /* ERROR: Stack underflow */
	return s1;
}

void buffer_underflow_104 ()
{
	buffer_underflow_104_s_001 s,s2;
	
	s2 = buffer_underflow_104_func_001(&s);
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Stack underflow when using recursive function 
 *
 ***********************************************************************/
typedef struct {
	char buf[10];
} buffer_underflow_105_s_001;

void buffer_underflow_105_func_001 (buffer_underflow_105_s_001 s, int cnt)
{
	while (s.buf[cnt] != 'Z' )
	{
		cnt--;
		if(cnt>0)
		{
			buffer_underflow_105_func_001(s, cnt);
		}
	    	else
	    	{
			s.buf[cnt] = 'C'; /* ERROR: Stack underflow */
		}
	}
}

void buffer_underflow_105 ()
{
	char buf[10];
	buffer_underflow_105_s_001 s;
	
	strcpy(s.buf,"STRING !");
	buffer_underflow_105_func_001(s,8);
	buf[0] = s.buf[1];
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Stack underflow when using recursive function 
 *
 ***********************************************************************/
typedef struct {
	char buf[10];
	char buf1[10];
	char buf2[10];
	char buf3[10];
	char buf4[10];
	char buf5[10];
	char buf6[10];
} buffer_underflow_106_s_001;

void buffer_underflow_106_func_001 (buffer_underflow_106_s_001 s)
{
	 int len = strlen(s.buf)- 1;
	 char c;
	
	 for (;s.buf[len] != 'Z';len--) /* ERROR: Stack underflow */
	 {
         	c = s.buf[len];
	 }
}

void buffer_underflow_106 ()
{
	buffer_underflow_106_s_001 s;
	
	strcpy(s.buf,"STRING !!!!");
	void (*func)(buffer_underflow_106_s_001);
	func = buffer_underflow_106_func_001;
	func(s);
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Stack underflow when using function call from else condition 
 *
 ***********************************************************************/
typedef struct {
	char buf[10];
	char buf1[10];
	char buf2[10];
	char buf3[10];
	char buf4[10];
	char buf5[10];
} buffer_underflow_107_s_001;

void buffer_underflow_107_func_001 (buffer_underflow_107_s_001 *s)
{
	 int len = strlen(s->buf)- 1;
	 char c;
	 
	 for (;s->buf[len] != 'Z';len--)
	 {
        	c = s->buf[len]; /* ERROR: Stack underflow */
	 }
}

void buffer_underflow_107_func_002 (buffer_underflow_107_s_001 s)
{
	s.buf[0] = 1;
}

void buffer_underflow_107 ()
{
	int flag = 0;
	buffer_underflow_107_s_001 s;
	
	s.buf[0] = 1;
	if (flag >1 )
	{
		buffer_underflow_107_func_002(s);
	}
	else
	{
		buffer_underflow_107_func_001(&s);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Index below bounds of dynamically allocated memory 
 *
 ***********************************************************************/
void buffer_underflow_201 ()
{
	char *buf=(char*)calloc(5,sizeof(char));
	int i;
	
	printf("print bufferundr");
	if(buf!=NULL)
	{
		for (i=4;i>=-1;i--)
	   	{
			buf[i]=1; /* ERROR: Buffer underflow */
	    	}
	    	free(buf);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Index below bounds of dynamically allocated memory 
 *
 ***********************************************************************/
void buffer_underflow_202 ()
{
	short *buf=(short*)calloc(5,sizeof(short));
	
	printf("underflow2");
	if(buf!=NULL)
	{
	    	*(buf-5)=1; /* ERROR: Buffer underflow */
		free(buf);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Index below bounds of dynamically allocated memory 
 *
 ***********************************************************************/
void buffer_underflow_203 ()
{
	int *buf=(int*)calloc(5,sizeof(int));
	int ret;
	int i;
	
	if(buf!=NULL)
	{
		for (i=0;i<5;i++)
		{
			buf[i]=1;
		}
		ret = buf[-1]; /* ERROR: Buffer underflow */
		free(buf);
		printf("%d",ret);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Index below bounds of dynamically allocated memory 
 *
 ***********************************************************************/
void buffer_underflow_204 ()
{
	int *buf=(int*)calloc(5,sizeof(int));
	
	if(buf!=NULL)
	{
	    	*(buf-5)= 1; /* ERROR: Buffer underflow */
		free(buf);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Index below bounds of dynamically allocated memory 
 *
 ***********************************************************************/
void buffer_underflow_205 ()
{
	long *buf=(long*)calloc(5,sizeof(long));
	int i;
	
	if(buf!=NULL)
	{
	    	for(i=-1;i<5;i++)
		{
	        	buf[i]=1; /* ERROR: Buffer underflow */
		}
		free(buf);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Index below bounds of dynamically allocated memory 
 *
 ***********************************************************************/
void buffer_underflow_206 ()
{
	float *buf=(float*)calloc(5,sizeof(float));
	int i;
	
	if(buf!=NULL)
	{
		for(i=-1;i<5;i++)
		{
			buf[i]=1.0; /* ERROR: Buffer underflow */
		}
	    	free(buf);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Index below bounds of dynamically allocated memory 
 *
 ***********************************************************************/
void buffer_underflow_207 ()
{
	double *buf=(double*)calloc(5,sizeof(double));
	int i;
	
	if(buf!=NULL)
	{
		for(i=-1;i<5;i++)
		{
			buf[i]=1.0; /* ERROR: Buffer underflow */
		}
	    	free(buf);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Index below bounds of dynamically allocated memory 
 *
 ***********************************************************************/
void buffer_underflow_208 ()
{
	int **buf = (int**)calloc(5,sizeof(int*));
	int i,j;

	for(i=0;i<5;i++)
	{
		buf[i]=(int*)calloc(5,sizeof(int));
	}

	for(i=-1;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			*(*(buf+i)+j)=i; /* ERROR: Buffer underflow */
		}
		if(i>0)
		{
			free(buf[i]);
		}
	}
	free(buf);
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Index below bounds of dynamically allocated memory 
 *
 ***********************************************************************/
void buffer_underflow_209 ()
{
	int *buf1=(int*)calloc(5,sizeof(int));
	int *buf2=(int*)calloc(5,sizeof(int));
	int *buf3=(int*)calloc(5,sizeof(int));
	int *buf4=(int*)calloc(5,sizeof(int));
	int *buf5=(int*)calloc(5,sizeof(int));
	int **pbuf[5] = {&buf1, &buf2, &buf3, &buf4, &buf5};
	int i,j=4;
	
	for(i=0;i<5;i++)
	{
		*((*pbuf[i-3])+j)=5; /* ERROR: Buffer underflow */
	}
	free(buf1);
	free(buf2);
	free(buf3);
	free(buf4);
	free(buf5);
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Index below bounds of dynamically allocated memory 
 *
 ***********************************************************************/
typedef struct {
	int a;
	int b;
	int c;
} buffer_underflow_210_s_001;

void buffer_underflow_210 ()
{
	buffer_underflow_210_s_001* sbuf= (buffer_underflow_210_s_001*)calloc(5,sizeof(buffer_underflow_210_s_001));
	
	if(sbuf!=NULL)
	{
		sbuf[-1].a = 1; /* ERROR: Buffer underflow */
	    	free(sbuf);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Index below bounds of dynamically allocated memory 
 *
 ***********************************************************************/
typedef struct {
	int a;
	int b;
	int buf[5];
} buffer_underflow_211_s_001;

void buffer_underflow_211 ()
{
	buffer_underflow_211_s_001* s=(buffer_underflow_211_s_001*)calloc(5,sizeof(buffer_underflow_211_s_001));
	
	if(s!=NULL)
	{
		(s-5)->buf[4] = 1; /* ERROR: Buffer underflow */
		free(s);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Index below bounds of dynamically allocated memory 
 *
 ***********************************************************************/
void buffer_underflow_212 ()
{
	int *buf=(int*)calloc(5,sizeof(int));
	int index = 5;
	
	if(buf!=NULL)
	{
	    	*(buf-index)=9; /* ERROR: Buffer underflow */
		free(buf);
	}
}
/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Index below bounds of dynamically allocated memory 
 *
 ***********************************************************************/
void  buffer_underflow_213 ()
{
	int *buf=(int*)calloc(5,sizeof(int));
	int index = 5;
	
	index = rand ()-2;
	if(buf!=NULL)
    	{
	    	buf[-index] = 1; /* ERROR: Buffer underflow */
		free(buf);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Index below bounds of dynamically allocated memory 
 *
 ***********************************************************************/
void buffer_underflow_214 ()
{
	int *buf=(int*)calloc(5,sizeof(int));
	int index = 3;
	
	if(buf!=NULL)
	{
 	   	*(buf +((-2 * index)+ 1))= 1; /* ERROR: Buffer underflow */
		free(buf);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Index below bounds of dynamically allocated memory 
 *
 ***********************************************************************/
void buffer_underflow_215 ()
{
	int *buf=(int*)calloc(5,sizeof(int));
	int index = 2;
	
	if(buf!=NULL)
	{
	    	buf[(index * index)- 5] = 1; /* ERROR: Buffer underflow */
	    	free(buf);
    	}
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Index below bounds of dynamically allocated memory 
 *
 ***********************************************************************/
int buffer_underflow_216_func_001 ()
{
	return -1;
}

void buffer_underflow_216 ()
{
	int *buf=(int*)calloc(5,sizeof(int));
	
	if(buf!=NULL)
	{
		buf[buffer_underflow_216_func_001 ()] = 1; /* ERROR: Buffer underflow */
		free(buf);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Index below bounds of dynamically allocated memory 
 *
 ***********************************************************************/
void buffer_underflow_217_func_001 (int index)
{
	int *buf=(int*)calloc(5,sizeof(int));
	
	if(buf!=NULL)
	{
	    	*(buf -index)= 1; /* ERROR: Buffer underflow */
	    	free(buf);
	}
}

void buffer_underflow_217 ()
{
	buffer_underflow_217_func_001(5);
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Index below bounds of dynamically allocated memory 
 *
 ***********************************************************************/
void buffer_underflow_218 ()
{
	int *buf=(int*)calloc(5,sizeof(int));
	int indexes[4] = {3, 4, 5, 6};
	int index = 2;
	
	if(buf!=NULL)
	{
	    	*(buf-indexes[index])= 1; /* ERROR: Buffer underflow */
	    	free(buf);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Index below bounds of dynamically allocated memory 
 *
 ***********************************************************************/
void buffer_underflow_219 ()
{
	int *buf=(int*)calloc(5,sizeof(int));
	int index = -5;
	int index1;
	
	index1 = index;
	if(buf!=NULL)
	{
	    	buf[index1] = 1; /* ERROR: Buffer underflow */
	    	free(buf);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Index below bounds of dynamically allocated memory 
 *
 ***********************************************************************/
void buffer_underflow_220 ()
{
	int *buf=(int*)calloc(5,sizeof(int));
	int index = -5;
	int index1;
	int index2;
	
	index1 = index;
	index2 = index1;
	if(buf!=NULL)
	{
	    	buf[index2] = 1; /* ERROR: Buffer underflow */
	    	free(buf);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Index below bounds of dynamically allocated memory 
 *
 ***********************************************************************/
void buffer_underflow_221 ()
{
	int *buf=(int*)calloc(5,sizeof(int));
	int *p1;
	int *p2;
	
	if(buf!=NULL)
	{
		p1 = buf;
		p2 = p1;
		*(p2-5)= 1; /* ERROR: Buffer underflow */
	    	free(buf);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Index below bounds of dynamically allocated memory 
 *
 ***********************************************************************/
void buffer_underflow_222 ()
{
	int *buf=(int*)calloc(5,sizeof(int));
	int *p;
	
	if(buf!=NULL)
	{
	    	p = buf;
	    	*(p-5)= 1; /* ERROR: Buffer underflow */
	    	free(buf);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Index below bounds of dynamically allocated memory 
 *
 ***********************************************************************/
void buffer_underflow_223 ()
{
	int *buf=(int*)calloc(5,sizeof(int));
	int *p;
	int i;
	
	if(buf!=NULL)
	{
		p = buf;
	    	for (i = 4;i >=-1;i--)
	    	{
	    		p[i]='1'; /* ERROR: Buffer underflow */
	    	}
	    	free(buf);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Index below bounds of dynamically allocated memory 
 *
 ***********************************************************************/
void buffer_underflow_224_func_001 (int *buf)
{
	*(buf-5)= 1; /* ERROR: Buffer underflow */
}

void buffer_underflow_224 ()
{
	int *buf=(int*)calloc(5,sizeof(int));
	
	if(buf!=NULL)
	{
	    	buffer_underflow_224_func_001(buf);
	    	free(buf);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Index below bounds of dynamically allocated memory 
 *
 ***********************************************************************/
void buffer_underflow_225 ()
{
	char *buf=(char*)calloc(5,sizeof(char));
	int i;

	if(buf!=NULL)
	{
	    	for(i=4;i>=-1;i--)
	    	{
	    		buf[i]='1'; /* ERROR: Buffer underflow */
	    	}
	    	free(buf);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Index below bounds of dynamically allocated memory 
 *
 ***********************************************************************/
void buffer_underflow_226 ()
{
	char *buf=(char*)calloc(5,sizeof(char));
	int *p;
	
	if(buf!=NULL)
	{
	     	p = (int*)buf;
	     	*(p - 10)= 1; /* ERROR: Buffer underflow */
	     	free(buf);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Index below bounds of dynamically allocated memory 
 *
 ***********************************************************************/
void buffer_underflow_227 ()
{
	int *buf=(int*)calloc(5,sizeof(int));
	char *p;
	
	if(buf!=NULL)
	{
		p = (char*)buf;
		*(p - 10)= 1; /* ERROR: Buffer underflow */
		free(buf);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Index below bounds of dynamically allocated memory 
 *
 ***********************************************************************/
void buffer_underflow_228 ()
{
	int *buf1=(int*)calloc(5,sizeof(int));
	int *buf2=(int*)calloc(3,sizeof(int));
	int i;

	for(i=0;i<5;i++)
	{
		*(buf1+i)=i;
	}
	*(buf2-*(buf1+4))=1; /* ERROR: Buffer underflow */
	free(buf1);
	free(buf2);
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Index below bounds of dynamically allocated memory 
 *
 ***********************************************************************/
void buffer_underflow_229 ()
{
	while (1)
	{
		char* buf= (char*)malloc(sizeof(char));
		if(buf!=NULL)
		{
		    	buf[-1]='a'; /* ERROR: Buffer underflow */
		    	free(buf);
		}
	    	break;
	}
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Index below bounds of dynamically allocated memory 
 *
 ***********************************************************************/
void buffer_underflow_230 ()
{
	int i,j;
	char ** doubleptr=(char**)malloc(10*sizeof(char*));

	for(i=0;i<10;i++)
	{
		doubleptr[i]=calloc(10,sizeof(char));
	}

	for(i=0;i<10;i++)
	{
		for(j=9;j>=-1;j--)
		{
		  	doubleptr[i][j]='a'; /* ERROR: Buffer underflow */
		}
		free(doubleptr[i]);
	}
	free(doubleptr);
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Index below bounds of dynamically allocated memory 
 *
 ***********************************************************************/
void buffer_underflow_231 ()
{
	int i;
	char* ptr1=(char*)calloc(12, sizeof(char));
	char a[12],*ptr2 = a;
	
	if(ptr1!=NULL)
	{
	    	ptr1[11]='\0';
	    	for(i=10;i>=-1;i--) /* ERROR: Buffer underflow */
	    	{
	        	ptr1[i]='a';
	    	}
	    	memcpy(ptr2,ptr1,12);
	    	free(ptr1);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Index below bounds of dynamically allocated memory 
 *
 ***********************************************************************/
typedef struct
{
	char arr[10];
	int arri[10];
}buffer_underflow_s_232;

void buffer_underflow_232 ()
{
	buffer_underflow_s_232* ptr_s= calloc(10,sizeof(buffer_underflow_s_232));
	int i;

	if(ptr_s!=NULL)
	{
		for(i=-1;i<10;i++)
		{
	    		ptr_s[i].arr[i]='a'; /* ERROR: Buffer underflow */
		}
		free(ptr_s);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Index below bounds of dynamically allocated memory 
 *
 ***********************************************************************/
void buffer_underflow_233 ()
{
	char *message = (char*)calloc(12, sizeof(char));
	int index=12;
	int len=index-12;
	int c;
  
  	if(message !=NULL)
    	{
	    	while(len>=-2 )
	    	{
		   	c = message[len];
		   	if(isspace(c))
		   	{
			   	message[len]='\n'; /* ERROR: Buffer underflow */
		   	}
	    		len--;
        	}
		free(message);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Index below bounds of dynamically allocated memory 
 *
 ***********************************************************************/
void buffer_underflow_234 ()
{
	char* srcbuf="Test Code";
	int i,loc=1;
	char* destbuf=(char*)malloc(10*sizeof(char));
	char ch='o';
	
	if(destbuf!=NULL)
	{
		for(i=-1;i<10;i++)
	    	{
			if(srcbuf[i]==ch) /* ERROR: Buffer underflow */
		     	{
				loc=i;
		     	}
	    	}
	    	strncpy(&destbuf[loc],&srcbuf[loc],1);
	    	free(destbuf);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Index below bounds of dynamically allocated memory 
 *
 ***********************************************************************/
void buffer_underflow_235 ()
{
	int i,loc1=0,loc2=0;
	char** doubleptr=(char**)malloc(10* sizeof(char*));
	
	for (i=0;i<10;i++)
	{
		doubleptr[i]=(char*)malloc(10*sizeof(char));
	}

	if(loc2==0)
	{
		loc2--;
	}

	doubleptr[0][loc2]='T'; /* ERROR: Buffer underflow */
	for (i=0;i<10;i++)
	{
		free(doubleptr[i]);
	}
	free(doubleptr);
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Index below bounds of dynamically allocated memory 
 *
 ***********************************************************************/
void buffer_underflow_236 ()
{
	  char test[]="This is a test code";
	  char *newTest= (char*)malloc(10*sizeof(char));
	
	  if(newTest!=NULL)
	  {
	     	memcpy (newTest,test,10);
	     	char c ;
	     	c = newTest[-10]; /* ERROR: Buffer underflow */
	     	free(newTest);
	  }
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Index below bounds when using 2D array 
 *
 ***********************************************************************/
void buffer_underflow_237 ()
{
	int i;
	char** doubleptr=(char**)malloc(10* sizeof(char*));
	
	if(doubleptr!=NULL)
	{
		for (i=0;i<10;i++)
	    	{
	    		doubleptr[i-10]=(char*)malloc(10*sizeof(char)); /* ERROR: Buffer underflow */
	    		if(doubleptr[i]!=NULL)
	    		{
	    	    		doubleptr[0][0]='T';
			    	free(doubleptr[i]);
	    		}
	    	}
		free(doubleptr);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: Index below bounds of structure member 
 *
 ***********************************************************************/
typedef struct
{
	char arr[10];
	int arri[10];

}buffer_underflow_s_238;

void buffer_underflow_238 ()
{
	buffer_underflow_s_238* new_s = malloc(10*sizeof(buffer_underflow_s_238));
	int loc=-1,i=0;

	if(new_s!=NULL)
	{
		new_s[loc].arr[i]='a'; /* ERROR: Buffer underflow */
	    	new_s[0].arri[i]=2;
	    	free(new_s);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Complexity: when using memcpy to copy structures 
 *
 ***********************************************************************/
typedef struct
{
	char arr[10];
	int arri[10];

}buffer_underflow_s_239;

void buffer_underflow_239 ()
{
	/*buffer_underflow_s_008* new_s;*/
	buffer_underflow_s_239* ptr_s1=malloc(15*sizeof(buffer_underflow_s_239));
	buffer_underflow_s_239  ptr_s2[15];
	int i;

	if(ptr_s1 != NULL)
	{
		for(i=-10;i<15;i++)
		{
			memset(ptr_s1,1,15*sizeof(buffer_underflow_s_239)); /* ERROR: Buffer underflow */
		}
	    	memcpy(ptr_s2,ptr_s1,15*sizeof(buffer_underflow_s_239));
	    	free(ptr_s1);
	}
}

/***********************************************************************
 *
 * Defect type: Buffer underflow
 * Main
 *
 ***********************************************************************/
extern volatile int vflag;

void buffer_underflow_main ()
{
	if (vflag == 1 || vflag == 888)
	{
		buffer_underflow_001 (3);
	}
	
	if (vflag == 2 || vflag == 888)
	{
		buffer_underflow_002 (3);
	}
	
	if (vflag == 3 || vflag == 888)
	{
		buffer_underflow_003 (3);
	}
	
	if (vflag == 4 || vflag == 888)
	{
		buffer_underflow_004 ();
	}
	
	if (vflag == 5 || vflag == 888)
	{
		buffer_underflow_005 (3);
	}
	
	if (vflag == 6 || vflag == 888)
	{
		buffer_underflow_006 (6);
	}
	
	if (vflag == 7 || vflag == 888)
	{
		buffer_underflow_007 ();
	}
	
	if (vflag == 8 || vflag == 888)
	{
		buffer_underflow_008 ();
	}
	
	if (vflag == 9 || vflag == 888)
	{
		buffer_underflow_009 ();
	}
	
	if (vflag == 10 || vflag == 888)
	{
		buffer_underflow_010 ();
	}
	
	if (vflag == 11 || vflag == 888)
	{
		buffer_underflow_011 ();
	}

	if (vflag == 12 || vflag == 888)
	{
		buffer_underflow_012 ();
	}

	if (vflag == 13 || vflag == 888)
	{
		buffer_underflow_013 ();
	}
	
	if (vflag == 101 || vflag == 888)
	{
		buffer_underflow_101 ();
	}
	
	if (vflag == 102 || vflag == 888)
	{
		buffer_underflow_102 ();
	}
	
	if (vflag == 103 || vflag == 888)
	{
		buffer_underflow_103 ();
	}

	if (vflag == 104 || vflag == 888)
	{
		buffer_underflow_104 ();
	}

	if (vflag == 105 || vflag == 888)
	{
		buffer_underflow_105 ();
	}

	if (vflag == 106 || vflag == 888)
	{
		buffer_underflow_106 ();
	}

	if (vflag == 107 || vflag == 888)
	{
		buffer_underflow_107 ();
	}

	if (vflag == 201 || vflag == 888)
	{
		buffer_underflow_201 ();
	}

	if (vflag == 202 || vflag == 888)
	{
		buffer_underflow_202 ();
	}

	if (vflag == 203 || vflag == 888)
	{
		buffer_underflow_203 ();
	}

	if (vflag == 204 || vflag == 888)
	{
		buffer_underflow_204 ();
	}

	if (vflag == 205 || vflag == 888)
	{
		buffer_underflow_205 ();
	}

	if (vflag == 206 || vflag == 888)
	{
		buffer_underflow_206 ();
	}

	if (vflag == 207 || vflag == 888)
	{
		buffer_underflow_207 ();
	}

	if (vflag == 208 || vflag == 888)
	{
		buffer_underflow_208 ();
	}

	if (vflag == 209 || vflag == 888)
	{
		buffer_underflow_209 ();
	}

	if (vflag == 210 || vflag == 888)
	{
		buffer_underflow_210 ();
	}

	if (vflag == 211 || vflag == 888)
	{
		buffer_underflow_211 ();
	}

	if (vflag == 212 || vflag == 888)
	{
		buffer_underflow_212 ();
	}

	if (vflag == 213 || vflag == 888)
	{
		buffer_underflow_213 ();
	}

	if (vflag == 214 || vflag == 888)
	{
		buffer_underflow_214 ();
	}

	if (vflag == 215 || vflag == 888)
	{
		buffer_underflow_215 ();
	}

	if (vflag == 216 || vflag == 888)
	{
		buffer_underflow_216 ();
	}

	if (vflag == 217 || vflag == 888)
	{
		buffer_underflow_217 ();
	}

	if (vflag == 218 || vflag == 888)
	{
		buffer_underflow_218 ();
	}

	if (vflag == 219 || vflag == 888)
	{
		buffer_underflow_219 ();
	}

	if (vflag == 220 || vflag == 888)
	{
		buffer_underflow_220 ();
	}

	if (vflag == 221 || vflag == 888)
	{
		buffer_underflow_221 ();
	}

	if (vflag == 222 || vflag == 888)
	{
		buffer_underflow_222 ();
	}

	if (vflag == 223 || vflag == 888)
	{
		buffer_underflow_223 ();
	}

	if (vflag == 224 || vflag == 888)
	{
		buffer_underflow_224 ();
	}

	if (vflag == 225 || vflag == 888)
	{
		buffer_underflow_225 ();
	}

	if (vflag == 226 || vflag == 888)
	{
		buffer_underflow_226 ();
	}

	if (vflag == 227 || vflag == 888)
	{
		buffer_underflow_227 ();
	}

	if (vflag == 228 || vflag == 888)
	{
		buffer_underflow_228 ();
	}

	if (vflag == 229 || vflag == 888)
	{
		buffer_underflow_229 ();
	}

	if (vflag == 230 || vflag == 888)
	{
		buffer_underflow_230 ();
	}

	if (vflag == 231 || vflag == 888)
	{
		buffer_underflow_231 ();
	}

	if (vflag == 232 || vflag == 888)
	{
		buffer_underflow_232 ();
	}

	if (vflag == 233 || vflag == 888)
	{
		buffer_underflow_233 ();
	}

	if (vflag == 234 || vflag == 888)
	{
		buffer_underflow_234 ();
	}

	if (vflag == 235 || vflag == 888)
	{
		buffer_underflow_235 ();
	}

	if (vflag == 236 || vflag == 888)
	{
		buffer_underflow_236 ();
	}

	if (vflag == 237 || vflag == 888)
	{
		buffer_underflow_237 ();
	}

	if (vflag == 238 || vflag == 888)
	{
		buffer_underflow_238 ();
	}

	if (vflag == 239 || vflag == 888)
	{
		buffer_underflow_239 ();
	}
}
