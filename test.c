#include <stdio.h>

int		main(void)
{
	int number = 2;
	
//	printf("salut%o%s\n", 11, "huhu");
printf("%-10d \n", number);
    printf("%010d \n", number);
	    printf("%-#10x \n", number);  
		    printf("%#x \n", number);
	return (0);
}
