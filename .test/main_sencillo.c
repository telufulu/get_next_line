#include "../get_next_line.h"
#include <fcntl.h>

void	hola(void)
{
	system("leaks a.out");
}

int	main()
{
	int	fd1 = open(".test/files/hola", O_RDONLY);
	int	i = 0;
	char	*res;

//	atexit(&hola);
	res = 0;
	while (i < 10)
	{
		printf("fd1: %d\n", fd1);
		res = get_next_line(fd1);
		printf("res: %s", res);
		free(res);
		close(fd1);
		fd1 = open(".test/files/hola", O_RDONLY);
		i++;
	}
	close(fd1);
	return (0);
}
