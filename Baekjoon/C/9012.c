#include <stdio.h>
#include <string.h>

int	main()
{
	int		N;
	int		ct;
	char	buf[100];

	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		ct = 0;
		memset(buf, 0, 100);
		scanf("%s", buf);
		for (int i = 0; i < strlen(buf); ++i)
		{
			if (buf[i] == '(')
				++ct;
			else
				--ct;
			if (ct < 0)
				break ;
		}
		if (ct != 0)
			printf("NO\n");
		else
			printf("YES\n");
	}
}
