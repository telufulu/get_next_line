#include "../get_next_line.h"
#include <fcntl.h>

int	main()
{
	int	fd = open(".test/files/hola", O_RDONLY);
	int	i = 0;
	char	*res;

	res = 0;
	while (i < 5)
	{
		res = get_next_line(fd);
		printf("%s", res);
		free(res);
		i++;
	}
	return (0);
}
