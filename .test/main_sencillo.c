#include "../get_next_line.h"
#include <fcntl.h>

int	main()
{
	int	fd = open(".test/files/empty", O_RDONLY);
	int	i = 0;
	char	*res;

	res = 0;
	while (i < 1)
	{
		res = get_next_line(fd);
		printf("fd: %d\n", fd);
		printf("%s", res);
		free(res);
		i++;
	}
	return (0);
}
