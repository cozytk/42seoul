#include <stdio.h>

int	main(void)
{
	//char *s = "abcde";
	int	d = 12345;
	int *p = &d;

	printf("|%20p|\n", p);
	return (0);
}
