//func.c file
#include <stdio.h>
#include "func.h"
//#define PRINT_ID

int func_name_or_id()
{
#ifdef PRINT_ID
	//if id return ==> return 0
	printf("%d\n",ID);
	return 0;
#endif
	//if name return ==> return 1
	printf("%s\n",NAME);
	return 1;
}
