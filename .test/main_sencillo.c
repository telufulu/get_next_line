#include "../get_next_line.h"
#include <fcntl.h>

int	main()
{
	int	fd = open(".test/files/read_error", O_RDONLY);
	int	i = 0;
	char	*res;

	res = 0;
	printf("fd: %d\n", fd);
	while (i < 1)
	{
		res = get_next_line(fd);
		printf("%s", res);
		free(res);
		i++;
	}
	close(fd);
	return (0);
}
