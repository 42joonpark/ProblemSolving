#include <math.h>
#include <stdio.h>
#include <unistd.h>

int	is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	main() {
	char	buf[1000001];
	int		idx;
	int		i;
	int		ct = 0;

	idx = read(STDIN_FILENO, buf, 1000001);
	buf[idx] = '\0';

	i = 0;
	while (buf[i])
	{
		if (is_alpha(buf[i]))
		{
			++ct;
			while (is_alpha(buf[i]) && buf[i])
				++i;
		}
		if (buf[i] == '\0')
			break ;
		++i;
	}
	printf("%d\n", ct);
}
