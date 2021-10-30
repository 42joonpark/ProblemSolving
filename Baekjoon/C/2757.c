#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	numlen(int num)
{
	int	len = 0;

	while (num >= 0)
	{
		len++;
		num /= 10;
		if (num == 0)
			break ;
	}
	return (len);
}

void	print_col(int col)
{
	static const char	*alphabet =  "ZABCDEFGHIJKLMNOPQRSTUVWXY";
	char				buf[100];
	int					idx;

	idx = 0;
	while (col > 0)
	{
		buf[idx] = alphabet[col % 26];
		--col;
		col /= 26;
		++idx;
	}
	while (--idx >= 0)
		printf("%c", buf[idx]);
}

int	main()
{
	char				buf[100];
	int					col;
	int					row;
	int					len;

	while (1)
	{
		scanf("%s", buf);
		if (buf[1] == '0' && buf[3] == '0')
			break ;
		row = atoi(&buf[1]);
		len = numlen(row);
		col = atoi(&buf[1 + len + 1]);
		print_col(col);
		printf("%d\n", row);
	}
}
