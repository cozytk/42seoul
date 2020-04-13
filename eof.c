#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char *str = (char *)malloc(sizeof(char) * 0);
	
	*str = 2;

	printf("%d\n", *str);
}
