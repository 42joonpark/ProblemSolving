#include <stdio.h>
#include <unistd.h>

int	main()
{
	char	buf[2];

	while (read(STDIN_FILENO, buf, 1) > 0)
	{
		buf[1] = '\0';
		printf("%s", buf);
	}
}
