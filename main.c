#include <stdio.h>

int	main(void)
{
	char *str = "abcde";

	printf("%2147483647.*s\n", 5, str);
	return(0);
}
