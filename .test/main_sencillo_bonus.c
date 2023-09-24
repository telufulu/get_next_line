#include "../get_next_line.h"
#include <fcntl.h>

int	main()
{
	int	fd1 = open(".test/files/hola", O_RDONLY);
	int	fd2 = open(".test/files/41_no_nl", O_RDONLY);
	int	i = 0;
	char	*res;

	res = 0;
	while (i < 1)
	{
		printf("fd1: %d\n", fd1);
		res = get_next_line(fd1);
		printf("res: %s\n", res);
		free(res);
		printf("fd2: %d\n", fd2);
		res = get_next_line(fd2);
		printf("res: %s\n", res);
		free(res);
		i++;
	}
	close(fd1);
	close(fd2);
	return (0);
}
