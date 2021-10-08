#include <stdio.h>

int	main()
{
	int	a;
	int	b;
	int	ct;
	int	res;

	ct = 0;
	res = 0;
	scanf("%d %d", &a, &b);
	for (int i = 1; i <= 1000; ++i)
	{
		for (int k = 0; k < i; ++k)
		{
			++ct;
			if (ct >= a && ct <= b)
				res += i;
			if (ct == b)
				break ;
		}
	}
	printf("%d\n", res);
}
