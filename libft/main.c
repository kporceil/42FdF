#include "libft.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	char *ptr;
	printf("%ld\n", ft_strtol(argv[1], &ptr, 16));
	printf("%s\n", ptr);
	return (0);
}
